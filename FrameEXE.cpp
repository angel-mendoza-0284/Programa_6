#include "FrameEXE.h"


static const wxColour CLR_BG(255, 255, 255);
static const wxColour CLR_LBLUE(99, 179, 237);
static const wxColour CLR_TXT(30, 30, 30);

static const wxColour CLR_RED(220, 20, 60);
static const wxColour CLR_GREEN(34, 139, 34);
static const wxColour CLR_BLUE(30, 144, 255);

static const wxColour CLR_SLEEP(176, 196, 222);
static const wxColour CLR_WAIT(250, 128, 114);
static const wxColour CLR_ACT(173, 255, 47);

static const wxColour CLR_EMPTY(192, 192, 192);
static const wxColour CLR_FULL(237, 28, 36);

static const int sleeping = 1;
static const int waiting = 2;
static const int acting = 3;

void FrameEXE::Refresh_nodeACT(Node* nodeACT)
{
    //RefreshNodeACT
    wxColour CLR_nodeACT;
    if (nodeACT->Veriwi())
        CLR_nodeACT = CLR_FULL;
    else
        CLR_nodeACT = CLR_EMPTY;
    ContNodes[nodeACT->Verid()]->SetBackgroundColour(CLR_nodeACT);
    ContNodes[nodeACT->Verid()]->Refresh();
}
wxString Seetatus(int status)
{
    switch (status)
    {
    case sleeping:
        return "sleeping";
    case waiting:
        return "waiting";
    case acting:
        return "acting";
    default:
        return "hola?";
    }
}
FrameEXE::FrameEXE(int n_slots) : wxFrame(nullptr, wxID_ANY, "Productor-Consumidor",
    wxDefaultPosition, wxSize(700, 700))
{
       //-------------------Panel-------------------
       panel = new wxPanel(this);
       panel->SetBackgroundColour(CLR_BG);
        
       Container = new List(n_slots);
       int cons_minACT = 3;
       int cons_maxACT = 6;
       int cons_minSLEEP = 3;
       int cons_maxSLEEP = 6;
       int prod_minACT = 3;
       int prod_maxACT = 6;
       int prod_minSLEEP = 3;
       int prod_maxSLEEP = 6;
       consumer = new Consumer(cons_minACT, cons_maxACT, cons_minSLEEP, cons_maxSLEEP);
       producer = new Producer(prod_minACT, prod_maxACT, prod_minSLEEP, prod_maxSLEEP);
       consumer->modStatus(waiting);
       producer->modStatus(waiting);
       globalCounter = 0;

       //--------------- CIRCULO DEL CONTAINER ---------------
       wxSize size = GetClientSize(); 
       int centerX = size.GetWidth() / 2;
       int centerY = size.GetHeight() / 2;
       int radius = 200;

       for (int i = 0; i < n_slots; i++)
       {
           double angulo = (2 * M_PI / n_slots) * i;

           int x = centerX + radius * cos(angulo);
           int y = centerY + radius * sin(angulo);

           wxStaticBox* box = new wxStaticBox(panel, wxID_ANY, "", wxPoint(x - 25, y), wxSize(50, 50));
           box->SetBackgroundColour(CLR_EMPTY);
           ContNodes.push_back(box);
       }
       //------ Static Texts ------
       int quarterX = centerX / 2;
       int octX = quarterX / 2;
       int quarterY = centerY / 2;

       ConsumerStatus = new wxStaticText(panel, wxID_ANY, Seetatus(consumer->verStatus()), wxPoint(octX, quarterY * 3 - 20));
           wxStaticText* ConsumerText = new wxStaticText(panel, wxID_ANY, "Consumidor", wxPoint(octX-22, quarterY*3));
           ConsumerTimer = new wxStaticText(panel, wxID_ANY, "", wxPoint(octX-22, quarterY*3-40));
           ConsumerText->SetForegroundColour(CLR_RED);

           Tick = new wxStaticText(panel, wxID_ANY, wxString::Format("[ TICK ] : [ %i ]", globalCounter), wxPoint(10, 10));
           Tick->SetForegroundColour(CLR_GREEN);
           ProducerStatus = new wxStaticText(panel, wxID_ANY, Seetatus(producer->verStatus()), wxPoint(quarterX * 3 + octX, quarterY * 3 - 20));
           wxStaticText*  ProducerText = new wxStaticText(panel, wxID_ANY, "Productor", wxPoint(quarterX*3+octX-13, quarterY*3));
           ProducerTimer = new wxStaticText(panel, wxID_ANY, "", wxPoint(quarterX*3+octX-13, quarterY*3-40));
           ProducerText->SetForegroundColour(CLR_BLUE);


           //Nodo inicial
           nodeCONS = Container->h;
           nodePROD = Container->h;
           move = true;
           timer.SetOwner(this, wxID_ANY);
           timer.Start(1000);
}
void FrameEXE::OnKeyEvent(wxKeyEvent& event)
{
    int key = event.GetKeyCode();
    if (key == WXK_ESCAPE)
    {
        timer.Stop();
        Close(true);
    }
}
void FrameEXE::OnTimer(wxTimerEvent& event)
{
    switch (producer->verStatus())
    {
    case sleeping:
        if (producer->verTimer() <= 0)
            producer->modStatus(waiting);
        else
            producer->modTimer();
        break;
    case waiting:
        if ((consumer->verStatus() != acting) && (!Container->Full()))
        {
            producer->Produce();
        }
        break;
    case acting:
        if (producer->verTimer() <= 0 || Container->Full())
            producer->Sleep();
        else
        {
            producer->modTimer();
            Container->ModNode(nodePROD);
            Refresh_nodeACT(nodePROD);
            nodePROD = nodePROD->next;
        }
        break;
    default:
        break;
    }

    switch (consumer->verStatus())
    {
    case sleeping:
        if (consumer->verTimer() <= 0)
            consumer->modStatus(waiting);
        else
            consumer->modTimer();
        break;
    case waiting:
        if ((producer->verStatus() != acting) && (!Container->Empty()))
        {
            consumer->Consume();
        }
        break;
    case acting:
        if (consumer->verTimer() <= 0 || Container->Empty())
            consumer->Sleep();
        else
        {
            consumer->modTimer();
            Container->ModNode(nodeCONS);
            Refresh_nodeACT(nodeCONS);
            nodeCONS = nodeCONS->next;
        }
        break;
    default:
        break;
    }
    //RefreshStatus
    ProducerStatus->SetLabel(Seetatus(producer->verStatus()));
    ConsumerStatus->SetLabel(Seetatus(consumer->verStatus()));
    ProducerTimer->SetLabel(wxString::Format("%i", producer->verTimer()));
    ConsumerTimer->SetLabel(wxString::Format("%i", consumer->verTimer()));

    //RefreshTick
    Tick->SetLabel(wxString::Format("[ TICK ] : [ %i ]", globalCounter));

    
    globalCounter++;
}
wxBEGIN_EVENT_TABLE(FrameEXE, wxFrame)
EVT_CHAR_HOOK(FrameEXE::OnKeyEvent)
EVT_TIMER(wxID_ANY, FrameEXE::OnTimer)
wxEND_EVENT_TABLE()