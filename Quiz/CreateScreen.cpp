#include "DxLib.h"
#include "CreateScreen.h"

int LineColor = GetColor(255, 255, 255);

/*�e�L�X�g�{�b�N�X���쐬*/
int DrawScreen() {

	DrawBox(x1, y1, x2, y2, LineColor, FALSE);

	return 0;

}

int O() {

	DrawScreen();
	DrawString(30, 290, "�����ł��I�I\n\nENTER:�����",LineColor);

	return 0;
}

int X() {

	DrawScreen();
	DrawString(30, 290, "�c�O�A�s�����ł��c�c�B\n\nENTER:�����",LineColor);

	return 0;
}