#include <iostream>

using namespace std;

const int ARR_SIZE =10;

int main(void)
{
	int arr[ARR_SIZE] = { 5,7,0,2,4,9,3,1,3 };
	int cnt[ARR_SIZE] = { 0, };

	//ARR_SIZE -1 : pop '\0'
	for (int i = 0; i < ARR_SIZE-1; i++)
	{
		cnt[arr[i]]++;
	}

	for (int i = 0; i < ARR_SIZE; i++)
	{
		for (int j = 0; j < cnt[i]; j++)
		{
			cout << i << " ";
		}
	}
	cout << endl;

	return 0;
}
