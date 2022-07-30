#include <iostream>

using std::cout;
using std::endl;

int g_num = 1; // 全局静态区
static int s_num = 2; // 全局静态区

void test0()
{
    int l_num = 2; // 栈区

    char str1[] = "hello"; // 栈区
    
    // str1 = 0x100; // error：段错误，数组名是常量，不能修改
    
    char * pstr2 = "world"; // 文字常量区（只读）
    // *pstr2 = 'x'; // error：段错误，不能修改
    
    char *pstr3 = new char[10](); // 堆区
    
    printf("str1: %p\n", str1);
    printf("*pstr2: %p\n", pstr2);
    printf("*pstr3: %p\n", pstr3);
    
    printf("&g_num: %p\n", &g_num);
    printf("&s_num: %p\n", &s_num);
    printf("&l_num: %p\n", &l_num);
    printf("test0: %p\n", test0); // 在程序代码区
}

int main()
{
    test0();
    printf("main: %p\n", main); // 在程序代码区
    return 0;
}