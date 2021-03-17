#include<stdio.h>
#include<stdlib.h>
union
{
char c[4];
float f;
int i;
}t1,t2,t3,t4;
 
// 输出字符的十六进制编码
void char_hex_out(char a)
{
const char HEX[] = "0123456789ABCDEF";
int index = a & 0x0F;
printf("%c%c",HEX[(a&0xF0)>>4],HEX[a&0x0F]);
}
 
// 输出4个字节数据的十六进制编码，可用于输出4字节变量的机器码
void four_byte_out(char * addr)
{
//输出指针变量的值，指针本质上是内存地址，是一个无符号数
//假设采用小端方式存储
char_hex_out(* (addr+3));
char_hex_out(* (addr+2));
char_hex_out(* (addr+1));
char_hex_out(* (addr+0));
printf("\n");
}
 
void float_add_overflow()
{
t1.i = 0x7F000000;
t2.i = 0x7F000000;
t3.f = t1.f+t2.f;
 
four_byte_out((char*)(&t1.f));
four_byte_out((char*)(&t2.f));
four_byte_out((char*)(&t3.f));
 
printf("t1=%.60f\n",t1.f);
printf("t2=%.60f\n",t2.f);
printf("t1+t2=%.60f\n",t3.f);
}
 
void float_sub_overflow()
{
t1.i = 0x00C00000;
t2.i = 0x00800000;
t3.f = t1.f-t2.f;
 
four_byte_out((char*)(&t1.f));
four_byte_out((char*)(&t2.f));
four_byte_out((char*)(&t3.f));
 
printf("t1=%.61f\n",t1.f);
printf("t2=%.61f\n",t2.f);
printf("t1-t2=%.61f\n",t3.f);
}
 
int main()
{
float_add_overflow();
float_sub_overflow();
return 0;
}
