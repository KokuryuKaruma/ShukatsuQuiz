#include "DxLib.h"
#include "Mailquestion.h"
#include "CreateScreen.h"

static int ArrowNumber = 0;
static int push = 0;

int Mail_page1() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "���̃��[�h�ł́A�A�����s���Ă�����ŕK�v�ɂȂ��Ă���}�i�[�̓��A�u���[���v\n�Ɋւ���}�i�[�̖����o�肵�Ă����܂��B\n���v��5��o�肳��܂��B\n���_��ڎw���Ċ撣���Ă��������I\n\n\n����:+1�_ x/5�Ō��ʂ��o����܂��B",TextColor);

	DrawString(50, 285, "�����",TextColor);
	DrawString(30, 285, "��", TextColor);

	return 0;
}

int Mail_page2() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*����*\n\n����ʐڂ��������Ǝv���Ă����Ƃ��烁�[�������܂����B\n���Ȃ��̊w�Z�͍����x�Z���ł��B\n�܊p�̋x�Z�ŋx�݂����Ǝv���A���̓��Ƀ��[����ԐM���܂����B\n���ۂɃ��[����ԐM�����̂�36���Ԍ�̎��ł����B", TextColor);

	DrawString(125, 350, "1.�����Ă���",TextColor);
	DrawString(405, 350, "2.�Ԉ���Ă���", TextColor);

	//���t���[�����ɖ�󂪔��ł����Ȃ��悤�ɐ���
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
		DrawString(105, 350, "��", TextColor);
		break;
	case 1:
		DrawString(385, 350, "��", TextColor);
		break;
	}

	return 0;
}

int Mail_page3() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "��Ƃ��璸�������[���ɂ́h24���Ԉȓ��h�ɕԐM����̂���{�I�ȃ}�i�[�ł��B\n�ԐM�ł��Ȃ��P�[�X������\��������ׁA�ڈ��Ƃ��Ċo���Ă����Ƃ����ł��傤�B\n", TextColor);

	DrawString(475, 425, "ENTER:���̖���", TextColor);

	return 0;
}

int Mail_page4() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*����*\n\n���Ȃ��͍��A�ʐڂ̓�������Ƃ̕��ƃ��[���ł����������������Ă��܂��B\n��Ƒ�����̎w��ő�O��]�܂ŗ\������L�����܂����B\n�ł����A�ǂ����Ă����Ȃ��͑���]���ɖʐڂ��󂯂����Ǝv���Ă��܂��B\n�\�����`����Ƃ��ɂ��������̂͂悭�Ȃ������Ǝv���A����]���ɐF��t����\n�����܂����B", TextColor);

	DrawString(125, 350, "1.�����Ă���", TextColor);
	DrawString(405, 350, "2.�Ԉ���Ă���", TextColor);

	//���t���[�����ɖ�󂪔��ł����Ȃ��悤�ɐ���
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
		DrawString(105, 350, "��", TextColor);
		break;
	case 1:
		DrawString(385, 350, "��", TextColor);
		break;
	}

	return 0;
}

int Mail_page5() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "���[���𑗐M����ۂɂ́A�����𑕏����Ȃ��悤�ɂ��܂��B\n�Љ�ł͊G������當���A������F�������g�p���܂���B\n�����𑾎���F�ő�������ƁA�������ă}�i�[�ᔽ���Ƒ������邱�Ƃ�����܂��B\n\n�ǂ����Ă������������ꍇ�́A�J�b�R���g�p����ȂǂőΉ����܂��傤�B", TextColor);

	DrawString(475, 425, "ENTER:���̖���", TextColor);

	return 0;
}