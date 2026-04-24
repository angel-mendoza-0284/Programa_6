#include "App.h"

bool App::OnInit()
{
	FrameIntro* frameIntro = new FrameIntro();
	frameIntro->SetClientSize(300, 180);
	frameIntro->Center();
	frameIntro->Show();
	return true;
}