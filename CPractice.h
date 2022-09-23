#pragma once
/*

    这个头文件记录了我练习C语言编程时做的一些题目

*/

#include<math.h>
#include<stdio.h>
#include<assert.h>

//判断一个数是否是素数
int is_prime(int n)
{
    int i = 0;
    if (n == 1)
        return 0;
    else if (n != 2 && n % 2 == 0)
        return 0;
    else
    {
        for (i = 3; i <= sqrt(n); i += 2)
        {
            if (n % i == 0)
            {
                return 0;
                //break;
            }
        }
        //if (i>sqrt(n))
        return 1;
    }
    return 0;
}

//自定义一个函数求字符串长度 不定义临时变量，用递归实现
int my_strlen(char* p)
{
    if (*p != '\0')
        return 1 + my_strlen(p + 1);  //为什么这里是p+1而不能写成p++? 但可以写成++p
    else
        return 0;
}

//用递归的方法求n的阶乘
int factorial(int n)
{
    if (n != 1)
        return n * factorial(n - 1);
    else
        return 1;
}

//求第n个斐波那契数 递归
int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2); //此递归效率很低，例如n=50的时候，计算机计算需要很长时间，用循环比较合适
}

//求第n个斐波那契数 循环
unsigned long long Fibonacci_2(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
    {
        int a = 0, b = 1, c = 0;
        while (n > 1)
        {
            c = a + b;
            a = b;
            b = c;
            n--;
        }
        return c;
    }
}

//汉诺塔问题   A--初始位置  B--辅助位置  C--目标位置
void Hanoi(int n, char A, char B, char C)//n代表现在需要将第n个圆盘放到目标C
{
    if (n == 1)                            //当递归到第1个圆盘时，直接将其放到目标C
        printf("%c->%c ", A, C);
    else
    {
        Hanoi(n - 1, A, C, B);                //1.将n-1层圆盘放到辅助位置B
        //2.对于第n-1层圆盘，将C当辅助位置，B当目标位置，所以B,C互换

        printf("%c->%c ", A, C);           //将第n个圆盘放到目标位置

        Hanoi(n - 1, B, A, C);                //1.将n-1层圆盘放到目标位置C
        //2.对于n-2层圆盘，A当作辅助位置，B当作初始位置，所以A,B互换
    }
}

//青蛙跳台阶问题 一次可以跳1个，一次也可以跳2个，请问跳到第n个台阶有多少中跳法？（类似于斐波那契数列）
int jump(int n) // n代表一共n个台阶
{
    int count = 0; //count代表跳法的个数
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    {
        return jump(n - 1) + jump(n - 2);
    }

}

//冒泡排序函数
void bubble_sort(int arr[], int sz)
{
    int i = 0, j = 0;
    int temp = 0;
    for (i = 0; i < sz - 1; i++)//这里表示冒泡循环的趟数，趟数=数组元素个数-1
    {
        int flag = 1;//假设这一趟要排序的数据已经有序

        for (j = 0; j < sz - i - 1; j++)//sz-i-1表示遍历到的位置，10个元素需要依次循环9，8，7，6。。。次
        {
            if (arr[j] > arr[j + 1])//每次循环都将较大的数右移一位
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;//本趟排序的数据其实不完全有序
            }
        }

        if (flag == 1)
        {
            break;
        }
    }
}

//写一个函数求出二进制数(补码)中有多少个1
int count_bit_one(int a)
{
    /*  1.解法1
    int count=0;
    int i=0;
    while(i<32)
    {
        if(((a>>i)&1)==1)
        {
            count++;
        }
        i++;
    }
    return count;
    */
    int count = 0;
    while (a)    //最精简的解法  谷歌面试题，考察频繁
    {
        a = a & (a - 1);
        count++;
    }
    return count;
}

//写一个递归函数，输入一个非负整数，返回它的每一位之和，例如输入1729，返回1+7+2+9=19.
int Digitsum(unsigned int n)
{
    if (n == 0)
        return 0;
    return n % 10 + Digitsum(n / 10);
}

//用递归实现n的k次方
double nKPower(int n, int k)
{
    if (k < 0)
        return (1.0 / n) * nKPower(n, k + 1);//或者写成 return (1.0/nKPower(n,-k));
    else if (k == 0)
        return 1;
    else return n * nKPower(n, k - 1);
}

//在屏幕打印菱形 形参n表示菱形中间一行的大小
void printDiamond(int n)
{
    int i = 0, j = 0;
    for (i = 1; i <= 2 * n - 1; i++)
    {
        if (i <= n)
        {
            for (j = 1; j <= n - i; j++)
            {
                printf(" ");
            }
            for (j = 1; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
        else
        {
            for (j = 1; j <= i - n; j++)
            {
                printf(" ");
            }
            for (j = 1; j <= 2 * n - i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
}

/*
    调用此函数会死循环
    VC6.0 环境下，i<=10 死循环     内存布局中 i 的地址和 arr[10]的地址相同
    gcc 编译器，i<=11 死循环       内存布局中 i 的地址和 arr[11]的地址相同
    VS2013 环境下，i<=12 死循环    内存布局中 i 的地址和 arr[12]的地址相同
    
    1.栈里面先使用高地址空间，再使用低地址空间
    2.数组随着下标增长，地址是由低到高变化
*/
void printhehe()
{
    int i = 0;  //先定义的i， 所以会放在栈区的高地址
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//如果先定义 arr[10] ，则 arr[10]放在高地址，不会死循环
    for (i = 0; i <= 12; i++)
    {
        printf("hehe\n");
        arr[i] = 0; 
    }
}

//写一个函数my_strcpy，实现strcpy函数的功能 (此代码是优化过的满分代码)
char* my_strcpy(char* dest, const char* src)
{
    char* ret = dest;
    assert(dest != NULL);//断言
    assert(src != NULL);//断言
     
    //把src指向的字符串拷贝到dest指向的空间，包含'\0'字符
    while (*dest++ = *src++)
    {
        ;
    }
    return ret;
}