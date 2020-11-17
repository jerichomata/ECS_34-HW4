#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

#define SIZE_TO_CLEAR 10000
#define INPUT_FILES_DIR "part1_files/"

// Should clear any recently used (but no longer
// "alive") stack memory. Purpose is to prevent
// student's code from working if their loadLibrary()
// returns a pointer to a local/automatic variable.
static void overwriteRecentStackUsage(void)
{
    char recent[SIZE_TO_CLEAR];
    memset(recent, 0, SIZE_TO_CLEAR);
}

// Makes assumptions about the memory manager.
// Should clear any recently deallocated memory.
// Purpose is to prevent student's code from working
// if their loadLibrary() returns a dangling pointer.
static void overwriteRecentHeapUsage(void)
{
    void* recent = malloc(SIZE_TO_CLEAR);
    memset(recent, 0, SIZE_TO_CLEAR);
    free(recent);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "You did not pass a test case number as command-line argument to this executable.\n");
        return 1;
    }
    int caseNum = atoi(argv[1]);
    struct Library * l1 = NULL, * l2 = NULL;
    char * filename1 = NULL;
    char * filename2 = NULL;
    switch (caseNum)
    {
        case 1: case 7:
            filename1 = INPUT_FILES_DIR"lib2.csv";
            filename2 = INPUT_FILES_DIR"lib1.csv";
            break;
        case 2: case 5:
            filename1 = INPUT_FILES_DIR"lib3.csv";
            filename2 = INPUT_FILES_DIR"lib4.csv";
            break;
        default:
            fprintf(stderr, "Invalid case number.\n");
            return 2;
    }
    l1 = loadLibrary(filename1);
    l2 = loadLibrary(filename2);
    overwriteRecentStackUsage();
    overwriteRecentHeapUsage();
    switch (caseNum)
    {
        case 1: case 2: case 7:
            printf("=== Library 1 ===\n");
            printLibrary(l1);
            printf("=== Library 2 ===\n");
            printLibrary(l2);
            break;
        case 5:
            printf("Number of common titles: %d\n",
                countCommonTitles(l1, l2));
            break;
        default:
            fprintf(stderr, "Invalid case number.\n");
            return 2;
    }
    if (caseNum == 7)
    {
        freeLibrary(l1);
        freeLibrary(l2);
    }
    return 0;
}