#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n,array[20],i,flag=0;

   printf("Enter the number of elements in Array-\n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\n array[%d]=",i);
        scanf("%d",&array[i]);
    }
    //[2,3,4,5,2]
    for( i=0;i<n;i++)
    {
        for( j=i+1;j<n;j++)
    {
        if (array[i]==array[j])
        {
            flag=1;
            printf ("\n duplicate numbers found at position %d and %d",i,j);
        }
    }
    }
    if (flag==0)
    {
        printf("\n array has no duplicate values");
    }
    return 0;
}
