#include "bullet.h"
#include "show.h"


short bullet::count_AI = 0;
short bullet::count_player = 0;
bullet::bullet(short party) {
	if (party==1)
	{
		id_player = ++count_player;
	}
	else if(party==-1)
	{
		id_AI = --count_AI;
	}
	else
	{
		printf("error!!!");
	}

	
	
	state = 1;
	style_set();
}
bullet::bullet() {  }

void bullet::style_set() {
	//单发
	bullet_conf[0].type = 11;
	bullet_conf[0].color = 0xC;
	bullet_conf[0].image = (char*)"〇"; 
	bullet_conf[0].max_length = 25;
	bullet_conf[0].power = 1.5;
	bullet_conf[0].speed = 150;
	bullet_conf[0].function = 0;
	bullet_conf[0].hp = 1;
	//bullet_conf[0].hp[1] = 0;
	//双发
	bullet_conf[1].type = 12;
	bullet_conf[1].color = 0xE;
	bullet_conf[1].image = (char*)"⊕"; 
	bullet_conf[1].max_length = 25;
	bullet_conf[1].power = 1;
	bullet_conf[1].speed = 120;
	bullet_conf[1].function = 0;
	bullet_conf[1].hp = 1;
	bullet_conf[1].hp2 = 1;
	//重炮
	bullet_conf[2].type = 13;
	bullet_conf[2].color = 0x9;
	bullet_conf[2].image = (char*)"●";
	bullet_conf[2].max_length = 20;
	bullet_conf[2].power = 2;
	bullet_conf[2].speed = 150;
	bullet_conf[2].function = 1;//后推
	bullet_conf[2].hp = 1;
	//bullet_conf[2].hp[1] = 0;
	//高射
	bullet_conf[3].type = 14;
	bullet_conf[3].color = 0xC;//黄色
	bullet_conf[3].image = (char*)"⊙";
	bullet_conf[3].max_length = 30;
	bullet_conf[3].power = 1;
	bullet_conf[3].speed = 50;
	bullet_conf[3].function = 2;//远程AOE
	bullet_conf[3].hp = 1;
//	bullet_conf[3].hp[1] = 0;
	//火炮
	bullet_conf[4].type = 15;
	bullet_conf[4].color = 0x4;
	bullet_conf[4].image = (char*)"●";
	bullet_conf[4].max_length = 25;
	bullet_conf[4].power = 1;
	bullet_conf[4].speed = 100;
	bullet_conf[4].function = 3;//灼烧
	bullet_conf[4].hp = 1;
//	bullet_conf[4].hp[1] = 0;

}

//传入子弹配置参数，分离每颗子弹的配置
void bullet::bullet_draw() {
	switch (dir)
	{
	case UP:
	{
		if (type != 1)
		{
			if (state)
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].Y--;
				//origin[1] = origin[0];
			}

		}
		else
		{
			switch (state)
			{
			//case 0:
			//{}
			//break;
			case -1:
			{
				//WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				//origin[0].Y--;
				origin[1].Y--;
			}
			break;
			case -2:
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				//WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].Y--;
				//origin[1].Y--;
			}
			break;
			case 1:
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].Y--;
				origin[1].Y--;
			}
			break;
			default:
				break;
			}

		}
		bullet_conf[type].max_length--;

	}
	break;
	case DOWN:
	{
		if (type != 1)
		{
			if (state)
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].Y++;
				//origin[1] = origin[0];
			}

		}
		else
		{
			switch (state)
			{
			//case 0:
			//{}
			//break;
			case -1:
			{
				//WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				//origin[0].Y--;
				origin[1].Y++;
			}
			break;
			case -2:
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				//WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].Y++;
				//origin[1].Y--;
			}
			break;
			case 1:
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].Y++;
				origin[1].Y++;
			}
			break;
			default:
				break;
			}
		}
		bullet_conf[type].max_length--;


	}
	break;
	case LEFT:
	{
		if (type != 1)
		{
			if (state)
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].X -= 2;
				//origin[1] = origin[0];
			}

		}
		else
		{
			switch (state)
			{
			//case 0:
			//{}
			//break;
			case -1:
			{
				//WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				//origin[0].Y--;
				origin[1].X-=2;
			}
			break;
			case -2:
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				//WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].X-=2;
				//origin[1].Y--;
			}
			break;
			case 1:
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].X-=2;
				origin[1].X-=2;
			}
			break;
			default:
				break;
			}
		}
		bullet_conf[type].max_length--;


	}
	break;
	case RIGHT:
	{
		if (type != 1)
		{
			if (state)
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].X += 2;
				//origin[1] = origin[0];
			}

		}
		else
		{
			switch (state)
			{
			//case 0:
			//{}
			//break;
			case -1:
			{
				//WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				//origin[0].Y--;
				origin[1].X+=2;
			}
			break;
			case -2:
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				//WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].X+=2;
				//origin[1].Y--;
			}
			break;
			case 1:
			{
				WriteChar(origin[0].X, origin[0].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y, bullet_conf[type].image, 1, bullet_conf[type].color);
				origin[0].X+=2;
				origin[1].X+=2;
			}
			break;
			default:
				break;
			}
		}
		bullet_conf[type].max_length--;

	}
	break;
	default:
		break;
	}
}

