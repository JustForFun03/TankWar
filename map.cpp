#include "map.h"
#include "show.h"
#include "remind.h"

#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<time.h>


#define show_map_speed 0
#define make_show_map_speed 0
#define wall "□"
#define path_save_map ".\\Map.txt"

#define N1 45
#define N2 70

//为何不能用'□'进行地图设置，wchar_t

map_border::map_border():game_x(0), game_y(0), num_arr(2 * (N1 + N2)) {
	set_map_border();
}
map_border::~map_border() {
	delete[]p_arr_border;
}

//wall坐标结构体数组
void map_border::set_map_border() {
	p_arr_border = new COORD[num_arr];
	for (int i = 0; i < 2 * N2; i += 2)
	{//上下边界
		(p_arr_border + i / 2)->X = i; (p_arr_border + i / 2)->Y = 0;
		(p_arr_border + i / 2 + N2)->X = i; (p_arr_border + i / 2 + N2)->Y = N1 - 1;
	}
	for (int j = 0; j < N1; j++)
	{
		(p_arr_border + j + 2 * N2)->X = 0; (p_arr_border + j + 2 * N2)->Y = j;
		(p_arr_border + j + 2 * N2 + N1)->X = 2 * (N2 - 1); (p_arr_border + j + 2 * N2 + N1)->Y = j;
	}
}



////显示地图
void map_border::show_map_border() {
	for (game_x = 0; game_x < 2 * N2; game_x += 2)
	{
		WriteChar(game_x, (short)0, (char*)wall, 1, 7);
		WriteChar(game_x, N1 - 1, (char*)wall, 1, 7);
		Sleep(show_map_speed);
	}
	for (game_y = 0; game_y < N1; game_y++)
	{
		WriteChar(0, game_y, (char*)wall, 1, 7);
		WriteChar(2 * (N2 - 1), game_y, (char*)wall, 1, 7);
		Sleep(show_map_speed);
	}
}


map_editor::map_editor() {
	map_blank();
	init_time = clock();
	//flag_load = 0;
}
//全部地图元素设置为road
void map_editor::map_blank() {
//	init_time = clock();
//	clock_t init_map_time = clock();
	for (short coord_x = 1; coord_x < (N2 - 1); coord_x ++)
	{
		for (short coord_y = 1; coord_y < N1 - 1; coord_y++)
		{
			Stc_arr_map[coord_y][coord_x].type = 0;
			Stc_arr_map[coord_y][coord_x].cross_tank = 1;
			Stc_arr_map[coord_y][coord_x].cross_bullet = 1;
			Stc_arr_map[coord_y][coord_x].show_tank = 1;
			Stc_arr_map[coord_y][coord_x].show_bullet = 1;
			Stc_arr_map[coord_y][coord_x].is_ignite = 1;
			Stc_arr_map[coord_y][coord_x].color = 0x0;
			strcpy_s(Stc_arr_map[coord_y][coord_x].image, 3,(char*)"  ");
			//Stc_arr_map[coord_y][coord_x].image = (char*)"  ";
			Stc_arr_map[coord_y][coord_x].hp = 127.0;
//			Stc_arr_map[coord_y][coord_x].time = init_map_time;

		}
	}

}


