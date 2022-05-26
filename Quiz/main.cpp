#include "DxLib.h"
#include "main.h"
#include "CreateScreen.h"
#include "Question.h"
#include "TitleScreen.h"
#include "Mailquestion.h"
#include "Result.h"
#include "FinishScreen.h"

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
			Score = 0;
			Title();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
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

		//���� ���
		case 6:
			Mail_page5();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 7;
				push = 1;
			}
			break;

		//��O�� ���
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

		//��O�� ���
		case 8:
			Mail_page7();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 9;
				push = 1;
			}
			break;

		//��l�� ���
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

		//��l�� ���
		case 10:
			Mail_page9();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 11;
				push = 1;
			}
			break;

		//��ܖ� ���
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

		//��ܖ� ���
		case 12:
			Mail_page11();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 13;
				push = 1;
			}
			break;

		/*�������牺���U���g�y�[�W*/
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

		/*�����܂�*/

		//�G���f�B���O
		case 17:
			Ending();
			if (CheckHitKey(KEY_INPUT_RETURN) == 1 && push == 0) {
				ModeNumber = 0;
				push = 1;
			}
			break;

		//���� ���𔻒�
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

		//���� ���𔻒�
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

		//��O�� ���𔻒�
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

		//��l�� ���𔻒�
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

		//��ܖ� ���𔻒�
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
	DxLib_End(); // DX���C�u�����g�p�̏I������
	return EXIT_SUCCESS; // �v���O�����̏I�� (EXIT_SUCCESS: 0)
}