#include "DxLib.h"
#include "Question.h"

static int TextColor = GetColor(255, 255, 255);
static int n = 0;
static int push = 0;

int QuizText() {

	DrawFormatString(25, 150, TextColor,"〜ゲーム説明〜\n就活生の皆さんは活動が捗っていますか？\n私は色々と辛いです…(泣)\n\nさて、前置きはここまでにして、このゲームでは就活生の皆さんにとって覚え\nて置いた方がいいであろうマナー等についてを問題形式にして出題します。\n全て答えられるようになると、内定の確率がアップするかも！？\n\nそれでは、頑張ってください！！");

	DrawFormatString(45, 350, TextColor, "メールマナー問題へ");
	DrawFormatString(25, 350, TextColor, "→");

	DrawFormatString(400, 400, TextColor, "←キー：左へ →キー：右へ");


	return 0;

}