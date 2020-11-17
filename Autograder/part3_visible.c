#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "You did not pass a test case number as command-line argument to this executable.\n");
        return 1;
    }
    int caseNum = atoi(argv[1]);
    struct CirQueue * q1 = NULL, * q2 = NULL, * q3 = NULL;
    int val = -1;
    switch (caseNum)
    {
        case 1:
            q1 = cirQueueCreate(8);
            cirQueueEnqueue(q1, 10);
            cirQueueEnqueue(q1, 20);
            cirQueueEnqueue(q1, 30);
            cirQueueEnqueue(q1, 40);
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 10
            cirQueueEnqueue(q1, 50);
            cirQueueEnqueue(q1, 60);
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 20
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 30
            cirQueueEnqueue(q1, 70);
            cirQueueEnqueue(q1, 80);
            cirQueueEnqueue(q1, 90);
            cirQueueEnqueue(q1, 100);
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 40
            cirQueueEnqueue(q1, 110);
            cirQueueEnqueue(q1, 120);
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 50
            cirQueueEnqueue(q1, 130);
            break;
        case 2:
            q1 = cirQueueCreate(3);
            q2 = cirQueueCreate(4);
            q3 = cirQueueCreate(2);
            cirQueueEnqueue(q1, 47);
            cirQueueEnqueue(q3, 100);
            cirQueueEnqueue(q3, 110);
            printf("%d\n", cirQueueLength(q3));  // 2
            cirQueueDequeue(q3, &val);
            printf("%d\n", val);  // 100
            cirQueueEnqueue(q3, 120);
            cirQueueEnqueue(q1, 52);
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 47
            printf("%d\n", cirQueueLength(q1));  // 1
            cirQueueEnqueue(q1, 92);
            cirQueueEnqueue(q2, 85);
            cirQueueDequeue(q3, &val);
            printf("%d\n", val);  // 110
            cirQueueEnqueue(q1, 55);
            cirQueueEnqueue(q2, 33);
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 52
            cirQueueDequeue(q2, &val);
            printf("%d\n", val);  // 85
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 92
            cirQueueEnqueue(q3, 130);
            cirQueueDequeue(q3, &val);
            printf("%d\n", val);  // 120
            cirQueueEnqueue(q3, 140);
            cirQueueDequeue(q3, &val);
            printf("%d\n", val);  // 130
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 55
            break;
        case 4:
            q1 = cirQueueCreate(-5);
            if (!q1) printf("NULL!\n");
            q2 = cirQueueCreate(0);
            if (!q1) printf("NULL!\n");
            q3 = cirQueueCreate(2);
            val = cirQueueEnqueue(q3, 5);
            printf("%d\n", val);  // 1
            val = cirQueueEnqueue(NULL, 8);
            printf("%d\n", val);  // 0
            val = cirQueueEnqueue(q3, 19);
            printf("%d\n", val);  // 1
            val = cirQueueEnqueue(q3, 55);
            printf("%d\n", val);  // 0
            q1 = cirQueueCreate(10000);
            cirQueueEnqueue(q1, 53);
            int val2 = cirQueueDequeue(q1, &val);
            printf("%d\n", val2);  // 1
            printf("%d\n", val);  // 53
            val2 = cirQueueDequeue(q1, &val);
            printf("%d\n", val2);  // 0
            break;
        case 5:
            q1 = cirQueueCreate(8);
            cirQueueEnqueue(q1, 18);
            cirQueueEnqueue(q1, -2);
            cirQueueEnqueue(q1, 35);
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // 18
            cirQueueEnqueue(q1, 120);
            cirQueueDequeue(q1, &val);
            printf("%d\n", val);  // -2
            cirQueueEnqueue(q1, 89);
            printf("%d\n", cirQueueLength(q1));  // 3
            val = cirQueueDestroy(q1);
            printf("%d\n", val);  // 1
            val = cirQueueDestroy(NULL);
            printf("%d\n", val);  // 0
            break;
        default:
            fprintf(stderr, "Invalid case number.\n");
            return 2;
    }
    return 0;
}