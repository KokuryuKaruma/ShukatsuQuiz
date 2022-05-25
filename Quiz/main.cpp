#include "DxLib.h"
#include "main.h"
#include "CreateScreen.h"
#include "Question.h"
#include "TitleScreen.h"
#include "Mailquestion.h"

/*
モード番号一覧
0:タイトル画面
1:モード選択画面
2:メールマナー問題ルール説明
3:メールマナー問題1
4:メールマナー問題1回答

100:答え合わせ
*/


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);                                           // ウインドウモードに変更
	SetWindowText("就活クイズ");                                        // ウィンドウのタイトルを指定
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);   // 解像度とカラービット数を設定
	if (DxLib_Init() == -1) { return EXIT_FAILURE; }                    // 初期化に失敗したらやめる (EXIT_FAILURE: -1)
	/*
		ここで変数の初期化, 画像のロードなど
	*/
	static int ModeNumber = 0;
	static int push = 0;
	static int MailNumber1 = 0;
	static int MailNumber2 = 0;

	static int Score = 0;
	SetDrawScreen(DX_SCREEN_BACK);

	/*******************GAME LOOP********************************/
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		/*
			ここで, パラメータをいろいろいじる.
		*/

		//毎フレーム毎に矢印が飛んでいかないように制御
		if(CheckHitKeyAll() == 0) {
			push = 0;
		}

		ClearDrawScreen();                      // 画面の内容を消去
		/*
			ここで, いろいろ描画する.
		*/

		switch (ModeNumber) {
		//タイトル
		case 0:
			MailNumber1 = 0;
			MailNumber2 = 0;
			Title();
			if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
				DrawString(0, 0, "0", GetColor(255,255,255));
				ModeNumber = 0;
			}
			else {
				DrawString(0, 0, "1", GetColor(255, 255, 255));
				ModeNumber = 1;
				push = 1;
			}
			break;

		//ゲーム概要
		case 1:
			QuizText();
			/*メールマナー問題選択時の処理*/
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 2;
				push = 1;
			}
			break;

		//クイズ ルール
		case 2:
			Mail_page1();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 3;
				push = 1;
			}
			break;

		//第一問 問題
		case 3:
			Mail_page2();

			if (MailNumber1 == 0 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 100;
				push = 1;
			}
			else if (MailNumber1 == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 1 && push == 0) {
				MailNumber1 = 1;
				push = 1;
			}

			if (MailNumber1 == 1 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 100;
				push = 1;
			}
			else if (MailNumber1 == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1 && push == 0) {
				MailNumber1 = 0;
				push = 1;
			}
			break;

		//第一問 解説
		case 4:
			Mail_page3();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 5;
				push = 1;
			}
			break;

		//第二問 問題
		case 5:
			Mail_page4();
			if (MailNumber2 == 0 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 101;
				push = 1;
			}
			else if (MailNumber2 == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 1 && push == 0) {
				MailNumber2 = 1;
				push = 1;
			}

			if (MailNumber2 == 1 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 101;
				push = 1;
			}
			else if (MailNumber2 == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1 && push == 0) {
				MailNumber2 = 0;
				push = 1;
			}
			break;

		case 6:
			Mail_page5();
			break;

		//第一問 正解判定
		case 100:
			if (MailNumber1 == 0) {
				X();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 4;
					push = 1;
				}
			}
			else if (MailNumber1 == 1) {
				O();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 4;
					push = 1;
					Score += 1;
				}
			}
			break;

		//第二問 正解判定
		case 101:
			if (MailNumber2 == 0) {
				X();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 6;
					push = 1;
				}
			}
			else if (MailNumber2 == 1) {
				O();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 6;
					push = 1;
					Score += 1;
				}
			}
			break;

		}

		ScreenFlip();
	}
	/*******************GAME LOOP END***************************/

	DxLib_End(); // DXライブラリ使用の終了処理
	return EXIT_SUCCESS; // プログラムの終了 (EXIT_SUCCESS: 0)
}