#pragma once
#include "Node.h"
class List
{
public:
	List(int size);
	Node* h;
	Node* t;
	void ModNode(Node* uwu);
	bool Full();
	bool Empty();
private:
	void Add(int owo);
	int n_iwi;
	int size;
};

