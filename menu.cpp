#include "menu.h"
#include "show.h"


#define N_menu_y 2	
#define N_menu_x 156	
#define show_menu_speed 0

C_menu::C_menu() :menu_x(0), menu_y(0) {

}

void C_menu::show_menu_wall() {
	for (menu_x = 140; menu_x < 185; menu_x += 2)
	{
		WriteChar(menu_x, 0, (char*)"��", 1, 3);
		WriteChar(menu_x, 44, (char*)"��", 1, 3);
		Sleep(show_menu_speed);
	}
	for (menu_y = 0; menu_y < 45; menu_y++)
	{
		WriteChar(140, menu_y, (char*)"��", 1, 3);
		WriteChar(184, menu_y, (char*)"��", 1, 3);
		Sleep(show_menu_speed);
	}
	WriteChar(N_menu_x + 4, N_menu_y, (char*)"�� ��", 1, 0xB);
	WriteChar(N_menu_x, N_menu_y + 2, (char*)"�� �� �� Ϸ��b��", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 4, (char*)"�� �� �� Ϸ��ESc��", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 6, (char*)"�� �� �� Ϸ��S��", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 8, (char*)"�� �� �� ����L��", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 10, (char*)"�� �� �� ͼ��m��", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 12, (char*)"�� �� �� ͼ (M)", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 14, (char*)"ʹ �� �� ͼ��u��", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 16, (char*)"ȡ �� �� ͼ��U��", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 18, (char*)"�� ͣ �� ����p��", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 20, (char*)"˫ �� �� Ϸ��c��", 1, 0xF);
	
	WriteChar(N_menu_x + 4, N_menu_y + 30, (char*)"˵ ��", 1, 0xB);
	WriteChar(N_menu_x - 6, N_menu_y + 32, (char*)"��w��s��a��d�ֱ������������", 1, 0xF);
	WriteChar(N_menu_x - 3, N_menu_y + 34, (char*)" ��q���л�̹��ģʽ", 1, 0xF);
	WriteChar(N_menu_x - 3, N_menu_y + 35, (char*)"��f�����ڣ�֧������", 1, 0xF);
	WriteChar(N_menu_x - 5, N_menu_y + 37, (char*)"��ͼ�༭֧��ʹ��i����o����", 1, 0xF);
	WriteChar(N_menu_x - 5, N_menu_y + 38, (char*)"k����l������б�Խ��ĸ�����", 1, 0xF);

}

