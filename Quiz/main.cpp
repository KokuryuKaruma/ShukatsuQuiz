#include "DxLib.h"
#include "main.h"
#include "CreateScreen.h"
#include "Question.h"
#include "TitleScreen.h"
#include "Mailquestion.h"
#include "Result.h"
#include "FinishScreen.h"

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
	static int MailNumber = 0;
	static int Score = 0;

	int bgm;
	bgm = LoadSoundMem("bgm.mp3");
	PlaySoundMem(bgm, DX_PLAYTYPE_LOOP);
	ChangeVolumeSoundMem(255 * 45 / 100, bgm);

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
			Score = 0;
			Title();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
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

			if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 100;
				push = 1;
			}
			else if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 1 && push == 0) {
				MailNumber = 1;
				push = 1;
			}

			if (MailNumber == 1 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 100;
				push = 1;
			}
			else if (MailNumber == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1 && push == 0) {
				MailNumber = 0;
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
			if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 101;
				push = 1;
			}
			else if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 1 && push == 0) {
				MailNumber = 1;
				push = 1;
			}

			if (MailNumber == 1 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 101;
				push = 1;
			}
			else if (MailNumber == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1 && push == 0) {
				MailNumber = 0;
				push = 1;
			}
			break;

		//第二問 解説
		case 6:
			Mail_page5();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 7;
				push = 1;
			}
			break;

		//第三問 問題
		case 7:
			Mail_page6();
			if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 102;
				push = 1;
			}
			else if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 1 && push == 0) {
				MailNumber = 1;
				push = 1;
			}

			if (MailNumber == 1 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 102;
				push = 1;
			}
			else if (MailNumber == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1 && push == 0) {
				MailNumber = 0;
				push = 1;
			}
			break;

		//第三問 解説
		case 8:
			Mail_page7();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 9;
				push = 1;
			}
			break;

		//第四問 問題
		case 9:
			Mail_page8();
			if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 103;
				push = 1;
			}
			else if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 1 && push == 0) {
				MailNumber = 1;
				push = 1;
			}

			if (MailNumber == 1 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 103;
				push = 1;
			}
			else if (MailNumber == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1 && push == 0) {
				MailNumber = 0;
				push = 1;
			}
			break;

		//第四問 解説
		case 10:
			Mail_page9();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 11;
				push = 1;
			}
			break;

		//第五問 問題
		case 11:
			Mail_page10();
			if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 104;
				push = 1;
			}
			else if (MailNumber == 0 && CheckHitKey(KEY_INPUT_RIGHT) == 1 && push == 0) {
				MailNumber = 1;
				push = 1;
			}

			if (MailNumber == 1 && CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 104;
				push = 1;
			}
			else if (MailNumber == 1 && CheckHitKey(KEY_INPUT_LEFT) == 1 && push == 0) {
				MailNumber = 0;
				push = 1;
			}
			break;

		//第五問 解説
		case 12:
			Mail_page11();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 13;
				push = 1;
			}
			break;

		/*ここから下リザルトページ*/
		case 13:
			Result_page1();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 14;
				push = 1;
			}
			break;

		case 14:
			Result_page2();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 15;
				push = 1;
			}
			break;

		case 15:
			Result_page3(Score);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 16;
				push = 1;
			}
			break;

		case 16:
			Result_page4(Score);
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 17;
				push = 1;
			}
			break;

		/*ここまで*/

		//エンディング
		case 17:
			Ending();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 0;
				push = 1;
			}
			break;

		//第一問 正解判定
		case 100:
			if (MailNumber == 0) {
				X();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 4;
					push = 1;
				}
			}
			else if (MailNumber == 1) {
				O();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 4;
					push = 1;
					Score += 20;
				}
			}
			break;

		//第二問 正解判定
		case 101:
			if (MailNumber == 0) {
				X();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 6;
					push = 1;
				}
			}
			else if (MailNumber == 1) {
				O();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 6;
					push = 1;
					Score += 20;
				}
			}
			break;

		//第三問 正解判定
		case 102:
			if (MailNumber == 0) {
				O();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 8;
					push = 1;
					Score += 20;
				}
			}
			else if (MailNumber == 1) {
				X();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 8;
					push = 1;
				}
			}
			break;

		//第四問 正解判定
		case 103:
			if (MailNumber == 0) {
				X();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 10;
					push = 1;
				}
			}
			else if (MailNumber == 1) {
				O();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 10;
					push = 1;
					Score += 20;
				}
			}
			break;

		//第五問 正解判定
		case 104:
			if (MailNumber == 0) {
				O();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 12;
					push = 1;
					Score += 20;
				}
			}
			else if (MailNumber == 1) {
				X();
				if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
					ModeNumber = 12;
					push = 1;
				}
			}
			break;

		}

		ScreenFlip();
	}
	/*******************GAME LOOP END***************************/

	DeleteSoundMem(bgm);
	DxLib_End(); // DXライブラリ使用の終了処理
	return EXIT_SUCCESS; // プログラムの終了 (EXIT_SUCCESS: 0)
}