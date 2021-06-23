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

	//구조체 접근 포인터
	Classmate *pFront;	

public:
	ClassmateList();
	~ClassmateList();
	
	void AddClassmate(Classmate &&cm);
	void DeleteClassmate(int num);
	Classmate SearchClassmate(int num)const;
	void PrintClssmateList()const;
	bool isEmpty()const;
	

	//초기화 함수(배열의 맨 앞)
	void Initialize();
};



#endif // !Classmate_H_

