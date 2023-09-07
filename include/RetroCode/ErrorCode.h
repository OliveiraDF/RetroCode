 // ErrorCode.mc File
 // The following are the message definitions.
//
//  Values are 32 bit values laid out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: RC_NOT_MATCHING
//
// MessageText:
//
// The string not matches the pattern.%n
//
#define RC_NOT_MATCHING                  ((HRESULT)0x00002001L)

//
// MessageId: RC_FORMAT_NOT_FOUND
//
// MessageText:
//
// Unable to know the image format.%n
//
#define RC_FORMAT_NOT_FOUND              ((HRESULT)0x00002002L)

//
// MessageId: RC_GL_INVALID_ENUM
//
// MessageText:
//
// An unacceptable value is specified for an enumerated argument. The offending function is ignored, having no side effect other than to set the error flag.%n
//
#define RC_GL_INVALID_ENUM               ((HRESULT)0x00002003L)

//
// MessageId: RC_GL_INVALID_VALUE
//
// MessageText:
//
// A numeric argument is out of range. The offending function is ignored, having no side effect other than to set the error flag.%n
//
#define RC_GL_INVALID_VALUE              ((HRESULT)0x00002004L)

//
// MessageId: RC_GL_INVALID_OPERATION
//
// MessageText:
//
// The specified operation is not allowed in the current state. The offending function is ignored, having no side effect other than to set the error flag.%n
//
#define RC_GL_INVALID_OPERATION          ((HRESULT)0x00002005L)

//
// MessageId: RC_GL_STACK_OVERFLOW
//
// MessageText:
//
// This function would cause a stack overflow. The offending function is ignored, having no side effect other than to set the error flag.%n
//
#define RC_GL_STACK_OVERFLOW             ((HRESULT)0x00002006L)

//
// MessageId: RC_GL_STACK_UNDERFLOW
//
// MessageText:
//
// This function would cause a stack underflow. The offending function is ignored, having no side effect other than to set the error flag.%n
//
#define RC_GL_STACK_UNDERFLOW            ((HRESULT)0x00002007L)

//
// MessageId: RC_GL_OUT_OF_MEMORY
//
// MessageText:
//
// There is not enough memory left to execute the function. The state of OpenGL is undefined, except for the state of the error flags, after this error is recorded.%n
//
#define RC_GL_OUT_OF_MEMORY              ((HRESULT)0x00002008L)

