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
	void OnTimer(wxTimerEvent& event);
	//Tal cual el programita
	List* Container;
	Consumer* consumer;
	Producer* producer;
	//Utilidad (redundancias)
	wxTimer timer;
	wxPanel* panel;
	Node* nodeCONS;
	Node* nodePROD;
	int globalCounter;
	bool move;

	void OnKill(wxWindowDestroyEvent& event);
	void OnKeyEvent(wxKeyEvent& event);
	void Refresh_nodeACT(Node* nodeACT);
	//zzztaticTexts
	vector<wxStaticBox*> ContNodes;
	wxStaticText* ConsumerStatus;
	wxStaticText* Tick;
	wxStaticText* ProducerStatus;
	wxStaticText* ConsumerTimer;
	wxStaticText* ProducerTimer;
	DECLARE_EVENT_TABLE()
};

