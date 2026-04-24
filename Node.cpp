#include "Node.h"
Node::Node()
{
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