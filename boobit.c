/* Library */
#include "./libs/boobit.h"

String createNameAndPath(String dir, String name, String extension)
{

    int sizeName = strlen(name);
    int sizeDir = strlen(dir);
    int sizeExtension = strlen(extension);
    int sizeTotal = (sizeDir + sizeName + sizeExtension + 1);

    String newName = (char *)malloc((sizeof(String) * sizeTotal));
    strcpy(newName, dir);
    strcat(newName, name);
    strcat(newName, extension);

    return newName;
}

FILE *openFileTxt(String nameFile)
{

    FILE *fileTxt = fopen(nameFile, "a");

    if (ferror(fileTxt))
    {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }

    return fileTxt; 
}

void writeStringEndTxt(FILE *streamFile, String stringText)
{

    fflush(streamFile);
    fputs(stringText, streamFile);

    return;
}

void writeIntegerEndTxt(FILE *streamFile, String maskText, int text){
	fflush(streamFile);
	fprintf(streamFile, maskText, text);
	return;
}

void writeFloatEndTxt(FILE *streamFile, String maskText, float text){
	fflush(streamFile);
	fprintf(streamFile, maskText, text);
	return;
}
