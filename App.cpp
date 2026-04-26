#include "App.h"

bool App::OnInit()
{
	FrameIntro* frameIntro = new FrameIntro();
	frameIntro->Center();
	frameIntro->Show();
	return true;
}