void map_editor::GetEffObstacle() {
	//重构有效障碍物数据
	eff_obstacle[N1-1][N2-1] = { 0 };
	for (short coord_x = 2; coord_x < 2 * N2 - 2; coord_x += 2)
	{
		for (short coord_y = 1; coord_y < N1 - 1; coord_y++)
		{
			if (Stc_arr_map[coord_y][coord_x / 2].type == 1
				|| Stc_arr_map[coord_y][coord_x / 2].type == 2
				|| Stc_arr_map[coord_y][coord_x / 2].type == 4)
			{
				eff_obstacle[coord_y][coord_x / 2] = 1;
				////派生障碍物
				////上下左右
				//eff_obstacle[coord_y + 1][coord_x / 2] = 1;
				//eff_obstacle[coord_y - 1][coord_x / 2] = 1;
				//eff_obstacle[coord_y][coord_x / 2 + 1] = 1;
				//eff_obstacle[coord_y][coord_x / 2 - 1] = 1;
				////四个对角
				//eff_obstacle[coord_y + 1][coord_x / 2 + 1] = 1;
				//eff_obstacle[coord_y - 1][coord_x / 2 - 1] = 1;
				//eff_obstacle[coord_y - 1][coord_x / 2 + 1] = 1;
				//eff_obstacle[coord_y + 1][coord_x / 2 - 1] = 1;
			}
			else
			{
				eff_obstacle[coord_y][coord_x / 2] = 0;
			}
		}
	}
}
void map_editor::element_set(short type,COORD coord) {

	switch (type)
	{
	case 0://road
	{
		Stc_arr_map[coord.Y][coord.X/2].type = 0;
		Stc_arr_map[coord.Y][coord.X/2].cross_tank = 1;
		Stc_arr_map[coord.Y][coord.X/2].cross_bullet = 1;
		Stc_arr_map[coord.Y][coord.X/2].show_tank = 1;
		Stc_arr_map[coord.Y][coord.X/2].show_bullet = 1;
		Stc_arr_map[coord.Y][coord.X/2].is_ignite = 0;
		Stc_arr_map[coord.Y][coord.X/2].color = 0x0;
		//Stc_arr_map[coord.Y][coord.X/2].color_temp = 0x0;
		strcpy_s(Stc_arr_map[coord.Y][coord.X/2].image, 3, (char*)"  ");
		//Stc_arr_map[coord.Y][coord.X/2].image = (char*)"  ";
		Stc_arr_map[coord.Y][coord.X/2].hp = 127.0;
	//	Stc_arr_map[coord.Y][coord.X/2].time = 0;
		Stc_arr_map[coord.Y][coord.X / 2].start_time = clock();
		Stc_arr_map[coord.Y][coord.X / 2].renew_speed = renew_road_speed;

	}
	break;
	case 1://iron
	{
		Stc_arr_map[coord.Y][coord.X/2].type = 1;
		Stc_arr_map[coord.Y][coord.X/2].cross_tank = 0;
		Stc_arr_map[coord.Y][coord.X/2].cross_bullet = 0;
		Stc_arr_map[coord.Y][coord.X/2].show_tank = 0;
		Stc_arr_map[coord.Y][coord.X/2].show_bullet = 0;
		Stc_arr_map[coord.Y][coord.X/2].is_ignite = 0;
		Stc_arr_map[coord.Y][coord.X/2].color = 0x06;
		//Stc_arr_map[coord.Y][coord.X/2].color_temp = 0x6;
		strcpy_s(Stc_arr_map[coord.Y][coord.X / 2].image ,3,"■");
		//Stc_arr_map[coord.Y][coord.X/2].image = (char*)"■";//"▂ ▃ ▄  ▆ ▇ █""卍"
		Stc_arr_map[coord.Y][coord.X/2].hp = 100.0;
	//	Stc_arr_map[coord.Y][coord.X/2].time = 0;
		Stc_arr_map[coord.Y][coord.X / 2].start_time = clock();
		Stc_arr_map[coord.Y][coord.X / 2].renew_speed =renew_iron_speed;
	}
	break;
	case 2://brick
	{
		Stc_arr_map[coord.Y][coord.X/2].type = 2;
		Stc_arr_map[coord.Y][coord.X/2].cross_tank = 0;
		Stc_arr_map[coord.Y][coord.X/2].cross_bullet = 0;
		Stc_arr_map[coord.Y][coord.X/2].show_tank = 0;
		Stc_arr_map[coord.Y][coord.X/2].show_bullet = 0;
		Stc_arr_map[coord.Y][coord.X/2].is_ignite = 0;
		Stc_arr_map[coord.Y][coord.X/2].color = 0x17;//57//17//37
		//Stc_arr_map[coord.Y][coord.X/2].color_temp = 0xE;
		strcpy_s(Stc_arr_map[coord.Y][coord.X / 2].image, 3, "卍");

		//Stc_arr_map[coord.Y][coord.X/2].image = (char*)"卍";// "▓"
		Stc_arr_map[coord.Y][coord.X/2].hp = 2.0;
	//	Stc_arr_map[coord.Y][coord.X/2].time = 0;
		Stc_arr_map[coord.Y][coord.X / 2].start_time = clock();
		Stc_arr_map[coord.Y][coord.X / 2].renew_speed = renew_brick_speed;
	}
	break;
	case 3://grass
	{
		Stc_arr_map[coord.Y][coord.X/2].type = 3;
		Stc_arr_map[coord.Y][coord.X/2].cross_tank = 1;
		Stc_arr_map[coord.Y][coord.X/2].cross_bullet = 1;
		Stc_arr_map[coord.Y][coord.X/2].show_tank = 0;
		Stc_arr_map[coord.Y][coord.X/2].show_bullet = 0;
		Stc_arr_map[coord.Y][coord.X/2].is_ignite = 1;
		Stc_arr_map[coord.Y][coord.X/2].color = 0x1A;
		//Stc_arr_map[coord.Y][coord.X/2].color_temp = 0xA;
		strcpy_s(Stc_arr_map[coord.Y][coord.X / 2].image, 3, "※");

		//Stc_arr_map[coord.Y][coord.X/2].image = (char*)"※";
		Stc_arr_map[coord.Y][coord.X/2].hp = 127.0;
	//	Stc_arr_map[coord.Y][coord.X/2].time = 0; 
		Stc_arr_map[coord.Y][coord.X / 2].start_time = clock();
		Stc_arr_map[coord.Y][coord.X / 2].renew_speed = renew_grass_speed;
	}
	break;
	case 4://river
	{
		Stc_arr_map[coord.Y][coord.X/2].type = 4;
		Stc_arr_map[coord.Y][coord.X/2].cross_tank = 0;
		Stc_arr_map[coord.Y][coord.X/2].cross_bullet = 1;
		Stc_arr_map[coord.Y][coord.X/2].show_tank = 0;
		Stc_arr_map[coord.Y][coord.X/2].show_bullet = 1;
		Stc_arr_map[coord.Y][coord.X/2].is_ignite = 0;
		Stc_arr_map[coord.Y][coord.X/2].color = 0x17;//97
		//Stc_arr_map[coord.Y][coord.X/2].color_temp = 0x1|0x7;
		strcpy_s(Stc_arr_map[coord.Y][coord.X / 2].image, 3, "≈");

		//Stc_arr_map[coord.Y][coord.X/2].image = (char*)"≈";//"■" 
		Stc_arr_map[coord.Y][coord.X/2].hp = 127.0;
	//	Stc_arr_map[coord.Y][coord.X/2].time = 0;
		Stc_arr_map[coord.Y][coord.X / 2].start_time = clock();
		Stc_arr_map[coord.Y][coord.X / 2].renew_speed = renew_river_speed;
	}
	break;
	default:
		break;
	}

}
//刷新自定义地图
void map_editor::map_renew() {
	for (short coord_x = 2; coord_x < 2*N2 - 2; coord_x+=2)
	{
		for (short coord_y = 1; coord_y < N1 - 1; coord_y++)
		{
			//Sleep(1);
			//墙自动刷新
			if (Stc_arr_map[coord_y][coord_x/2].hp <= 0)
			{
				Stc_arr_map[coord_y][coord_x / 2].type = 0;
				COORD pos = { coord_x ,coord_y };
				element_set(0,pos);
				WriteChar(coord_x, coord_y, Stc_arr_map[coord_y][coord_x / 2].image,
					1, Stc_arr_map[coord_y][coord_x / 2].color);

			}

			//for (int i = 1; i < 5 ;i++)
			//{
				if (Stc_arr_map[coord_y][coord_x / 2].type)
				{
					if (clock() - Stc_arr_map[coord_y][coord_x / 2].start_time > Stc_arr_map[coord_y][coord_x / 2].renew_speed)
					{
						Stc_arr_map[coord_y][coord_x / 2].start_time = clock();
						WriteChar(coord_x, coord_y, Stc_arr_map[coord_y][coord_x / 2].image,
							1, Stc_arr_map[coord_y][coord_x / 2].color);
					}
				}
			//}
		}
	}
}

