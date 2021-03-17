#include<stdio.h>
#include<stdlib.h>
union
{
char c[4];
float f;
int i;
}t1,t2;
int main()
{
t1.i = 0x80000000;
t2.i = 0x00000000;
if(t1.f == t2.f)
{
    printf("float data is equal\n");
}
if(t1.i != t2.i)
{
    printf("int data is not equal\n");
}
return 0;
}
