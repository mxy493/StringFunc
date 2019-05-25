// StringFunc.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

void strcpy1(char* str1, const char* str2);					//复制字符串
void strncpy1(char* str1, const char* str2, int n);			//复制指定长度字符串
void strcat1(char* str1, char* str2);						//附加字符串
void strncat1(char* str1, const char* str2, int n);			//附加指定长度字符串
int strlen1(const char* str);					        	//取字符串长度
int strcmp1(const char* str1, const char* str2);			//比较字符串
int strcasecmp1(const char* str1, const char* str2);		//忽略大小写比较字符串
int strncmp1(const char* str1, const char* str2, int n);	//比较指定长度字符串
int strchr1(const char* str, const char c);					//在字符串中查找指定字符
int strrchr1(const char* str, const char c);				//在字符串中反向查找
int strstr1(const char* str1, const char* str2);			//查找字符串
double strtod1(char* str, char* ppend);				        //从字符串str中转换double类型数值，并将后续的字符串指针存储到ppend指向的char*类型存储

long strtol1(const char* str, char* ppend, const int base);	//从字符串str中转换long类型整型数值，base显式设置转换的整型进制，设置为0以根据特定格式判断所用进制，0x, 0X 前缀以解释为十六进制格式整型，0前缀以解释为八进制格式整型

int atoi1(const char* str);									//字符串转换到 int 整型
double atof1(const char* str);								//字符串转换到 double 符点数
long atol1(const char* str);								//字符串转换到 long 整型

int main()
{
	char str1[100] = "f-.d-12.34.B1";
	char str2[100] = "12B";

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
	//cout << strrchr1(str1, '2') << endl;
	//cout << strstr1(str1, str2) << endl;
	cout << strtod1(str1, str2) << endl;
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
	while (*str1 != '\0')				    //将指针str1后移使其指向字符串str1尾字符后一位
		++str1;
	while (n-- && *str2 != '\0')		    //逐个复制n个字符
		* str1++ = *str2++;
}

int strlen1(const char* str)
{
	const char* eos = str;                  //定义指针eos指向字符串p
	while (*eos++)                          //遍历字符串p使指针eos逐字符后移，知道遍历玩字符串str
		NULL;
	return((int)(eos - str - 1));           //eos指向字符串str最后一个字符后一位
}

int strcmp1(const char* str1, const char* str2)
{
	int ret = 0;        //作为返回值，-1为<，0为=，1为>
	while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str2) //比较当前所指字符大小
	{
		++str1;         //指针后移
		++str2;
	}
	if (ret < 0)
		ret = -1;       //小于0返回-1
	else if (ret > 0)
		ret = 1;        //大于0返回1
	return(ret);        //等于0(相等）返回0
}

int strcasecmp1(const char* str1, const char* str2)
{
	int ret = 0;        //作为返回值，-1为<，0为=，1为>
	if(str1 == NULL && str2 == NULL)
		return NULL;
	int ch1, ch2;
	while (str1 && str2 && *str1 && *str2)
	{
		if ((ch1 = (int)* str1) >= 'A' && (ch1 <= 'Z'))     //将大写字母统一转为小写
			ch1 += 32;
		if ((ch2 = (int)* str2) >= 'A' && (ch2 <= 'Z'))
			ch2 += 32;
		if (ch1 == ch2)     //如果相同，都往后移一位，继续循环比较
		{
			++str1;
			++str2;
		}
		else break;         //否则跳出循环，比较第一次遇到的不同字符
	}
	if (ch1 - ch2 < 0)      //小于0返回-1
		ret = -1;
	else if (ch1 - ch2 > 0) //大于0返回1
		ret = 1;
	return ret;             //默认相等返回0
}

