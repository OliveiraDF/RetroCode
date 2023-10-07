; // ErrorCode.mc File

LanguageNames=
    (
        French   = 0x0407:Messages_FRA
        English  = 0x0409:Messages_ENU
    )

;////////////////////////////////////////
;// Events
;//

MessageId       = +1
SymbolicName    = RC_EVENT_STARTED
Language        = French
L'application %1 a �t� d�marr� avec succ�s
.
Language        = English
The app %1 has been started successfully
.

MessageId       = +1
SymbolicName    = RC_EVENT_STOPPED
Language        = French
L'application %1 a �t� arr�t�
.
Language        = English
The app %1 has been stopped
.

; // The following are the message definitions.

MessageId=0x1000
SymbolicName=RC_NOT_MATCHING
Language=French
La cha�ne de caract�re ne matche pas le pattern
.
Language=English
The string not matches the pattern
.

MessageId=+1
SymbolicName=RC_FORMAT_NOT_FOUND
Language=French
Impossible de conna�tre le format de l'image
.
Language=English
Unable to know the image format
.

MessageId=+1
SymbolicName=RC_GL_INVALID_ENUM
Language=French
Une valeur inacceptable est sp�cifi�e pour un argument �num�r�. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
.
Language=English
An unacceptable value is specified for an enumerated argument. The offending function is ignored, having no side effect other than to set the error flag
.

MessageId=+1
SymbolicName=RC_GL_INVALID_VALUE
Language=French
Un argument num�rique est hors de port�e. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
.
Language=English
A numeric argument is out of range. The offending function is ignored, having no side effect other than to set the error flag
.

MessageId=+1
SymbolicName=RC_GL_INVALID_OPERATION
Language=French
L�op�ration sp�cifi�e n�est pas autoris�e dans l��tat actuel. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
.
Language=English
The specified operation is not allowed in the current state. The offending function is ignored, having no side effect other than to set the error flag
.

MessageId=+1
SymbolicName=RC_GL_STACK_OVERFLOW
Language=French
Cette fonction provoquerait un d�passement de capacit� de la pile. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
.
Language=English
This function would cause a stack overflow. The offending function is ignored, having no side effect other than to set the error flag
.

MessageId=+1
SymbolicName=RC_GL_STACK_UNDERFLOW
Language=French
Cette fonction provoquerait un sous-flux de pile. La fonction incrimin�e est ignor�e, n�ayant aucun effet secondaire autre que de d�finir l�indicateur d�erreur
.
Language=English
This function would cause a stack underflow. The offending function is ignored, having no side effect other than to set the error flag
.

MessageId=+1
SymbolicName=RC_GL_OUT_OF_MEMORY
Language=French
Il ne reste pas assez de m�moire pour ex�cuter la fonction. L��tat d�OpenGL n�est pas d�fini, � l�exception de l��tat des indicateurs d�erreur, une fois cette erreur enregistr�e
.
Language=English
There is not enough memory left to execute the function. The state of OpenGL is undefined, except for the state of the error flags, after this error is recorded
.

MessageId=+1
SymbolicName=RC_GLEXT_NOTINITIALIZED
Language=French
Les prototypes GLEXT n'ont pas �t� initialis�s
.
Language=English
GLEXT prototypes are not initialized
.
