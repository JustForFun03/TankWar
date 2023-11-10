#include "remind.h"
#include "show.h"
#include<stdio.h>
//#include  "C_map.h"

#define show_remind_speed 0
#define color_wall 4
#define score_x 76
#define remind_MAX 60


C_remind::C_remind() :remind_x(0), remind_y(0) {

}
void C_remind::show_remind_wall() {
	for (remind_x = 0; remind_x < 185; remind_x += 2)
	{
		WriteChar(remind_x, 45, (char*)"□", 1, color_wall);
		WriteChar(remind_x, 51, (char*)"□", 1, color_wall);
		Sleep(show_remind_speed);
	}
	for (remind_y = 45; remind_y < 51; remind_y++)
	{
		WriteChar(0, remind_y, (char*)"□", 1, color_wall);
		WriteChar(184, remind_y, (char*)"□", 1, color_wall);
		Sleep(show_remind_speed);
	}
	cls_news();
	//WriteChar(70, N1 + 1, (char*)"得分：??", 1, 0xC);
	WriteChar(2, N1 + 1, (char*)"温馨提示：适度游戏益脑，沉迷游戏伤身", 1, 9);
	WriteChar(2, N1 + 2, (char*)"按b开始游戏", 1, 9);
}
void C_remind::cls_news() {
	for (int x = 2; x < remind_MAX; x++)
	{
		for (int y = N1 + 2; y < N1 + 6; y++)
		{
			WriteChar(x, y, (char*)" ", 1, 0xA);
		}
	}
}
int C_remind::game_over() {
	cls_news();
	//WriteChar(2, N1 + 2, (char*)"你已阵亡！", 1, 0xA);
	//Sleep(1000);
	WriteChar(2, N1 + 3, (char*)"客官，再来一局吗", 1, 0xA);
	WriteChar(2, N1 + 4, (char*)"按b重新开始游戏", 1, 0xA);
	WriteChar(2, N1 + 5, (char*)"按L重新加载档案", 1, 0xA);
	return 1;
}
void C_remind::show_data_login() {
	WriteChar(70, N1 + 1, (char*)"1号玩家得分：", 1, 0xC);
	WriteChar(90, N1 + 1, (char*)"1号命中比率：", 1, 0xC);
	WriteChar(70, N1 + 2, (char*)"1号开炮次数：", 1, 0xC);
	WriteChar(90, N1 + 2, (char*)"1号命中次数：", 1, 0xC);
	WriteChar(70, N1 + 3, (char*)"1号剩余命数：", 1, 0xC);
	WriteChar(90, N1 + 3, (char*)"1号击杀AI数：", 1, 0xC);
}
void C_remind::show_data_start(unsigned int* Hits, unsigned int* Score,char* life_left,unsigned int* Fires,unsigned int AI_death) {
	WriteChar(84, N1 + 1, Score[0], 0xC);
	//double HitRatio = fabs(HIts[0] / Fires[0]);
	WriteChar(104, N1 + 1, 0.0, 0xC);
	WriteChar(84, N1 + 2, Fires[0],  0xC);
	WriteChar(104, N1 + 2, Hits[0],  0xC);
	WriteChar(84, N1 + 3, life_left[0],  0xC);
	WriteChar(104, N1 + 3, AI_death,  0xC);
}
void C_remind::show_data_renew(unsigned int* Hits, unsigned int* Score, char* life_left, unsigned int* Fires, unsigned int AI_death) {
	WriteChar(84, N1 + 1, Score[0], 0xC);
	if (Fires[0]!=0)
	{
		double HitRatio = fabs((double)Hits[0] / Fires[0]);
		WriteChar(104, N1 + 1, HitRatio, 0xC);
	}
	WriteChar(84, N1 + 2, Fires[0], 0xC);
	WriteChar(104, N1 + 2, Hits[0], 0xC);
	WriteChar(84, N1 + 3, life_left[0], 0xC);
	WriteChar(104, N1 + 3, AI_death, 0xC);
}
void C_remind::show_data_wipe() {
	WriteChar(84, N1 + 1, (char*)"    ",1, 0xC);
	WriteChar(104, N1 + 1, (char*)"    ",1, 0xC);
	WriteChar(84, N1 + 2, (char*)"    ",1,0xC);
	WriteChar(104, N1 + 2, (char*)"    ",1, 0xC);
	WriteChar(84, N1 + 3, (char*)"    ", 1,0xC);
	WriteChar(104, N1 + 3, (char*)"    ",1, 0xC);
}

//class C_death_wall :public C_game_over 

