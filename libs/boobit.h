/* Developed by Pedro Harmendani - 2016 */

/* Library */


#ifndef CTYPE_H
#define CTYPE_H
#include <ctype.h>
#endif

#ifndef ERRNO_H
#define ERRNO_H
#include <errno.h>
#endif

/* New types for this header */
typedef char* String;

/* Functions and Procedures */

/* Create some name, local and extension for the file
** and return it String name. Params: (String dir, String name, String extension)
*/
String createNameAndPath(String, String, String);

/* Create new file pointer and return it. */
FILE *openFileTxt(String);

/* Write something after (String*) end line of the file (FILE*) and save it in the disc*/
void writeFileEndTxt(FILE*, String);

