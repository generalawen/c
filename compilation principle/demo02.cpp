#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
char *change(char data[]);
bool compare(char a, char b);
int priority(char a);
//优先级判断
int priority(char a)
{
    if (a == '(')
    {
        return 0;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return 2;
    }
}
// 比较优先级，返回true
bool compare(char a, char b)
{   
    return priority(a) > priority(b);
}
// 中缀表达式--> 后缀表达式(逆波兰表达式)
// 返回字符串数组
char *change(char data[])
{
    char *hou = (char *)malloc(MAX * sizeof(char));
    stack<char> s;
    int index = 0; // 后缀表达式的长度
    int length = strlen(data);
    // 1. 判断类型
    for (int i = 0; i <length; i++)
    {
        // 如果是运算数，直接输出，
        if (data[i] >= '0' && data[i] <= '9')
        {
            hou[index] = data[i];
            index++;
        }
        else if(data[i]=='('){
             s.push(data[i]);
        }
        else if (data[i] == ')')
        {
            // 不断的弹出栈元素并输出直到遇到左括号结束
            while (!s.empty() && s.top() != '(')
            {
                hou[index] = s.top();
                index++;
                s.pop();
            }
            s.pop(); //退出左括号
        }
        else
        {
            // 表示 运算符优先级小于等于 栈顶元素,就退出栈顶元素，并输出
            // 包含情况data[i]='(',compare 返回false
            while (!s.empty() && !compare(data[i], s.top()))
            {
                hou[index] = s.top();
                index++;
                s.pop();
            }
            s.push(data[i]);
        }
    }
     while (!s.empty())
    {
        hou[index] = s.top();
        index++;
        s.pop();
    }
    return hou;
}
// 后缀表达式的计算
int main()
{
    //  2*(9+6/3-5)+4
    // 结果 2963/+5-*4+
    char s[MAX] = "2*(9+6/3-5)+4";
    char *result;
    result = change(s);
    printf("%s\n", result);
    return 0;
}

