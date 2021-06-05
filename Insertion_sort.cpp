#include <iostream>
#include "Stopwatch.h"

using namespace std;
void insertion(int a[], int n);
void swap(int &a, int &b);

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
int main()
{
	StopWatch timer;
	timer.Start();
	int ary[9] = {6,4,8,3,1,9,7,2,5 };
	insertion(ary, 9);
	timer.Stop();
	cout << "실행시간: " << timer.GetElapsedTime() << "ms\n";
}

void insertion(int a[], int n)
{
	int i, j, m;
	int cpr_cnt=0;
	int swp_cnt=0;

	for (i = 0; i < n - 1; i++) 
	{
		
		int min = i;						//정렬 되지 않은 min값 찾기
		for (j = i + 1; j < n; j++)
		{
			if (a[j] < a[min])
			{
				min = j;
			}
		}
			
		for (m = 0; m < n; m++)
		{
			if (m == i)
			{
				cout << "   * ";
			}
			else if (m == min)
			{
				cout << "  + ";
			}
			else
			{
				cout << "    ";
			}
			++cpr_cnt;
		}
		cout << "\n";

		for (m = 0; m < n; m++)
			cout << "   " << a[m];
		cout << "\n";

		swap( a[i], a[min]);
		swp_cnt++;
	}
	cout << "\n";
	for (m = 0; m < n; m++)
		cout << "   " << a[m];
	cout << "\n\n";
	cout << "비교 횟수 : " << cpr_cnt << endl;
	cout << "바꾼횟수 : " << swp_cnt << endl;
}
