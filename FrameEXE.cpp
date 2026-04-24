#include "FrameEXE.h"
FrameEXE::FrameEXE(int n_slots) : wxFrame(nullptr, wxID_ANY, "Productor-Consumidor",
    wxDefaultPosition, wxSize(700, 700))
{
       Container = new List(n_slots);
}