#include <bits/stdc++.h>
 using namespace std;
 const int Q  = 100;
 char ch[Q];
 int cnt;
 
 void unsigned_number()
 {
	bool isfirst = true;
	//head��ʾʶ�𵽵��޷���ʵ���ĵ�һ������tail�������һ����
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
				//����������������򸡵����Ŀ�ѧ������ʾ
				tail = float_number(i);
				for(int j = head; j < tail; j++) printf("%c",ch[j]);
				printf("\n");
				isfirst = true;
				i = tail;
			}
			else if(ch[i]=='E') 
			{	
				//��������������Ŀ�ѧ������ʾ
				tail = makeE(i);
				for(int j = head; j < tail; j++) printf("%c",ch[j]);
				printf("\n");
				isfirst = true;
				i = tail;
			}
			else
			{ 		
				//�������	
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
	//����flag���ж��ǲ���С������һ���ַ�
	bool flag = true;
	int t;
	for(int j = i+1; j <= cnt; j++)
	{
		if(flag)
		{
			flag = false;
			//С����'.'���һ���ַ���������������򷵻�'.'���±�
			if(isdigit(ch[j])) continue;
			else{t = i; return t;} 
		}
		else
		{
			if(isdigit(ch[j])) continue;
			//����'E',ͨ�����ú���_E()���õ�Ҫ���ص��±�
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
	//����flag���ж��ǲ���'E'��ĵ�һ���ַ�������flag2���ж��ǲ���'E'��ĵڶ����ַ�
	//ͨ����������־���ж��ַ�E֮���ַ��ĺϷ���
	bool flag = true;
	bool flag2 = true;
	int t;
	for(int j = i + 1; j < cnt; j++)
	{
		if(flag)
		{
			flag = false;
			//�ַ�'E'֮����'+'��'-'����� ���򷵻��ַ�'E'���±�
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
				//���'E'����ĵڶ����ַ�����������������򷵻�'E'���±�
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
	cout<<"�������ַ������ԣ�����"<<endl; 
	for(;;)
	{
		cin>>ch[cnt];
		if(ch[cnt]==';') break;
		cnt++;
	}
	unsigned_number();

	return 0;
	
 }
