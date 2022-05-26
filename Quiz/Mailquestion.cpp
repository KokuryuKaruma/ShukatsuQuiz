#include "DxLib.h"
#include "Mailquestion.h"
#include "CreateScreen.h"

static int ArrowNumber = 0;
static int push = 0;

int Mail_page1() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "このモードでは、就活を行っていく上で必要になってくるマナーの内、「メール」\nに関するマナーの問題を出題していきます。\n合計で5問出題されます。\n満点を目指して頑張ってください！\n\n\n正解:+20点 不正解:0点\nx/100で結果が出されます。",TextColor);

	DrawString(50, 285, "第一問へ",TextColor);
	DrawString(30, 285, "→", TextColor);

	return 0;

}

int Mail_page2() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*第一問*\n\n後日面接をしたいと思っている企業からメールが来ました。\nあなたの学校は今日休校日です。\n折角の休校で休みたいと思い、次の日にメールを返信しました。\n実際にメールを返信したのは36時間後の事でした。", TextColor);

	DrawString(125, 350, "1.合っている",TextColor);
	DrawString(405, 350, "2.間違っている", TextColor);

	//毎フレーム毎に矢印が飛んでいかないように制御
	while (CheckHitKeyAll() == 0) {
		push = 0;
	}

	if (ArrowNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT)) {
		ArrowNumber = 1;
		push = 1;
	}

	if (ArrowNumber == 1 && CheckHitKey(KEY_INPUT_LEFT)) {
		ArrowNumber = 0;
		push = 1;
	}

	switch (ArrowNumber) {
	case 0:
		DrawString(105, 350, "→", TextColor);
		break;
	case 1:
		DrawString(385, 350, "→", TextColor);
		break;
	}

	return 0;

}

int Mail_page3() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*解説*\n\n企業から頂いたメールには”24時間以内”に返信するのが基本的なマナーです。\n返信できないケースがある可能性もある為、目安として覚えておくといいでしょう。\n", TextColor);

	DrawString(475, 425, "ENTER:次の問題へ", TextColor);

	return 0;

}

int Mail_page4() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*第二問*\n\nあなたは今、面接の日程を企業の方とメールでやり取りをし調整をしています。\n企業側からの指定で第三希望まで予定日を記入しました。\nですが、どうしてもあなたは第一希望日に面接を受けたいと思っています。\n予定日を伝えるときにそういうのはよくないかもと思い、第一希望日に色を付けて\nおきました。", TextColor);

	DrawString(125, 350, "1.合っている", TextColor);
	DrawString(405, 350, "2.間違っている", TextColor);

	//毎フレーム毎に矢印が飛んでいかないように制御
	while (CheckHitKeyAll() == 0) {
		push = 0;
	}

	if (ArrowNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT)) {
		ArrowNumber = 1;
		push = 1;
	}

	if (ArrowNumber == 1 && CheckHitKey(KEY_INPUT_LEFT)) {
		ArrowNumber = 0;
		push = 1;
	}

	switch (ArrowNumber) {
	case 0:
		DrawString(105, 350, "→", TextColor);
		break;
	case 1:
		DrawString(385, 350, "→", TextColor);
		break;
	}

	return 0;

}

int Mail_page5() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*解説*\n\nメールを送信する際には、文字を装飾しないようにします。\n社会では絵文字や顔文字、太字や色文字を使用しません。\n文字を太字や色で装飾すると、かえってマナー違反だと捉えられることもあります。\n\nどうしても強調したい場合は、カッコを使用するなどで対応しましょう。", TextColor);

	DrawString(475, 425, "ENTER:次の問題へ", TextColor);

	return 0;

}

int Mail_page6() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*第三問*\n\nあなたは今から企業宛てに、応募方法について問い合わせをしようと思っています。\n説明会の際に、企業側の人は応募に使用するメールアドレスは指定はないと言って\nいました。\nしかし、あなたは自身のプライベート用メールアドレスは就職活動に不適切だと思\nい、新しく就職活動用にメールアドレスを取得しました。", TextColor);

	DrawString(125, 350, "1.合っている", TextColor);
	DrawString(405, 350, "2.間違っている", TextColor);

	//毎フレーム毎に矢印が飛んでいかないように制御
	while (CheckHitKeyAll() == 0) {
		push = 0;
	}

	if (ArrowNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT)) {
		ArrowNumber = 1;
		push = 1;
	}

	if (ArrowNumber == 1 && CheckHitKey(KEY_INPUT_LEFT)) {
		ArrowNumber = 0;
		push = 1;
	}

	switch (ArrowNumber) {
	case 0:
		DrawString(105, 350, "→", TextColor);
		break;
	case 1:
		DrawString(385, 350, "→", TextColor);
		break;
	}

	return 0;

}

