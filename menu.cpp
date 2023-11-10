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
		WriteChar(menu_x, 0, (char*)"□", 1, 3);
		WriteChar(menu_x, 44, (char*)"□", 1, 3);
		Sleep(show_menu_speed);
	}
	for (menu_y = 0; menu_y < 45; menu_y++)
	{
		WriteChar(140, menu_y, (char*)"□", 1, 3);
		WriteChar(184, menu_y, (char*)"□", 1, 3);
		Sleep(show_menu_speed);
	}
	WriteChar(N_menu_x + 4, N_menu_y, (char*)"菜 单", 1, 0xB);
	WriteChar(N_menu_x, N_menu_y + 2, (char*)"单 人 游 戏（b）", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 4, (char*)"退 出 游 戏（ESc）", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 6, (char*)"保 存 游 戏（S）", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 8, (char*)"加 载 存 档（L）", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 10, (char*)"制 作 地 图（m）", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 12, (char*)"查 看 地 图 (M)", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 14, (char*)"使 用 地 图（u）", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 16, (char*)"取 消 地 图（U）", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 18, (char*)"暂 停 继 续（p）", 1, 0xF);
	WriteChar(N_menu_x, N_menu_y + 20, (char*)"双 人 游 戏（c）", 1, 0xF);
	
	WriteChar(N_menu_x + 4, N_menu_y + 30, (char*)"说 明", 1, 0xB);
	WriteChar(N_menu_x - 6, N_menu_y + 32, (char*)"按w、s、a、d分别控制上下左右", 1, 0xF);
	WriteChar(N_menu_x - 3, N_menu_y + 34, (char*)" 按q键切换坦克模式", 1, 0xF);
	WriteChar(N_menu_x - 3, N_menu_y + 35, (char*)"按f键开炮，支持连发", 1, 0xF);
	WriteChar(N_menu_x - 5, N_menu_y + 37, (char*)"地图编辑支持使用i键、o键、", 1, 0xF);
	WriteChar(N_menu_x - 5, N_menu_y + 38, (char*)"k键、l键控制斜对角四个方向", 1, 0xF);

}

