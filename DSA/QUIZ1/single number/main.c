#include <stdio.h>
#include <stdlib.h>

int main()
{
 int findSingle(int array[],int array_size)
{
    int res=array[0];
    for(int i=1;i< array_size;i++)
        res=res^array[1];
    return res;
}
}
