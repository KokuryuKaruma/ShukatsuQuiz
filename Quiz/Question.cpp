#include "DxLib.h"
#include "Question.h"

static int TextColor = GetColor(255, 255, 255);
static int n = 0;
static int push = 0;

int QuizText() {

	DrawFormatString(25, 150, TextColor,"�`�Q�[�������`\n�A�����̊F����͊����������Ă��܂����H\n���͐F�X�Ɛh���ł��c(��)\n\n���āA�O�u���͂����܂łɂ��āA���̃Q�[���ł͏A�����̊F����ɂƂ��Ċo��\n�Ēu�������������ł��낤�}�i�[���ɂ��Ă���`���ɂ��ďo�肵�܂��B\n�S�ē�������悤�ɂȂ�ƁA����̊m�����A�b�v���邩���I�H\n\n����ł́A�撣���Ă��������I�I");

	DrawFormatString(45, 350, TextColor, "���}�i�[����");

	DrawFormatString(100, 450, TextColor, "�y������@�z���L�[�F���� ���L�[�F�E�� ENTER�L�[�F���� or �i��");


	return 0;

}