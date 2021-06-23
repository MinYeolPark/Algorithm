#include "Classmate.h"

ClassmateList::ClassmateList()
{
	len = 0;
	pFront = NULL;
}

ClassmateList::~ClassmateList()
{
	if (isEmpty())
	{
		Classmate *pDel = pFront;
		Classmate *pDelNext = pFront->pNext;

		while (pDelNext != NULL)
		{
			pDel = pDelNext;
			pDel = pDelNext->pNext;
		}
		delete pDel;
	}
}

void ClassmateList::AddClassmate(Classmate && cm)
{
	//구조체 배열 저장할 메모리 동적할당
	Classmate *pNew = new Classmate(cm);
	if (pNew == NULL)
	{
		cout << "동적할당에 실패하였습니다." << endl;
		exit(EXIT_FAILURE);
	}

	if (len == 0)//처음 리스트 추가
	{
		//포인터 맨 앞으로 이동
		pFront = pNew;
	}
	else if (cm.num < pFront->num)//첫 위치에 추가
	{
		pNew->pNext = pFront;
		pFront = pNew;
	}
	else//중간에 삽입
	{
		Classmate* pPrev = pFront;
		for(;pPrev->pNext!=NULL;pPrev=pPrev->pNext)
		{
			Classmate *pNext = pPrev->pNext;
			if (pNext->num > pNew->num)//입력한 숫자가 pNext보다 작으면 삽입
			{
				pNew->pNext = pPrev->pNext;
				pPrev->pNext = pNew;
				break;
			}
		}
		if (pPrev->pNext == NULL)
		{
			pPrev->pNext = pNew;
		}
	}
	len++;
	
}

void ClassmateList::DeleteClassmate(int num)
{
	if (isEmpty())
		return;

	Classmate *pDel = NULL;
	if (pFront->num == num)//맨앞의 노드를 삭제하는 경우
	{
		pDel = pFront;//포인터 맨앞으로
		pFront = pDel->pNext;//맨 앞의 포인터를 뒤로 이동
		delete pDel;
	}

	else
	{
		Classmate *pPrev = pFront;
		pDel = pPrev->pNext;
		for (; pPrev->pNext != NULL; pPrev = pDel, pDel = pDel->pNext)
		{
			if (num == pDel->num)//포인터가 가진 값이 입력한 값과 같으면
			{
				pPrev->pNext = pDel->pNext;//임시 포인터 값을 삭제
				delete pDel;
				break;
			}
		}
	}
	len--;
}

Classmate ClassmateList::SearchClassmate(int num) const
{
	Classmate searched{ -1,"X",NULL };//없는 학생

	if (isEmpty())
	{
		return searched;
	}
	for (Classmate *pSearch = pFront; pSearch != NULL; pSearch = pSearch->pNext)
	{
		if (pSearch->num == num)//입력한 번호가 맞으면
		{
			searched = *pSearch;//빈 학생정보에 학생정보를 복사
			break;
		}
	}
	
	return searched;
}

void ClassmateList::PrintClssmateList() const
{
	if (isEmpty())
		return;

	for (Classmate *pcm = pFront; pcm != NULL; pcm = pcm->pNext)
	{
		printf("[%d]", &*pcm);
		cout << "Number: " << pcm->num << " , " << " Name: " << pcm->name << endl;
	}
}

bool ClassmateList::isEmpty() const//Classmate Operator
{
	return len == 0;
}

void ClassmateList::Initialize()
{
	if (isEmpty())
		return;
	Classmate *pDel = NULL;
	while (pFront != NULL)
	{
		pDel = pFront;
		pFront = pDel->pNext;
		delete pDel;		
	}
	delete pFront;
}
