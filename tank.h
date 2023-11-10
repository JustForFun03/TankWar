#pragma once
#include "map.h"
//#include "tank_war.h"
//#include "bullet.h"
//#include "control.h"!!!


#include <windows.h>
#include <time.h>
#include <vector>
#include <map>

using namespace std;
using std::vector;

using std::map;

#define MODE 'q'
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define FIRE 'f'

#define MODE2 'o'
#define UP2 'i'
#define DOWN2 'k'
#define LEFT2 'j'
#define RIGHT2 'l'
#define FIRE2 'h'


#define MAX_tank_history  10000

enum AI_operation {
	up,
	down,
	left,
	right,
	fire
};
typedef struct _coord_pair {
	COORD pos_Begin;
	COORD pos_End;

	friend bool operator<(_coord_pair obj1, _coord_pair obj2);
}COORD_pair, *PCOORD_pair;

bool less_rule(COORD_pair obj1, COORD_pair obj2);

extern map_editor g_obj_map_buffer;//�Զ����ͼ
extern map<COORD_pair, vector<COORD>>g_PathTables;
extern C_remind g_obj_remind;//��Ϣ����




typedef struct _history_info {
	short mode;
	char dir;
	COORD pos;

} history_info, *Phistory_info;

class tank_info
{

public:
	//�������ݿ�
	static bool(*p)[4][9];

	//������״
	static void shape_tank();
public:
	COORD pos;
	COORD last_pos;
	COORD muzzle_pos[2];
	char dir;
	char last_dir;
	float hp;
	short flag_back;
	//short attack;
	short mode;
	short last_mode;
	clock_t tank_time;
	int velocity;
	short party;
	short id;
	unsigned int Fires;
	//char* design;          
	WORD color;
	unsigned int distance;
	double angle;
	double angle2;
	short DifX;
	short DifY;
	short DifX2;
	short DifY2;
	short DifX_cent;
	short DifY_cent;
	//vector<history_info>v_history_tank;

	tank_info();
	//~tank_info();

	//����ڿ�
	PCOORD get_muzzzle();

	//���ƹ��캯��
	tank_info(const tank_info&);

	//����̹��
	void draw_tank();

	//����̹��
	void wipe_tank();

	//�ƶ�
	void move_tank(char direc);
	//����
	void back_tank();

	//����
	//void history_tank();

	//̹�˺���Ϸ�߽�
	char collision_TankBorder();
	//̹��֮��
	char collision_TankInter();
	//̹�����ͼ
	char collision_TankMap();
	//̹����ײ����
	void execute(char signal);

	//��ȡ����
	unsigned int GetDistance(COORD pos);
	//��ȡ�Ƕ�
	double GetAngle(COORD pos);
	//����ͼ�Ƿ��ڵ�Ŀ��
	bool CheckMapBlock();

	//����Զ�Ѱ·���з���
	char GetDir(COORD pos,COORD last_pos);
};


class tank_player1 : public tank_info
{
public:
	static short count;
public:
//	unsigned short Hits;
	char life_left;
public:
	tank_player1();
	//~tank_player1();
	tank_player1(short x,short y);//ָ��λ��
	tank_player1(const tank_player1& obj);//���ƹ���

public:
	//void tank_player_reborn();
};


class tank_AI :public tank_info {

public:
	char stuck;
	bool flag_GetPath;
	short HunterTarget;
public:
	static short count_born;
	static short count_death;
	static bool group_GetPath;
	static short group_targetID;
public:
	
	//ָ��λ�ù���
	tank_AI(short,short);
	//�������
	tank_AI(int);

	//��������
	tank_AI(const tank_AI&);
	//Ĭ�Ϲ���
	tank_AI();
	//~tank_AI();

	//���Ҳʺ��
	bool SearchTables(COORD pos_End, vector<COORD>& vec);

public:
	//void tank_AI_reborn();
};
