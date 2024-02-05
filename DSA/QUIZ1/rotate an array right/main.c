#include <stdio.h>
#include <stdlib.h>
void rotate_once_right(int array[],int length);
void rotate_right(int array[], int length, int n);

int main(void)
{
    int a1[]={1,2,3,4,5,6};

    for(int i=0;i<6;i++)
        printf("%d", a1[i]);
    printf("\n");

    //rotate_once_right(a1, 6);
rotate_right(a1, 6,2);
    for(int i=0;i<6;i++)
        printf("%d", a1[i]);
    printf("\n");

    rotate_once_right(a1,6);

    return 0;
}
void rotate_right(int array[], int length, int n)
{
   for(int i=0;i<n; i++)
        rotate_once_right(array,length);
}
void rotate_once_right(int array[],int length)
{
    int temp=array[length-1];
    for {int i=(length - 2);i>=0;i--}
     array[i=1]=array[i];
     array[0]=temp;
}
