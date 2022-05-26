#include "DxLib.h"
#include "FinishScreen.h"

int Ending() {

	int FontHandle;

	FontHandle = CreateFontToHandle(NULL, 64, 4);

	DrawStringToHandle(25, 150, "Thank You \n\n　　for Playing！！", GetColor(255, 255, 255), FontHandle);

	DeleteFontToHandle(FontHandle);

	return 0;
}