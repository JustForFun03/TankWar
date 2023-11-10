#pragma once
#include "show.h"
#include "menu.h"
#include "remind.h"
#include "interface.h"
#include "welcome_image.h"
#include "map.h"
#include "tank.h"
#include "bullet.h"
#include "control.h"

//��ͼȫ�ֶ���
map_editor g_obj_map_buffer;//�Զ����ͼ
map_border g_obj_map_border;//��ͼ�߽�
//̹��ȫ�ֶ���
vector<tank_player1>g_v_tanks_player;//���̹��
vector<tank_AI>g_v_tanks_AI;//̹�˵з�0
//�ӵ�ȫ�ֶ���
vector<bullet>g_v_bullet_player;
vector<bullet>g_v_bullet_AI;
//�ʺ��ȫ��
map<COORD_pair, vector<COORD>>g_PathTables;

C_menu g_obj_menu;//�˵�����
C_remind g_obj_remind;//��Ϣ����

STC_Data g_Data;
bool g_loadNotNew=0;

//#define path_SaveConfig  ".\\SaveConfig.txt"
#define path_save_map ".\\Map.txt"
#define path_save_Tables ".\\Tables.txt"
#define path_save_config ".\\Save_config.txt"