//自定义地图的初始化显示
void map_editor::map_editor_init() {
	for (short coord_x = 2; coord_x < 2 * N2 - 2; coord_x += 2)
	{
		for (short coord_y = 1; coord_y < N1 - 1; coord_y++)
		{
			//if (Stc_arr_map[coord_y][coord_x / 2].type)
			//{
			//	Stc_arr_map[coord_y][coord_x / 2].start_time = clock();
			//	WriteChar(coord_x, coord_y, Stc_arr_map[coord_y][coord_x / 2].image,
			//		1, Stc_arr_map[coord_y][coord_x / 2].color);
			//}
			
			COORD pos = { coord_x ,coord_y };
			if (Stc_arr_map[coord_y][coord_x / 2].type)
			{
				//在不修改保存的文件情况下通过set修改地图显示效果
				element_set(Stc_arr_map[coord_y][coord_x / 2].type, pos);
				//Stc_arr_map[coord_y][coord_x / 2].start_time = clock();
				WriteChar(coord_x, coord_y, Stc_arr_map[coord_y][coord_x / 2].image,
					1, Stc_arr_map[coord_y][coord_x / 2].color);
			}
			else 
			{
				WriteChar(coord_x, coord_y, Stc_arr_map[coord_y][coord_x / 2].image,
					1, 0);
			}
		}
	}

}

