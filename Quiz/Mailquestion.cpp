#include "DxLib.h"
#include "Mailquestion.h"
#include "CreateScreen.h"

static int ArrowNumber = 0;
static int push = 0;

int Mail_page1() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "このモードでは、就活を行っていく上で必要になってくるマナーの内、「メール」\nに関するマナーの問題を出題していきます。\n合計で5問出題されます。\n満点を目指して頑張ってください！\n\n\n正当:+1点 x/5で結果が出されます。",TextColor);

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
	DrawString(0, 0, "企業から頂いたメールには”24時間以内”に返信するのが基本的なマナーです。\n返信できないケースがある可能性もある為、目安として覚えておくといいでしょう。\n", TextColor);

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
	DrawString(0, 0, "メールを送信する際には、文字を装飾しないようにします。\n社会では絵文字や顔文字、太字や色文字を使用しません。\n文字を太字や色で装飾すると、かえってマナー違反だと捉えられることもあります。\n\nどうしても強調したい場合は、カッコを使用するなどで対応しましょう。", TextColor);

	DrawString(475, 425, "ENTER:次の問題へ", TextColor);

	return 0;
}