#include<stdio.h>
#include<stdlib.h>
#include<math.h>
 
int main()
{
double aa=1e-80;
for(int i=1;i<=500;i++)
    aa/=10;
float a = 0.0;
float b;
a = a/0;
b = -sqrt(-1);
printf("a=%f b=%f\n",a,b);
return 0;
}
