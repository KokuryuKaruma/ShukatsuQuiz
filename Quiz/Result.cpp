#include "DxLib.h"
#include "Result.h"
#include "CreateScreen.h"

int Result_page1() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "回答お疲れさまでした！！\n\n実際に問題形式で出題されたものに回答すると、客観的に見ることができ自分がマ\nナーをちゃんと守れているかを見つめなおす機会になったのではないでしょうか？\n\nそれでは、実際に点数を確認してみましょう！！", TextColor);

	DrawString(495, 425, "ENTER:次へ", TextColor);

	return 0;

}

int Result_page2() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "あなたの今回の点数は……。", TextColor);

	DrawString(495, 425, "ENTER:次へ", TextColor);

	return 0;

}

int Result_page3(int x) {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawFormatString(0, 0, TextColor, "%d / 100点でした！！", x);

	DrawString(495, 425, "ENTER:次へ", TextColor);

	return 0;

}

int Result_page4(int x) {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	
	if (x == 0) {
		DrawString(0, 0, "0点でしたか……。\n\n\n一度就職活動に向けて、マナーの確認用の本などを読んでみるといいかもしれませ\nん。\n\nですが、就職活動に向けて頑張るのはこれからです！！\n\n\n諦めずに頑張っていきましょう！！", TextColor);
	}
	else if (x == 20) {
		DrawString(0, 0, "20点、1問正解ですね。\n\n\nマナーを身に着ける一番の近道は、もし自分がそうされたらどう思うかを客観的に\n見て、一番心地いい行動をすると上手くいくかもしれません。\n\n\nですが、就職活動に向けて頑張るのはこれからです！！\n\n諦めずに頑張っていきましょう！！", TextColor);
	}
	else if (x == 40) {
		DrawString(0, 0, "40点、2問正解です。\n\n\n恐らく基本的な部分は理解が出来ているのではないでしょうか？\n就職活動を行っていく上で、周りより一段上の所で活動をしていきたいのであれば\nもう少し点数を狙ってみるのもアリかもしれません。\n\n\n就職活動に向けて頑張るのはこれからです！！\n\n諦めずに頑張っていきましょう！！", TextColor);
	}
	else if (x == 60) {
		DrawString(0, 0, "60点、3問正解です！！\n\n\n恐らくこれくらいできればある程度のマナーは理解しているのだと思います。\n慢心せずに、就職活動で実際にマナーを意識する場面でミスをしなければきっとう\nまくいくと思います。\n\n\n就職活動、頑張っていきましょう！！", TextColor);
	}
	else if (x == 80) {
		DrawString(0, 0, "80点、4問正解です！！\n\n\nこれだけできれば、きっと就職活動はうまくいきます！！\n後は自信を持って一つ一つの行動に胸を張ってください。\n\n\nあなたの就職活動はうまくいくでしょう！\n自信を持って自分を高め、自分で納得ができる社会人になりましょう！！", TextColor);
	}
	else if (x == 100) {
		DrawString(0, 0, "100点、全問正解です！！\n\n\n正直なところ、全部正答したあなたは就職活動はもう終わってますか……？\n嫉妬してしまいます……。\n\nもしまだ内定が無い！！となっていたとしても、きっとすぐ上手くいくと思います。\n少なくとも、マナー面では怖いものなしです。\n\n\n自分の将来の明るい道に向かって突き進んでいきましょう！！", TextColor);
	}

	DrawString(415, 425, "ENTER:ゲームを終了する", TextColor);

	return 0;

}