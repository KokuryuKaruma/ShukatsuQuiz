#include "DxLib.h"
#include "Question.h"

int TextColor = GetColor(255, 255, 255);
int n = 0;

int QuizText() {

	DrawFormatString(25, 150, TextColor,"�`�Q�[�������`\n�A�����̊F����͊����������Ă��܂����H\n���͐F�X�Ɛh���ł��c(��)\n\n���āA�O�u���͂����܂łɂ��āA���̃Q�[���ł͏A�����̊F����ɂƂ��Ċo��\n�Ēu�������������ł��낤�}�i�[���ɂ��Ă���`���ɂ��ďo�肵�܂��B\n�S�ē�������悤�ɂȂ�ƁA����̊m�����A�b�v���邩���I�H\n\n����ł́A����I��ł��������I�I");

	DrawFormatString(45, 350, TextColor, "1.���[���}�i�[���");
	DrawFormatString(250, 350, TextColor, "2.�ʐڃ}�i�[���");
	DrawFormatString(455, 350, TextColor, "3.�d�b�}�i�[���");

	/*�I��1�̎�*/
	if (n == 0) {
		if (CheckHitKey(KEY_INPUT_RIGHT)){
			n = 1;
		}
	}

	/*�I��2�̎�*/
	if (n == 1) {
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			n = 0;
		}
		else if (CheckHitKey(KEY_INPUT_RIGHT)) {
			n = 2;
		}
	}

	/*�I��3�̎�*/
	if (n == 2) {
		if (CheckHitKey(KEY_INPUT_LEFT)) {
			n = 1;
		}
	}

	switch (n) {
	case 0:
		DrawFormatString(25, 350, TextColor, "��");
		break;
	case 1:
		DrawFormatString(230, 350, TextColor, "��");
		break;
	case 2:
		DrawFormatString(435, 350, TextColor, "��");
		break;
	}

	return 0;

}