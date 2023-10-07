 // ErrorCode.mc File
////////////////////////////////////////
// Events
//
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
// MessageId: RC_EVENT_STARTED
//
// MessageText:
//
// L'application %1 a �t� d�marr� avec succ�s
//
#define RC_EVENT_STARTED                 0x00000001L

//
// MessageId: RC_EVENT_STOPPED
//
// MessageText:
//
// L'application %1 a �t� arr�t�
//
#define RC_EVENT_STOPPED                 0x00000002L

 // The following are the message definitions.
//
// MessageId: RC_NOT_MATCHING
//
// MessageText:
//
// La cha�ne de caract�re ne matche pas le pattern
//
#define RC_NOT_MATCHING                  0x00001000L

//
// MessageId: RC_FORMAT_NOT_FOUND
//
// MessageText:
//
// Impossible de conna�tre le format de l'image
//
#define RC_FORMAT_NOT_FOUND              0x00001001L

//
// MessageId: RC_GL_INVALID_ENUM
//
// MessageText:
//
// Une valeur inacceptable est sp�cifi�e pour un argument �num�r�. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
//
#define RC_GL_INVALID_ENUM               0x00001002L

//
// MessageId: RC_GL_INVALID_VALUE
//
// MessageText:
//
// Un argument num�rique est hors de port�e. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
//
#define RC_GL_INVALID_VALUE              0x00001003L

//
// MessageId: RC_GL_INVALID_OPERATION
//
// MessageText:
//
// L�op�ration sp�cifi�e n�est pas autoris�e dans l��tat actuel. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
//
#define RC_GL_INVALID_OPERATION          0x00001004L

//
// MessageId: RC_GL_STACK_OVERFLOW
//
// MessageText:
//
// Cette fonction provoquerait un d�passement de capacit� de la pile. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
//
#define RC_GL_STACK_OVERFLOW             0x00001005L

//
// MessageId: RC_GL_STACK_UNDERFLOW
//
// MessageText:
//
// Cette fonction provoquerait un sous-flux de pile. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
//
#define RC_GL_STACK_UNDERFLOW            0x00001006L

//
// MessageId: RC_GL_OUT_OF_MEMORY
//
// MessageText:
//
// Il ne reste pas assez de m�moire pour ex�cuter la fonction. L��tat d�OpenGL n�est pas d�fini, � l�exception de l��tat des indicateurs d�erreur, une fois cette erreur enregistr�e
//
#define RC_GL_OUT_OF_MEMORY              0x00001007L

//
// MessageId: RC_GLEXT_NOTINITIALIZED
//
// MessageText:
//
// Les prototypes GLEXT n'ont pas �t� initialis�s
//
#define RC_GLEXT_NOTINITIALIZED          0x00001008L

