#define CRT_SECURE_NO_WARNINGS
#pragma once
#ifndef Classmate_H_
#define Classmate_H_


#include <iostream>
#include <string>

using namespace std;

struct Classmate
{
	int num;
	string name;
	Classmate *pNext;
};

class ClassmateList
{
private:
	int len;

	//����ü ���� ������
	Classmate *pFront;	

public:
	ClassmateList();
	~ClassmateList();
	
	void AddClassmate(Classmate &&cm);
	void DeleteClassmate(int num);
	Classmate SearchClassmate(int num)const;
	void PrintClssmateList()const;
	bool isEmpty()const;
	

	//�ʱ�ȭ �Լ�(�迭�� �� ��)
	void Initialize();
};



#endif // !Classmate_H_

