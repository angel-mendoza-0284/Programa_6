#include "FrameIntro.h"

static const wxColour CLR_BG(255, 255, 255);
static const wxColour CLR_LBLUE(99, 179, 237);
static const wxColour CLR_TXT(30, 30, 30);

FrameIntro::FrameIntro() : wxFrame(nullptr, wxID_ANY, "Productor-Consumidor",
    wxDefaultPosition, wxSize(700, 700))
{
    SetBackgroundColour(CLR_BG);

    wxPanel* panel = new wxPanel(this);
    panel->SetBackgroundColour(CLR_BG);

    // ---------------------------------------TITULO---------------------------------------
    wxStaticText* title = new wxStaticText(panel, wxID_ANY, "PROGRAMA 6",
        wxPoint(0, 28), wxSize(320, 24),
        wxALIGN_CENTER_HORIZONTAL);
    wxFont fontTitle(13, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    title->SetFont(fontTitle);
    title->SetForegroundColour(CLR_LBLUE);

    // ---------------------------------------OwO---------------------------------------
    wxStaticText* subtitle = new wxStaticText(panel, wxID_ANY, " OwO ",
        wxPoint(0, 54), wxSize(320, 16),
        wxALIGN_CENTER_HORIZONTAL);
    wxFont fontSub(8, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
    subtitle->SetFont(fontSub);
    subtitle->SetForegroundColour(CLR_TXT);

    // ---------------------------------------BOTON---------------------------------------
    wxButton* button = new wxButton(panel, wxID_ANY, "[ INICIAR ]",
        wxPoint(60, 110), wxSize(200, 32));
    wxFont fontBtn(9, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD);
    button->SetFont(fontBtn);
    button->SetBackgroundColour(CLR_LBLUE);
    button->SetForegroundColour(CLR_BG);

    button->Bind(wxEVT_BUTTON, &FrameIntro::Create_FrameEXE, this);

    Center();
}

void FrameIntro::Create_FrameEXE(wxCommandEvent& event)
{
    int n_slots = 18;
    FrameEXE* newFrame = new FrameEXE(n_slots);
    newFrame->Center();
    newFrame->Show();
    this->Close();
}