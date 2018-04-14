#include<iostream>
using namespace std;
void show(int queer[], int lenth)//打印函数
{
	for (int i = 0; i < lenth; i++)
	{
		for (int j = 0; j < lenth; j++)
		{
			if (j == queer[i])
			{
				cout << "@"; //打印皇后
			}
			else
			{
				cout << "*";//打印不是皇后的位置
			}

		}
		cout << endl;
	}
}
bool isclsh(int quen[], int length)//判断
{
	for (int i = 0; i < length; i++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if (quen[i] == quen[j])
			{
				return false;
			}
			if (abs(quen[i] - quen[j]) == abs(i - j))
			{
				return false;
			}

		}
	}


	return true;
}
bool isclsh2(int quen[], int rwn)//判断函数
{
	for (int i = 0; i < rwn; i++) //当前行数，和前面的行数对比
	{
		if(quen[i] == quen[rwn]) //是否在同一列，在同一列，返回false,
		{
			return false;
		
		}
		if (abs(quen[i] - quen[rwn]) == abs(i - rwn))//是否在45度角
		{
			return false;
		}
	}
	return true;
}
void queens_h(int quen[], int rwn,int length,int &num)
{
//回溯法,通过递归
	for (int i = 0; i < length; i++) //每行放一个皇后。变量每一行
	{	//rwn为当前的行数,从第0行开始，把第一行的皇后先放在了第0个
		quen[rwn] = i;
		if (isclsh2(quen, rwn))//判断，当前的quen是否成立，不成立的话，当前行的皇后，向后移动一位，
		{
			if (rwn == length - 1)//成立，而且，已经在最后一行了，排序全部完成，打印输出
			{
				show(quen, length);
				num++;
				cout << "第" << num << "方法" << endl;
				cout << '\n';
			}
			else//没排序完。使用递归切换到下一行
			{
				
				queens_h(quen, rwn+1, length, num);
			}
		}
	}
}
void queens_s(int quen[], int length)  //穷举法
{
	int i = 0;
		for (quen[0] = 0; quen[0] < length; quen[0]++)
		
			for (quen[1] = 0; quen[1] < length; quen[1]++)
			
				for (quen[2] = 0; quen[2] < length; quen[2]++)
				
					for (quen[3] = 0; quen[3] < length; quen[3]++)
					
						for (quen[4] = 0; quen[4] < length; quen[4]++)
						
							for (quen[5] = 0; quen[5] < length; quen[5]++)
							

								for (quen[6] = 0; quen[6] < length; quen[6]++)
								
									for (quen[7] = 0; quen[7] < length; quen[7]++)
									{
										bool res=isclsh(quen, length);
										if (res) 
										{
											show(quen, length);
											i++;
											cout << "第" << i << "方法" << endl;
											cout << '\n';
										}
									}
			
		

}
int main()
{
	int quer[10];
	int length = 10;
	//queens_s(quer, 8);
	int num = 0;
	queens_h(quer, 0, length, num);
	cin.get();
	return 0;
}