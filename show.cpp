
#include"show.h"

#include<stdio.h>
#include<windows.h>



void Show_cursor(bool is_show) {
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;		//光标结构类型
	cci.dwSize = 1;					//光标大小
	cci.bVisible = is_show;			//是否显示光标
	SetConsoleCursorInfo(hOutStd, &cci);
}

//指定坐标打印颜色参数的字符（串）
/*	1 直接打印
	2 打印空白
	3 不显示
*/

void WriteChar(short x, short y, char* pStr, int item, WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	switch (item) { //注意设置颜色
	case 1: {
		if (pStr!=nullptr)
		{
			printf("%s", pStr); //打印东西
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
			break;		//不显示
	default:
		break;
	}
	SetConsoleTextAttribute(hOutStd, 0xA);
}

//打印特定位置的数据
void WriteChar(short x, short y, int Hit_Score,  WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	printf("%d", Hit_Score);
	SetConsoleTextAttribute(hOutStd, 0);
}
//打印特定位置的数据
void WriteChar(short x, short y, char life_left, WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	printf("%d", life_left);
	SetConsoleTextAttribute(hOutStd, 0);
}
//打印特定位置的数据
void WriteChar(short x, short y, unsigned int Fires, WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	printf("%u", Fires);
	SetConsoleTextAttribute(hOutStd, 0);
}
//打印特定位置的数据
void WriteChar(short x, short y,double ratio, WORD color) {
	COORD position = { x,y };
	HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutStd, position);
	SetConsoleTextAttribute(hOutStd, color);
	printf("%.2lf%% ", ratio*100);
	SetConsoleTextAttribute(hOutStd, 0);
	//printf("\% ");
}

//打印空白
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

//条件打印
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
//		//删除最后图像
//		COORD position = { (p_xy + length - 1)->X,(p_xy + length - 1)->Y };
//		HANDLE hOutStd = GetStdHandle(STD_OUTPUT_HANDLE);
//		SetConsoleCursorPosition(hOutStd, position);
//		SetConsoleTextAttribute(hOutStd, color);
//		printf("  ");
//	}
//}


