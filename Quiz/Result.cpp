#include "DxLib.h"
#include "Result.h"
#include "CreateScreen.h"

int Result_page1() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "�񓚂���ꂳ�܂ł����I�I\n\n���ۂɖ��`���ŏo�肳�ꂽ���̂ɉ񓚂���ƁA�q�ϓI�Ɍ��邱�Ƃ��ł��������}\n�i�[�������Ǝ��Ă��邩�����߂Ȃ����@��ɂȂ����̂ł͂Ȃ��ł��傤���H\n\n����ł́A���ۂɓ_�����m�F���Ă݂܂��傤�I�I", TextColor);

	DrawString(495, 425, "ENTER:����", TextColor);

	return 0;

}

int Result_page2() {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawString(0, 0, "���Ȃ��̍���̓_���́c�c�B", TextColor);

	DrawString(495, 425, "ENTER:����", TextColor);

	return 0;

}

int Result_page3(int x) {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	DrawFormatString(0, 0, TextColor, "%d / 100�_�ł����I�I", x);

	DrawString(495, 425, "ENTER:����", TextColor);

	return 0;

}

int Result_page4(int x) {

	int TextColor = GetColor(255, 255, 255);

	DrawScreen();
	
	if (x == 0) {
		DrawString(0, 0, "0�_�ł������c�c�B\n\n\n��x�A�E�����Ɍ����āA�}�i�[�̊m�F�p�̖{�Ȃǂ�ǂ�ł݂�Ƃ�����������܂�\n��B\n\n�ł����A�A�E�����Ɍ����Ċ撣��̂͂��ꂩ��ł��I�I\n\n\n���߂��Ɋ撣���Ă����܂��傤�I�I", TextColor);
	}
	else if (x == 20) {
		DrawString(0, 0, "20�_�A1�␳���ł��ˁB\n\n\n�}�i�[��g�ɒ������Ԃ̋ߓ��́A�����������������ꂽ��ǂ��v�������q�ϓI��\n���āA��ԐS�n�����s��������Ə�肭������������܂���B\n\n\n�ł����A�A�E�����Ɍ����Ċ撣��̂͂��ꂩ��ł��I�I\n\n���߂��Ɋ撣���Ă����܂��傤�I�I", TextColor);
	}
	else if (x == 40) {
		DrawString(0, 0, "40�_�A2�␳���ł��B\n\n\n���炭��{�I�ȕ����͗������o���Ă���̂ł͂Ȃ��ł��傤���H\n�A�E�������s���Ă�����ŁA�������i��̏��Ŋ��������Ă��������̂ł����\n���������_����_���Ă݂�̂��A����������܂���B\n\n\n�A�E�����Ɍ����Ċ撣��̂͂��ꂩ��ł��I�I\n\n���߂��Ɋ撣���Ă����܂��傤�I�I", TextColor);
	}
	else if (x == 60) {
		DrawString(0, 0, "60�_�A3�␳���ł��I�I\n\n\n���炭���ꂭ�炢�ł���΂�����x�̃}�i�[�͗������Ă���̂��Ǝv���܂��B\n���S�����ɁA�A�E�����Ŏ��ۂɃ}�i�[���ӎ������ʂŃ~�X�����Ȃ���΂����Ƃ�\n�܂������Ǝv���܂��B\n\n\n�A�E�����A�撣���Ă����܂��傤�I�I", TextColor);
	}
	else if (x == 80) {
		DrawString(0, 0, "80�_�A4�␳���ł��I�I\n\n\n���ꂾ���ł���΁A�����ƏA�E�����͂��܂������܂��I�I\n��͎��M�������Ĉ��̍s���ɋ��𒣂��Ă��������B\n\n\n���Ȃ��̏A�E�����͂��܂������ł��傤�I\n���M�������Ď��������߁A�����Ŕ[�����ł���Љ�l�ɂȂ�܂��傤�I�I", TextColor);
	}
	else if (x == 100) {
		DrawString(0, 0, "100�_�A�S�␳���ł��I�I\n\n\n�����ȂƂ���A�S�������������Ȃ��͏A�E�����͂����I����Ă܂����c�c�H\n���i���Ă��܂��܂��c�c�B\n\n�����܂����肪�����I�I�ƂȂ��Ă����Ƃ��Ă��A�����Ƃ�����肭�����Ǝv���܂��B\n���Ȃ��Ƃ��A�}�i�[�ʂł͕|�����̂Ȃ��ł��B\n\n\n�����̏����̖��邢���Ɍ������ē˂��i��ł����܂��傤�I�I", TextColor);
	}

	DrawString(415, 425, "ENTER:�Q�[�����I������", TextColor);

	return 0;

}