int strncmp1(const char* str1, const char* str2, int n)
{
	int ret = 0;        //作为返回值，-1为<，0为=，1为>
	if (str1 == NULL && str2 == NULL)
		return NULL;
	while (str1 && str2 && *str1 && *str2 && *str1 == *str2 && n--)
	{
		if (n == 0)     //n=0跳出循环，不再继续判断后面的字符
		{
			if (*str1 - *str2 < 0)
				ret = -1;
			else if (*str1 - *str2 > 0)
				ret = 1;
			else ret = 0;
			break;
		}
		++str1;
		++str2;
	}
	if (n > 0)          //n>0说明还未判断完n个字符就遇到了字符串结束
	{
		if (str1 && *str1 != '\0' && str2 && *str2 != '\0')
		{
			if (*str2 - *str1 > 0)
				ret = -1;
			else if (*str2 - *str1 < 0)
				ret = 1;
			else ret = 0;
		}
		else if (!str1 || *str1 == '\0')    //指针为NULL或者指向'\0'都说明字符串结束
			ret = -1;
		else if (!str2 || *str2 == '\0')
			ret = 1;
		else ret = 0;
	}
	return ret;
}

int strchr1(const char* str, const char c)
{
	if (str == NULL)
		return NULL;
	int loc = 0;
	for (; *str != (char)c; ++str)      //没找到字符ｃ，则指针后移继续查找
	{
		loc++;              //同步记录当前字符的位置
		if (*str == '\0')   //说明还没找到字符ｃ，但字符串以查找完
			return NULL;
	}
	return loc + 1;         //能运行到这一步说明找到了字符ｃ，为第loc+1个字符
}

int strrchr1(const char* str, const char c)
{
	if (str == NULL)
		return NULL;
	int cur = 0;            //计数字符位置，以及得出字符串长度
	int loc;                //用以记录找到的每一个字符ｃ的位置，最终值为最后一个字符ｃ的位置
	for (; *str != '\0'; ++str)
	{
		if (*str == c)      //遇到字符c就记录该字符的位置
			loc = cur;
		++cur;
	}
	if (loc == NULL)        //loc默认没有初始化为NULL，仍为NULL说明字符串中没有找到字符ｃ
		return NULL;
	else
		return cur - loc;   //返回反向查找找到的第一个字符ｃ，即正向查找的最后一个字符ｃ
}

int strstr1(const char* str1, const char* str2)
{
	if(str1 == NULL || str2 == NULL)
		return NULL;
	int loc = 0;
	const char* s = str1;
	const char* t = str2;
	for (; *str1 != '\0'; ++str1)       //在str1中找str2
	{
		for (s = str1, t = str2; *t != '\0' && *s == *t; ++s, ++t)
			NULL;               //判断以字符*s开头的字符串是否与str2相等
		if (*t == '\0')         //说明在str1中找到了字符串str2，位置为loc+1
			return loc + 1;
		++loc;                  //还未找到则字符位置+1继续循环查找
	}
	return NULL;                //字符串str1中找不到字符串str2
}

double strtod1(char* str, char* ppend)
{
	if (str == NULL)
		return NULL;
	double d;               //作为返回值
	int deci = 0;           //记录小数点位数，为０说明还没有遇到小数点，大于０则为deci位小数
	bool neg = false;       //判断正负，默认false为整数
	bool find = false;      //判断是否找到可转为double类型的字符
	while (*str != '\0')
	{
        if(*str == '-')
            neg = true;
		else if (*str == '.' && find==true && deci == 0)       //找到小数点，find为true说明已找到数字字符，并且deci为0则作为小数点转换
		{
			deci++;
			str++;
			continue;
		}
		else if (*str >= '0' && *str <= '9')
		{
			if(find==false)
			{
				find = true;
				d = 0;          //d初始化为0
			}
			if (deci == 0)      //为整数
			{
				d = d * 10 + (*str - '0');
			}
			else                //为小数
			{
				d = d + (*str - '0') / pow(10, deci);
				deci++;
			}
		}
		else if(neg == true && find == false)    //负号后一位不是数字字符，则负号无效
            neg = false;
        else if(find)
        {
            ppend = str;        //将字符串str的剩余部分存到ppend（实际上只是改了指针指向）
            if(neg == true)
                d = -1 * d;
            return d;
        }
		str++;
	}
	if (find)
	{
		ppend = str;            //将字符串str的剩余部分存到ppend（实际上只是改了指针指向）
        if(neg == true)
            d = -1 * d;
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
