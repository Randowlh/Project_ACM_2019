#include <stdio.h>
//将n个盘中从x柱搬至z柱，可借助y柱
void Hanoi (int n, char x, char y, char z);

int main ()
{   int n;  //盘子数量
    scanf( "%d", &n);
    Hanoi (n, 'A', 'B', 'C');
    return 0;
}
//将n个盘中从x柱搬至z柱，可借助y柱
void Hanoi (int n, char x, char y, char z)
{
    if (n == 1) {
        printf ("%c->%c\n", x, z); //一个盘子时可直接搬动
    } else {
        Hanoi (n-1, x, z, y);//将n-1个盘中从x柱搬至y柱，借助z柱
        printf ("%c->%c\n", x, z);//剩余一个盘子时可直接搬动
        Hanoi (n-1, y, x, z);//将n-1个盘中从y柱搬至z柱，借助x柱
    }
}
