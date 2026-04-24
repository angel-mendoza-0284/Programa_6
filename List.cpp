#include "List.h"

//--Helper--
void List::Add()
{
	if (!h)//el primero
	{
		h = new Node();
		t = h;
		return;
	}
	//los demas owo
	{
		t->next = new Node();
		t = t->next;
	}
	
}
List::List(int size)
{
	for (int i = 1; i < size; i++)
	{
		Add();
	}
}