//自定义地图的加载
void map_editor::map_load() {
	FILE* pfile_load;
	fopen_s(&pfile_load, path_save_map, "rb");
	for (short coord_x = 0; coord_x < N2 - 1; coord_x++)
	{
		for (short coord_y = 0; coord_y < N1 - 1; coord_y++)
		{
			fread_s(this->Stc_arr_map, (N1 - 1)*(N2 - 1)* sizeof(Stc_map_element),sizeof(Stc_map_element), (N1 - 1)*(N2 - 1),pfile_load);

		}
	}
	fclose(pfile_load);
}

//地图编辑移动和显示函数
void map_editor::editor_fun_move(map_editor&  obj,COORD& loc_editor, COORD& loc_editor_last, bool& flag, char& mode) {
	
	bool wipe_flag = 0;

	while (1)
		{

			if (flag)
			{
				break;
			}
			char dir = 0;
			if (_kbhit())
			{
				dir = _getch();
			}
			if (dir==UP||dir==DOWN||dir==LEFT||dir==RIGHT||
				dir==LEFT_UP||dir==RIGHT_UP||dir==LEFT_DOWN||dir==RIGHT_DOWN
				)
			{
				wipe_flag = 1;
			}
			if (wipe_flag)
			{
				WriteChar(loc_editor.X, loc_editor.Y, (char*)obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].image, 1,
					obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].color);
			}

			

			//存储当前坐标
			loc_editor_last = loc_editor;
			switch (dir)
			{
			case UP:
			{
				loc_editor.Y--;
			}
			break;
			case DOWN:
			{
				loc_editor.Y++;
			}
			break;
			case LEFT:
			{

				loc_editor.X -= 2;
			}
			break;
			case RIGHT:
			{
				loc_editor.X += 2;
			}
			break;
			case LEFT_UP: 
			{
				loc_editor.X -= 2;
				loc_editor.Y--;
			}

			break;
			case RIGHT_UP:
			{
				loc_editor.X += 2;
				loc_editor.Y--;
			}

			break;
			case LEFT_DOWN:
			{
				loc_editor.X -= 2;
				loc_editor.Y++;
			}

			break;
			case RIGHT_DOWN:
			{
				loc_editor.X += 2;
				loc_editor.Y++;
			}

			break;
			case '1':
			{
				flag = 1;
				mode = '1';
			}
			break;
			case '2':
			{
				flag = 1;
				mode = '2';
			}
			break;
			case '3':
			{
				flag = 1;
				mode = '3';
			}
			break;
			case '4':
			{
				flag = 1;
				mode = '4';
			}
			break;
			case '0':
			{
				flag = 1;
				mode = '0';
			}
			break;
			default:
				break;
			}
			if (editor_fun_collision_border(loc_editor))
			{
				loc_editor = loc_editor_last;
				
			}
			if (wipe_flag==1)
			{
				WriteChar(loc_editor.X, loc_editor.Y, (char*)"□", 1, 0x7);
				//ShowCursor(0);
				wipe_flag = 0;
			}
			

		}

}
void map_editor::editor_fun_type(map_editor&  obj, COORD& loc_editor,COORD& loc_editor_last, bool& flag, char& mode,short type) {

	obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].type = type;
	obj.element_set(obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].type, loc_editor);
	WriteChar(loc_editor.X, loc_editor.Y, 
		(char*)obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].image,
		1, obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].color);
	if (!type)
	{
		WriteChar(loc_editor.X, loc_editor.Y, (char*)"×", 1, 0xF);
	}
	bool print_flag = 0;//擦除开关
	while (1)
	{

		if (flag)
		{
			break;
		}
		char dir = 0;
		if (_kbhit())
		{
			dir = _getch();
		}
		if (dir == UP || dir == DOWN || dir == LEFT || dir == RIGHT ||
			dir == LEFT_UP || dir == RIGHT_UP || dir == LEFT_DOWN || dir == RIGHT_DOWN
			)
		{
			print_flag = 1;
		}

		loc_editor_last = loc_editor;

		//
		if (!type)
		{
			WriteChar(loc_editor.X, loc_editor.Y, (char*)"  ", 1, 0);
		}
		else
		{

		}

		//
		switch (dir) {
		case UP:
		{
				loc_editor.Y--;
		}
		break;
		case DOWN:
		{
				loc_editor.Y++;
		}
		break;
		case LEFT:
		{
				loc_editor.X -= 2;
		}
		break;
		case RIGHT:
		{
			loc_editor.X += 2;
		}
		break;
		case LEFT_UP:
		{

			loc_editor.X -= 2;
			loc_editor.Y--;
		}
			break;
		case RIGHT_UP:
		{
				loc_editor.X += 2;
				loc_editor.Y--;
		}
		break;
		case LEFT_DOWN:
		{
				loc_editor.X -= 2;
				loc_editor.Y++;
		}
		break;
		case RIGHT_DOWN:
		{

				loc_editor.X += 2;
				loc_editor.Y++;

		}
		break;
		case '1':
		{
			flag = 1;
		}
		break;
		case '2':
		{
			flag = 1;
		}
		break;
		case '3':
		{
			flag = 1;
		}
		break;
		case '4':
		{
			flag = 1;
		}
		break;
		case '0':
		{
			flag = 1;
		}
		break;
		default:
			break;
		}
		//判断是否和边界冲突
		if (editor_fun_collision_border(loc_editor))
		{
			loc_editor = loc_editor_last;
		}

		if (print_flag)
		{
			//改写点对应的属性
			obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].type = type;
			obj.element_set(obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].type, loc_editor);

			//分别打印移动后的图案
			if (!type)
			{
				WriteChar(loc_editor.X, loc_editor.Y, (char*)"×", 1, 0xF);
			}
			else
			{
				WriteChar(loc_editor.X, loc_editor.Y,
					(char*)obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].image,
					1, obj.Stc_arr_map[loc_editor.Y][loc_editor.X / 2].color);
			}
			print_flag = 0;
		}

		

		
	}
}

