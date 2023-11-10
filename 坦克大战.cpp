#include "show.h"
#include "menu.h"
#include "remind.h"
#include "interface.h"
#include "welcome_image.h"
#include "map.h"
#include "tank.h"
#include "bullet.h"
#include "control.h"
#include "tank_war.h"

#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>



int main()
{
	//控制台设置
	C_interface obj_console;
	obj_console.console_set();
	obj_console.sound_set();

	//初始界面

	welcome_image obj_welcome;
	obj_welcome.image();
	WriteChar(2, N1 + 4, (char*)"即将进入游戏......", 1, 0xA);
	printf("\n\n  ");
	//Sleep(200000);
	system("pause");

	bool login_flag = 1;

	//菜单控制

	while (1) {
		//初始化随机种子
		srand((unsigned)time(NULL));

		//游戏界面与菜单界面加载
		if (login_flag)
		{
			system("cls");

			//游戏界面
			//map_border obj_map_border;
			g_obj_map_border.show_map_border();


			//菜单界面加载
			//C_menu obj_menu;
			g_obj_menu.show_menu_wall();


			//通知界面
			//C_remind obj_remind;
			g_obj_remind.show_remind_wall();
			g_obj_remind.show_data_login();

			login_flag = 0;

			//地图全局对象
			g_obj_map_buffer.map_blank();//自定义地图
			g_obj_map_buffer.flag_load = 0;

		   // g_obj_map_border.;//地图边界

		}


		char c = 0;
		switch (c = _getch()) {
		case 'b': {							//单人模式
			login_flag=single_player_game(login_flag);

			g_obj_remind.game_over();

			//存档消除
			if (g_loadNotNew)
			{
				g_loadNotNew = 0;
			}
			//所有的静态变量都需要重置！！！
			tank_player1::count = 0;
			tank_AI::count_death = 0;
			tank_AI::count_born = 0;
			bullet::count_AI = bullet::count_player = 0;

			//control obj_ctrl;				//初始化控制引擎
			//tank_player1 obj_player;		//初始化玩家坦克
			//bullet obj_bullet;				//初始化子弹
			//
			//clock_t bullet_start = clock();//初始化子弹时间
			//clock_t tank_init = clock();//初始化坦克时间
			//vector<Stc_bullet_init>v_bullet_init;//初始化子弹矢量

			//int flag_back = 0;					//初始化回退值


			//while (true)
			//{
			//	//地图自动刷新
			//	if (clock()- g_obj_map_buffer.init_time>20)
			//	{
			//		g_obj_map_buffer.init_time = clock();
			//		g_obj_map_buffer.map_renew();
			//	}
			//	//坦克自动刷新
			//	if (clock()-tank_init>20)
			//	{
			//		tank_init = clock();
			//		obj_player.draw_tank(0x7, obj_player.design, obj_player.pos,
			//			obj_player.p, obj_player.mode, obj_player.dir);
			//	}

			//	if (_kbhit())
			//	{


			//		char c = 0;
			//		while (_kbhit() != 0) {
			//			 c = _getch();
			//		}
			//		//记录历史
			//		if (MODE==c||UP==c ||DOWN==c|| LEFT==c || RIGHT==c)
			//		{
			//			history_info stc_history;
			//			stc_history.mode = obj_player.mode;
			//			stc_history.dir = obj_player.dir;
			//			stc_history.pos = obj_player.pos;
			//			obj_player.v_history_tank.push_back(stc_history);
			//			if (obj_player.v_history_tank.size()> MAX_tank_history)
			//			{
			//				vector<history_info>::iterator it = obj_player.v_history_tank.begin();
			//				obj_player.v_history_tank.erase(it);
			//			}
			//			flag_back = 0;
			//		}

			//		switch (c)
			//		{
			//		case MODE:
			//		{						//消息区域显示选项
			//			scanf_s("%hd", &mode);
			//			obj_player.wipe_tank((char*)"  ", obj_player.pos, obj_player.p, obj_player.mode, obj_player.dir);
			//			obj_player.mode = mode;*/

			//			//切换模式
			//			obj_player.wipe_tank((char*)"  ", obj_player.pos, obj_player.p, obj_player.mode, obj_player.dir);
			//			obj_player.last_mode = obj_player.mode;
			//			obj_player.last_dir = obj_player.dir;
			//			obj_player.last_pos = obj_player.pos;
			//			if (obj_player.mode==5)
			//			{
			//				obj_player.mode = 0;
			//			}
			//			else
			//			{
			//				obj_player.mode++;
			//			}
			//		}
			//		break;
			//		case UP:
			//		{
			//			obj_player.wipe_tank((char*)"  ", obj_player.pos, obj_player.p, obj_player.mode, obj_player.dir);
			//			obj_player.last_mode = obj_player.mode;
			//			obj_player.last_dir = obj_player.dir;
			//			obj_player.last_pos = obj_player.pos;

			//			obj_player.dir = UP;
			//			if (obj_player.last_dir == obj_player.dir)
			//			{
			//				
			//				obj_player.pos.Y--;
			//			}

			//		}
			//		break;
			//		case DOWN:
			//		{
			//			obj_player.wipe_tank((char*)"  ", obj_player.pos, obj_player.p, obj_player.mode, obj_player.dir);
			//			//system("pause");
			//			obj_player.last_mode = obj_player.mode;
			//			obj_player.last_dir = obj_player.dir;
			//			obj_player.last_pos = obj_player.pos;
			//			obj_player.dir = DOWN;
			//			if (obj_player.last_dir == obj_player.dir)
			//			{
			//				
			//				obj_player.pos.Y++;
			//			}

			//		}
			//		break;
			//		case LEFT:
			//		{

			//			obj_player.wipe_tank((char*)"  ", obj_player.pos, obj_player.p, obj_player.mode, obj_player.dir);
			//			obj_player.last_mode = obj_player.mode;
			//			obj_player.last_dir = obj_player.dir;
			//			obj_player.last_pos = obj_player.pos;
			//			obj_player.dir = LEFT;
			//			if (obj_player.last_dir == obj_player.dir)
			//			{
			//			
			//				obj_player.pos.X -= 2;
			//			}
			//		}
			//		break;
			//		case RIGHT:
			//		{
			//			obj_player.wipe_tank((char*)"  ", obj_player.pos, obj_player.p, obj_player.mode, obj_player.dir);
			//			obj_player.last_mode = obj_player.mode;
			//			obj_player.last_dir = obj_player.dir;
			//			obj_player.last_pos = obj_player.pos;
			//			obj_player.dir = RIGHT;
			//			if (obj_player.last_dir == obj_player.dir)
			//			{
			//			
			//				obj_player.pos.X += 2;
			//			}
			//		}
			//		break;
			//		case VK_BACK:
			//		{
			//			obj_player.wipe_tank((char*)"  ", obj_player.pos, obj_player.p, obj_player.mode, obj_player.dir);
			//			//赋值vector中最后一个的信息
			//			if (!flag_back)
			//			{
			//				flag_back = 1;
			//			}
			//			else
			//			{
			//				flag_back++;
			//			}
			//			int index=obj_player.v_history_tank.size()-flag_back;
			//			//int index = total_size - flag_back;
			//			if (index < 0)
			//			{
			//				index = 0;
			//			}
			//			obj_player.mode=obj_player.v_history_tank[index].mode;
			//			obj_player.dir=obj_player.v_history_tank[index].dir;
			//			obj_player.pos=obj_player.v_history_tank[index].pos;
			//		}
			//		break;
			//		case 'q':
			//		{
			//		
			//		}
			//		break;
			//		case 'f':
			//		{
			//			//坦克传递给子弹对象
			//			PCOORD p_muzzle = obj_player.get_muzzzle();
			//			char bullet_type = obj_player.mode - 1;
			//			char bullet_dir = obj_player.dir;

			//			obj_bullet.origin[0].X = (*p_muzzle).X;
			//			obj_bullet.origin[0].Y = (*p_muzzle).Y;
			//			obj_bullet.origin[1].X = (*(p_muzzle + 1)).X;
			//			obj_bullet.origin[1].Y = (*(p_muzzle + 1)).Y;
			//			//	obj_bullet.origin[1] = *(p_muzzle+1);
			//			if (obj_player.mode)
			//			{
			//				obj_bullet.type = bullet_type;
			//			}
			//			else
			//			{
			//				break;
			//			}
			//			obj_bullet.dir = bullet_dir;


			//			//obj_bullet.bullet_conf->hp =obj_bullet.bullet_draw(obj_bullet.origin, obj_bullet.dir, obj_bullet.type);

			//			//vector存储多个子弹初始化数据
			//			//子弹对象传递给子弹vector
			//			Stc_bullet_init bullet;
			//			bullet.init_dir= obj_bullet.dir;
			//			bullet.init_type= obj_bullet.type;
			//			if (obj_bullet.type!=1)
			//			{
			//				bullet.init_muzzle[0].X = obj_bullet.origin[0].X;
			//				bullet.init_muzzle[0].Y = obj_bullet.origin[0].Y;
			//			}
			//			else
			//			{
			//				bullet.init_muzzle[0].X = obj_bullet.origin[0].X;
			//				bullet.init_muzzle[0].Y = obj_bullet.origin[0].Y;
			//				bullet.init_muzzle[1].X = obj_bullet.origin[1].X;
			//				bullet.init_muzzle[1].Y = obj_bullet.origin[1].Y;
			//			}


			//			bullet.bullet_conf= obj_bullet.bullet_conf[bullet.init_type];
			//			clock_t this_time = clock();
			//			bullet.init_time = this_time;
			//			
			//			v_bullet_init.push_back(bullet);

			//			//初始子弹和边界判断
			//			v_bullet_init[v_bullet_init.size()-1].bullet_conf.hp = obj_bullet.bullet_draw
			//			(v_bullet_init[v_bullet_init.size() - 1].init_muzzle, v_bullet_init[v_bullet_init.size() - 1].init_dir,
			//				v_bullet_init[v_bullet_init.size() - 1].init_type, v_bullet_init[v_bullet_init.size() - 1].bullet_conf.max_length);
			//			if (!v_bullet_init[v_bullet_init.size() - 1].bullet_conf.hp)
			//			{
			//				v_bullet_init.pop_back();
			//			}
			//			//, obj_bullet.type,  obj_bullet.bullet_conf[5]
			//			
			//		}
			//		break;
			//		default:
			//			break;
			//		}

			//		//坦克和地图以及边界碰撞
			//		char cross_tank_player_border= obj_ctrl.collision_TankBorder(obj_player,g_obj_map_border);
			//		char cross_tank_player_map = obj_ctrl.collision_TankMap(obj_player,g_obj_map_buffer);
			//		char cross = cross_tank_player_border||cross_tank_player_map;
			//		//printf("%d",collision);
			//		obj_ctrl.execute(cross,obj_player);

			//	}
			//	//子弹处理
			//	for (unsigned int i = 0; i < v_bullet_init.size(); i++)
			//	{
			//		if ((clock() - v_bullet_init[i].init_time) > v_bullet_init[i].bullet_conf.speed)
			//		{
			//			v_bullet_init[i].init_time = clock();
			//			//擦除
			//			obj_bullet.bullet_wipe(v_bullet_init[i].init_muzzle, v_bullet_init[i].init_dir, v_bullet_init[i].init_type);
			//			//绘画
			//			short& distance = v_bullet_init[i].bullet_conf.max_length;//射程

			//			char bullet_state= obj_bullet.bullet_draw(v_bullet_init[i].init_muzzle, v_bullet_init[i].init_dir, v_bullet_init[i].init_type, distance);
	
			//			
			//			if (distance <= 0)//射程消失
			//			{
			//				obj_bullet.bullet_wipe(v_bullet_init[i].init_muzzle, v_bullet_init[i].init_dir, v_bullet_init[i].init_type);
			//				vector<Stc_bullet_init>::iterator it = v_bullet_init.begin();
			//				v_bullet_init.erase(it + i);
			//				
			//			}
			//			else if (!bullet_state)//遇到地图障碍物显示
			//			{
			//				vector<Stc_bullet_init>::iterator it = v_bullet_init.begin();
			//				v_bullet_init.erase(it + i);
			//			}
			//			
			//		}
			//	}

			//}

		}
				  break;
		case 'c'://双人模式
		{
;			//login_flag = double_player_game(login_flag,  2);
			//printf("%d",login_flag);
			system("pause");
		}
			break;
		case VK_ESCAPE: {							//退出游戏1
			system("cls");
			//system("pause");
			welcome_image obj_welcome;
			obj_welcome.image();
			WriteChar(2, N1 + 4, (char*)"再按ESC键完成退出，其它键返回游戏", 1, 0xA);
			char enter = 0;
			enter = _getch();
			if (enter == VK_ESCAPE)
			{
				return 0;
			}
			//存档消除
			if (g_loadNotNew)
			{
				g_loadNotNew = 0;
			}
			login_flag = 1;
		}
			break;
		case 'S': {							//保存游戏1
			g_obj_remind.cls_news();
			WriteChar(2, N1 + 2, (char*)"仅可在游戏暂停时使用保存功能！", 1, 0xA);
		}
				  break;
		case 'L':							//加载游戏0.5
		{
			//if (g_obj_map_buffer.flag_load)
			//{
			//	g_obj_remind.cls_news();
			//	WriteChar(2, N1 + 2, (char*)"当前为使用地图状态，不可使用加载存档功能！", 1, 0xA);
			//	WriteChar(2, N1 + 3, (char*)"按U退出使用地图状态后可加载存档！", 1, 0xA);
			//}
			//else
			//{
			if (!g_loadNotNew)
			{
				g_obj_remind.cls_news();

				int number_tank_player = Load_number((char*)path_SaveConfig_tank_player);
				int number_tank_AI = Load_number((char*)path_SaveConfig_tank_AI);
				int number_bullet_player = Load_number((char*)path_SaveConfig_bullet_player);
				int number_bullet_AI = Load_number((char*)path_SaveConfig_bullet_AI);


				Load_vector((char*)path_save_tank_player, number_tank_player, g_v_tanks_player);
				Load_vector((char*)path_save_tank_AI, number_tank_AI, g_v_tanks_AI);
				Load_vector((char*)path_save_bullet_player, number_bullet_player, g_v_bullet_player);
				Load_vector((char*)path_save_bullet_AI, number_bullet_AI, g_v_bullet_AI);

				Load_map_editor(g_obj_map_buffer, (char*)path_save_map_editor_INgame);
				Load_Score((char*)path_save_score);

				WriteChar(2, N1 + 2, (char*)"存档已加载！", 1, 0xA);

				g_loadNotNew = 1;//表明加载档案
				g_obj_map_buffer.flag_load = 2;//表明地图为存档地图
			}
				

				////玩家坦克数量
				//int size_tank_player = 0;
				//FILE* pfile_load_config_tank_player;
				//fopen_s(&pfile_load_config_tank_player, path_SaveConfig_tank_player , "rb");
				//fread_s(&size_tank_player, 1* sizeof(int), sizeof(int), 1, pfile_load_config_tank_player);
				//fclose(pfile_load_config_tank_player);
				////加载玩家坦克
				//tank_player1 buffer_tank_player[2];
				//FILE* pfile_load_tank_player;
				//fopen_s(&pfile_load_tank_player, path_save_tank_player, "rb");
				//fread_s(buffer_tank_player, size_tank_player * sizeof(tank_player1), sizeof(tank_player1),
				//	size_tank_player, pfile_load_tank_player);
				//fclose(pfile_load_tank_player);

				//for (int i = 0; i < size_tank_player; i++)
				//{
				//	g_v_tanks_player.push_back(buffer_tank_player[i]);
				//}

				////加载AI坦克
				////AI坦克数量
				//int size_tank_AI = 0;
				//FILE* pfile_load_config_tank_AI;
				//fopen_s(&pfile_load_config_tank_AI, path_SaveConfig_tank_AI, "rb");
				//fread_s(&size_tank_AI, sizeof(int), sizeof(int), 1, pfile_load_config_tank_AI);
				//fclose(pfile_load_config_tank_AI);

				////tank_AI obj1(1);
				////tank_AI obj2(1);
				////tank_AI obj3(1);
				//tank_AI buffer_tank_AI[3] ;
				//FILE* pfile_load_tank_AI;
				//fopen_s(&pfile_load_tank_AI, path_save_tank_player, "rb");
				//fread_s(buffer_tank_AI, size_tank_AI * sizeof(tank_AI), sizeof(tank_AI),
				//	size_tank_AI, pfile_load_tank_AI);
				//fclose(pfile_load_tank_AI);

				//for (int i = 0; i < size_tank_AI; i++)
				//{
				//	g_v_tanks_AI.push_back(buffer_tank_AI[i]);
				//}



		}
		break;
		case 'm': {							//制作地图1	
			
			map_editor obj_map_editor;
			COORD loc_editor = {2,1};
			COORD loc_editor_last = {2,1};
			
			WriteChar(loc_editor.X,loc_editor.Y ,(char*)"□",1 , 0x7);

			bool transfer_flag = 0;
			char mode = 0;
			while (1)
			{
				if (login_flag)
				{
					break;
				}
				//ShowCursor(0);
				char c = 127;
				if (_kbhit())
				{
					c = _getch();
				}
				if (transfer_flag)
				{
					c = mode;
					transfer_flag = 0;
					mode = 0;
				}
				//bool& flag = transfer_flag;
				//char& Mode = mode;
				COORD& loc = loc_editor;
				COORD& loc_last = loc_editor_last;
				switch (c) {
				case VK_SPACE://移动
				{
					obj_map_editor.editor_fun_move(obj_map_editor, loc,loc_last, transfer_flag, mode);
				}
				break;
				case '1'://iron
				{
					obj_map_editor.editor_fun_type(obj_map_editor, loc, loc_last, transfer_flag,mode, 1);
				}
				break;
				case '2'://brick
				{
					obj_map_editor.editor_fun_type(obj_map_editor, loc, loc_last, transfer_flag, mode,2);
				}
				break;
				case '3'://grass
				{
					obj_map_editor.editor_fun_type(obj_map_editor, loc, loc_last, transfer_flag, mode, 3);
				}
				break;
				case '4'://river
				{
					obj_map_editor.editor_fun_type(obj_map_editor, loc, loc_last, transfer_flag, mode, 4);
				}
				break;
				case '0':
				{
					obj_map_editor.editor_fun_type(obj_map_editor, loc, loc_last, transfer_flag, mode, 0);
				}
				break;
				case VK_ESCAPE:
				{
					WriteChar(2,N1+4,(char*)"  ",3,0xA);
					system("pause");
					FILE* pfile_save;
					fopen_s(&pfile_save, path_save_map,"wb+");
					for (short coord_x = 0; coord_x < N2-1; coord_x++)
					{
						for (short coord_y = 0; coord_y < N1-1; coord_y++)
						{
							fwrite(obj_map_editor.Stc_arr_map,sizeof(Stc_map_element),(N1-1)*(N2-1),pfile_save);

						}
					}
					fclose(pfile_save);

					login_flag=1;
				}
					break;
				default:
					break;
				
				}

			}

		}
				  break;
		case 'M': {							//查看地图1

			g_obj_map_buffer.map_load();
			g_obj_map_buffer.map_editor_init();
			
			while (1) {
				Show_cursor(0);
				WriteChar(2, N1 + 2, (char*)"按ESC键退出", 1, 0xA);
				char choice = 0;
				if (_kbhit())
				{
					choice = _getch();
				}
				if (choice == VK_ESCAPE)
				{
					break;
				}
			}
			login_flag = 1;
		}
				  break;
		case 'u': {		
			//if (g_loadNotNew)
			//{
			//	//使用地图1
			//	g_obj_map_buffer.map_load();
			//	g_obj_map_buffer.map_editor_init();

			//	g_obj_map_buffer.GetEffObstacle();//初始化有效障碍物-作用 坦克生成和寻路判断
			//	g_loadNotNew = 0;
			//}
			if (!g_obj_map_buffer.flag_load)
			{
				//使用地图1
				g_obj_map_buffer.map_load();
				g_obj_map_buffer.map_editor_init();

				g_obj_map_buffer.GetEffObstacle();//初始化有效障碍物-作用 坦克生成和寻路判断

				//初始化寻路彩虹表
				//control obj_PathTables;
				//obj_PathTables.GetPathTables(g_PathTables);

				//保存彩虹表项总数
				//int count = g_PathTables.size();
				//FILE* save_config;
				//fopen_s(&save_config, path_save_config, "wb+");
				//fwrite(&count, sizeof(int), 1, save_config);
				//fclose(save_config);

				////保存彩虹表
				//FILE* Tables_save;
				//fopen_s(&Tables_save, path_save_Tables, "wb+");
				//for (auto it = g_PathTables.begin(); it != g_PathTables.end(); it++)
				//{
				//	fwrite(&g_PathTables, sizeof(map<COORD_pair, vector<COORD>>), count, Tables_save);
				//}
				//fclose(Tables_save);

				//导入彩虹表
				//先取出总数
				//int count_load = 0;
				//FILE* load_config;
				//fopen_s(&load_config, path_save_config, "wb+");
				//fread_s(&count_load, 1*sizeof(int), sizeof(int), 1, load_config);
				//fclose(load_config);

				////导入
				//FILE* pTables_load;
				//fopen_s(&pTables_load, path_save_Tables, "rb");
				//for (int i = 0; i < count_load; i++)
				//{
				//	fread_s(&g_obj_map_buffer, count_load * sizeof(map<COORD_pair, vector<COORD>>),
				//		sizeof(map<COORD_pair, vector<COORD>>),count_load, pTables_load);
				//}
				//fclose(pTables_load);

				//
				g_obj_map_buffer.flag_load = 1;

			}
			else
			{
				
			}

			//for (auto it = g_PathTables.begin(); it != g_PathTables.end(); it++)
			//{
			//	printf("%d,%d  %d,%d\t",it->first.pos_Begin.X, it->first.pos_Begin.Y,it->first.pos_End.X, it->first.pos_End.Y);
			//	for (auto i=it->second.begin() ; i!= it->second.end(); i++)
			//	{
			//		printf("%d,%d ", i->X, i->Y);
			//	}
			//	printf("\n");
			//}
			//system("pause");
			//g_obj_map_buffer.map_renew();
			//WriteChar(2, N1 + 3, (char*)"当前不可使用加载存档功能！", 1, 0xA);

		}
				  break;
		case 'U':
		{
			if (!g_obj_map_buffer.flag_load)
			{
				WriteChar(2, N1 + 2, (char*)"当前未加载地图！", 1, 0xA);
			}
			else
			{
				//界面恢复
				g_obj_map_buffer.map_blank();//自定义地图
				g_obj_map_buffer.flag_load = 0;
				g_obj_map_buffer.map_editor_init();

				g_obj_remind.cls_news();
				WriteChar(2, N1 + 2, (char*)"地图已撤销！", 1, 0xA);
			}

		}
		break;
		case 'p':
			g_obj_remind.cls_news();
			WriteChar(2, N1 + 2, (char*)"仅可在游戏中使用暂停功能！", 1, 0xA);
			break;
		case 'v': {							//速度扩展
//			//C_snake obj_snake;
//			obj_remind.cls_news();
//			WriteChar(2, N1 + 2, (char*)"选择蛇游走速度等级!", 1, 0xA);
//			printf("当前等级为%hd", g_velocity);
//			WriteChar(2, N1 + 3, (char*)"请从1-400中选择一个\
//整数输入(数字越小速度越快)：", 1, 0xA);
//			scanf_s("%hd", &g_velocity);
//			WriteChar(2, N1 + 4, (char*)"已经设置速度等级为", 1, 0xA);
//			printf("%hd", g_velocity);
		}
				  break;
		case 't': {							//方向扩展
			//if (1)
			//{
			//	obj_remind.cls_news();
			//	WriteChar(2, N1 + 2, (char*)"方向扩展已开启，现在i、o、k、l键可用", 1, 0xA);

			//}
			//else
			//{
			//	obj_remind.cls_news();
			//	WriteChar(2, N1 + 2, (char*)"方向扩展已关闭", 1, 0xA);
			//}
			//
		}
				  break;
		case 'x':
		{
			if (1) {
				//	obj_remind.cls_news();
				//	WriteChar(2, N1 + 2, (char*)"身体束缚已开启，撞到自己会死亡", 1, 0xA);
				//}
				//else
				//{
				//	obj_remind.cls_news();
				//	WriteChar(2, N1 + 2, (char*)"身体束缚已关闭", 1, 0xA);
				//	g_body_bound = 0;
				//}
			}
			break;
		}
		case 'j':
		{
			//	if (1) {
			//		obj_remind.cls_news();
			//		WriteChar(2, N1 + 2, (char*)"跳跃功能已开启", 1, 0xA);
			//	}
			//	else {
			//		obj_remind.cls_news();
			//		WriteChar(2, N1 + 2, (char*)"跳跃功能已关闭", 1, 0xA);
			//	}
			//}
			break;
		}
		}

	}
}



