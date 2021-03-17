#include<stdio.h>
#include<stdlib.h>
int main()
{
float a = 3.14;
float b = 1e20;
printf("(3.14+1e20)-1e20 = %f\n",(a+b)-b);
printf("3.14+(1e20-1e20) = %f\n",a+(b-b));
return 0;
}
