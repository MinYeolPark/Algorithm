#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int number = 9;
int heap[9] = { 9,3,2,6,7,1,4,8,5 };

void swap(int &a, int&b);
void Set_Heap(int i);

void swap(int &a, int&b)
{
	int temp = a;
	a = b;
	b = temp;
}

void Set_Heap(int i)
{
	
	int c_left = 2 * i + 1;
	int c_right = c_left + 1;
	
	if (c_left < number&&heap[c_left] < heap[c_right])
		c_left=c_right;
	if (heap[i] < heap[c_left])
	{
		swap(heap[i], heap[c_left]);
	}

	if (c_left <= number / 2)
		Set_Heap(c_left);
}

void Print_Heap(int root, int column)
{
	for (int j = 0; j < number; j++)
	{

		cout << heap[j] << " ";

	}
	cout << "\n";


}

int main(void)
{
	for (int i = number /2; i >= 0; i--)
	{
		Set_Heap(i);
	}
	cout << "기본배열: ";
	Print_Heap(-1,-1);
	for (int i = number - 1; i >= 0; i--)
	{
		swap(heap[0], heap[i]);
		int root = 0;
		int c_left = 1;
		int c_right = c_left + 1;
		Print_Heap(root, c_left);
		do {
			c_left = 2 * root + 1;
			if (c_left < i - 1 && heap[c_left] < heap[c_right])c_left++;
			if (c_left < i&&heap[root] < heap[c_left])swap(heap[root], heap[c_left]);
			root = c_left;
		} while (c_left < i);
		cout << "\n\n";
	}
}