#include "List.h"

//--Helper--
void List::Add(int owo)
{
	if (!h)//el primero
	{
		h = new Node(owo);
		t = h;
		return;
	}
	//los demas owo
	{
		t->next = new Node(owo);
		t = t->next;
	}
	
}
List::List(int size)
{
	n_iwi = 0;
	this->size = size;
	for (int i = 0; i < size; i++)
	{
		Add(i);
	}
	t->next = h;
}
void List::ModNode(Node* uwu)
{
	if (!uwu)
		return;
	if (uwu->Veriwi())
		n_iwi++;
	else
		n_iwi--;
	uwu->Modiwi();

}
bool List::Full()
{
	if (n_iwi == size)
		return true;
	else
		return false;
}
bool List::Empty()
{
	if (n_iwi == 0)
		return true;
	else
		return false;
}