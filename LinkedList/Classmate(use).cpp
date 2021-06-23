//문제. 입력 순서와 상관없이 번호 순서대로 정렬된 리스트를 구현하는 프로그램 작성
//1. 리스트 초기화
//2.노드 추가
//	2.1 제일 앞에 추가
//	2.2 맨뒤에 추가
//	2.3 노드 사이에 추가
//3. 노드 삭제
//	3.1 제일 앞 노드삭제
//	3.2 맨 뒤 노드 삭제
//	3.3 사이 노드 삭제
//4. 검색
//	번호를 입력 받아서 해당 번호이름 출력
//5. 출력
//	리스트 전체 데이터 출력
//ex)
//	메뉴선택
//	1.학생 추가
//	2.학생 삭제
//	3.전체 출력
//	4.종료
#define _CRT_SECURE_NO_WARNINGS
#include "Classmate.h"
using namespace std;

void PrintMenu();

int main()
{
	PrintMenu();
	ClassmateList list;

	while (1)
	{
		printf("Select number : ");
		int command;
		scanf("%d", &command);

		switch (command)
		{
		case 1:
		{
			int num;
			printf("Please Input number : ");
			scanf("%d", &num);

			string name;
			printf("Please input name : ");
			cin >> name;

			list.AddClassmate(Classmate{ num,name });
			break;
		}

		case 2:
		{
			int num;
			printf("Please input number to delete : ");
			scanf("%d", &num);

			list.DeleteClassmate(num);
			break;
		}

		case 3:
		{
			list.PrintClssmateList();
			break;
		}

		case 4:
		{
			int num;
			printf("Please input number to search : ");
			scanf("%d", &num);

			Classmate Searched;
			Searched=list.SearchClassmate(num);
			cout << "Searched student name: "<<Searched.name << endl;
			break;
		}
		case 5:
		{
			cout << "Program Terminate " << endl;
			return 0;
			break;
		}
		case 6:
		{
			list.Initialize();
			cout << "Initialize Complete " << endl;
			break;
		}

		default:
		{
			cout << command << "Please input another command ";
			PrintMenu();
		}
		}
		cout << endl;
	}

	return 0;
}


void PrintMenu()
{
	printf("==========Linked List(Classmate)==========\n");
	printf("Please select menu\n\n");
	printf(" 1. Add classmate(number, name)\n");
	printf(" 2. Delete classmate(number)\n");
	printf(" 3. Print entire classmate\n");
	printf(" 4. Search classmate\n");
	printf(" 5. Quit\n");
	printf(" 6. Initialize\n");
	printf("========================================\n\n");
}
