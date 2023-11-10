
#include"show.h"

#include<stdio.h>
#include<windows.h>



void Show_cursor(bool is_show) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;		//���ṹ����
	cci.dwSize = 1;					//����С
	cci.bVisible = is_show;			//�Ƿ���ʾ���
	SetConsoleCursorInfo(hOutStd, &cci);
}

//ָ�������ӡ��ɫ�������ַ�������
/*	1 ֱ�Ӵ�ӡ
	2 ��ӡ�հ�
	3 ����ʾ
*/

void WriteChar(short x, short y, char* pStr, int item, WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	switch (item) { //ע��������ɫ
	case 1: {
		if (pStr!=nullptr)
		{
			printf("%s", pStr); //��ӡ����
		}
		else
		{
			printf("error!");
		}
		

		//ShowCursor(0);
	}
			break;
	case 2:{
		printf("  ");
	}
		break;
	case 3: {
		COORD position = { x,y };
		HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hOutStd, position);
		SetConsoleTextAttribute(hOutStd, color);
	}
			break;		//����ʾ
	default:
		break;
	}
	SetConsoleTextAttribute(hOutStd, 0xA);
}

//��ӡ�ض�λ�õ�����
void WriteChar(short x, short y, int Hit_Score,  WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	printf("%d", Hit_Score);
	SetConsoleTextAttribute(hOutStd, 0);
}
//��ӡ�ض�λ�õ�����
void WriteChar(short x, short y, char life_left, WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	printf("%d", life_left);
	SetConsoleTextAttribute(hOutStd, 0);
}
//��ӡ�ض�λ�õ�����
void WriteChar(short x, short y, unsigned int Fires, WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	printf("%u", Fires);
	SetConsoleTextAttribute(hOutStd, 0);
}
//��ӡ�ض�λ�õ�����
void WriteChar(short x, short y,double ratio, WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	printf("%.2lf%% ", ratio*100);
	SetConsoleTextAttribute(hOutStd, 0);
	//printf("\% ");
}

//��ӡ�հ�
//void WriteChar(PCOORD p_xy, int length, WORD color) {
//	for (int i = 0; i < length; i++)
//	{
//		COORD position = { (p_xy + i)->X,(p_xy + i)->Y };
//		HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
//		SetConsoleCursorPosition(hOutStd, position);
//		SetConsoleTextAttribute(hOutStd, color);
//		printf("  ");
//	}
//}

//������ӡ
//void WriteChar(PCOORD p_xy, char* pStr, int length, WORD color) {
//	if (1)
//	{
//		for (int i = 0; i < length; i++)
//		{
//			COORD position = { (p_xy + i)->X,(p_xy + i)->Y };
//			HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
//			SetConsoleCursorPosition(hOutStd, position);
//			SetConsoleTextAttribute(hOutStd, color);
//			printf("%s", pStr);
//		}
//	}
//
//	else
//	{
//		for (int i = 0; i < length - 1; i++)
//		{
//			COORD position = { (p_xy + i)->X,(p_xy + i)->Y  };
//			HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
//			SetConsoleCursorPosition(hOutStd, position);
//			SetConsoleTextAttribute(hOutStd, color);
//			printf("%s", pStr);
//		}
//		//ɾ�����ͼ��
//		COORD position = { (p_xy + length - 1)->X,(p_xy + length - 1)->Y };
//		HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
//		SetConsoleCursorPosition(hOutStd, position);
//		SetConsoleTextAttribute(hOutStd, color);
//		printf("  ");
//	}
//}


