#pragma once
#include "welcome_image.h"
#include "show.h"
#include "remind.h"
//#include "tank_war.h"

#include <windows.h>
#include <vector>
#include<stdio.h>
#include<string.h>
#include<time.h>
#include<conio.h>
#include<windows.h>


#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define LEFT_UP 'i'
#define RIGHT_UP 'o'
#define LEFT_DOWN 'k'
#define RIGHT_DOWN 'l'

#define renew_road_speed   500
#define renew_iron_speed   45
#define renew_brick_speed  45
#define renew_grass_speed  5
#define renew_river_speed  160

using std::vector;

#define path_save_score			 ".\\Score.txt"
#define path_save_customize_map  ".\\CustomizeMap.txt"

//extern map_editor g_obj_map_buffer;//自定义地图
//extern map_border g_obj_map_border;//地图边界

//#define N1 45
//#define N2 70

class map_border{
public:
	map_border();
	~map_border();
	short game_x;
	short game_y;
	short num_arr;
	PCOORD p_arr_border;
	void set_map_border();
	void show_map_border();
};

typedef struct _map_element{
	short type;
	short cross_tank;
	short cross_bullet;
	short show_tank;
	short show_bullet;
	short is_ignite;

	WORD color;
//	WORD color_temp;
	char image[3];
	float hp;
	clock_t start_time;
	int renew_speed;
//	int time;
}Stc_map_element,*PStc_map_element;



class map_editor {
public:
	//COORD loc;
	//Stc_map_element stc_element;
	int init_time;
	int flag_load;//0未加载，1内置地图初始，2存档地图
	//int count;
	short type;
	Stc_map_element Stc_arr_map[N1-1][N2-1];



	//vector<COORD>  vec_PathTable[N1-1][N2-1][N1-1][N2-1];
	void map_blank();


public:
	map_editor();
	bool eff_obstacle[N1-1][N2-1];
	void GetEffObstacle();

public:
	void element_set(short type,COORD coord);

	void  editor_fun_move(map_editor&,COORD&, COORD&,bool&,char&);
	void  editor_fun_type(map_editor&,COORD&, COORD&,bool&,char&,short);
	bool  editor_fun_collision_border(COORD);

	void map_renew();
	void map_editor_init();
	void map_load();
	
};



