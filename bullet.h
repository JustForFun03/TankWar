#pragma once
#include"map.h"
//#include"tank_war.h"

#include<windows.h>
#include<vector>


extern map_editor g_obj_map_buffer;//�Զ����ͼ
//extern vector<tank_player1>g_v_tanks_player;//���̹��
//extern vector<tank_AI>g_v_tanks_AI;//̹�˵з�0

using std::vector;

#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

typedef struct _bullet_conf {
	char type;
	WORD color;
	char* image;
	short max_length;//�ж����
	short speed;
	float power;
	char function;
	char hp;//�ж��ӵ���ײ
	char hp2;
	
}Stc_bullet_conf,*PStc_bullet_conf;


class bullet{
public:
	static short count_player;
	static short count_AI;
public:
	COORD origin[2];
	char dir;
	char type;
	char state;//�ж��������ײ
	int init_time;
	short owner_id;
	short party;
	short id_player;
	short id_AI;

	Stc_bullet_conf  bullet_conf[5];//type  color   design

	bullet(short);
	bullet();
	void style_set();
	void bullet_draw();
	void bullet_wipe();
	void BulletBorder();
	void BulletMap();
};


