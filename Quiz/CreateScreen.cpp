#include "DxLib.h"
#include "CreateScreen.h"

int LineColor = GetColor(255, 255, 255);

/*テキストボックスを作成*/
int DrawScreen() {

	DrawBox(x1, y1, x2, y2, LineColor, FALSE);

	return 0;

}

int O() {

	DrawScreen();
	DrawString(30, 290, "正解です！！\n\nENTER:解説へ",LineColor);

	return 0;
}

int X() {

	DrawScreen();
	DrawString(30, 290, "残念、不正解です……。\n\nENTER:解説へ",LineColor);

	return 0;
}