#include "DxLib.h"
#include "CreateScreen.h"

int LineColor = GetColor(255, 255, 255);

/*テキストボックスを作成*/
int DrawScreen() {

	DrawBox(x1, y1, x2, y2, LineColor, FALSE);

	return 0;

}