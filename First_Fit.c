#include <stdio.h>
#include <conio.h>
#define max 25

int main()
{

    int frag[max], block[max], jobs[max], i, j, nb, nj, temp, bf[max], jf[max];

    printf("Memory Management Scheme - First Fit \n");
    printf("Enter the number of blocks: ");
    scanf("%d", &nb);

    printf("Enter the number of jobs: ");
    scanf("%d", &nj);

    printf("Enter the size of blocks --> \n");
    for (i = 0; i < nb; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
        bf[i] = 0;
    }

    printf("Enter the size of jobs --> \n");
    for (i = 0; i < nj; i++)
    {
        printf("Job %d: ", i + 1);
        scanf("%d", &jobs[i]);
    }

    for (i = 0; i < nj; i++)
    {
        for (j = 0; j < nb; j++)
        {
            if (bf[j] == 0)
            {
                temp = block[j] - jobs[i];
                if (temp > 0)
                {
                    jf[i] = j;
                    break;
                }
            }
        }

        frag[i] = temp;
        bf[j] = 1;
    }

    printf("Job No \t Job Size \t Block No \t Block Size \t Fragment\n");
    for (i = 0; i < nj; i++)
    {
        printf("%d \t\t %d \t\t %d \t\t %d \t\t %d \n", i + 1, jobs[i], jf[i], block[jf[i]], frag[i]);
    }

    return 0;
}