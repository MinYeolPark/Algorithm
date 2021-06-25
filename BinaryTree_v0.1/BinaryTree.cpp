#include <iostream>
#include "Binary_v2.h"

using namespace std;

int main()
{
	cout << "Binary tree" << endl;
	cout << "(1) 삽입 (2) 삭제 (3) 검색 (4) 출력 (0) 종료 :" << endl;
	int n;
	BSTree myTree{};
	while (1)
	{
		cin >> n;
		switch (n)
		{
		case 1:
		{
			int num;
			cout << "Please Input number to add : ";
			cin >> num;
			myTree.Insert(num);
			break;
		}
		case 2:
		{
			int del;
			cout << "Please Input number to delete : ";
			cin >> del;
			myTree.Remove(del);
			break;
		}
		case 3:
		{
			int target;
			cout << "Please Input number to find : ";
			cin >> target;
			int ans=myTree.Contains(target);
			cout << boolalpha << ans << endl;
			break;
		}
		case 4:
		{
			myTree.Print();
			break;
		}
		case 0:
		{
			cout << "Program Terminate" << endl;
			return 0;
		}
		}
	}
	return 0;
}
