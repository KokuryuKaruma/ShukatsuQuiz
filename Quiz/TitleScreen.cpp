#include "DxLib.h"
#include "TitleScreen.h"
#include "main.h"

int TitleTextColor = GetColor(255, 255, 255);

int Title() {
	
	DrawString(240, 120, "�^�C�g���e�L�X�g", TitleTextColor);
	DrawString(260, 380, "PRESS ENTER", TitleTextColor);
	
	return 0;
}