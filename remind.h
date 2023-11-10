#pragma once
#include<windows.h>
#include<math.h>
#define N1 45
#define N2 70


class C_remind
{

public:

	short remind_x;
	short remind_y;

	C_remind();
	void show_remind_wall();
	void cls_news();
	int game_over();
	void show_data_login();
	void show_data_start(unsigned int* HIts, unsigned int* Score, char* life_left, unsigned int* Fires,unsigned int AI_death);
	void show_data_renew(unsigned int* HIts, unsigned int* Score, char* life_left, unsigned int* Fires, unsigned int AI_death);
	void show_data_wipe();
};
//class C_game_item {//Ðéº¯Êý
//public:
//	int virtual game_item() = 0;
//};

//class C_death_wall :public C_remind {
//public:
//	
//};


