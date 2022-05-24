#include "DxLib.h"
#include "main.h"
#include "CreateScreen.h"
#include "Question.h"
#include "TitleScreen.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);                                           // �E�C���h�E���[�h�ɕύX
	SetWindowText("�A���N�C�Y");                                        // �E�B���h�E�̃^�C�g�����w��
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);   // �𑜓x�ƃJ���[�r�b�g����ݒ�
	if (DxLib_Init() == -1) { return EXIT_FAILURE; }                    // �������Ɏ��s�������߂� (EXIT_FAILURE: -1)
	/*
		�����ŕϐ��̏�����, �摜�̃��[�h�Ȃ�
	*/
	int ModeNumber = 0;
	SetDrawScreen(DX_SCREEN_BACK);

	/*******************GAME LOOP********************************/
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		/*
			������, �p�����[�^�����낢�낢����.
		*/
		ClearDrawScreen();                      // ��ʂ̓��e������
		/*
			������, ���낢��`�悷��.
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

	DxLib_End(); // DX���C�u�����g�p�̏I������
	return EXIT_SUCCESS; // �v���O�����̏I�� (EXIT_SUCCESS: 0)
}