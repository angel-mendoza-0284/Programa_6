#include "Producer.h"

static const int sleeping = 1;
static const int waiting = 2;
static const int acting = 3;

Producer::Producer(int minACT, int maxACT, int minSLEEP, int maxSLEEP)
{
	status = 0;
	timer = 0;
	this->minACT = minACT;
	this->maxACT = maxACT;
	this->minSLEEP = minSLEEP;
	this->maxSLEEP = maxSLEEP;
}

int Producer::Produce()
{
	timer = rand() % (maxACT - minACT + 1) + minACT;
	modStatus(acting);

	return timer;
}
int Producer::Sleep()
{
	timer = rand() % (maxSLEEP - minSLEEP + 1) + minSLEEP;
	modStatus(sleeping);

	return timer;
}
void Producer::modStatus(int owo)
{
	switch (owo)
	{
	case sleeping:
	case waiting:
	case acting:
		status = owo;
		break;
	default:
		break;
	}
}
int Producer::verStatus()
{
	return status;
}

void Producer::modTimer()
{
	timer--;
}
int Producer::verTimer()
{
	return timer;
}