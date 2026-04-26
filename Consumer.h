#pragma once
#include "Node.h"
class Consumer
{
public:
	//consumer
	Consumer(int minACT, int maxACT, int minSLEEP, int maxSLEEP);
	int Consume();
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

