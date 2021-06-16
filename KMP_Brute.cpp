#include "Stopwatch.h"
#include <string>
#include <iostream>
using namespace std;

int KMP(string s1, string s2);
int BruteForce(string main, string sub);
void Print_str(string s1,string s2,bool isSame,int i,int j);
int main()
{
	string str1, str2;
	cout << "Input Data :";
	getline(cin, str1, '\n');
	cout << "Input Searching data(return index) : ";
	getline(cin, str2, '\n');

	StopWatch Timer;
	Timer.Start();
	int kmp_answer = KMP(str1, str2);
	Timer.Stop();
	cout << "Kmp.answer : " << Timer.GetElapsedTime() << "ms" << endl;

	StopWatch Timer2;
	Timer2.Start();
	int Brt_answer = BruteForce(str1, str2);
	cout << "Match Index : " << kmp_answer << endl;
	Timer2.Stop();
	cout << "Brute.answer : " << Timer2.GetElapsedTime() << "ms" << endl;
	return 0;
}

int KMP(string s1, string s2)
{
	int cpr_cnt = 0;
	
	bool isSame = false;
	int temp = 0;

	for (int i = 0; i <= s1.length()-s2.length()+1; i++)
	{
		int cnt = 0;
		for (int j = 0; j < s2.length(); j++)
		{
			if (s1[i + j] == s2[j])
			{
				temp = i;
				cnt++;
				isSame = true;
				cpr_cnt++;
				Print_str(s1, s2, isSame, i, j);

				//If match before end
				if (isSame == true && cnt == s2.length())
				{
					return temp;
				}
			}
			else
			{
				isSame = false;
				cpr_cnt++;
				Print_str(s1, s2, isSame, i, j);

				//Move to dismatched position
				i += j;
				break;
			}
		}
	}
	return temp;
}

void Print_str(string s1, string s2, bool isSame, int i, int j)
{
	cout << s1 << endl;
	for (int k = 0; k < i; k++)
	{
		cout << " ";
	}
	if (isSame == true)
	{
		for (int k = 0; k < j; k++)
		{
			cout << " ";
		}
		cout << "+" << endl;
	}
	else if (isSame == false)
	{
		for (int k = 0; k < j; k++)
		{
			cout << " ";
		}
		cout << "|" << endl;
	}
	else
	{
		cout << " " << endl;
	}

	for (int k = 0; k < i; k++)
	{
		cout << " ";
	}
	cout << s2 << endl;
}