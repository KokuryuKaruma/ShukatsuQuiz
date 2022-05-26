#include "DxLib.h"
#include "Mailquestion.h"
#include "CreateScreen.h"

static int ArrowNumber = 0;
static int push = 0;

int Mail_page1() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "���̃��[�h�ł́A�A�����s���Ă�����ŕK�v�ɂȂ��Ă���}�i�[�̓��A�u���[���v\n�Ɋւ���}�i�[�̖����o�肵�Ă����܂��B\n���v��5��o�肳��܂��B\n���_��ڎw���Ċ撣���Ă��������I\n\n\n����:+20�_ �s����:0�_\nx/100�Ō��ʂ��o����܂��B",TextColor);

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
	DrawString(0, 0, "*���*\n\n��Ƃ��璸�������[���ɂ́h24���Ԉȓ��h�ɕԐM����̂���{�I�ȃ}�i�[�ł��B\n�ԐM�ł��Ȃ��P�[�X������\��������ׁA�ڈ��Ƃ��Ċo���Ă����Ƃ����ł��傤�B\n", TextColor);

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
	DrawString(0, 0, "*���*\n\n���[���𑗐M����ۂɂ́A�����𑕏����Ȃ��悤�ɂ��܂��B\n�Љ�ł͊G������當���A������F�������g�p���܂���B\n�����𑾎���F�ő�������ƁA�������ă}�i�[�ᔽ���Ƒ������邱�Ƃ�����܂��B\n\n�ǂ����Ă������������ꍇ�́A�J�b�R���g�p����ȂǂőΉ����܂��傤�B", TextColor);

	DrawString(475, 425, "ENTER:���̖���", TextColor);

	return 0;

}

int Mail_page6() {
	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*��O��*\n\n���Ȃ��͍������ƈ��ĂɁA������@�ɂ��Ė₢���킹�����悤�Ǝv���Ă��܂��B\n������̍ۂɁA��Ƒ��̐l�͉���Ɏg�p���郁�[���A�h���X�͎w��͂Ȃ��ƌ�����\n���܂����B\n�������A���Ȃ��͎��g�̃v���C�x�[�g�p���[���A�h���X�͏A�E�����ɕs�K�؂��Ǝv\n���A�V�����A�E�����p�Ƀ��[���A�h���X���擾���܂����B", TextColor);

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

int Mail_page7() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*���*\n\n���[���A�h���X�͂���قǏd������Ă���킯�ł͂���܂��񂪁A���ł������킯\n�ł͂���܂���B\n\n�Ⴆ�΁A�ߋ��ɍ쐬�������[���A�h���X�ŁA�ςȕ��͂�L���������g�p���Ă����\n�̂Ȃǂ͏A�E�����Ɍ����Ă��郁�[���A�h���X�ł͂���܂���B\n\n���X�g���Ă������[���A�h���X���s�K�؂��Ɗ������ꍇ�́A�V�����A�E�����p�̃�\n�[���A�h���X���쐬���邱�Ƃ������߂��܂��B", TextColor);

	DrawString(475, 425, "ENTER:���̖���", TextColor);

	return 0;

}

int Mail_page8() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*��l��*\n\n���Ȃ��͍������ƈ��ĂɃG���g���[����ׂɃ��[���𑗂�܂��B\n�ȉ��̕��͍͂����Ă��܂����H\n\n�u�����b�ɂȂ��Ă���܂��B\n�@������w�̏��тł��B\n\n�@���̓x�A��Ђ̃��N���[�g�T�C�g��营��u�]�������Ǝv���A�������Ē����܂�\n�@���B\n�@���܂��ẮA�w�肳�ꂽ�����̕��𑗕t�����Ē����܂��B\n\n�@���萔�����|�����܂����A��낵�����肢���܂��B�v", TextColor);

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

int Mail_page9() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*���*\n\n���[���Ȃǂ𑗂�ہA�h��͐������g���K�v������܂��B\n\n�����ł͐������g���Ă������ł��A������h����g�p���Ă���P�[�X�͈ӊO��\n��������܂��B\n�Ⴆ�΁A��蕶�̏ꍇ�̕��͂ł́A��ƈ��ĂɃ��[�����쐬����ۂɂ́u��Ёv��\n�͂Ȃ��u�M�Ёv�Ə����܂��B\n\n�h��\�����d�˂ĉߏ�ɒ��J�ɂ������Ă��܂���d�h��Ȃǂɂ��C��t���܂��傤�B", TextColor);

	DrawString(475, 425, "ENTER:���̖���", TextColor);

	return 0;

}

int Mail_page10() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*��ܖ�*\n\n���Ȃ��͍��A��Ƃ��瑗���Ă������[���ɕԐM���悤�Ƃ��Ă��܂��B\n���������[�����悭����ƁA�����ȊO�̃��[���A�h���X������ɂ���܂����B\n\n���Ȃ��͂��̃��[���A�h���X����Ƃ̕��̕����Ƃ������Ƃ�m���Ă����ׁACC�Ń�\n�[����ԐM���܂����B", TextColor);

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

int Mail_page11() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "*���*\n\n���[���̈���ɂ��āATO�̓��C���̑��M�Ώێ҂��w���܂��B\n�t�ɁACC�̓��C���Ώێ҈ȊO�ɁA���[���̓��e�����L�������l������ꍇ�Ɏg�p��\n�܂��B\nCC��ݒ肷��ƁA���C���̑Ώێ҂ɑ���̂Ɠ����ɁACC��ݒ肵������ɂ����[��\n�̓��e�����L�ł���ׁA�v���ȏ�񋤗L���\�ɂȂ�܂��B\n\n�t�ɁACC�Ɋ�Ƒ����ݒ肵�Ă���l������̂Ɍl���ŕԐM������ƁA�������Đ�\n���ɖ��f�������Ă��܂����Ƃ�����ׁA�C��t���܂��傤�B", TextColor);

	DrawString(455, 425, "ENTER:���ʂ̊m�F��", TextColor);

	return 0;

}