void bullet::bullet_wipe() {
	switch (dir)
	{
	case UP:
	{
		if (type != 1)
		{
				WriteChar(origin[0].X, origin[0].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
		}
		else
		{
			switch (state) {
			case 1:
			{
				WriteChar(origin[0].X, origin[0].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case -1:
			{
				//WriteChar(origin[0].X, origin[0].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case -2:
			{
				WriteChar(origin[0].X, origin[0].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
				//WriteChar(origin[1].X, origin[1].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case 0:
			{
				WriteChar(origin[0].X, origin[0].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y + 1, (char*)"  ", 1, bullet_conf[type].color);
			}
			default:
				break;
			}

		}
	}
	break;
	case DOWN:
	{
		if (type != 1)
		{
			WriteChar(origin[0].X, origin[0].Y-1, (char*)"  ", 1, bullet_conf[type].color);
		}
		else
		{
			switch (state) {
			case 1:
			{
				WriteChar(origin[0].X, origin[0].Y - 1, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y - 1, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case -1:
			{
				//WriteChar(origin[0].X, origin[0].Y-1, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y - 1, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case -2:
			{
				WriteChar(origin[0].X, origin[0].Y - 1, (char*)"  ", 1, bullet_conf[type].color);
				//WriteChar(origin[1].X, origin[1].Y-1, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case 0:
			{
				WriteChar(origin[0].X, origin[0].Y - 1, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X, origin[1].Y - 1, (char*)"  ", 1, bullet_conf[type].color);
			}
			default:
				break;
			}

		}
	}
	break;
	case LEFT:
	{
		if (type != 1)
		{
			WriteChar(origin[0].X + 2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
		}
		else
		{
			switch (state) {
			case 1:
			{
				WriteChar(origin[0].X + 2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X + 2, origin[1].Y, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case -1:
			{
				//WriteChar(origin[0].X + 2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X + 2, origin[1].Y, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case -2:
			{
				WriteChar(origin[0].X + 2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
				//WriteChar(origin[1].X + 2, origin[1].Y, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case 0:
			{
				WriteChar(origin[0].X+2, origin[0].Y , (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X+2, origin[1].Y , (char*)"  ", 1, bullet_conf[type].color);
			}
			default:
				break;
			}
		}
	}
	break;
	case RIGHT:
	{
		if (type != 1)
		{
			WriteChar(origin[0].X - 2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
		}
		else
		{
			switch (state) {
			case 1:
			{
				WriteChar(origin[0].X - 2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X - 2, origin[1].Y, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case -1:
			{
				//WriteChar(origin[0].X - 2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X - 2, origin[1].Y, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case -2:
			{
				WriteChar(origin[0].X - 2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
				//WriteChar(origin[1].X - 2, origin[1].Y, (char*)"  ", 1, bullet_conf[type].color);
			}
			break;
			case 0:
			{
				WriteChar(origin[0].X-2, origin[0].Y, (char*)"  ", 1, bullet_conf[type].color);
				WriteChar(origin[1].X-2, origin[1].Y, (char*)"  ", 1, bullet_conf[type].color);
			}
			default:
				break;
			}
		}
	}
	break;
	default:
		break;
	}

}


//子弹和边界碰撞
void bullet::BulletBorder() {
	if (type!=1)
	{
		if (origin[0].X == 0 || origin[0].X == 138 || origin[0].Y == 0 || origin[0].Y == 44)
		{
			state = 0;
		}
		//state = 1;

	}
	else
	{
		switch (state) {
		case -1:
		{
			if (origin[1].X == 0 || origin[1].X == 138 || origin[1].Y == 0 || origin[1].Y == 44)
			{
				state = 0;
			}
		
		}
		break;
		case -2:
		{
			if (origin[0].X == 0 || origin[0].X == 138 || origin[0].Y == 0 || origin[0].Y == 44)
			{
				state = 0;
			}
		}
		break;
		case 1:
		{
			if ((origin[0].X == 0 || origin[0].X == 138 || origin[0].Y == 0 || origin[0].Y == 44) &&
				(origin[1].X == 0 || origin[1].X == 138 || origin[1].Y == 0 || origin[1].Y == 44))
			{
				state = 0;
			}
			else if ((origin[0].X == 0 || origin[0].X == 138 || origin[0].Y == 0 || origin[0].Y == 44) &&
				!(origin[1].X == 0 || origin[1].X == 138 || origin[1].Y == 0 || origin[1].Y == 44))
			{
				state = -1;
			}
			else if (!(origin[0].X == 0 || origin[0].X == 138 || origin[0].Y == 0 || origin[0].Y == 44) &&
				(origin[1].X == 0 || origin[1].X == 138 || origin[1].Y == 0 || origin[1].Y == 44))
			{
				state = -2;
			}
			else
			{
				state = 1;
			}
		}
		break;
		case 0:
		{}
		break;
		}



	}

	
}

//子弹和地图碰撞
void bullet::BulletMap() {

	if (type != 1)//非双发
	{
		if (state)
		{
			if (g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].cross_bullet == 0)
			{
				//if (g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].type == 1 ||
				//	g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].type == 2)

				g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].hp-=
					bullet_conf[type].power;
				state = 0;
			}
		}
	}
	else //双发
	{//设置变量
		switch (state) {
		case -1:
		{
			if (g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].cross_bullet == 0)
			{
				g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].hp-= 
					bullet_conf[type].power;
				state = 0;
			}
		}
		break;
		case -2:
		{
			if (g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].cross_bullet == 0)
			{
				g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].hp-=
					bullet_conf[type].power;
				state = 0;
			}
		}
		break;
		case 1:
		{
			if (g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].cross_bullet == 0 &&
				g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].cross_bullet == 0)
			{
				//if ((g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].type == 1 ||
				//	g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].type == 2)&&
				//	(g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].type == 1 ||
				//		g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].type == 2))
				//{
				g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].hp-=
					bullet_conf[type].power;
				g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].hp-= 
					bullet_conf[type].power;
				//}
				//bullet_double_flag = 1;
				state = 0;
				//同时碰撞
			}
			else if (g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].cross_bullet == 0 &&
				g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].cross_bullet != 0)
			{
				//if (g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].type == 1 ||
				   //g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].type == 2)
				{
					g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].hp-=
						bullet_conf[type].power;

				}
				state = -1;
				//左边碰撞

			}
			else if (g_obj_map_buffer.Stc_arr_map[origin[0].Y][origin[0].X / 2].cross_bullet != 0 &&
				g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].cross_bullet == 0)
			{
				//if (g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].type == 1 ||
				   //g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].type == 2)
				{
					g_obj_map_buffer.Stc_arr_map[origin[1].Y][origin[1].X / 2].hp-=
						bullet_conf[type].power;
				}
				state = -2;
				//右边碰撞
			}
			else
			{
				state = 1;
				//都没碰撞
			}
		}
		break;
		case 0:
		{}
		break;
		}



		

	}

}
