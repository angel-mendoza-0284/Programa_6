#pragma once
#include "FrameEXE.h"
#include <wx/spinctrl.h>
class FrameIntro : public wxFrame
{
public:
	FrameIntro();
private:
	wxSpinCtrl* n_slots;
	void Create_FrameEXE(wxCommandEvent& event);
};

