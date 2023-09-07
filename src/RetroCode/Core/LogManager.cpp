/**
 *
 * Retro Code
 *
 * MIT License
 *
 * Copyright(c) 2014-2023 Retro Technique
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files(the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions :
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */

#include "pch.h"
#include "LogManager.h"

namespace retro
{
	namespace core
	{

		static inline CString GetWin32ErrorDesc(DWORD uError)
		{
			CString strError;
			LPVOID pMsgBuf = NULL;

			if (FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
				NULL, uError, 0, reinterpret_cast<LPTSTR>(&pMsgBuf), 0, NULL) != 0)
			{
				strError = reinterpret_cast<LPCTSTR>(pMsgBuf);
				LocalFree(pMsgBuf);
			}

			return strError;
		}

		CLogManager CLogManager::ms_Instance;

		CLogManager::CLogManager()
			: m_nRepeatedMessageCount(0)
		{

		}

		CLogManager::~CLogManager()
		{

		}

		HRESULT CLogManager::RegisterObserver(ILogObserver* pObserver)
		{
			ASSERT(pObserver);

			POSITION pos = m_Observers.AddTail(pObserver);
			if (!pos)
			{
				return E_OUTOFMEMORY;
			}

			return S_OK;
		}

		void CLogManager::UnregisterObserver(ILogObserver* pObserver)
		{
			ASSERT(pObserver);

			POSITION pos = m_Observers.Find(pObserver);
			if (pos)
			{
				m_Observers.RemoveAt(pos);
			}
		}

		void CLogManager::UnregisterAll()
		{
			m_Observers.RemoveAll();
		}

		void CLogManager::Log(LPCTSTR lpszMessage, ELogLevel eLogLevel)
		{
			ASSERT(lpszMessage);

			m_Mutex.Lock();
			
			if (StrCmp(m_strLastMessage.GetString(), lpszMessage) == 0)
			{
				m_nRepeatedMessageCount++;
				return;
			}

			const CTime dtNow = CTime::GetCurrentTime();

			if (m_nRepeatedMessageCount > 0)
			{
				CString strTmp;
				strTmp.Format(_T("Last message repeated %d time%c"), m_nRepeatedMessageCount, m_nRepeatedMessageCount == 1 ? _T(' ') : _T('s'));

				DispatchLogs(dtNow, ELogLevel_Information, strTmp.GetString());

				m_nRepeatedMessageCount = 0;
			}

			m_strLastMessage = lpszMessage;

			DispatchLogs(dtNow, eLogLevel, lpszMessage);

			m_Mutex.Unlock();
		}

		void CLogManager::LogInterfaceError(LPCTSTR lpszMessage, HRESULT hr, ELogLevel eLogLevel)
		{
			ASSERT(lpszMessage);

			CString strError;

			strError += lpszMessage;

			IErrorInfo* pIEI = NULL;
			if (SUCCEEDED(GetErrorInfo(0, &pIEI)) && pIEI)
			{
				BSTR zStr = NULL;
				if (SUCCEEDED(pIEI->GetDescription(&zStr)))
				{
					strError += zStr;

					SysFreeString(zStr);
				}

				pIEI->Release();
			}
			else
			{
				strError += GetWin32ErrorDesc(hr);
			}

			Log(strError.GetString(), eLogLevel);
		}

		void CLogManager::LogWinError(LPCTSTR lpszMessage, DWORD dwError, ELogLevel eLogLevel)
		{
			ASSERT(lpszMessage);

			CString strError;
		
			strError += lpszMessage;
			strError += GetWin32ErrorDesc(dwError);

			Log(strError.GetString(), eLogLevel);
		}

		void CLogManager::Flush()
		{
			m_Mutex.Lock();

			POSITION logpos = m_Historic.GetHeadPosition();
			while (logpos)
			{
				const TLog& Entry = m_Historic.GetNext(logpos);

				POSITION obspos = m_Observers.GetHeadPosition();
				while (obspos)
				{
					ILogObserver* pObserver = m_Observers.GetNext(obspos);
					if (pObserver)
					{
						pObserver->OnMessage(Entry.dtDate, Entry.eLevel, Entry.strMessage.GetString());
					}
				}
			}

			m_Mutex.Unlock();
		}

		void CLogManager::Clear()
		{
			m_Mutex.Lock();

			m_Historic.RemoveAll();

			m_Mutex.Unlock();
		}

		void CLogManager::DispatchLogs(const CTime& dtNow, ELogLevel eLogLevel, LPCTSTR lpszMessage)
		{
			ASSERT(lpszMessage);

			TLog Entry;
			Entry.dtDate = dtNow;
			Entry.eLevel = eLogLevel;
			Entry.strMessage = lpszMessage;

			m_Historic.AddTail(Entry);

			POSITION pos = m_Observers.GetHeadPosition();
			while (pos)
			{
				ILogObserver* pObserver = m_Observers.GetNext(pos);
				if (pObserver)
				{
					pObserver->OnMessage(dtNow, eLogLevel, lpszMessage);
				}
			}
		}

		CLogManager& CLogManager::GetInstance()
		{
			return ms_Instance;
		}

	}
}