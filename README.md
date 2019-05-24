# StringFunc
C++标准库字符串函数的模拟实现
```
void strcpy1(char* str1, const char* str2);                    //复制字符串
void strncpy1(char* str1, const char* str2, int n);            //复制指定长度字符串
void strcat1(char* str1, char* str2);                          //附加字符串
void strncat1(char* str1, const char* str2, int n);            //附加指定长度字符串
int strlen1(const char* str);                                  //取字符串长度
int strcmp1(const char* str1, const char* str2);               //比较字符串
int strcasecmp1(const char* str1, const char* str2);           //忽略大小写比较字符串
int strncmp1(const char* str1, const char* str2, int n);       //比较指定长度字符串
int strchr1(const char* p, char c);                            //在字符串中查找指定字符
int strrchr1(const char* p, char c);                           //在字符串中反向查找
int strstr1(const char* p, const char* p1);                    //查找字符串
double strtod1(const char* str, char* ppend);                  //从字符串 str 中转换 double 类型数值，并将后续的字符串指针存储到 ppend 指向的 char* 类型存储
long strtol1(const char* str, char* ppend, const int base);    //从字符串 str 中转换 long 类型整型数值，base 显式设置转换的整型进制，设置为 0 以根据特定格式判断所用进制，0x, 0X 前缀以解释为十六进制格式整型，0前缀以解释为八进制格式整型
int atoi1(const char* str);                                    //字符串转换到 int 整型
double atof1(const char* str);                                 //字符串转换到 double 符点数
long atol1(const char* str);                                   //字符串转换到 long 整型
```
