#include<stdio.h>
#include<stdlib.h>
int main()
{
float f1 = 16777216.0;
float f2 = 16777217.0;
float f3 = 16777218.0;
 
printf("16,777,216:%f\n",f1);
printf("16,777,217:%f\n",f2);
printf("16,777,218:%f\n",f3);
printf("f1==f2?%s",f1==f2?"true":"false");
return 0;
}
