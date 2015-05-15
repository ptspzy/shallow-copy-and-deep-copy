// 浅拷贝与深拷贝.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
class A
{
public:
	A();
	A(int age,char *p);
	~A();
	A(A &p);

private:
	int pAge;
	char *pName;
};

A::A()
{
}
A::A(int age, char *p) 
{
	pAge = age;
	pName = new char[strlen(p) + 1];  //动态空间申请之后的赋值 
	if (pName != NULL)
		strcpy(pName, p);
}

A::A(A &p)
{
	cout << "使用拷贝构造函数" << endl;
	pAge = p.pAge;
	pName = new char[strlen(p.pName) + 1];  //动态空间申请之后的赋值  
	if (pName != NULL)
		strcpy(pName, p.pName);
}

A::~A()
{
	cout << "调用析构函数" << endl;
	if (pName != NULL)
		delete[]pName;
}
int _tmain(int argc, _TCHAR* argv[])
{
	A a(20,"pzy");
	A b(a);
	return 0;
}

