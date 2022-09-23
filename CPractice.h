#pragma once
/*

    ���ͷ�ļ���¼������ϰC���Ա��ʱ����һЩ��Ŀ

*/

#include<math.h>
#include<stdio.h>
#include<assert.h>

//�ж�һ�����Ƿ�������
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

//�Զ���һ���������ַ������� ��������ʱ�������õݹ�ʵ��
int my_strlen(char* p)
{
    if (*p != '\0')
        return 1 + my_strlen(p + 1);  //Ϊʲô������p+1������д��p++? ������д��++p
    else
        return 0;
}

//�õݹ�ķ�����n�Ľ׳�
int factorial(int n)
{
    if (n != 1)
        return n * factorial(n - 1);
    else
        return 1;
}

//���n��쳲������� �ݹ�
int Fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Fibonacci(n - 1) + Fibonacci(n - 2); //�˵ݹ�Ч�ʺܵͣ�����n=50��ʱ�򣬼����������Ҫ�ܳ�ʱ�䣬��ѭ���ȽϺ���
}

//���n��쳲������� ѭ��
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

//��ŵ������   A--��ʼλ��  B--����λ��  C--Ŀ��λ��
void Hanoi(int n, char A, char B, char C)//n����������Ҫ����n��Բ�̷ŵ�Ŀ��C
{
    if (n == 1)                            //���ݹ鵽��1��Բ��ʱ��ֱ�ӽ���ŵ�Ŀ��C
        printf("%c->%c ", A, C);
    else
    {
        Hanoi(n - 1, A, C, B);                //1.��n-1��Բ�̷ŵ�����λ��B
        //2.���ڵ�n-1��Բ�̣���C������λ�ã�B��Ŀ��λ�ã�����B,C����

        printf("%c->%c ", A, C);           //����n��Բ�̷ŵ�Ŀ��λ��

        Hanoi(n - 1, B, A, C);                //1.��n-1��Բ�̷ŵ�Ŀ��λ��C
        //2.����n-2��Բ�̣�A��������λ�ã�B������ʼλ�ã�����A,B����
    }
}

//������̨������ һ�ο�����1����һ��Ҳ������2��������������n��̨���ж�������������������쳲��������У�
int jump(int n) // n����һ��n��̨��
{
    int count = 0; //count���������ĸ���
    if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
    {
        return jump(n - 1) + jump(n - 2);
    }

}

//ð��������
void bubble_sort(int arr[], int sz)
{
    int i = 0, j = 0;
    int temp = 0;
    for (i = 0; i < sz - 1; i++)//�����ʾð��ѭ��������������=����Ԫ�ظ���-1
    {
        int flag = 1;//������һ��Ҫ����������Ѿ�����

        for (j = 0; j < sz - i - 1; j++)//sz-i-1��ʾ��������λ�ã�10��Ԫ����Ҫ����ѭ��9��8��7��6��������
        {
            if (arr[j] > arr[j + 1])//ÿ��ѭ�������ϴ��������һλ
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = 0;//���������������ʵ����ȫ����
            }
        }

        if (flag == 1)
        {
            break;
        }
    }
}

//дһ�����������������(����)���ж��ٸ�1
int count_bit_one(int a)
{
    /*  1.�ⷨ1
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
    while (a)    //���Ľⷨ  �ȸ������⣬����Ƶ��
    {
        a = a & (a - 1);
        count++;
    }
    return count;
}

//дһ���ݹ麯��������һ���Ǹ���������������ÿһλ֮�ͣ���������1729������1+7+2+9=19.
int Digitsum(unsigned int n)
{
    if (n == 0)
        return 0;
    return n % 10 + Digitsum(n / 10);
}

//�õݹ�ʵ��n��k�η�
double nKPower(int n, int k)
{
    if (k < 0)
        return (1.0 / n) * nKPower(n, k + 1);//����д�� return (1.0/nKPower(n,-k));
    else if (k == 0)
        return 1;
    else return n * nKPower(n, k - 1);
}

//����Ļ��ӡ���� �β�n��ʾ�����м�һ�еĴ�С
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
    ���ô˺�������ѭ��
    VC6.0 �����£�i<=10 ��ѭ��     �ڴ沼���� i �ĵ�ַ�� arr[10]�ĵ�ַ��ͬ
    gcc ��������i<=11 ��ѭ��       �ڴ沼���� i �ĵ�ַ�� arr[11]�ĵ�ַ��ͬ
    VS2013 �����£�i<=12 ��ѭ��    �ڴ沼���� i �ĵ�ַ�� arr[12]�ĵ�ַ��ͬ
    
    1.ջ������ʹ�øߵ�ַ�ռ䣬��ʹ�õ͵�ַ�ռ�
    2.���������±���������ַ���ɵ͵��߱仯
*/
void printhehe()
{
    int i = 0;  //�ȶ����i�� ���Ի����ջ���ĸߵ�ַ
    int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };//����ȶ��� arr[10] ���� arr[10]���ڸߵ�ַ��������ѭ��
    for (i = 0; i <= 12; i++)
    {
        printf("hehe\n");
        arr[i] = 0; 
    }
}

//дһ������my_strcpy��ʵ��strcpy�����Ĺ��� (�˴������Ż��������ִ���)
char* my_strcpy(char* dest, const char* src)
{
    char* ret = dest;
    assert(dest != NULL);//����
    assert(src != NULL);//����
     
    //��srcָ����ַ���������destָ��Ŀռ䣬����'\0'�ַ�
    while (*dest++ = *src++)
    {
        ;
    }
    return ret;
}