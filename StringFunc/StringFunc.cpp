// StringFunc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
using namespace std;

void strcpy1(char* str1, const char* str2);					//复制字符串
void strncpy1(char* str1, const char* str2, int n);			//复制指定长度字符串
void strcat1(char* str1, char* str2);						//附加字符串
void strncat1(char* str1, const char* str2, int n);			//附加指定长度字符串
int strlen1(const char* p);									//取字符串长度
int strcmp1(const char* p, const char* p1);					//比较字符串
int strcasecmp1(const char* p, const char* p1);				//忽略大小写比较字符串
int strncmp1(const char* p, const char* p1, int n);			//比较指定长度字符串
int strchr1(const char* p, char c);							//在字符串中查找指定字符
int strrchr1(const char* p, char c);						//在字符串中反向查找
int strstr1(const char* p, const char* p1);					//查找字符串
double strtod1(const char* str, char* ppend);				//从字符串 str 中转换 double 类型数值，并将后续的字符串指针存储到 ppend 指向的 char* 类型存储。

long strtol1(const char* str, char* ppend, const int base);	//从字符串 str 中转换 long 类型整型数值，base 显式设置转换的整型进制，设置为 0 以根据特定格式判断所用进制，0x, 0X 前缀以解释为十六进制格式整型，0前缀以解释为八进制格式整型

int atoi1(const char* str);									//字符串转换到 int 整型
double atof1(const char* str);								//字符串转换到 double 符点数
long atol1(const char* str);								//字符串转换到 long 整型

int main()
{
	char str1[100] = "24.2ddas";
	char str2[100] = "6223";

	//strcpy1(str1, str2);
	//strncpy1(str1, str2, 2);
	//strcat1(str1, str2);
	//strncat1(str1, str2, 3);

	cout << "str1:" << str1 << endl;
	cout << "str2:" << str2 << endl;
	//cout << strlen1(str1) << endl;
	//cout << strlen1(str2) << endl;
	//cout << strcmp1(str1, str2) << endl;
	//cout << strcasecmp1(str1, str2) << endl;
	//cout << strncmp1(str1, str2, 2) << endl;
	//cout << strchr1(str1, '2') << endl;
	//cout << strrchr1(str1, '6') << endl;
	//cout << strstr1(str1, str2) << endl;
	//cout << strtod1(str1, str2) << endl;
	//cout << atoi1(str1) << endl;
	//cout << atof1(str1) << endl;
	//cout << atol1(str1) << endl;

	return 0;
}

void strcpy1(char* str1, const char* str2)
{
	if ((str1 == NULL) || (str2 == NULL))		//判断指针是否为空，为空退出函数
		return;
	while (str1 && (*str1++ = *str2++) != '\0')	//str1非空，并且*str2赋值给*str1，str1、str2后移一位
		NULL;
}

void strncpy1(char* str1, const char* str2, int n)
{
	if ((str1 == NULL) || (str2 == NULL))
		return;
	while (n--)					//逐个字符复制，复制n个字符
	{
		if (*str2 != '\0')
		{
			*str1++ = *str2++;	//*str2赋值给*str1，并且str1、str2后移一位
		}
		else
		{
			*str1++ = '\0';		//str1补'\0'
		}
	}
	while (str1)
	{
		if (*str1 != '\0')		//从str1[n]开始将其后所有字符置为'\0'
			* str1++ = '\0';
		else break;				//遇'\0'表明字符串结束
	}
}

void strcat1(char* str1, char* str2)
{
	if((str1 == NULL) || (str2 == NULL))
		return;
	while (*str1 != '\0')				//将指针str1后移使其指向字符串str1尾字符后一位
		++str1;
	while ((*str1++ = *str2++) != '\0')	//逐个复制字符
		NULL;
}

void strncat1(char* str1, const char* str2, int n)
{
	if ((str1 == NULL) && (str2 == NULL))
		return;
	while (*str1 != '\0')				//将指针str1后移使其指向字符串str1尾字符后一位
		++str1;
	while (n-- && *str2 != '\0')		//逐个复制n个字符
		* str1++ = *str2++;
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

double strtod1(const char* str, char* ppend)
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

long strtol1(const char* str, char* ppend, const int base)
{
	if (str == NULL)
		return NULL;
	long ret;
	int inte = 0;			//全部转为十进制整数
	bool find = false;
	//for (int i = 0; i < s.size(); i++) 
	//{
	//	char t = s[i];
	//	if (t >= '0' && t <= '9')
	//		inte = inte * base + t - '0';
	//	else inte = inte * base + t - 'a' + 10;
	//}
	
	if (base == 2)
	{
		while (*str != '\0')
		{
			if (*str >= '0' && *str <= '1')
			{
				find = true;
				inte = inte * 10 + (*str - '0');
			}
			else if (find == true)
				break;
		}

	}
	else if (base == 8)
	{

	}
	else if (base == 10)
	{

	}
	else if (base == 16)
	{

	}
	return 0;
}

int atoi1(const char* str)
{
	if (str == NULL)
		return NULL;
	int ret = 0;
	bool find = false;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			find = true;
			ret = ret * 10 + *str - '0';
		}
		else if (find == true)
			return ret;
		str++;
	}
	if (find == true)
		return ret;
	else
		return NULL;
}

double atof1(const char* str)
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
			if (find == false)
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
			return d;
		str++;
	}
	if (find)
		return d;
	else
		return NULL;
}

long atol1(const char* str)
{
	if (str == NULL)
		return NULL;
	long ret = 0;
	bool find = false;
	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
		{
			find = true;
			ret = ret * 10 + *str - '0';
		}
		else if (find == true)
			return ret;
		str++;
	}
	if (find == true)
		return ret;
	else
		return NULL;
}
