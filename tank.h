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

extern map_editor g_obj_map_buffer;//自定义地图
extern map<COORD_pair, vector<COORD>>g_PathTables;
extern C_remind g_obj_remind;//消息区域




typedef struct _history_info {
	short mode;
	char dir;
	COORD pos;

} history_info, *Phistory_info;

class tank_info
{

public:
	//配置数据库
	static bool(*p)[4][9];

	//设置形状
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

	//获得炮口
	PCOORD get_muzzzle();

	//复制构造函数
	tank_info(const tank_info&);

	//画出坦克
	void draw_tank();

	//消除坦克
	void wipe_tank();

	//移动
	void move_tank(char direc);
	//倒车
	void back_tank();

	//倒车
	//void history_tank();

	//坦克和游戏边界
	char collision_TankBorder();
	//坦克之间
	char collision_TankInter();
	//坦克与地图
	char collision_TankMap();
	//坦克碰撞处理
	void execute(char signal);

	//获取距离
	unsigned int GetDistance(COORD pos);
	//获取角度
	double GetAngle(COORD pos);
	//检查地图是否遮挡目标
	bool CheckMapBlock();

	//配合自动寻路进行方向
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
	tank_player1(short x,short y);//指定位置
	tank_player1(const tank_player1& obj);//复制构造

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
	
	//指定位置构造
	tank_AI(short,short);
	//随机构造
	tank_AI(int);

	//拷贝构造
	tank_AI(const tank_AI&);
	//默认构造
	tank_AI();
	//~tank_AI();

	//查找彩虹表
	bool SearchTables(COORD pos_End, vector<COORD>& vec);

public:
	//void tank_AI_reborn();
};
