#include<stdio.h>
#include<stdlib.h>
void test_float_cal()
{
float a,b,c;
int d;
b = 3.3;
c = 1.1;
a = b/c;
d = b/c;
printf("a=%f,d=%d",a,d);
 
if(a == 3)
{
printf("\nFloat a=3.3/1.1==3.0");
}
}
void test_double_cal()
{
double a,b,c;
int d;
b = 3.3;
c = 1.1;
a = b/c;
d = b/c;
printf("\n\na=%f,d=%d",a,d);
 
if(a != 3)
{
printf("\nDouble a=3.3/1.1!=3.0");
}
}
int main()
{
test_float_cal();
test_double_cal();
return 0;
}
