#include "tank.h"
#include "show.h"

extern vector<tank_player1>g_v_tanks_player;
extern vector<tank_AI>g_v_tanks_AI;

template<typename T1,typename T2>
bool compare_sign(T1 data1,T2 data2) {
	if ((data1>0&&data2>0)||(data1<0&&data2<0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<typename T1,typename T2,typename T3>
bool CheckBetween(T1 data1, T2 data2,T3 checkdata){
	//if ((data1-checkdata)*(data2- checkdata) <=0)
	//{
	//	return 1;
	//}	
	if ((checkdata>=data1&&checkdata<=data2)||(checkdata>=data2&&checkdata<=data1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


bool(*tank_info::p)[4][9]=new bool[8][4][9];


//����������
tank_info::tank_info(){	//:design(new char[3]) 
	Fires = 0;
	//design = new char[3];
	//strcpy_s(design, 3, (const char*)"��");
	shape_tank();
};

//���ƹ���
tank_info::tank_info(const tank_info& obj) {
	Fires = obj.Fires;
	//design = new char[3];
	//strcpy_s(design, 3, (char*)obj.design);
}
//tank_info::~tank_info() {
//	delete []design;
//	design = nullptr;
//}


//������״
//p[mode][dir][body]
void tank_info::shape_tank()
{

	//0//����
	p[0][0][0] = 1;
	p[0][0][1] = 1;
	p[0][0][2] = 1;
	p[0][0][3] = 1;
	p[0][0][4] = 1;
	p[0][0][5] = 1;
	p[0][0][6] = 1;
	p[0][0][7] = 1;
	p[0][0][8] = 1;

	// 1://����ģʽ
//up
	p[1][0][0] = 0;
	p[1][0][1] = 1;
	p[1][0][2] = 0;
	p[1][0][3] = 1;
	p[1][0][4] = 1;
	p[1][0][5] = 1;
	p[1][0][6] = 1;
	p[1][0][7] = 0;
	p[1][0][8] = 1;
	//down
	p[1][1][0] = 1;
	p[1][1][1] = 0;
	p[1][1][2] = 1;
	p[1][1][3] = 1;
	p[1][1][4] = 1;
	p[1][1][5] = 1;
	p[1][1][6] = 0;
	p[1][1][7] = 1;
	p[1][1][8] = 0;
	//left
	p[1][2][0] = 0;
	p[1][2][1] = 1;
	p[1][2][2] = 1;
	p[1][2][3] = 1;
	p[1][2][4] = 1;
	p[1][2][5] = 0;
	p[1][2][6] = 0;
	p[1][2][7] = 1;
	p[1][2][8] = 1;
	//right
	p[1][3][0] = 1;
	p[1][3][1] = 1;
	p[1][3][2] = 0;
	p[1][3][3] = 0;
	p[1][3][4] = 1;
	p[1][3][5] = 1;
	p[1][3][6] = 1;
	p[1][3][7] = 1;
	p[1][3][8] = 0;

	// 2://˫��ģʽ
	//up
	p[2][0][0] = 1;
	p[2][0][1] = 0;
	p[2][0][2] = 1;
	p[2][0][3] = 0;
	p[2][0][4] = 1;
	p[2][0][5] = 0;
	p[2][0][6] = 1;
	p[2][0][7] = 1;
	p[2][0][8] = 1;
	//down
	p[2][1][0] = 1;
	p[2][1][1] = 1;
	p[2][1][2] = 1;
	p[2][1][3] = 0;
	p[2][1][4] = 1;
	p[2][1][5] = 0;
	p[2][1][6] = 1;
	p[2][1][7] = 0;
	p[2][1][8] = 1;
	//left
	p[2][2][0] = 1;
	p[2][2][1] = 0;
	p[2][2][2] = 1;
	p[2][2][3] = 0;
	p[2][2][4] = 1;
	p[2][2][5] = 1;
	p[2][2][6] = 1;
	p[2][2][7] = 0;
	p[2][2][8] = 1;
	//right
	p[2][3][0] = 1;
	p[2][3][1] = 0;
	p[2][3][2] = 1;
	p[2][3][3] = 1;
	p[2][3][4] = 1;
	p[2][3][5] = 0;
	p[2][3][6] = 1;
	p[2][3][7] = 0;
	p[2][3][8] = 1;


	//3: {//����ģʽ
//up
	p[3][0][0] = 0;
	p[3][0][1] = 1;
	p[3][0][2] = 0;
	p[3][0][3] = 1;
	p[3][0][4] = 1;
	p[3][0][5] = 1;
	p[3][0][6] = 1;
	p[3][0][7] = 1;
	p[3][0][8] = 1;

	//down
	p[3][1][0] = 1;
	p[3][1][1] = 1;
	p[3][1][2] = 1;
	p[3][1][3] = 1;
	p[3][1][4] = 1;
	p[3][1][5] = 1;
	p[3][1][6] = 0;
	p[3][1][7] = 1;
	p[3][1][8] = 0;
	//left
	p[3][2][0] = 0;
	p[3][2][1] = 1;
	p[3][2][2] = 1;
	p[3][2][3] = 1;
	p[3][2][4] = 1;
	p[3][2][5] = 1;
	p[3][2][6] = 0;
	p[3][2][7] = 1;
	p[3][2][8] = 1;
	//right
	p[3][3][0] = 1;
	p[3][3][1] = 1;
	p[3][3][2] = 0;
	p[3][3][3] = 1;
	p[3][3][4] = 1;
	p[3][3][5] = 1;
	p[3][3][6] = 1;
	p[3][3][7] = 1;
	p[3][3][8] = 0;

	//4://����ģʽ
//up
	p[4][0][0] = 0;
	p[4][0][1] = 1;
	p[4][0][2] = 0;
	p[4][0][3] = 0;
	p[4][0][4] = 1;
	p[4][0][5] = 0;
	p[4][0][6] = 1;
	p[4][0][7] = 1;
	p[4][0][8] = 1;
	//down
	p[4][1][0] = 1;
	p[4][1][1] = 1;
	p[4][1][2] = 1;
	p[4][1][3] = 0;
	p[4][1][4] = 1;
	p[4][1][5] = 0;
	p[4][1][6] = 0;
	p[4][1][7] = 1;
	p[4][1][8] = 0;
	//left
	p[4][2][0] = 0;
	p[4][2][1] = 0;
	p[4][2][2] = 1;
	p[4][2][3] = 1;
	p[4][2][4] = 1;
	p[4][2][5] = 1;
	p[4][2][6] = 0;
	p[4][2][7] = 0;
	p[4][2][8] = 1;

	//right
	p[4][3][0] = 1;
	p[4][3][1] = 0;
	p[4][3][2] = 0;
	p[4][3][3] = 1;
	p[4][3][4] = 1;
	p[4][3][5] = 1;
	p[4][3][6] = 1;
	p[4][3][7] = 0;
	p[4][3][8] = 0;

	// 5://����

	p[5][0][0] = 0;
	p[5][0][1] = 1;
	p[5][0][2] = 0;
	p[5][0][3] = 0;
	p[5][0][4] = 1;
	p[5][0][5] = 0;
	p[5][0][6] = 1;
	p[5][0][7] = 0;
	p[5][0][8] = 1;

	//down
	p[5][1][0] = 1;
	p[5][1][1] = 0;
	p[5][1][2] = 1;
	p[5][1][3] = 0;
	p[5][1][4] = 1;
	p[5][1][5] = 0;
	p[5][1][6] = 0;
	p[5][1][7] = 1;
	p[5][1][8] = 0;

	//left
	p[5][2][0] = 0;
	p[5][2][1] = 0;
	p[5][2][2] = 1;
	p[5][2][3] = 1;
	p[5][2][4] = 1;
	p[5][2][5] = 0;
	p[5][2][6] = 0;
	p[5][2][7] = 0;
	p[5][2][8] = 1;
	//right
	p[5][3][0] = 1;
	p[5][3][1] = 0;
	p[5][3][2] = 0;
	p[5][3][3] = 0;
	p[5][3][4] = 1;
	p[5][3][5] = 1;
	p[5][3][6] = 1;
	p[5][3][7] = 0;
	p[5][3][8] = 0;


}
//����ڿ�
PCOORD tank_info::get_muzzzle() {

	switch (dir)
	{
	case UP:
	{
		if (mode != 2)
		{
			muzzle_pos[0].X = pos.X;
			muzzle_pos[0].Y = pos.Y - 2;
		}
		else
		{
			muzzle_pos[0].X = pos.X - 2;
			muzzle_pos[0].Y = pos.Y - 2;
			muzzle_pos[1].X = pos.X + 2;
			muzzle_pos[1].Y = pos.Y - 2;
		}

	}
	break;
	case DOWN:
	{
		if (mode != 2)
		{
			muzzle_pos[0].X = pos.X;
			muzzle_pos[0].Y = pos.Y + 2;
		}
		else
		{
			muzzle_pos[0].X = pos.X + 2;
			muzzle_pos[0].Y = pos.Y + 2;
			muzzle_pos[1].X = pos.X - 2;
			muzzle_pos[1].Y = pos.Y + 2;
		}
	}
	break;
	case LEFT:
	{
		if (mode != 2)
		{
			muzzle_pos[0].X = pos.X - 4;
			muzzle_pos[0].Y = pos.Y;
		}
		else
		{
			muzzle_pos[0].X = pos.X - 4;
			muzzle_pos[0].Y = pos.Y + 1;
			muzzle_pos[1].X = pos.X - 4;
			muzzle_pos[1].Y = pos.Y - 1;
		}
	}
	break;
	case RIGHT:
	{
		if (mode != 2)
		{
			muzzle_pos[0].X = pos.X + 4;
			muzzle_pos[0].Y = pos.Y;
		}
		else
		{
			muzzle_pos[0].X = pos.X + 4;
			muzzle_pos[0].Y = pos.Y - 1;
			muzzle_pos[1].X = pos.X + 4;
			muzzle_pos[1].Y = pos.Y + 1;
		}
	}
	break;
	default:
		break;
	}
	return muzzle_pos;
}

//����
void tank_info::wipe_tank() {
	for (short i = 0; i < 9; i++)
	{
		COORD offset = { 0,0 };
		char ndir = -1;
		switch (dir)
		{
		case UP:
			ndir = 0; break;
		case DOWN:
			ndir = 1; break;
		case LEFT:
			ndir = 2; break;
		case RIGHT:
			ndir = 3; break;
		default:
			break;
		}
		if (p[mode][ndir][i])
		{
			switch (i)
			{
			case 0:
			{offset.X = -2, offset.Y = -1; }
			break;
			case 1:
			{offset.X = 0, offset.Y = -1; }
			break;
			case 2:
			{offset.X = +2, offset.Y = -1; }
			break;
			case 3:
			{offset.X = -2, offset.Y = 0; }
			break;
			case 4:
			{offset.X = 0, offset.Y = 0; }
			break;
			case 5:
			{offset.X = +2, offset.Y = 0; }
			break;
			case 6:
			{offset.X = -2, offset.Y = +1; }
			break;
			case 7:
			{offset.X = 0, offset.Y = +1; }
			break;
			case 8:
			{offset.X = +2, offset.Y = +1; }
			break;
			}
			WriteChar(pos.X + offset.X, pos.Y + offset.Y, (char*)"��", 2, color);
		}

	}
}

//�ƶ����괦��
void tank_info::move_tank(char direc) {
	wipe_tank();
	last_mode = mode;
	last_dir = dir;
	last_pos = pos;

	dir = direc;
	if (last_dir == dir)
	{
		switch (dir)
		{
		case UP:
		{
			pos.Y--;
		}
		break;
		case DOWN:
		{
			pos.Y++;
		}
		break;
		case LEFT:
		{
			pos.X -= 2;
		}
		break;
		case RIGHT:
		{
			pos.X += 2;
		}
		break;
		default:
			break;
		}
	}
}
//�������괦��
void tank_info::back_tank() {
	wipe_tank();
	last_mode = mode;
	last_dir = dir;
	last_pos = pos;


	switch (dir)
	{
	case UP:
	{
		pos.Y++;
	}
	break;
	case DOWN:
	{
		pos.Y--;
	}
	break;
	case LEFT:
	{
		pos.X += 2;
	}
	break;
	case RIGHT:
	{
		pos.X -= 2;
	}
	break;
	default:
		break;
	}
}
//��ʷ��¼����
//void tank_info::history_tank() {
//	history_info stc_history;
//	stc_history.mode = mode;
//	stc_history.dir = dir;
//	stc_history.pos = pos;
//	v_history_tank.push_back(stc_history);
//
//
//	if (v_history_tank.size() > MAX_tank_history)
//	{
//		vector<history_info>::iterator it = v_history_tank.begin();
//		v_history_tank.erase(it);
//	}
//
//	flag_back = 0;
//}

//����
void tank_info::draw_tank() {
	for (short i = 0; i < 9; i++)
	{
		COORD offset = { 0,0 };
		char ndir = -1;
		switch (dir)
		{
		case UP:
			ndir = 0; break;
		case DOWN:
			ndir = 1; break;
		case LEFT:
			ndir = 2; break;
		case RIGHT:
			ndir = 3; break;
		default:
			break;
		}
		if (p[mode][ndir][i])
		{
			switch (i)
			{
			case 0:
			{offset.X = -2, offset.Y = -1; }
			break;
			case 1:
			{offset.X = 0, offset.Y = -1; }
			break;
			case 2:
			{offset.X = +2, offset.Y = -1; }
			break;
			case 3:
			{offset.X = -2, offset.Y = 0; }
			break;
			case 4:
			{offset.X = 0, offset.Y = 0; }
			break;
			case 5:
			{offset.X = +2, offset.Y = 0; }
			break;
			case 6:
			{offset.X = -2, offset.Y = +1; }
			break;
			case 7:
			{offset.X = 0, offset.Y = +1; }
			break;
			case 8:
			{offset.X = +2, offset.Y = +1; }
			break;
			}
			WriteChar(pos.X + offset.X, pos.Y + offset.Y, (char*)"��", 1, color);

		}

	}
}



//̹�˱߽���ײ���
char tank_info::collision_TankBorder() {
	short x = pos.X;
	short y = pos.Y;
	if (x<=2||x>=2*(N2-2)||
		y<=1||y>=N1-2)
	{
		return 1;
	}
	return 0;
}

/*����1 ��ײ���
* ����-1 ��ײAI
* ����0 ����ײ
*/
//̹��֮����ײ���

char tank_info::collision_TankInter() {
	for (auto it = g_v_tanks_player.begin(); it != g_v_tanks_player.end(); it++)
	{
		if (it->id==id)//�ų��Լ�
		{
			//printf("yyyyy");

			continue;
		}
		int DifX = abs(pos.X - it->pos.X);
		int DifY = abs(pos.Y - it->pos.Y);
		if (DifX <= 4 && DifY <= 2)
		{
			//printf("xxxxxxxxxx");
			return 1;
		}

	}
	for (auto it = g_v_tanks_AI.begin(); it != g_v_tanks_AI.end(); it++)
	{
		if (it->id == id)//�ų��Լ�
		{
			continue;

		}
		int DifX = abs(pos.X - it->pos.X);
		int DifY = abs(pos.Y - it->pos.Y);
		if (DifX <= 4 && DifY <= 2)
		{
			return -1;
		}
	}
	return 0;
}

//̹�˵�ͼ��ײ���
char tank_info::collision_TankMap() {
	for (int i = -1; i <=1; i++)
	{
		for (int j = -1; j <=1; j++)
		{
			if (g_obj_map_buffer.eff_obstacle[pos.Y + j][pos.X / 2 + i])
			{
				return 1;
			}
		}
	}
	return 0;
}

void tank_info::execute(char signal) {
	//printf("%d",signal);

	if (signal)//ȷ����ײ
	{
		if (pos.X != last_pos.X || pos.Y != last_pos.Y)
		{
			pos = last_pos;
			//obj_player.dir = obj_player.last_dir;

		}
		else 	if (dir != last_dir)
		{
			//obj_player.pos = obj_player.last_pos;
			dir = last_dir;

		}
		else
		{
			mode = last_mode;

		}

	}
	draw_tank();
}

//��ȡ����
unsigned int tank_info::GetDistance(COORD pos_dst) {
	unsigned int x = abs(pos.X-pos_dst.X)/2;
	unsigned int y = abs(pos.Y-pos_dst.Y);
	distance = x + y;
	return x + y;
}

//��ȡ��λ
double tank_info::GetAngle(COORD pos_dst) {
	 DifX = (pos_dst.X-2 -pos.X);
	 DifY = (pos_dst.Y-pos.Y);
	if (DifY==0)
	{
		angle = 999.9;
	}
	else
	{
		angle = fabs((double)DifX / DifY);
	}
	DifX2 = (pos_dst.X+2 - pos.X);
	DifY2 = (pos_dst.Y - pos.Y);
	if (DifY2 == 0)
	{
		angle2 = 999.9;
	}
	else
	{
		angle2 = fabs((double)DifX2 / DifY2);
	}
	DifX_cent = (pos_dst.X - pos.X);
	DifY_cent = (pos_dst.Y - pos.Y);
	return angle;
}
//����ͼ�Ƿ��ڵ�Ŀ��
bool tank_info::CheckMapBlock() {
	for (short coord_x = 2; coord_x < 2 * N2 - 2; coord_x += 2)
	{
		for (short coord_y = 1; coord_y < N1 - 1; coord_y++)
		{
			if (g_obj_map_buffer.Stc_arr_map[coord_y][coord_x / 2].type == 1
				|| g_obj_map_buffer.Stc_arr_map[coord_y][coord_x / 2].type ==2
				|| g_obj_map_buffer.Stc_arr_map[coord_y][coord_x / 2].type == 3
				)
			{
				double Difx = (double)(coord_x - pos.X);
				double Dify = (double)(coord_y - pos.Y);
				double AngelMap_AI=0.0;
				if (Dify == 0.0)
				{
					AngelMap_AI= 999.9;
				}
				else
				{
					AngelMap_AI= fabs(Difx / Dify);
				}
				
				//if (CheckBetween(angle, angle2, AngelMap_AI))
				//{
				//	printf("%lf,%lf ,%lf", angle, angle2, AngelMap_AI );
				//}
				if (
					//ͬ��
					(compare_sign(DifX,Difx)&& compare_sign(DifY,Dify)&&
					compare_sign(DifX2, Difx) && compare_sign(DifY2, Dify) && compare_sign(DifX_cent, Difx)&& compare_sign(DifY_cent, Dify)/*����ͬ��*/)
					&&
					//Զ��
					((fabs(Difx)<=fabs(DifX))&& (fabs(Difx) <=fabs(DifX2))
					&&(fabs(Dify) <= fabs(DifY)) && (fabs(Dify) <= fabs(DifY2)))&& (fabs(Difx) <= fabs(DifX_cent))
					&&
					//�Ƕ���
					(CheckBetween(angle, angle2, AngelMap_AI) || //һ�����
					    
					(((DifX + DifX2 == 0)&&(Difx==0)))||//��ֱ
					((abs(DifY)==1)&&(abs(DifY2==1))&&(abs(Dify)==1)))||/*ˮƽ��+-1*/
					(angle==999.9&&angle2==999.9&&AngelMap_AI==999.9/*ˮƽ���*/)
					)
				{
					//printf("xxxxxx");
					return 1;
				}

			}
		}
	}
	return 0;
}
char tank_info::GetDir(COORD pos, COORD last_pos) {
	if (pos.X-last_pos.X==-2)
	{
		return LEFT;
	}
	else if (pos.X - last_pos.X == 2)
	{
		return RIGHT;
	}
	else if (pos.Y - last_pos.Y == -1)
	{
		return UP;
	}
	else if(pos.Y - last_pos.Y == 1)
	{
		return DOWN;
	}
	else
	{
		printf("error!");
		return 0;
	}
}



short tank_AI::count_born = 0;
short tank_AI::count_death=0;
bool tank_AI::group_GetPath =0;
short tank_AI::group_targetID =0;

tank_AI::tank_AI() {
	//design = new char[3];
	//strcpy_s(design, 3, (char*)"��");
}
//���λ�ó�ʼ��AI
tank_AI::tank_AI(int ID){
	char GenFailure = 0;
	//srand(time(NULL));
	do
	{
		//����߽��ͻ
		this->pos.X = 2 * (rand() % (N2 - 4)) + 4;
		this->pos.Y = rand() % (N1 - 4) + 2;

		//����AI��˫��̹�˳�ͻ
		char Failure1 = collision_TankInter();
		//printf("GenFailure=%d", Failure1);

		//��ͼ����״̬�±�������Ч��ͼ��ͻ
		//char Failure2 = collision_TankEffObstaclle(pos);
		char Failure2 = collision_TankMap(); 
		//printf("GenFailure2=%d", Failure2);

		GenFailure = Failure1 || Failure2 ;
		//printf("GenFailure=%d", GenFailure);

	} while (GenFailure);
	count_born--;
	//id = ID;

	dir =DOWN;
	last_dir = DOWN;

	//srand(time(NULL));
	char temp_mode=rand() % 5;
	mode = temp_mode+1;
	last_mode = temp_mode;

	velocity = 190;
	party = -1;
	id = count_born;
	stuck = 0;
	flag_GetPath=0;
	angle=0;
	HunterTarget = 0;
	hp = 5;
	
	tank_time = clock();
	color = 0x2;//
	//design = (char*)"��";
	//design = new char[3];
	//strcpy_s(design, 3,  (char*)"��");

	draw_tank();
}

//ָ��λ�ó�ʼ��AI
tank_AI::tank_AI(short x,short y) {
	count_born--;

	pos.X = x;
	pos.Y = y;
	dir = DOWN;
	last_dir = DOWN;
	mode = 1;
	last_mode = 0;
	party = -1;
	id = count_born;
	hp = 100;
	flag_back = 0;
	tank_time = clock();
	color = 0x2;//
	//design = (char*)"��";
	//design = new char[3];
	//strcpy_s(design, 3, (const char*)"��");

	draw_tank();
}
//���ƹ��캯��
tank_AI::tank_AI(const tank_AI& obj) {
	distance = obj.distance;
	id = obj.id;

	pos = obj.pos;
	last_pos = obj.last_pos;
	dir = obj.dir;
	last_dir = obj.last_dir;
	mode = obj.mode;
	last_mode = obj.last_mode;
	velocity = obj.velocity;
	party = obj.party;
	id = obj.id;
	stuck = obj.stuck;
	flag_GetPath = obj.flag_GetPath;
	angle = obj.angle;
	DifX = obj.DifX;
	DifY = obj.DifY;
	angle2 = obj.angle2;
	DifX2 = obj.DifX2;
	DifY2 = obj.DifY2;
	HunterTarget = obj.HunterTarget;
	hp = obj.hp;
	//flag_back = obj.flag_back;
	tank_time = obj.tank_time;
	color = obj.color;
	//design = new char[3];
	//system("pause");
	//strcpy_s(design, 3, obj.design);

}


//���Ҳʺ��
bool tank_AI::SearchTables(COORD pos_End,vector<COORD>& vec) {
	COORD_pair PathKey;
	PathKey.pos_Begin = pos;
	PathKey.pos_End = pos_End;
	//����Ƿ���ڼ�¼
	auto it=g_PathTables.find(PathKey);
	if (it!= g_PathTables.end())
	{
		vec.assign(it->second.begin(), it->second.end());
		return true;
	}
	else
	{
		return false;
	}
}
//����
//tank_AI::~tank_AI() {
//	delete []design;
//	design = nullptr;
//}

//���
short tank_player1::count = 0;
tank_player1::tank_player1() {
	//design = new char[3];
	//strcpy_s(design, 3, (char*)"��");
};
//tank_player1::~tank_player1() { 
//	delete[]design; 
//	design = nullptr;
//};
tank_player1::tank_player1(short x,short y)
{
	
	pos.X = x;
	pos.Y = y;
	//emer_flag = 0;
	dir = RIGHT;
	last_dir = RIGHT;
	last_dir = RIGHT;
	party = 1;

	count++;
	id = count;
	
	hp = 5;
	mode = 1;
	last_mode = 0;
	flag_back = 0;

	//achievement = 0;
	life_left = 3;
	tank_time = clock();
	color = 0x7;//��ɫ
	//design = new char[3];
	//char* p= (char*)"��";
	//strcpy_s(design,3, (char*)"��");
	draw_tank();
}

tank_player1::tank_player1(const tank_player1& obj) :tank_info(obj){
	pos = obj.pos;
	dir = obj.dir;
	last_dir = obj.last_dir;
	mode = obj.mode;
	last_mode = obj.last_mode;
	party = obj.party;
	id = obj.id;

	hp = obj.hp;
	flag_back = obj.flag_back;
	life_left = obj.life_left;

	tank_time = obj.tank_time;
	color = obj.color;
	//design = new char[3];
	//strcpy_s(design, 3, (const char*)"��");
	//strcpy_s(design, 3, (char*)obj.design);
}







