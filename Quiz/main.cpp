#include "DxLib.h"
#include "main.h"
#include "CreateScreen.h"
#include "Question.h"
#include "TitleScreen.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);                                           // ウインドウモードに変更
	SetWindowText("就活クイズ");                                        // ウィンドウのタイトルを指定
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);   // 解像度とカラービット数を設定
	if (DxLib_Init() == -1) { return EXIT_FAILURE; }                    // 初期化に失敗したらやめる (EXIT_FAILURE: -1)
	/*
		ここで変数の初期化, 画像のロードなど
	*/
	int ModeNumber = 0;
	SetDrawScreen(DX_SCREEN_BACK);

	/*******************GAME LOOP********************************/
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		/*
			ここで, パラメータをいろいろいじる.
		*/
		ClearDrawScreen();                      // 画面の内容を消去
		/*
			ここで, いろいろ描画する.
		*/

		switch (ModeNumber) {
		case 0:
			Title();
			if (CheckHitKey(KEY_INPUT_RETURN) == 0) {
				DrawString(0, 0, "0", GetColor(255,255,255));
				ModeNumber = 0;
			}
			else {
				DrawString(0, 0, "1", GetColor(255, 255, 255));
				ModeNumber = 1;
			}
			break;

		case 1:
			QuizText();
			break;

		}

		ScreenFlip();
	}
	/*******************GAME LOOP END***************************/

	DxLib_End(); // DXライブラリ使用の終了処理
	return EXIT_SUCCESS; // プログラムの終了 (EXIT_SUCCESS: 0)
}