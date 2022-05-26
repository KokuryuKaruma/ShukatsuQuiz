#include "DxLib.h"
#include "TitleScreen.h"
#include "main.h"

int TitleTextColor = GetColor(255, 255, 255);

int Title() {

	int FontHandle;

	FontHandle = CreateFontToHandle(NULL, 64, 4);

	DrawStringToHandle(85, 95, "èAäàÉ}ÉiÅ[Quiz", GetColor(255, 255, 255), FontHandle);

	DrawString(260, 380, "PRESS ENTER", TitleTextColor);

	DeleteFontToHandle(FontHandle);
	
	return 0;
}