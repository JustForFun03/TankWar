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

//地图全局对象
map_editor g_obj_map_buffer;//自定义地图
map_border g_obj_map_border;//地图边界
//坦克全局对象
vector<tank_player1>g_v_tanks_player;//玩家坦克
vector<tank_AI>g_v_tanks_AI;//坦克敌方0
//子弹全局对象
vector<bullet>g_v_bullet_player;
vector<bullet>g_v_bullet_AI;
//彩虹表全局
map<COORD_pair, vector<COORD>>g_PathTables;

C_menu g_obj_menu;//菜单区域
C_remind g_obj_remind;//消息区域

STC_Data g_Data;
bool g_loadNotNew=0;

//#define path_SaveConfig  ".\\SaveConfig.txt"
#define path_save_map ".\\Map.txt"
#define path_save_Tables ".\\Tables.txt"
#define path_save_config ".\\Save_config.txt"