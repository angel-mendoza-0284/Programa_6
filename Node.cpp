#include "Node.h"
Node::Node(int owo)
{
	id = owo;
	next = nullptr;
	iwi = false;
}
void Node::Modiwi()
{
	iwi = !iwi;
}
bool Node::Veriwi()
{
	return iwi;
}
int Node::Verid()
{
	return id;
}