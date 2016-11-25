#include <iostream>
#include <assert.h>
using namespace std;

//编写一个字符串复制函数
char *strcpy(char *strSrc, const char * strDest)
{
	assert((strSrc!=NULL)&&(strDest!=NULL));
	char *address = strSrc;
	while((*strSrc++=*strDest++)!='\0');
	return address;
}

int strlen(const char *strSrc)
{
	assert(strSrc!=NULL);
	int count = 0;
	while(*strSrc++!='\0')
		count++;
	return count;
}

int main()
{
	char a[] = "hello";
	char b[5];
	strcpy(b,a);
	cout<<b<<endl;
	cout<<strlen(b)<<endl;
	return 0;
}