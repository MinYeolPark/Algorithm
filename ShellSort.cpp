#include <iostream>
#define n 8

void ShellSort(void);
void swap(int& a, int& b);
void print(int* arr);
void print_s(int num1, int num2);

using std::cout;
using std::endl;
int main()
{
	ShellSort();
	return 0;
}

void ShellSort(void)
{
	int arr[n] = { 8,1,4,2,7,6,3,5 };
	cout << "배열 : ";
	print(arr);

	int i, k, p = 1, h = n / 2;
	int cnt_cpr = 0;
	int cnt_swp = 0;

	while (1)
	{
		cout << "\n패스" << p++ << ": h=" << h << endl;
		print(arr);
		for (int j = h; j < n; j++)
		{
			if (arr[j - h] > arr[j])//앞자리가 뒷자리보다 크면 교환
			{
				k = j;
				while (arr[k - h] > arr[k])
				{
					swap(arr[k - h], arr[k]);
					cnt_swp++;
					cnt_cpr++;
					print_s(k - h, k);
					print(arr);
					k -= h;
				}
			}
			else
			{
				print_s(j - h, j);
				print(arr);
				cnt_cpr++;
			}
		}
		if (h == 1)
			break;
		else
			h = h / 2;
	}
	cout << "\n비교를 " << cnt_cpr << "회 했습니다/\n";
	cout << "교환을 " << cnt_swp << "회 했습니다" << endl;
}

void print_s(int num1, int num2)
{
	for(int i=0;i<n;i++)
		if (i == num1)
		{
			cout << "  " << '<';
		}
		else if (i = num2)
		{
			cout << "  " << '>';
		}
		else
		{
			cout << "  " << ' ';
		}
	cout << "\n";
}

void print(int* arr)
{
	for (int i = 0; i < n; i++)
	{
		cout << "  " << arr[i];
	}
	cout << "\n";
}

void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}