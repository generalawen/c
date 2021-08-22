#include <bits/stdc++.h>
 using namespace std;
 const int Q  = 100;
 char ch[Q];
 int cnt;
 
 void unsigned_number()
 {
	bool isfirst = true;
	//head表示识别到的无符号实数的第一个数，tail表述最后一个数
	int head,tail;
	for(int i = 0; i <= cnt; i++)
	{
		if(isfirst)
		{
			if(isdigit(ch[i]))	
			{isfirst = false;head = i;} 
			else continue;
		}
		else
		{
			if(isdigit(ch[i])) continue;
			else if(ch[i]=='.') 
			{	
				//输出浮点数或整数或浮点数的科学计数表示
				tail = float_number(i);
				for(int j = head; j < tail; j++) printf("%c",ch[j]);
				printf("\n");
				isfirst = true;
				i = tail;
			}
			else if(ch[i]=='E') 
			{	
				//输出整数或整数的科学计数表示
				tail = makeE(i);
				for(int j = head; j < tail; j++) printf("%c",ch[j]);
				printf("\n");
				isfirst = true;
				i = tail;
			}
			else
			{ 		
				//输出整数	
				tail = i; 
				for(int j = head; j < tail; j++) printf("%c",ch[j]);
				printf("\n");
				isfirst = true;
				
			}
		}
	}
}

int float_number(int i)
{
	//设置flag来判断是不是小数点后第一个字符
	bool flag = true;
	int t;
	for(int j = i+1; j <= cnt; j++)
	{
		if(flag)
		{
			flag = false;
			//小数点'.'后第一个字符是数字则继续否则返回'.'的下标
			if(isdigit(ch[j])) continue;
			else{t = i; return t;} 
		}
		else
		{
			if(isdigit(ch[j])) continue;
			//遇到'E',通过调用函数_E()来得到要返回的下标
			else if(ch[j] == 'E') 
			{
				t = makeE(j);
				return t;
			}
			else
			{
				t = j;
				return t;
			}
		}
		
	}
	return 0;
}

int makeE(int i)
{
	//设置flag来判断是不是'E'后的第一个字符，设置flag2来判断是不是'E'后的第二个字符
	//通过这两个标志来判断字符E之后字符的合法性
	bool flag = true;
	bool flag2 = true;
	int t;
	for(int j = i + 1; j < cnt; j++)
	{
		if(flag)
		{
			flag = false;
			//字符'E'之后是'+'或'-'则继续 否则返回字符'E'的下标
			if(ch[j] == '+'||ch[j] == '-') continue;
			else
			{
				t = i;
				return t;
			}
		}
		else
		{
			if(flag2)
			{
				flag2 = false;
				//如果'E'后面的第二个字符是数字则继续，否则返回'E'的下标
				if(isdigit(ch[j])) continue;
				else 
				{
					t = i;
					return t;
				}
			}
			else
			{
				if(isdigit(ch[j])) continue;
				else
				{
					t = j;
					return j;
				}
				
			}
			
		}	
	}
}
 int main()
 {
	cnt = 0;
	cout<<"请输入字符串并以；结束"<<endl; 
	for(;;)
	{
		cin>>ch[cnt];
		if(ch[cnt]==';') break;
		cnt++;
	}
	unsigned_number();

	return 0;
	
 }
