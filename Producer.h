#pragma once
#include "Node.h"
class Producer
{
public:
	//producer
	Producer(int minACT, int maxACT, int minSLEEP, int maxSLEEP);
	int Produce();
	int Sleep();
	//status
	void modStatus(int owo);
	int verStatus();
	//timer
	void modTimer();
	int verTimer();
private:
	int status;
	int timer;

	int minACT;
	int maxACT;
	int minSLEEP;
	int maxSLEEP;
};

