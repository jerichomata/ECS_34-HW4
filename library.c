#include "library.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Library* loadLibrary(const char* filename)
{
    struct Library *libLoad = malloc(sizeof(struct Library)); //free
    
    // libLoad->numBooks = malloc(sizeof(struct Book));
    libLoad->books= malloc(sizeof(struct Book));

    FILE *csvFile = fopen(filename, "r");

    int count=0;
    char *buffer= malloc(BUF_LEN); //free
    char *parseFile;

    if(!csvFile)
    {
        return NULL;
    } else 
    {
        while(fgets(buffer, BUF_LEN, csvFile) != NULL)
        {
            parseFile = strtok(buffer, ",");
            if(isdigit(*buffer) == 0)
            {
                return NULL;
            }
            libLoad[count].numBooks = atoi(buffer);
            parseFile = strtok(NULL, ",");
            libLoad[count].books->title = parseFile;
            parseFile = strtok(NULL, ",");
            libLoad[count].books->author = parseFile;
            parseFile = strtok(NULL, ",");
            libLoad[count].books->year = atoi(parseFile);
            count++;
        }
    }

    free(buffer);

    fclose(csvFile);

    return libLoad;
}

int printLibrary(const struct Library* library)
{
    if(!library)
    {
        return 0;
    }
    int len = (sizeof(struct Library)); 
    for(int i=0; i < len; ++i)
    {
        printf("%s by %s (%d)\n", library->books->title,library->books->author,
         library->books->year);
    }
    return 1;
}

// int countCommonTitles(const struct Library* lib1,
//                       const struct Library* lib2)
// {
    
// }

// int freeLibrary(struct Library* library)
// 
    
// }

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        fprintf(stderr, "Did not provide two library files.\n");
        return 1;
    }
    char* filename1 = argv[1];
    char* filename2 = argv[2];
    struct Library* lib1 = loadLibrary(filename1);
    struct Library* lib2 = loadLibrary(filename2);
    printf("=== Library 1 ===\n");
    printLibrary(lib1);
    printf("=== Library 2 ===\n");
    printLibrary(lib2);
    // printf("\nNo. common titles: %d\n", countCommonTitles(lib1, lib2));
    // freeLibrary(lib1);
    // freeLibrary(lib2);
}