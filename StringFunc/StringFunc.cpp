// StringFunc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

void strcpy1(char* p, const char* p1);					//复制字符串
void strncpy1(char* p, const char* p1, int n);			//复制指定长度字符串
void strcat1(char* p, char* p1);						//附加字符串
void strncat1(char* p, const char* p1, int n);			//附加指定长度字符串
int strlen1(const char* p);								//取字符串长度
int strcmp1(const char* p, const char* p1);				//比较字符串
int strcasecmp1(const char* p, const char* p1);			//忽略大小写比较字符串
int strncmp1(const char* p, const char* p1, int n);		//比较指定长度字符串

int strchr1(const char* p, char c);						//在字符串中查找指定字符
int strrchr1(const char* p, char c);					//在字符串中反向查找
int strstr1(const char* p, const char* p1);				//查找字符串
double strtod(const char* str, char* ppend);			//从字符串 p 中转换 double 类型数值，并将后续的字符串指针存储到 ppend 指向的 char* 类型存储。
void strtol(char* p, char* ppend, char* base);			//从字符串 p 中转换 long 类型整型数值，base 显式设置转换的整型进制，设置为 0 以根据特定格式判断所用进制，0x, 0X 前缀以解释为十六进制格式整型，0    前缀以解释为八进制格式整型
void atoi(char* p);										//字符串转换到 int 整型
void atof(char* p);										//字符串转换到 double 符点数
void atol(char* p);										//字符串转换到 long 整型

int main()
{
	char str1[100] = "Bsa0.24";
	char str2[100] = "62";
	//cout << "Input str1:";
	//cin >> str1;
	//cout << "Input str2:";
	//cin >> str2;

	//strcpy1(str1, str2);
	//strncpy1(str1, str2, 2);
	//strcat1(str1, str2);
	//strncat1(str1, str2, 3);

	cout << str1 << endl;
	cout << str2 << endl;
	//cout << strlen1(str1) << endl;
	//cout << strlen1(str2) << endl;
	//cout << strcmp1(str1, str2) << endl;
	//cout << strcasecmp1(str1, str2) << endl;
	//cout << strncmp1(str1, str2, 2) << endl;
	//cout << strchr1(str1, '2') << endl;
	//cout << strrchr1(str1, '6') << endl;
	//cout << strstr1(str1, str2) << endl;
	//cout << strtod(str1, str2) << endl;

	std::cout << "Hello World!\n" << endl;
	return 0;
}

void strcpy1(char* p, const char* p1)
{
	if ((p == NULL) && (p1 == NULL))
		return;
	while (p && (*p++ = *p1++) != '\0')
		NULL;
}

void strncpy1(char* p, const char* p1, int n)
{
	if ((p == NULL) && (p1 == NULL))
		return;
	while (p && n--)
	{
		if (*p1 != '\0')
		{
			*p++ = *p1++;
		}
		else
		{
			*p++ = '\0';
		}
	}
	while (p)
	{
		if (*p != '\0')
			* p++ = '\0';
	}
}

void strcat1(char* p, char* p1)
{
	if((p == NULL) && (p1 == NULL))
		return;
	while (p && *p != '\0')
		++p;
	while (p && (*p++ = *p1++) != '\0')
		NULL;
}

void strncat1(char* p, const char* p1, int n)
{
	if ((p == NULL) && (p1 == NULL))
		return;
	while (p && *p != '\0')
		++p;
	while (p && n-- && *p1 != '\0')
		* p++ = *p1++;
}

int strlen1(const char* p)
{
	const char* eos = p;
	while (*eos++)
		NULL;
	return((int)(eos - p - 1));
}

int strcmp1(const char* p, const char* p1)
{
	int ret = 0;
	while (!(ret = *(unsigned char*)p - *(unsigned char*)p1) && *p1)
	{
		++p;
		++p1;
	}
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return(ret);
}

int strcasecmp1(const char* p, const char* p1)
{
	int ret = 0;
	if(p == NULL && p1 == NULL)
		return NULL;
	int ch1, ch2;
	while (p && p1 && *p && *p1)
	{
		if ((ch1 = (int)* p) >= 'A' && (ch1 <= 'Z'))
			ch1 += 32;
		if ((ch2 = (int)* p1) >= 'A' && (ch2 <= 'Z'))
			ch2 += 32;
		if (ch1 == ch2)
		{
			++p;
			++p1;
		}
		else break;
	}
	if (ch1 - ch2 < 0)
		ret = -1;
	else if (ch1 - ch2 > 0)
		ret = 1;
	return ret;
}

int strncmp1(const char* p, const char* p1, int n)
{
	int ret = 0;
	if (p == NULL && p1 == NULL)
		return NULL;
	while (p && p1 && *p && *p1 && *p == *p1 && n--)
	{
		if (n == 0)
		{
			if (*p - *p1 < 0)
				ret = -1;
			else if (*p - *p1 > 0)
				ret = 1;
			else ret = 0;
			break;
		}
		++p;
		++p1;
	}
	if (n > 0)
	{
		if (p && *p != '\0' && p1 && *p1 != '\0')
		{
			if (*p1 - *p > 0)
				ret = -1;
			else if (*p1 - *p < 0)
				ret = 1;
			else ret = 0;
		}
		else if (!p && *p == '\0')
			ret = -1;
		else if (!p1 && *p1 == '\0')
			ret = 1;
		else ret = 0;
	}
	return ret;
}

int strchr1(const char* str, char c)
{
	if (str == NULL)
		return NULL;
	int loc = 0;
	for (; *str != (char)c; ++str)
	{
		loc++;
		if (*str == '\0')
			return NULL;
	}
	return loc + 1;
}

int strrchr1(const char* str, char c)
{
	if (str == NULL)
		return NULL;
	int cur = 0;
	int loc;
	for (; *str != '\0'; ++str)
	{
		if (*str == c)
			loc = cur;
		++cur;
		//if (*str == '\0')
		//	return NULL;
	}
	if (loc == NULL)
		return NULL;
	else
		return cur - loc;
}

int strstr1(const char* str1, const char* str2)
{
	if(str1 == NULL && str2 == NULL)
		return NULL;
	int loc = 0;
	const char* s = str1;
	const char* t = str2;
	for (; *str1 != '\0'; ++str1)
	{
		for (s = str1, t = str2; *t != '\0' && *s == *t; ++s, ++t)
			NULL;
		if (*t == '\0')
			return loc + 1;
		++loc;
	}
	return NULL;
}

double strtod(const char* str, char* ppend)
{
	if (str == NULL)
		return NULL;
	double d;
	int deci = 0;
	bool find = false;
	while (*str != '\0')
	{
		if (*str == '.' && deci == 0)
		{
			++deci;
			str++;
			continue;
		}
		else if (*str >= '0' && *str <= '9')
		{
			if(find==false)
			{
				find = true;
				d = 0;
			}
			if (deci == 0)
			{
				d = d * 10 + ((int)* str - 48);
				str++;
				continue;
			}
			else
			{
				d = d + ((int)* str - 48) / pow(10, deci);
				++deci;
			}
		}
		else if (find)
		{
			*ppend = *str;
			return d;
		}
		str++;
	}
	if (find)
	{
		*ppend = *str;
		return d;
	}
	else
		return NULL;
}

void strtol(char* p, char* ppend, char* base)
{
}

void atoi(char* p)
{
}

void atof(char* p)
{
}

void atol(char* p)
{
}
