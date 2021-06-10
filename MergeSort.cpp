#include  <iostream>

#define max 6

void mergesort(int a[], int low, int high);
void merge(int a[], int low, int mid, int high);
void Print_a(int a[]);
using namespace std;

int main()
{
	int a[max] = { 20,10,70,80,40,90 };
	int i = 0;

	cout << "befor merge :";
	Print_a(a);
	puts("\n");
	mergesort(a, 0, max - 1);
	cout << "after merge :";
	Print_a(a);
	puts("\n");
}

void mergesort(int a[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;

		//left part sort
		mergesort(a, low, mid);
		//right part sort
		mergesort(a, mid+1, high);

		//merge(left,right)
		merge(a, low, mid, high);
	}
	else
		return;
}
void merge(int a[], int low, int mid, int high)
{
	int b[1000];
	int i = low; int j = mid + 1; int k = 0;

	while (i <= mid && j <= high)
	{
		if (a[i] <= a[j])
		{
			b[k++] = a[i++];
		}
		else
		{
			b[k++] = a[j++];
		}
	}
	while (i <= mid)
	{
		b[k++] = a[i++];
	}
	while (j <= high)
	{
		b[k++] = a[j++];
	}
	//Adjust k value to end index;
	k--;
	while (k >= 0)
	{
		//Copy b(temp array) array to a(main) array
		a[low + k] = b[k];
		k--;
	}
}
void Print_a(int a[])
{
	for (int i = 0; i < max; i++)
	{
		cout << a[i] << " ";
	}
}