#include<stdio.h>
#include<stdlib.h>
int main()
{
double a = 0.1;
double b = 0.2;
double c = 0.3;
double d = a+b;
 
printf("a(0.1):%.30g\n",a);
printf("b(0.2):%.30g\n",b);
printf("c(0.3):%.30g\n",c);
printf("d(0.4):%.30g\n",d);
printf("c==d?%s\n",c==d?"true":"false");
printf("c<d?%s\n",c<d?"true":"false");
return 0;
}
