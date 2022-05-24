#include "DxLib.h"
#include "Question.h"

int TextColor = GetColor(255, 255, 255);
int n = 0;

int QuizText() {

	DrawFormatString(25, 150, TextColor,"～ゲーム説明～\n就活生の皆さんは活動が捗っていますか？\n私は色々と辛いです…(泣)\n\nさて、前置きはここまでにして、このゲームでは就活生の皆さんにとって覚え\nて置いた方がいいであろうマナー等についてを問題形式にして出題します。\n全て答えられるようになると、内定の確率がアップするかも！？\n\nそれでは、問題を選んでください！！");

	DrawFormatString(45, 350, TextColor, "1.メールマナー問題");
	DrawFormatString(250, 350, TextColor, "2.面接マナー問題");
	DrawFormatString(455, 350, TextColor, "3.電話マナー問題");

	/*選択1の時*/
	if (n == 0) {
		if (CheckHitKey(KEY_INPUT_RIGHT)){
			n = 1;
		}
	}

	/*選択2の時*/
	if (n == 1) {
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			n = 0;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT)) {
			n = 2;
		}
	}

	/*選択3の時*/
	if (n == 2) {
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			n = 1;
		}
	}

	switch (n) {
	case 0:
		DrawFormatString(25, 350, TextColor, "→");
		break;
	case 1:
		DrawFormatString(230, 350, TextColor, "→");
		break;
	case 2:
		DrawFormatString(435, 350, TextColor, "→");
		break;
	}

	return 0;

}