bool map_editor::editor_fun_collision_border(COORD loc) {
	if (loc.X <= 0 || loc.X >= 138 || loc.Y <= 0 || loc.Y >= 44)
	{
		return 1;
	}
	else
	{
		return 0;
	}

}




//C_customize_map成员函数

//C_customize_map::C_customize_map() {
//	p_unit = new COORD{ 0,0 };
//}
//C_customize_map::~C_customize_map() {
//	delete p_unit;
//	p_unit = nullptr;
//}
//void C_customize_map::make_map() {
//	map_border();
//	show_map_border();
//	cls_news();
//	WriteChar(2, N1 + 2, (char*)"按方向键显示并控制光标 ", 1, 3);
//	WriteChar(2, N1 + 3, (char*)"按b开始选定区域，按e结束选定区域 ", 1, 3);
//	WriteChar(2, N1 + 4, (char*)"按q结束编辑自动保存退出", 1, 3);

	//		C_map::show_map();
			//C_food obj;
			//obj.set_food();
			//obj.show_food();

	//FILE* pfile_eXport;
	//fopen_s(&pfile_eXport, path_eXport, "a+");
	//char dir = 0;
	//while (1) {
	//	dir = _getch();
	//	if (dir != 'q') {
	//		if (dir == 'b') {
	//			char paint = 0;
	//			do {
	//				paint = _getch();
	//				PCOORD p_XY = crawl(paint, 1);
	//				fprintf(pfile_eXport, "\n%d,%d", p_XY->X, p_XY->Y);
	//			} while (paint != 'e');
	//		}
	//		Show_cursor(1);
	//		crawl(dir, 3);
	//	}
	//	else {
	//		break;
	//	}
	//}
	//fclose(pfile_eXport);
	//cls_news();
	//WriteChar(2, N1 + 2, (char*)"地图1保存成功！ ", 1, 3);
