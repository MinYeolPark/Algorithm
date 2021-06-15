#include <iostream>
#include <string>
using namespace std;

int BruteForce(string main, string sub);
void Print_Str(string main, string sub, int isSame, int a,int b);
int main()
{
	string str1, str2;
	cout << "Input Data :";
	getline(cin, str1, '\n');
	cout << "Input Searching data(return index) : ";
	getline(cin, str2, '\n');

	int answer = BruteForce(str1, str2);

	cout << "Match Index : " << answer;
}

int BruteForce(string main, string sub)
{
	bool isSame = -1;
	int temp = 0;
	int cpr_cnt = 0;

	for (int i = 0; i < main.length()-sub.length()+1; i++)
	{
		cout << "Path : " << i << endl;
		for (int j = 0; j < sub.length(); j++)
		{
			if (main[i + j] == sub[j] )
			{
				isSame = true;
				temp = i;
				cpr_cnt++;
				Print_Str(main, sub, isSame, i,j);
				
				if (j == sub.length() - 2)
					continue;
			}
			else
			{
				isSame = false;
				cpr_cnt++;
				Print_Str(main, sub, isSame, i,j);
				break;
			}
		}
	}
	return temp;
}

void Print_Str(string main, string sub, int isSame, int a,int b)
{
	cout << main << endl;

	for (int i = 0; i < a ; i++)
	{
		cout << " ";
	}

	if (isSame == true)
	{
		for (int k = 0; k < b; k++)
		{
			cout << " ";
		}
		cout << "+" << endl;		
	}
	else if (isSame == false)
	{
		for (int k = 0; k < b; k++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	else
	{
		cout << " " << endl;
	}

	//공백 출력
	for (int i = 0; i < a ; i++)
	{
		cout << " ";
	}
	if (isSame == true)
	{

	}

	cout << sub << endl;
}