//记录了一些较难知识点的学习笔记

#include <stdio.h>

int main1()
{
	//数组指针  ---- 指向数组的指针 ---- 存放数组的地址
	
	//int arr[10] = { 0 };
	//arr 是首元素地址
	//&arr[0] 是首元素地址
	//&arr 是数组的地址

	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int(*p)[10] = &arr; //数组的地址存起来，此时的 p 就是数组指针

	return 0;
}

int main2()
{
	char* arr[5];
	
	//此处的pa应该怎么表示？
	char* (*pa)[5] = &arr;//1. pa---->指针变量的名字
						  //2. pa前面的*---->说明pa是个指针
						  //3. [5]---->pa指向的数组是5个元素的
						  //4. pa指向的数组的元素类型是 char*
	 
	//对比
	char* arr[5];
	char* (*pa)[5] = &arr;
	
	int arr2[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int (*pa2)[10] = &arr2; 

	return 0;
}

int main3()
{
	int arr[5];			//arr是一个5元素的整型数组
	int* parr1[10];		//parr1是一个数组，数组有10个元素，每个元素的类型是int*,parr1是指针数组
	int(*parr2)[10];	//parr2是一个指针，该指针指向了一个数组，数组有10个元素，每个元素类型是int,是一个数组指针
	int(*parr3[10])[5]; //parr3是一个数组，该数组有10个元素，每个元素是一个数组指针，该数组指针指向的数组有5个元素，每个元素是int

	return 0;
}

int add(int x, int y)
{
	int z = 0;
	z = x + y;
	return z;
}

int main4()
{
	//函数指针，是指向函数的指针

	//&函数名，和函数名，都是函数的地址
	printf("%p\n", &add);
	printf("%p\n", add);

	int (*pa)(int, int) = add;
	printf("%p\n", (*pa)(2, 3)); //打印的是 5；pa存的是函数的地址，*pa找到这个函数

	return 0;
}

void print(const char* str)
{
	printf("%s\n", str);
}

int main5()
{
	void (*p)(const char*) = print;
	(*p)("hello world");
	return 0;
}

void (*signal(int, void(*)(int))) (int);
/*解释：1.signal 是一个函数声明
	    2.signal 函数的参数有两个，一个是int,一个是函数指针，该函数指针指向的函数的参数是 int，返回类型
		  是 void
		3.signal 函数的返回类型也是一个函数指针，该函数指针指向的函数的参数是 int，返回类型是 void
*/
//可以用typedef对以上类型进行简化
typedef void(*pfunt_t)(int);
//则以上声明可以写成：
pfunt_t signal(int, pfunt_t);

int main6()
{
	int arr[10] = { 0 };
	int(*p)[10] = &arr;//取出数组的地址

	int (*pf)(int, int);//pf是一个函数指针
	int (*pfArr[4])(int, int); //pfArr是一个数组-函数指针的数组
	int (*(*ppfArr)[4])(int, int) = &pfArr; //ppfArr是一个指向【函数指针数组】的指针
											//ppfArr是一个数组指针，指针指向的数组有4个元素
											//指向的数组的每个元素的类型是一个函数指针 int(*)(int,int)
	
	return 0;
}
