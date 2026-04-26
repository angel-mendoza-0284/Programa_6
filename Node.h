#pragma once
#include <iostream>
using namespace std;

class Node
{
public:
	Node(int owo);
	Node* next;
	void Modiwi();
	bool Veriwi();

	int Verid();
private:
	bool iwi;//true si esta lleno
	int id;
};

