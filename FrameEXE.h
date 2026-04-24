#pragma once
#include <wx/wx.h>
#include "Producer.h"
#include "Consumer.h"
#include "List.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
class FrameEXE : public wxFrame
{
public:
	FrameEXE(int n_slots);
private:

	//Tal cual el programita
	List* Container;
	Consumer* consumer;
	Producer* producer;
	//Utilidad (redundancias)
	
	//zzztaticTexts
	vector<wxStaticText*> ContNodes;
	wxStaticText* ConsumerStatus;
	wxStaticText* ProducerStatus;
};