int Mail_page7() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*解説*\n\nメールアドレスはそれほど重視されているわけではありませんが、何でもいいわけ\nではありません。\n\n例えば、過去に作成したメールアドレスで、変な文章や記号文字を使用しているも\nのなどは就職活動に向いているメールアドレスではありません。\n\n元々使っていたメールアドレスが不適切だと感じた場合は、新しく就職活動用のメ\nールアドレスを作成することをお勧めします。", TextColor);

	DrawString(475, 425, "ENTER:次の問題へ", TextColor);

	return 0;

}

int Mail_page8() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*第四問*\n\nあなたは今から企業宛てにエントリーする為にメールを送ります。\n以下の文章は合っていますか？\n\n「お世話になっております。\n　○○大学の小林です。\n\n　この度、御社のリクルートサイトより是非志望したいと思い連絡させて頂きまし\n　た。\n　つきましては、指定された資料の方を送付させて頂きます。\n\n　お手数をお掛けしますが、よろしくお願いします。」", TextColor);

	DrawString(125, 350, "1.合っている", TextColor);
	DrawString(405, 350, "2.間違っている", TextColor);

	//毎フレーム毎に矢印が飛んでいかないように制御
	while (CheckHitKeyAll() == 0) {
		push = 0;
	}

	if (ArrowNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT)) {
		ArrowNumber = 1;
		push = 1;
	}

	if (ArrowNumber == 1 && CheckHitKey(KEY_INPUT_LEFT)) {
		ArrowNumber = 0;
		push = 1;
	}

	switch (ArrowNumber) {
	case 0:
		DrawString(105, 350, "→", TextColor);
		break;
	case 1:
		DrawString(385, 350, "→", TextColor);
		break;
	}

	return 0;

}

int Mail_page9() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*解説*\n\nメールなどを送る際、敬語は正しく使う必要があります。\n\n自分では正しく使っているつもりでも、誤った敬語を使用しているケースは意外と\n多くあります。\n例えば、問題文の場合の文章では、企業宛てにメールを作成する際には「御社」で\nはなく「貴社」と書きます。\n\n敬語表現を重ねて過剰に丁寧にしすぎてしまう二重敬語などにも気を付けましょう。", TextColor);

	DrawString(475, 425, "ENTER:次の問題へ", TextColor);

	return 0;

}

int Mail_page10() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*第五問*\n\nあなたは今、企業から送られてきたメールに返信しようとしています。\n頂いたメールをよく見ると、自分以外のメールアドレスも宛先にありました。\n\nあなたはそのメールアドレスが企業の方の物だということを知っていた為、CCでメ\nールを返信しました。", TextColor);

	DrawString(125, 350, "1.合っている", TextColor);
	DrawString(405, 350, "2.間違っている", TextColor);

	//毎フレーム毎に矢印が飛んでいかないように制御
	while (CheckHitKeyAll() == 0) {
		push = 0;
	}

	if (ArrowNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT)) {
		ArrowNumber = 1;
		push = 1;
	}

	if (ArrowNumber == 1 && CheckHitKey(KEY_INPUT_LEFT)) {
		ArrowNumber = 0;
		push = 1;
	}

	switch (ArrowNumber) {
	case 0:
		DrawString(105, 350, "→", TextColor);
		break;
	case 1:
		DrawString(385, 350, "→", TextColor);
		break;
	}

	return 0;

}

int Mail_page11() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*解説*\n\nメールの宛先について、TOはメインの送信対象者を指します。\n逆に、CCはメイン対象者以外に、メールの内容を共有したい人がいる場合に使用し\nます。\nCCを設定すると、メインの対象者に送るのと同時に、CCを設定した相手にもメール\nの内容を共有できる為、迅速な情報共有が可能になります。\n\n逆に、CCに企業側が設定している人が居るのに個人宛で返信をすると、かえって先\n方に迷惑をかけてしまうことがある為、気を付けましょう。", TextColor);

	DrawString(455, 425, "ENTER:結果の確認へ", TextColor);

	return 0;

}