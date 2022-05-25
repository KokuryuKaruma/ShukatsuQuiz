#include "DxLib.h"
#include "main.h"
#include "CreateScreen.h"
#include "Question.h"
#include "TitleScreen.h"
#include "Mailquestion.h"

/*
���[�h�ԍ��ꗗ
0:�^�C�g�����
1:���[�h�I�����
2:���[���}�i�[��胋�[������
3:���[���}�i�[���1
4:���[���}�i�[���1��

100:�������킹
*/


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	ChangeWindowMode(TRUE);                                           // �E�C���h�E���[�h�ɕύX
	SetWindowText("�A���N�C�Y");                                        // �E�B���h�E�̃^�C�g�����w��
	SetGraphMode(Window::WIDTH, Window::HEIGHT, Window::COLOR_BIT);   // �𑜓x�ƃJ���[�r�b�g����ݒ�
	if (DxLib_Init() == -1) { return EXIT_FAILURE; }                    // �������Ɏ��s�������߂� (EXIT_FAILURE: -1)
	/*
		�����ŕϐ��̏�����, �摜�̃��[�h�Ȃ�
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
			������, �p�����[�^�����낢�낢����.
		*/

		//���t���[�����ɖ�󂪔��ł����Ȃ��悤�ɐ���
		if(CheckHitKeyAll() == 0) {
			push = 0;
		}

		ClearDrawScreen();                      // ��ʂ̓��e������
		/*
			������, ���낢��`�悷��.
		*/

		switch (ModeNumber) {
		//�^�C�g��
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

		//�Q�[���T�v
		case 1:
			QuizText();
			/*���[���}�i�[���I�����̏���*/
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 2;
				push = 1;
			}
			break;

		//�N�C�Y ���[��
		case 2:
			Mail_page1();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 3;
				push = 1;
			}
			break;

		//���� ���
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

		//���� ���
		case 4:
			Mail_page3();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 5;
				push = 1;
			}
			break;

		//���� ���
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

		//���� ���𔻒�
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

		//���� ���𔻒�
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

	DxLib_End(); // DX���C�u�����g�p�̏I������
	return EXIT_SUCCESS; // �v���O�����̏I�� (EXIT_SUCCESS: 0)
}