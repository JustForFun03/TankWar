#pragma once
#include"tank.h"
#include"map.h"
#include"bullet.h"
#include"menu.h"
#include"remind.h"
//#include"tank_war.h"

#include<algorithm>
#include<time.h>

using namespace std;
using std::map;
using std::make_pair;


#define path_SaveConfig_tank_player  ".\\SaveConfigtank_player.txt"
#define path_SaveConfig_tank_AI  ".\\SaveConfigtank_AI.txt"
#define path_SaveConfig_bullet_player  ".\\SaveConfigbullet_player.txt"
#define path_SaveConfig_bullet_AI  ".\\SaveConfigbullet_AI.txt"
#define path_save_tank_player  ".\\tank_player.txt"
#define path_save_tank_AI  ".\\tank_AI.txt"
#define path_save_bullet_player  ".\\bullet_player.txt"
#define path_save_bullet_AI  ".\\bullet_AI.txt"
#define path_save_map_editor_INgame  ".\\map_editor_INgame.txt"


#define UP 'w'                                                                                                                                                                 
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
#define LEFT_UP 'i'
#define RIGHT_UP 'o'
#define LEFT_DOWN 'k'
#define RIGHT_DOWN 'l'

#define PAUSE 'p'
#define SAVE_GAME 'S'

#define MAX_tank_history  10000
#define count_down  5

#define tank_renew_speed 200
#define map_editor_renew_speed 5

#define reborn_pos_x   134
#define reborn_pos_y   42

#define AI_DISTANCE   35

#define KEYDOWN(vk_code)((GetAsyncKeyState(vk_code)&0x8000)?1:0)
#define KEYUP(vk_code)((GetAsyncKeyState(vk_code)&0x8000)?0:1)

//��ͼȫ�ֶ���
extern map_editor g_obj_map_buffer;//�Զ����ͼ
extern map_border g_obj_map_border;//��ͼ�߽�

extern vector<tank_player1>g_v_tanks_player;//���̹��
extern vector<tank_AI>g_v_tanks_AI;//̹�˵з�0
//�ӵ�ȫ�ֶ���
extern vector<bullet>g_v_bullet_player;
extern vector<bullet>g_v_bullet_AI;

extern C_menu g_obj_menu;
extern C_remind g_obj_remind;

//ͳ�����ݽṹ��
typedef struct _statistics {
	unsigned int Hits[2];
	unsigned int Score[2];
	char Life_left[2];
	unsigned int Fire_player[2];
	unsigned int Fire_AI;
	short AI_death;
	short AI_count_born;
	void GetScore() {
		if (Fire_player[0])
		{
			Score[0] = (double)Hits[0] / Fire_player[0] * 100 /*+ Life_left[0] * 20*/ + AI_death * 5;
		}
		else
		{
			Score[0] = 0;
		}

	}
}STC_Data, *PSTC_Data;

extern STC_Data g_Data;

extern bool g_loadNotNew;
//int g_size[4];



//vectorɾ���Ż�
template<typename T1, typename T2>
void vec_erase_optimize_index(vector<T1>& vec, T2 match);
//vectorɾ���Ż�
template<typename T1, typename T2>
void vec_erase_optimize_item(vector<T1>& vec, T2 match);

//��������
int Load_number(char* path);
//��������
template <typename T1>
void Save_number(char* path, vector<T1>& vec);
//����vector
//template <typename T1>
void Save_vector(char* path, vector<tank_player1>& vec);
void Save_vector(char* path, vector<tank_AI>& vec);
void Save_vector(char* path, vector<bullet>& vec);
void Save_map_editor(map_editor& obj, char* path);
void Save_Score(char* path);

//vector����
//template <typename T1>
void Load_vector(char* path, int number, vector<tank_player1>& vec);
void Load_vector(char* path, int number, vector<tank_AI>& vec);
void Load_vector(char* path, int number, vector<bullet>& vec);
void Load_map_editor(map_editor& obj, char* path);
void Load_Score(char* path);



//AStar�㷨
typedef struct _node {
	_node* pFather;
	COORD pos;
	int G;
	int H;
	int F;
	//bool flag_delete;
}NODE, *PNODE;

class AStar {
public:
	COORD m_Begin;
	COORD m_End;
	vector<PNODE>m_vecOpen;
	vector<PNODE>m_vecClose;

	int CalcH(COORD pos);
	//���ó�ʼ����
	void SetMap(COORD pos_AIpos, COORD pos_player);

	//������·��
	void GetPath(vector<COORD>& vecPath,char stuck,int id);

	bool block_collision(COORD, COORD);

	bool tank_block(COORD pos,int id);

	//������·��ת��Ϊ����·��
	//void DirSeq(vector<COORD> vecPath);

	~AStar();
};




class control:public AStar
{
public:
	//ѡ����Ч��λ
	bool CheckPoints(COORD pos);
	//��ȡ·����
	int GetPathTables(map<COORD_pair, vector<COORD>>& PathTable);


public:

	void AI_attack(tank_AI& tank_AI,vector<COORD>& vecPath, vector<bullet>& v_bullet_player, vector<bullet>& v_bullet_AI);

	//̹�˷����ӵ� 
	void tank_fire(tank_player1& obj_tank_player, vector<bullet>& v_bullet);
	void tank_fire(tank_AI& obj_tank_AI, vector<bullet>& v_bullet);

	//̹�˺��ӵ�
	short collision_TankBullet(bullet& obj_bullet);
	//�ӵ�����AI̹�˴���
	void hit_tank_AI(vector<tank_AI>& vec, short id);
	short hit_tank_player(vector<tank_player1>& vec, short id);
	
	//�ӵ����ӵ�
	 void collision_BulletInter(bullet& obj_bullet, vector<bullet>& vec);

	 //��ӡ��������
	 void print_bullet_cross(COORD pos);

	 //��ͣ�浵
	 void pause_save(vector<bullet>&, vector<bullet>& );

	 //��ʾʵʱͳ�����ݺͷ���
	 void ShowData();

	 //time_tʱ����ӵ�ͼ��ָ����¸���
	 void time_clock();
};

//������Ϸ
bool single_player_game(bool);

//bool double_player_game(bool, short );