//}

//int C_customize_map::count(char* path) {
//	//	printf("%d",this->a);
//	FILE *pfile_read;
//	fopen_s(&pfile_read, path, "r");
//
//	int if_move_end = fseek(pfile_read, 0X00L, SEEK_END);
//	int total_size = ftell(pfile_read);
//	//	printf("总长度%d ", total_size);
//	int if_move_set = fseek(pfile_read, 0X00L, SEEK_SET);
//	int sum = 0, location = 0;
//
//	while ((total_size - location) > 0)
//	{
//		fscanf_s(pfile_read, "%hd,%hd", &p_unit->X, &p_unit->Y);
//		sum++;
//		location = ftell(pfile_read);
//	}
//	fclose(pfile_read);
//	return sum;
//}
//PCOORD C_customize_map::load_map(int num, char*path) {
//	//定义结构体数组
//	PCOORD PCOORD_arr = new COORD[num];
//
//	FILE *pfile_load;
//	fopen_s(&pfile_load, path, "r");
//
//	for (int i = 0; i < num; i++)
//	{
//		fscanf_s(pfile_load, "%hd,%hd", &(PCOORD_arr + i)->X, &(PCOORD_arr + i)->Y);
//	}
//	fclose(pfile_load);
//	return PCOORD_arr;
//}
//void C_customize_map::make_show_map(PCOORD PCOORD, int num) {
//	for (int i = 0; i < num; i++)
//	{
//		WriteChar((PCOORD + i)->X, (PCOORD + i)->Y, (char*)"■", 1, 0X3);
//		Sleep(make_show_map_speed);
//	}
//	cls_news();
//	if (g_map_state != 10)
//	{
//		WriteChar(2, N1 + 2, (char*)"地图已加载 ", 1, 0XA);
//	}
//
//}

//void C_customize_map::make_wipe_map(PCOORD PCOORD, int num) {
//	for (int i = 0; i < num; i++)
//	{
//		WriteChar((PCOORD + i)->X, (PCOORD + i)->Y, (char*)"  ", 1, 3);
//		Sleep(0);
//	}
//	cls_news();
//	if (g_map_state == 11)
//	{
//		WriteChar(2, N1 + 2, (char*)"地图已取消 ", 1, 0XA);
//	}
//	else
//	{
//		//	WriteChar(2, N1 + 2, (char*)"地图已取消 ", 1, 0XA);
//	}
//
//}
