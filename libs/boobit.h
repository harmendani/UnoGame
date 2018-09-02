/* Developed by Pedro Harmendani - 2016 */

/* New types for this header */
typedef char* String;

/* Functions and Procedures */

/* Create some name, local and extension for the file
** and return it String name.
*/
String createNameAndPath(String, String, String);

/* Create new file pointer and return it. */
FILE *openFileTxt(String);

/* Write String type in the end line of the file and save it in the disc*/
void writeStringEndTxt(FILE*, String);

/* Write something Integer (type formatted) in the end line of the file and save it in the disc*/
void writeThingEndTxt(FILE *, String, int);

/* Write something Float (type formatted) in the end line of the file and save it in the disc*/
void writeFloatEndTxt(FILE *streamFile, String maskText, float text);

