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
	//����ü �迭 ������ �޸� �����Ҵ�
	Classmate *pNew = new Classmate(cm);
	if (pNew == NULL)
	{
		cout << "�����Ҵ翡 �����Ͽ����ϴ�." << endl;
		exit(EXIT_FAILURE);
	}

	if (len == 0)//ó�� ����Ʈ �߰�
	{
		//������ �� ������ �̵�
		pFront = pNew;
	}
	else if (cm.num < pFront->num)//ù ��ġ�� �߰�
	{
		pNew->pNext = pFront;
		pFront = pNew;
	}
	else//�߰��� ����
	{
		Classmate* pPrev = pFront;
		for(;pPrev->pNext!=NULL;pPrev=pPrev->pNext)
		{
			Classmate *pNext = pPrev->pNext;
			if (pNext->num > pNew->num)//�Է��� ���ڰ� pNext���� ������ ����
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
	if (pFront->num == num)//�Ǿ��� ��带 �����ϴ� ���
	{
		pDel = pFront;//������ �Ǿ�����
		pFront = pDel->pNext;//�� ���� �����͸� �ڷ� �̵�
		delete pDel;
	}

	else
	{
		Classmate *pPrev = pFront;
		pDel = pPrev->pNext;
		for (; pPrev->pNext != NULL; pPrev = pDel, pDel = pDel->pNext)
		{
			if (num == pDel->num)//�����Ͱ� ���� ���� �Է��� ���� ������
			{
				pPrev->pNext = pDel->pNext;//�ӽ� ������ ���� ����
				delete pDel;
				break;
			}
		}
	}
	len--;
}

Classmate ClassmateList::SearchClassmate(int num) const
{
	Classmate searched{ -1,"X",NULL };//���� �л�

	if (isEmpty())
	{
		return searched;
	}
	for (Classmate *pSearch = pFront; pSearch != NULL; pSearch = pSearch->pNext)
	{
		if (pSearch->num == num)//�Է��� ��ȣ�� ������
		{
			searched = *pSearch;//�� �л������� �л������� ����
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
