#include <stdio.h>
#include <stdlib.h>
typedef struct structure
{
    char *s;
    int **_2D_array;
} structure;
int main()
{
    structure *demo = malloc(sizeof(structure));
    demo->s = malloc(20 * sizeof(char));
    demo->_2D_array = malloc(2 * sizeof(int));
    for (int i = 0; i < 2; i++)
    {
        demo->_2D_array[i] = malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++)
            demo->_2D_array[i][j] = i + j;
    }
    demo->s = "Lakshya Garg";
    printf("contents:\n");
    printf("String=%s\nArray:\n", demo->s);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%d ", demo->_2D_array[i][j]);
        printf("\n");
        free(demo->_2D_array[i]);
    }
    free(demo->s);
    free(demo->_2D_array);
    free(demo);
    return 0;
}