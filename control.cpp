#include"control.h"
//#include"tank_war.h"

//vector删除优化
template<typename T1,typename T2>
void vec_erase_optimize_index(vector<T1>& vec,T2 match) {
	vector<T1>vec_renew;
	auto length = vec.size();
	
	for (unsigned int index=0; index < length; index++)
	{
		bool flag = 1;
		if (index==match)
		{
			flag = 0;
		}
		if (flag)
		{
			vec_renew.push_back(vec[index]);
		}

	}
	vec.swap(vec_renew);
}
//vector删除优化
template<typename T1, typename T2>
void vec_erase_optimize_item(vector<T1>& vec, T2 match) {
	vector<T1>vec_renew;
	auto length = vec.size();

	for (unsigned int index = 0; index < length; index++)
	{
		bool flag = 1;
		if (vec[index].id==match )
		{
			flag = 0;
		}
		if (flag)
		{
			vec_renew.push_back(vec[index]);
		}

	}
	vec.swap(vec_renew);
}


//保存分数
void Save_Score(char* path) {
	FILE* pfile_save;
	fopen_s(&pfile_save, path, "wb");
	fwrite(&g_Data, sizeof(STC_Data), 1, pfile_save);
	fclose(pfile_save);
}
//加载分数
void Load_Score(char* path) {
	FILE* pfile_load;
	fopen_s(&pfile_load, path, "rb");
	fread_s(&g_Data, sizeof(STC_Data), sizeof(STC_Data),1, pfile_load);
	fclose(pfile_load);
}
//保存地图
void Save_map_editor(map_editor& obj, char* path) {
	FILE* pfile_save;
	fopen_s(&pfile_save, path, "wb");
	for (short coord_x = 0; coord_x < N2 - 1; coord_x++)
	{
		for (short coord_y = 0; coord_y < N1 - 1; coord_y++)
		{
			fwrite(obj.Stc_arr_map, sizeof(Stc_map_element),  (N1 - 1)*(N2 - 1), pfile_save);

		}
	}
	//for (int i = 0; i < (N1-1)*(N2-1); i++)
	//{
	//	fwrite(obj.Stc_arr_map, sizeof(Stc_map_element), 1, pfile_save);
	//}
	fclose(pfile_save);
}

//导入地图
void Load_map_editor(map_editor& obj, char* path) {
	FILE* pfile_load;
	fopen_s(&pfile_load, path, "rb");
	for (short coord_x = 0; coord_x < N2 - 1; coord_x++)
	{
		for (short coord_y = 0; coord_y < N1 - 1; coord_y++)
		{
			fread_s(obj.Stc_arr_map, (N1 - 1)*(N2 - 1) * sizeof(Stc_map_element), sizeof(Stc_map_element), (N1 - 1)*(N2 - 1), pfile_load);

		}
	}
	//for (int i = 0; i < (N1 - 1)*(N2 - 1); i++)
	//{
	//	fread_s(obj.Stc_arr_map, sizeof(Stc_map_element), sizeof(Stc_map_element),1, pfile_load);
	//}
	fclose(pfile_load);
}
//vector存档
//读取数量
int Load_number(char* path) {
	int save_number = 0;
	FILE *pfile;
	fopen_s(&pfile, path, "rb");
	fread_s(&save_number, 1 * sizeof(int), sizeof(int), 1, pfile);
	fclose(pfile);
	return save_number;
}
template<typename T1>
//保存数量
void Save_number(char* path,vector<T1>& vec) {
	int save_number = vec.size();
	FILE *pfile;
	fopen_s(&pfile, path, "wb");
	fwrite(&save_number,  sizeof(int),  1, pfile);
	fclose(pfile);
}
//vector保存
//template <class T1>
void Save_vector(char* path,vector<tank_player1>& vec) {

	//tank_player1  buffer[N1*N2] ;
	//for (int index = 0; index < vec.size(); index++)
	//{
	//	buffer[index] = vec[index];
	//}
	FILE* pfile_save;
	fopen_s(&pfile_save, path, "wb");
	for (int i = 0; i < vec.size(); i++)
	{
		fwrite(&vec[i], sizeof(tank_player1), 1, pfile_save);
	}

	fclose(pfile_save);
	//tank_player1::count ;

}

//fprintf_s(pfile_save, "\n%hd,%hd", 
//	vec[i].pos, vec[i].muzzle_pos, vec[i].dir, vec[i].last_dir, vec[i].hp,
//	vec[i].flag_back, vec[i].mode, vec[i].last_mode, vec[i].tank_time, vec[i].velocity, vec[i].party,
//	vec[i].id, vec[i].Fires, vec[i].color, vec[i].distance, vec[i].angle,
//	vec[i].angle2, vec[i].DifX, vec[i].DifY, vec[i].DifX2, vec[i].DifY2,
//	vec[i].life_left);



void Save_vector(char* path, vector<tank_AI>& vec) {

	//tank_AI  buffer[N1*N2] ;
	//for (int index = 0; index < vec.size(); index++)
	//{
	//	buffer[index] = vec[index];
	//}
	FILE* pfile_save;
	fopen_s(&pfile_save, path, "wb");
	for (int i = 0; i < vec.size(); i++)
	{
		fwrite(&vec[i], sizeof(tank_AI), 1, pfile_save);
	}

	fclose(pfile_save);

	//tank_AI::count_born = 0;
	//tank_AI::count_death = 0;
	//tank_AI::group_GetPath = 0;
	//tank_AI::group_targetID = 0;
}
void Save_vector(char* path, vector<bullet>& vec) {

	//bullet  buffer[N1*N2];
	//for (int index = 0; index < vec.size(); index++)
	//{
	//	buffer[index] = vec[index];
	//}
	FILE* pfile_save;
	fopen_s(&pfile_save, path, "wb");
	for (int i = 0; i < vec.size(); i++)
	{
		fwrite(&vec[i], sizeof(bullet), 1, pfile_save);
	}

	fclose(pfile_save);

	 //bullet::count_AI = 0;
	 //bullet::count_player = 0;
}
//vector加载
//template <typename T1>
void Load_vector(char* path, int number, vector<tank_player1>& vec) {
	//tank_player1 obj(4,3);
	//tank_player1  buffer[N1*N2];

	FILE* pfile_load;
	fopen_s(&pfile_load, path, "rb");
	tank_player1 obj_buffer;
	for (int i = 0; i < number; i++)
	{
		fread_s(&obj_buffer, sizeof(tank_player1), sizeof(tank_player1),1, pfile_load);
		vec.push_back(obj_buffer);
	}
	fclose(pfile_load);
	//fread_s(buffer, sizeof(tank_player1)*number, sizeof(tank_player1), number, pfile_load);

	//for (int index = 0; index < number; index++)
	//{
	//	vec.push_back(buffer[index]);
	//}

	tank_player1::count--;
}
void Load_vector(char* path, int number, vector<tank_AI>& vec) {
	//tank_AI obj(1);
	//tank_AI  buffer[N1*N2];
	//FILE* pfile_load;
	//fopen_s(&pfile_load, path, "rb");
	//fread_s(buffer, sizeof(tank_AI)*number, sizeof(tank_AI), number, pfile_load);
	//fclose(pfile_load);

	//for (int index = 0; index < number; index++)
	//{
	//	vec.push_back(buffer[index]);
	//}	
	FILE* pfile_load;
	fopen_s(&pfile_load, path, "rb");
	tank_AI obj_buffer;
	for (int i = 0; i < number; i++)
	{
		fread_s(&obj_buffer, sizeof(tank_AI), sizeof(tank_AI), 1, pfile_load);
		vec.push_back(obj_buffer);
	}
	fclose(pfile_load);

	 tank_AI::count_born++;
	 //tank_AI::count_death = 0;
	 //tank_AI::group_GetPath = 0;
	// tank_AI::group_targetID = 0;
}
void Load_vector(char* path, int number, vector<bullet>& vec) {

	//bullet  buffer[N1*N2];

	//FILE* pfile_load;
	//fopen_s(&pfile_load, path, "rb");
	//fread_s(buffer, sizeof(bullet)*number, sizeof(bullet), number, pfile_load);
	//fclose(pfile_load);

	//for (int index = 0; index < number; index++)
	//{
	//	vec.push_back(buffer[index]);
	//}

	FILE* pfile_load;
	fopen_s(&pfile_load, path, "rb");
	bullet obj_buffer;
	for (int i = 0; i < number; i++)
	{
		fread_s(&obj_buffer, sizeof(bullet), sizeof(bullet), 1, pfile_load);
		vec.push_back(obj_buffer);
	}
	fclose(pfile_load);
	bullet::count_AI++;
	bullet::count_player--;
}

//vector读档
//template <typename T1>
//void vector_save(vector<T1>& vec) {
//
//	FILE* pfile_save;
//	fopen_s(&pfile_save, path_save_bullet_player, "ab");
//	for (auto& ele : vec) {
//		fread_s(obj_map_buffer.Stc_arr_map, (N1 - 1)*(N2 - 1) * sizeof(Stc_map_element),
//			sizeof(Stc_map_element), (N1 - 1)*(N2 - 1), pfile_save);
//	}
//	fclose(pfile_save);
//}
//自动寻路
//计算F
int AStar::CalcH(COORD Pos) {
	return (abs(Pos.X - m_End.X)) / 2 + abs(Pos.Y - m_End.Y);
}
//团块碰撞
bool AStar::block_collision(COORD pos_cent, COORD pos_dst) {
	int x = abs(pos_cent.X - pos_dst.X);
	int y = abs(pos_cent.Y - pos_dst.Y);
	if (x<=2&&y<=1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool AStar::tank_block(COORD pos,int id) {
	for (auto it = g_v_tanks_AI.begin(); it != g_v_tanks_AI.end(); it++)
	{
		if (id==it->id/*abs(pos.X-it->pos.X)<=2&&abs(pos.Y -it->pos.Y)<=1*/)//排除自己
		{
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
	return 0;
}

//求出最短路径
void AStar::GetPath(_Out_ vector<COORD>& vecPath,char stuck,int id)
{
	//1. 先将起点构建出来 添加到open表中
	PNODE pNode = new NODE;
	pNode->pFather = NULL;
	pNode->pos = m_Begin;
	pNode->G = 0;
	pNode->H = CalcH(pNode->pos);
	pNode->F = pNode->G + pNode->H;

	m_vecOpen.push_back(pNode);
	//2. 循环探测open表中的点
	while (m_vecOpen.size() != 0)
	{
		//printf("x\t");
		//2.1 寻找open表中F最小的点 MinF
		int nMinF = m_vecOpen[m_vecOpen.size() - 1]->F;
		int nIndex = m_vecOpen.size() - 1;
		for (int i = m_vecOpen.size() - 2; i >= 0; i--)
		{
			if (m_vecOpen[i]->F < nMinF)
			{
				nMinF = m_vecOpen[i]->F;
				nIndex = i;
			}
		}
		PNODE node_min = m_vecOpen[nIndex];
		//2.2 如果找到的是终点，那么就应该获取路径并返回
		if (
			m_vecOpen[nIndex]->pos.X == m_End.X &&
			m_vecOpen[nIndex]->pos.Y == m_End.Y
			|| block_collision(m_vecOpen[nIndex]->pos,m_End)
			)
		{
			//获取路径...
			PNODE pTemp = m_vecOpen[nIndex];
			//vecPath.clear();
			while (pTemp != nullptr)
			{
				vecPath.push_back(pTemp->pos);
				pTemp = pTemp->pFather;
			}
			//for (auto ele: vecPath)
			//{
			//	printf("%d,%d\t",ele.X,ele.Y);
			//}
			//system("pause");
			return;
		}


		//2.3 如果不是终点
		PNODE pNewNode[4] = { 0 };
		// 从上  下  左  右 派生出4个点
		for (int i = 0; i < 4; i++)
		{
			//printf("9");
			pNewNode[i] = new NODE;
			pNewNode[i]->pFather = m_vecOpen[nIndex];
			pNewNode[i]->pos = m_vecOpen[nIndex]->pos;
		}
		pNewNode[0]->pos.Y--;//向上探测
		pNewNode[1]->pos.Y++;//向下探测
		pNewNode[2]->pos.X -= 2;//向左探测
		pNewNode[3]->pos.X += 2;//向右探测
		for (int i = 0; i < 4; i++)
		{
			pNewNode[i]->G = m_vecOpen[nIndex]->G + 1;
			pNewNode[i]->H = CalcH(pNewNode[i]->pos);
			pNewNode[i]->F = pNewNode[i]->G + pNewNode[i]->H;
		}
		//对这4个点进行检测并将合适的点加入到open表，用于未来进行探测
		vector<PNODE>vec_renew;
		//bool flag_swap = 0;
		for (int i = 0; i < 4; i++)
		{
			// a. 检测是不是边界
			int x = pNewNode[i]->pos.X;
			int y = pNewNode[i]->pos.Y;
			bool bOk = true;
			if (x == 0 || x == 2 || x == 2 * N2 || x == 2 * N2 - 2
				|| y == 0 || y == 1 || y == N1 || y == N1 - 1)
			{
				bOk = false;
			}
			// b. 检测是不是障碍物
			if (
				   g_obj_map_buffer.eff_obstacle[y - 1][x / 2 - 1]
				|| g_obj_map_buffer.eff_obstacle[y - 1][x / 2    ]
				|| g_obj_map_buffer.eff_obstacle[y - 1][x / 2 + 1]
				|| g_obj_map_buffer.eff_obstacle[y    ][x / 2 - 1]
				|| g_obj_map_buffer.eff_obstacle[y    ][x / 2    ]
				|| g_obj_map_buffer.eff_obstacle[y    ][x / 2 + 1]
				|| g_obj_map_buffer.eff_obstacle[y + 1][x / 2 - 1]
				|| g_obj_map_buffer.eff_obstacle[y + 1][x / 2    ]
				|| g_obj_map_buffer.eff_obstacle[y + 1][x / 2 + 1]
				)
			{
				bOk = false;
			}
			//坦克绕过
			if (stuck) {
				bool test = tank_block({ pNewNode[i]->pos.X,pNewNode[i]->pos.Y },id);
				//printf("%d ",test);
				if (tank_block({ pNewNode[i]->pos.X,pNewNode[i]->pos.Y },id))
				{
					bOk = false;
				}
			}

			// c. 检测是不是在OPEN表中已经有了

			for (unsigned int Openi = 0; Openi < m_vecOpen.size(); Openi++)
			{
				bool flag_add = 1;

				if (
					x == m_vecOpen[Openi]->pos.X &&
					y == m_vecOpen[Openi]->pos.Y
					)
				{
					//OPEN表中这个点的F大于新节点的F，此时可以更新一下
					if (m_vecOpen[Openi]->F > pNewNode[i]->F)
					{
						//auto it = m_vecOpen.begin() + Openi;
						////delete *it;
						//delete m_vecOpen[Openi];
						//m_vecOpen.erase(it);
						flag_add = 0;
					}
					else
					{
						bOk = false;
					}
				}
				if (flag_add)
				{
					vec_renew.push_back(m_vecOpen[Openi]);
					//flag_swap = 1;
				}
			}
			//传递
			m_vecOpen.swap(vec_renew);
			vec_renew.clear();

			// d. 检测是不是在CLOSE表中已经有了
			for (unsigned int Closei = 0; Closei < m_vecClose.size(); Closei++)
			{
				if (
					x == m_vecClose[Closei]->pos.X &&
					y == m_vecClose[Closei]->pos.Y
					)
				{
					bOk = false;
				}
			}
			// 如果通过了检测，那么就应该将其加入到open表中。
			if (bOk == true)
			{
				m_vecOpen.push_back(pNewNode[i]);
				//vec_renew.push_back(pNewNode[i]);
			}

		}

		// MinF此时已经完成了使命，将其从open中去除，加入到CLOSE表中。
		m_vecClose.push_back(node_min);
		auto it_index = m_vecOpen.begin();
		for (auto it = m_vecOpen.begin(); it != m_vecOpen.end(); it++)
		{
			if (node_min == *it)
			{
				it_index = it;
				break;
			}
		}
		//printf("%d,%d\t", node_min->pos.X,node_min->pos.Y);
		m_vecOpen.erase(it_index);
	}
}

//设置寻路初始条件s
void AStar::SetMap(COORD pos_AI_pos, COORD pos_player) {
	m_Begin = pos_AI_pos;
	m_End = pos_player;

	
	//用于调试的打印代码
	//for (short coord_x = 2; coord_x < 2 * N2 ; coord_x += 2)
	//{
	//	for (short coord_y = 1; coord_y < N1; coord_y++)
	//	{
	//		if (eff_map[coord_y][coord_x / 2].type)
	//		{
	//			WriteChar(coord_x, coord_y, (char*)"☆", 1, 6);
	//		}
	//		
	//	}
	//}
}
//析构函数
AStar::~AStar() {
	//释放内存
	for (auto it = m_vecOpen.begin(); it != m_vecOpen.end(); it++) {
		if (NULL != *it)
		{
			delete *it;
			*it = NULL;
		}
	}
	m_vecOpen.clear();
	for (auto it = m_vecClose.begin(); it != m_vecClose.end(); it++) {
		if (NULL != *it)
		{
			delete *it;
			*it = NULL;
		}
	}
	m_vecClose.clear();
}


//map指定顺序
bool less_rule(COORD_pair obj1, COORD_pair obj2) {
	return obj1 < obj2;
}

//排序指定函数
bool comp(const tank_AI& obj1, const tank_AI& obj2) {
	return obj1.distance < obj2.distance ;
}





bool operator<(_coord_pair obj1, _coord_pair obj2) {
	if (obj1.pos_Begin.X < obj2.pos_Begin.X)
	{
		return true;
	}
	else if (obj1.pos_Begin.X > obj2.pos_Begin.X)
	{
		return false;
	}
	else 	if (obj1.pos_Begin.X == obj2.pos_Begin.X&&obj1.pos_Begin.Y < obj2.pos_Begin.Y)
	{
		return true;
	}
	else if (obj1.pos_Begin.X == obj2.pos_Begin.X&&obj1.pos_Begin.Y > obj2.pos_Begin.Y)
	{
		return false;
	}
	else if (obj1.pos_End.X < obj2.pos_End.X)
	{
		return true;
	}
	else if (obj1.pos_End.X > obj2.pos_End.X)
	{
		return false;
	}
	else if (obj1.pos_End.Y < obj2.pos_End.Y)
	{
		return true;
	}
	else
	{
		return false;
	}
};


bool control::CheckPoints(COORD pos) {
	for (int i = -1; i <= 1; i++)
	{
		for (int j = -1; j <= 1; j++)
		{
			if (g_obj_map_buffer.eff_obstacle[pos.Y + j][pos.X / 2 + i])
			{
				return 1;
			}
		}
	}
	return 0;
}

int control::GetPathTables(map<COORD_pair, vector<COORD>>& PathTable)
{
	int count = 0;
	for (short Begin_x = 4; Begin_x < 2 * N2 - 4; Begin_x += 2)//减去墙边
	{
		for (short Begin_y = 2; Begin_y < N1 - 2; Begin_y++)//减去墙边
		{
			//外面循环起点坐标，内部循环终点坐标

			//排除起点无效坐标
			if (CheckPoints({ Begin_x,Begin_y }))
			{
				continue;
			}
			for (short End_x = 70; End_x < 72; End_x+=2)
			{
				for (short End_y = 35; End_y < 36; End_y++)
				{
					//排除起点和终点重合
					if (Begin_x== End_x&& Begin_y== End_y)
					{
						continue;
					}
					//排除终点无效坐标
					else if (CheckPoints({End_x,End_y}))
					{
						continue;
					}
					else
					{
						count++;
						//if (count%10000==0)
						//{
						//	printf("%d ", count);
						//}
						
						AStar obj_Astar;
						COORD_pair coord_pair;
						coord_pair.pos_Begin = obj_Astar.m_Begin = { Begin_x,Begin_y };
						coord_pair.pos_End = obj_Astar.m_End = { End_x,End_y };
						
						obj_Astar.SetMap(obj_Astar.m_Begin, obj_Astar.m_End);
						vector<COORD>vec_Path;
						obj_Astar.GetPath(vec_Path,0,0);
						PathTable.insert(make_pair(coord_pair, vec_Path));
						//printf("%d,%d  %d,%d\n", coord_pair.pos_Begin.X, coord_pair.pos_Begin.Y, coord_pair.pos_End.X, coord_pair.pos_End.Y);
						//for (auto it = vec_Path.begin(); it!= vec_Path.end(); it++)
						//{
						//	printf("%d,%d  ",it->X,it->Y);
						//}
						//printf("\n");
						//printf("\n");
						//printf("\n");
						//system("pause");
					}
				}

			}

		}
	}
	printf("%d ", count);
	return count;
}

void control::AI_attack(tank_AI& obj_tank_AI,vector<COORD>& vecPath,
	vector<bullet>& v_bullet_player, vector<bullet>& v_bullet_AI) {
	int length = vecPath.size();
	//速度变化
	//if (length < 40)
	//{
	//	velocity = 200;
	//}
	//else if (distance < 80)
	//{
	//	velocity = 150;
	//}
	//else
	//{
	//	velocity = 100;
	//}
	//obj_tank_AI.GetDistance(g_v_tanks_player[0].pos);
	if (length ==0)
	{
		//length = 2;
		//随机和坦克以及子弹检测
		if (clock() - obj_tank_AI.tank_time > obj_tank_AI.velocity) {
			obj_tank_AI.tank_time = clock();
			AI_operation operation = (AI_operation)(rand() % 5);
			switch (operation)
			{
			case up:
			{
				obj_tank_AI.move_tank(UP);
			}
			break;
			case down:
			{
				obj_tank_AI.move_tank(DOWN);
			}
			break;
			case left:
			{
				obj_tank_AI.move_tank(LEFT);
			}
			break;
			case right:
			{
				obj_tank_AI.move_tank(RIGHT);
			}
			break;
			case fire:
			{
				//更新数据
				obj_tank_AI.Fires++;
				//坦克传递给子弹对象
				tank_fire(obj_tank_AI,v_bullet_AI);

			}
			break;
			default:
				break;
			}
			//坦克和地图以及边界碰撞
			char cross_tank_AI_border = obj_tank_AI.collision_TankBorder();
			char cross_tank_AI_map = obj_tank_AI.collision_TankMap();
			char cross_tank_inter_both = obj_tank_AI.collision_TankInter();

			//printf("%d ",cross_tank_inter_both);
			//system("pause");

			char cross = cross_tank_AI_border || cross_tank_AI_map || cross_tank_inter_both;
			obj_tank_AI.execute(cross);
			//if (!cross_tank_inter_both){
			//	stuck = 0;
			//}
		}
	}
	else//自动寻路
	{
		int i = length - 2;//寻到的路的第一步
		if (clock() - obj_tank_AI.tank_time > obj_tank_AI.velocity)
		{
			//printf("ccccc");
			obj_tank_AI.tank_time = clock();
			obj_tank_AI.wipe_tank();
			obj_tank_AI.last_pos = obj_tank_AI.pos;
			COORD pos_buffer = vecPath[i];
			obj_tank_AI.last_dir = obj_tank_AI.dir;
			obj_tank_AI.dir = obj_tank_AI.GetDir(pos_buffer, obj_tank_AI.pos);
			//char cross_tank_inter_dir=0;
			char cross_tank_inter_pos = 0;
			if (obj_tank_AI.dir != obj_tank_AI.last_dir)//改变了方向
			{

			}
			else//未改变方向
			{
				obj_tank_AI.pos = pos_buffer;
				cross_tank_inter_pos = obj_tank_AI.collision_TankInter();

			}

			obj_tank_AI.execute(cross_tank_inter_pos);
			//如果拥堵短暂切换成把阻塞的坦克作为障碍物来自动寻路
			if (cross_tank_inter_pos)
			{
				obj_tank_AI.stuck = 6;
			}
			else
			{
				if (length>=30)
				{
					obj_tank_AI.stuck=10;
				}

				if (obj_tank_AI.stuck)
				{
					obj_tank_AI.stuck--;
				}

			}


			//子弹
			bool Is_fire = rand() % 3;
			if (!Is_fire)
			{
				tank_fire(obj_tank_AI,v_bullet_AI);
			}

		}

	}






	//调试代码
	//for (int i = length - 1; i > 3; i--)
	//{
	//	printf("%d,%d", vecPath[i].X, vecPath[i].Y);
	//	printf("\t");
	//}
}
void control::tank_fire(tank_player1& obj_tank_player,vector<bullet>& v_bullet) {

	//坦克传递给子弹对象
	bullet obj_bullet(1);				//初始化子弹

	if (obj_tank_player.mode)
	{
		//传递类型
		char bullet_type = obj_tank_player.mode - 1;
		obj_bullet.type = bullet_type;
		//传递方向
		char bullet_dir = obj_tank_player.dir;
		obj_bullet.dir = bullet_dir;
		//传递势力
		short bullet_party = obj_tank_player.party;
		obj_bullet.party = bullet_party;
		//传递开炮者ID
		obj_bullet.owner_id = obj_tank_player.id;

		PCOORD p_muzzle = obj_tank_player.get_muzzzle();
		if (obj_bullet.type != 1)
		{
			obj_bullet.origin[0].X = (*p_muzzle).X;
			obj_bullet.origin[0].Y = (*p_muzzle).Y;
			//obj_bullet.origin[1] = obj_bullet.origin[0];
		}
		else
		{
			obj_bullet.origin[0].X = (*p_muzzle).X;
			obj_bullet.origin[0].Y = (*p_muzzle).Y;
			obj_bullet.origin[1].X = (*(p_muzzle + 1)).X;
			obj_bullet.origin[1].Y = (*(p_muzzle + 1)).Y;
		}

		clock_t this_time = clock();
		obj_bullet.init_time = this_time;

		v_bullet.push_back(obj_bullet);
		auto NewBullet_index = v_bullet.size() - 1;
		//初始子弹和边界判断
		v_bullet[NewBullet_index].BulletBorder();
		v_bullet[NewBullet_index].BulletMap();
		v_bullet[NewBullet_index].bullet_draw();
		//初始子弹和坦克判断
		short victim_ID = collision_TankBullet(v_bullet[NewBullet_index]);
		if (victim_ID)
		{
			//打击坦克
			hit_tank_AI(g_v_tanks_AI, victim_ID);
		}
		if (!v_bullet[NewBullet_index].state|| victim_ID)
		{
			v_bullet[NewBullet_index].bullet_wipe();
			v_bullet.pop_back();
		}


		//if (!v_bullet[v_bullet.size() - 1].bullet_conf[v_bullet[v_bullet.size() - 1].type].hp)
		//{
		//	v_bullet.pop_back();
		//}
	}


}
void control::tank_fire(tank_AI& obj_tank_AI, vector<bullet>& v_bullet) {

	//坦克传递给子弹对象
	bullet obj_bullet(-1);				//初始化子弹

	
	if (obj_tank_AI.mode)
	{
		char bullet_type = obj_tank_AI.mode - 1;
		obj_bullet.type = bullet_type;
		char bullet_dir = obj_tank_AI.dir;
		obj_bullet.dir = bullet_dir;
		short bullet_party = obj_tank_AI.party;
		obj_bullet.party = bullet_party;
		//传递开炮者ID
		obj_bullet.owner_id = obj_tank_AI.id;

		PCOORD p_muzzle = obj_tank_AI.get_muzzzle();
		if (obj_bullet.type != 1)
		{
			obj_bullet.origin[0].X = (*p_muzzle).X;
			obj_bullet.origin[0].Y = (*p_muzzle).Y;
			obj_bullet.origin[1] = obj_bullet.origin[0];
		}
		else
		{
			obj_bullet.origin[0].X = (*p_muzzle).X;
			obj_bullet.origin[0].Y = (*p_muzzle).Y;
			obj_bullet.origin[1].X = (*(p_muzzle + 1)).X;
			obj_bullet.origin[1].Y = (*(p_muzzle + 1)).Y;
		}

		clock_t this_time = clock();
		obj_bullet.init_time = this_time;

		//初始子弹和边界判断
		obj_bullet.BulletBorder();
		obj_bullet.BulletMap();
		obj_bullet.bullet_draw();
		//初始子弹和坦克判断
		short victim_ID = collision_TankBullet(obj_bullet);
		if (victim_ID)
		{
			//打击坦克
			hit_tank_player(g_v_tanks_player, victim_ID);
		}
		if (!obj_bullet.state || victim_ID)
		{
			obj_bullet.bullet_wipe();
		}
		v_bullet.push_back(obj_bullet);
	}


}

//判断子弹和坦克碰撞
//返回击中坦克的id
short control::collision_TankBullet(bullet& obj_bullet){
	if ( obj_bullet.party == 1)//玩家子弹
	{
		if (obj_bullet.type != 1)//单发
		{
			for (auto &ele : g_v_tanks_AI) {
			
				for (short i = 0; i < 9; i++)
				{
					COORD offset = { 0,0 };
					char ndir = -1;
					switch (ele.dir)
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
					if (ele.p[ele.mode][ndir][i])
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
						//WriteChar(pos.X + offset.X, pos.Y + offset.Y, design, 1, color);
						if (obj_bullet.origin[0].X == ele.pos.X + offset.X&&
							obj_bullet.origin[0].Y ==ele.pos.Y + offset.Y)
						{
							
							ele.hp -= obj_bullet.bullet_conf[obj_bullet.type].power;
							//更新统计数据--命中数
							g_Data.Hits[obj_bullet.owner_id-1]++;
							//printf("xxxxxxxxxx,%d", obj_bullet.owner_id - 1);
							return ele.id;
						}

					}

				}
			}
			return 0;
		}
		else//双发   
		{
			for (auto &ele : g_v_tanks_AI) {

				for (short i = 0; i < 9; i++)
				{
					COORD offset = { 0,0 };
					char ndir = -1;
					switch (ele.dir)
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
					if (ele.p[ele.mode][ndir][i])
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
						//WriteChar(pos.X + offset.X, pos.Y + offset.Y, design, 1, color);
						if (obj_bullet.state==1)
						{
							if ((obj_bullet.origin[0].X == ele.pos.X + offset.X&&
								obj_bullet.origin[0].Y == ele.pos.Y + offset.Y)||
								(obj_bullet.origin[1].X == ele.pos.X + offset.X&&
								obj_bullet.origin[1].Y == ele.pos.Y + offset.Y)
								)
							{
								ele.hp -= obj_bullet.bullet_conf[obj_bullet.type].power;
								g_Data.Hits[obj_bullet.owner_id-1]++;
								return ele.id;
							}

						}
						else if (obj_bullet.state == -1)
						{
							if (obj_bullet.origin[1].X == ele.pos.X + offset.X&&
								obj_bullet.origin[1].Y == ele.pos.Y + offset.Y)
							{
								ele.hp -= obj_bullet.bullet_conf[obj_bullet.type].power;
								g_Data.Hits[obj_bullet.owner_id-1]++;
								return ele.id;
							}
						}
						else if (obj_bullet.state == -2)
						{
							if (obj_bullet.origin[0].X == ele.pos.X + offset.X&&
								obj_bullet.origin[0].Y == ele.pos.Y + offset.Y)
							{
								ele.hp -= obj_bullet.bullet_conf[obj_bullet.type].power;
								g_Data.Hits[obj_bullet.owner_id-1]++;
								return ele.id;
							}
						}
						else
						{
							//printf("errorTank_Bullet");
						}


					}

				}
			}
		}
		return 0;
	}
	else if (obj_bullet.party == -1)//AI子弹
	{
		if (obj_bullet.type != 1)//单发
		{
			for (auto &ele : g_v_tanks_player) {

				for (short i = 0; i < 9; i++)
				{
					COORD offset = { 0,0 };
					char ndir = -1;
					switch (ele.dir)
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
					if (ele.p[ele.mode][ndir][i])
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
						//WriteChar(pos.X + offset.X, pos.Y + offset.Y, design, 1, color);
						if (obj_bullet.origin[0].X == ele.pos.X + offset.X&&
							obj_bullet.origin[0].Y == ele.pos.Y + offset.Y)
						{
							//可以发挥子弹特效
							ele.hp -= obj_bullet.bullet_conf[obj_bullet.type].power;
							//g_Data.Hits[obj_bullet.owner_id-1]++;
							printf("\a");
							return ele.id;
						}

					}

				}
			}
			return 0;
		}
		else//双发   未完待续
		{
			for (auto &ele : g_v_tanks_player) {

				for (short i = 0; i < 9; i++)
				{
					COORD offset = { 0,0 };
					char ndir = -1;
					switch (ele.dir)
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
					if (ele.p[ele.mode][ndir][i])
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
						//WriteChar(pos.X + offset.X, pos.Y + offset.Y, design, 1, color);
						if (obj_bullet.state == 1)
						{
							if ((obj_bullet.origin[0].X == ele.pos.X + offset.X&&
								obj_bullet.origin[0].Y == ele.pos.Y + offset.Y) ||
								(obj_bullet.origin[1].X == ele.pos.X + offset.X&&
									obj_bullet.origin[1].Y == ele.pos.Y + offset.Y)
								)
							{
								ele.hp -= obj_bullet.bullet_conf[obj_bullet.type].power;
								//g_Data.Hits[obj_bullet.owner_id-1]++;
								printf("\a"); 
								return ele.id;
							}

						}
						else if (obj_bullet.state == -1)
						{
							if (obj_bullet.origin[1].X == ele.pos.X + offset.X&&
								obj_bullet.origin[1].Y == ele.pos.Y + offset.Y)
							{
								ele.hp -= obj_bullet.bullet_conf[obj_bullet.type].power;
								//g_Data.Hits[obj_bullet.owner_id-1]++;
								return ele.id;
							}
						}
						else if (obj_bullet.state == -2)
						{
							if (obj_bullet.origin[0].X == ele.pos.X + offset.X&&
								obj_bullet.origin[0].Y == ele.pos.Y + offset.Y)
							{
								ele.hp -= obj_bullet.bullet_conf[obj_bullet.type].power;
								//g_Data.Hits[obj_bullet.owner_id-1]++;
								return ele.id;
							}
						}
						else
						{
							//printf("errorTank_Bullet");
						}


					}

				}
			}
		}
		return 0;
	}
	else
	{
		printf("error!!!");
		return 0;
	}

}


//函数重载坦克击中后处理
void control::hit_tank_AI(vector<tank_AI>& vec, short id) {
	vector<tank_AI>vec_renew;

	for (auto& ele : vec)
	{
		bool flag = 1;
		if (ele.id == id)
		{

			//删除
			if (ele.hp<=0)
			{
				flag = 0;
				//坦克擦除
				ele.wipe_tank();
				tank_AI::count_death++;
			}
		}
		if (flag)
		{
			vec_renew.push_back(ele);
		}
	}
	vec.assign(vec_renew.begin(),vec_renew.end());
}
short control::hit_tank_player(vector<tank_player1>& vec, short id) {
	for (auto& ele : vec)
	{
		if (ele.id == id)
		{

			if (ele.hp <= 0.0)
			{
				
				//玩家坦克擦除
				ele.wipe_tank();
				//更新关键数据
				if (ele.life_left>0)
				{
					ele.life_left--;
					//hp重置
					ele.hp = 5;
					//回到重生点
					ele.pos = { reborn_pos_x,reborn_pos_y };
					ele.dir = UP;
					ele.mode = 1;
					return 0;
				}
				else if (ele.life_left==0)
				{
					ele.wipe_tank();
					//vec_erase_optimize_item(vec,ele.id);
					//printf("不可复活！");
					return ele.id;
				}
				else
				{
					
					printf("errorhit_player");
					return 0;
				}


			}
		}
	}
	return 0;
}

//子弹之间碰撞
void control::collision_BulletInter(bullet& obj_bullet,vector<bullet>& vec) {

		for (auto & ele : vec) {
			if (obj_bullet.type!=1 && ele.type!= 1)//判断玩家单发和AI单发碰撞
			{
				if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y)
				{
					obj_bullet.state = 0;
					ele.state=0;
					obj_bullet.bullet_wipe();
					ele.bullet_wipe();
					print_bullet_cross(ele.origin[0]);
				}
			}
			else if (obj_bullet.type == 1 && ele.type != 1)//判断玩家双发和AI单发碰撞
			{
				if (obj_bullet.state == 1)//先判断完整双发
				{
					if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y)//击中玩家左边
					{
						obj_bullet.state = -1;
						ele.state = 0;
						ele.bullet_wipe();
						print_bullet_cross(ele.origin[0]);

					}
					else if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y)//击中玩家左边
					{
						obj_bullet.state = -2;
						ele.state = 0;
						ele.bullet_wipe();
						print_bullet_cross(ele.origin[0]);

					}
					else
					{
						//printf("error_bulletInter111");
					}

				}
				else if (obj_bullet.state == -1)//再判断左缺双发
				{
					if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y)
					{
						obj_bullet.state = 0;
						ele.state = 0;
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(ele.origin[0]);

					}

				}
				else if (obj_bullet.state == -2)//再判断右缺双发
				{

					if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y)
					{
						
						obj_bullet.state = 0;
						ele.state = 0;
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(ele.origin[0]);

					}
				}
				else
				{
					//printf("error_bulletInter222");
				}
			}
			else if (obj_bullet.type != 1 && ele.type == 1)//判断玩家单发和AI双发碰撞
			{
				if (ele.state==1)//AI完整双发
				{
					if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y)//变成左缺
					{
						obj_bullet.state = 0;
						ele.state = -1;
						obj_bullet.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);
						
					}
					else if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y)//变成右缺
					{
						obj_bullet.state = 0;
						ele.state = -1;
						obj_bullet.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);

					}
					else
					{
						//printf("error_bulletInter333");
					}
				}
				else if (ele.state==-1)//AI左缺双发
				{
					if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y)
					{
						obj_bullet.state = 0;
						ele.state = 0;
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);

					}

				}
				else if (ele.state == -2)//AI右缺双发
				{
					if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y)
					{
						obj_bullet.state = 0;
						ele.state = 0;
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);

					}
				}
				else
				{
					//printf("error_bulletInter444");
				}
			}
			else if (obj_bullet.type == 1 && ele.type == 1)//判断玩家双发和AI双发碰撞
			{
				if (obj_bullet.state == 1 && ele.state == 1)//都是完整双发
				{
					if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y&&
						ele.origin[1].X == obj_bullet.origin[0].X&&ele.origin[1].Y == obj_bullet.origin[0].Y
						)//两两相撞？会有完全重合吗
					{
						obj_bullet.state = 0;
						ele.state = 0; 
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);
						print_bullet_cross(obj_bullet.origin[1]);

					}
					else if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y&&
						!(ele.origin[1].X == obj_bullet.origin[1].X&&ele.origin[1].Y == obj_bullet.origin[1].Y))//左左
					{
						obj_bullet.state = -1;
						ele.state = -1;
						print_bullet_cross(obj_bullet.origin[0]);

					}
					else if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y &&
						!(ele.origin[1].X == obj_bullet.origin[0].X&&ele.origin[1].Y == obj_bullet.origin[0].Y))//左右
					{
						obj_bullet.state = -2;
						ele.state = -1;
						print_bullet_cross(obj_bullet.origin[1]);

					}
					else if (ele.origin[1].X == obj_bullet.origin[0].X&&ele.origin[1].Y == obj_bullet.origin[0].Y &&
						!(ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y))//右左
					{
						obj_bullet.state = -1;
						ele.state = -2;
						print_bullet_cross(obj_bullet.origin[0]);

					}
					else if (ele.origin[1].X == obj_bullet.origin[1].X&&ele.origin[1].Y == obj_bullet.origin[1].Y &&
						!(ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y))//右右
					{
						obj_bullet.state = -2;
						ele.state = -2;
						print_bullet_cross(obj_bullet.origin[1]);

					}
					else
					{
						//printf("error_bulletInter444");
					}
				}
				else if (obj_bullet.state == 1 && ele.state == -1)//玩家子弹完整AI子弹左缺
				{
					if (ele.origin[1].X== obj_bullet.origin[0].X&&ele.origin[1].Y == obj_bullet.origin[0].Y)//击中玩家左边
					{
						obj_bullet.state = -1;
						ele.state = 0;
						
						ele.bullet_wipe();
						print_bullet_cross(ele.origin[1]);

					}
					else if(ele.origin[1].X == obj_bullet.origin[1].X&&ele.origin[1].Y == obj_bullet.origin[1].Y)//击中玩家右边
					{
						obj_bullet.state = -2;
						ele.state = 0;
						
						ele.bullet_wipe();
						print_bullet_cross(ele.origin[1]);

					}
					else
					{
						//printf("error_bulletInter555");
					}
				}
				else if (obj_bullet.state == 1 && ele.state == -2)//玩家子弹完整AI子弹右缺
				{
					if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y)//击中玩家左边
					{
						obj_bullet.state = -1;
						ele.state = 0;
						
						ele.bullet_wipe();
						print_bullet_cross(ele.origin[0]);

					}
					else if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y)//击中玩家右边
					{
						obj_bullet.state = -2;
						ele.state = 0;
						
						ele.bullet_wipe();
						print_bullet_cross(ele.origin[0]);

					}
					else
					{
						//printf("error_bulletInter666");
					}
				}
				else if (obj_bullet.state == -1 && ele.state == 1)//玩家子弹左缺AI子弹完整
				{
					if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y)//击中AI左边
					{
						obj_bullet.state = 0;
						ele.state = -1;
						obj_bullet.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[1]);

						
					}
					else if (ele.origin[1].X == obj_bullet.origin[1].X&&ele.origin[1].Y == obj_bullet.origin[1].Y)//击中AI右边
					{
						obj_bullet.state =0;
						ele.state = -2;
						obj_bullet.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[1]);

					}
					else
					{
						//printf("error_bulletInter777");
					}
				}
				else if (obj_bullet.state == -1 && ele.state == -1)//玩家子弹左缺AI子弹左缺
				{
					if (ele.origin[1].X == obj_bullet.origin[1].X&&ele.origin[1].Y == obj_bullet.origin[1].Y)
					{
						obj_bullet.state = 0;
						ele.state = 0;
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[1]);

					}

				}
				else if (obj_bullet.state == -1 && ele.state == -2)//玩家子弹左缺AI子弹右缺
				{
					if (ele.origin[0].X == obj_bullet.origin[1].X&&ele.origin[0].Y == obj_bullet.origin[1].Y)
					{
						obj_bullet.state = 0;
						ele.state = 0;
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[1]);

					}
				}
				else if (obj_bullet.state == -2 && ele.state == 1)//玩家子弹右缺AI子弹完整
				{
					if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y)//击中AI左边
					{
						obj_bullet.state = 0;
						ele.state = -1;
						obj_bullet.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);

					}
					else if (ele.origin[1].X == obj_bullet.origin[0].X&&ele.origin[1].Y == obj_bullet.origin[0].Y)//击中AI右边
					{
						obj_bullet.state = 0;
						ele.state = -2;
						obj_bullet.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);

					}
					else
					{
						//printf("error_bulletInter888");
					}
				}
				else if (obj_bullet.state == -2 && ele.state == -1)//玩家子弹右缺AI子弹左缺
				{
					if (ele.origin[1].X == obj_bullet.origin[0].X&&ele.origin[1].Y == obj_bullet.origin[0].Y)
					{
						obj_bullet.state = 0;
						ele.state = 0;
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);

					}
				}
				else if (obj_bullet.state == -2 && ele.state == 2)//玩家子弹右缺AI子弹右缺
				{
					if (ele.origin[0].X == obj_bullet.origin[0].X&&ele.origin[0].Y == obj_bullet.origin[0].Y)
					{
						obj_bullet.state = 0;
						ele.state = 0;
						obj_bullet.bullet_wipe();
						ele.bullet_wipe();
						print_bullet_cross(obj_bullet.origin[0]);

					}
				}
				else
				{
					//printf("error_bulletInter999");
				}
			}
			else
			{
				//printf("error_bulletInter101010");
			}

		}
}
//打印火力交界点
void control::print_bullet_cross(COORD pos) {
	WriteChar(pos.X,pos.Y, (char*)"×", 1, 0xF);//亮白色
	Sleep(5);
	WriteChar(pos.X, pos.Y,(char*)"  ", 1, 1);
}
//暂停存档
void control::pause_save(vector<bullet>& vec_bullet_AI, vector<bullet>& vec_bullet_player) {
	g_obj_remind.cls_news();
	WriteChar(2, N1 + 2, (char*)"游戏已暂停！ ", 1, 0xA);
	WriteChar(2, N1 + 3, (char*)"保存档案请按S", 1, 0xA);
	WriteChar(2, N1 + 4, (char*)"继续游戏请按p ", 1, 0xA);
	while (1) {
		Sleep(100);
		if (_kbhit())
		{
			char d = 0;
			while (_kbhit() != 0) {
				d = _getch();
			}
			if (d == PAUSE) {//继续
				g_obj_remind.cls_news();
				WriteChar(2, N1 + 2, (char*)"游戏继续！ ", 1, 0xA);
				break;
			}
			if (d == SAVE_GAME) {//存档
				//obj_main.save(obj_snake);
				g_obj_remind.cls_news();

				Save_number((char*)path_SaveConfig_tank_player,g_v_tanks_player);
				Save_number((char*)path_SaveConfig_tank_AI,g_v_tanks_AI);
				Save_number((char*)path_SaveConfig_bullet_player, vec_bullet_player);
				Save_number((char*)path_SaveConfig_bullet_AI, vec_bullet_AI);


				Save_vector((char*)path_save_tank_player, g_v_tanks_player);
				Save_vector((char*)path_save_tank_AI, g_v_tanks_AI);
				Save_vector((char*)path_save_bullet_player, vec_bullet_player);
				Save_vector((char*)path_save_bullet_AI, vec_bullet_AI);

				Save_map_editor(g_obj_map_buffer, (char*)path_save_map_editor_INgame);
				Save_Score((char*)path_save_score);

				WriteChar(2, N1 + 2, (char*)"已保存档案！", 1, 0xA);
				WriteChar(2, N1 + 3, (char*)"继续游戏请按p", 1, 0xA);
			}
		}
	}
}

//显示实时统计数据和分数
void control::ShowData() {

}

void control::time_clock() {

	for (auto & ele : g_v_tanks_player) {
		Sleep(1);
		ele.tank_time = clock();
	}
	for (auto & ele : g_v_tanks_AI) {
		Sleep(1);
		ele.tank_time = clock();
	}
	for (auto & ele : g_v_bullet_player) {
		Sleep(1);
		ele.init_time = clock();
		ele.style_set();
	}
	for (auto & ele : g_v_bullet_AI) {
		Sleep(1);
		ele.init_time = clock();
		ele.style_set();

	}
}

//单人游戏
bool single_player_game(bool login_flag) {

	static bool flag_Reset = 0;
	control obj_ctrl;				//初始化控制引擎

	vector<bullet>v_bullet_player;//初始化player子弹向量
	vector<bullet>v_bullet_AI;//初始化AI子弹向量

	g_obj_remind.cls_news();
	WriteChar(2, N1 + 4, (char*)"游戏开始", 1, 0xA);
	Show_cursor(0);

	//非加载初始化玩家坦克
	if (!g_loadNotNew)
	{
		tank_player1 obj_player(70, 30);	//初始化玩家坦克 //70,35
		g_v_tanks_player.push_back(obj_player);//初始化玩家坦克向量
	}

	//指定生成初始化AI坦克
	//tank_AI obj_AI1(130, 5);//, obj_AI2(40,40), obj_AI3(24,14);
	//g_v_tanks_AI.push_back(obj_AI1);

	//初始化统计数据
	if (!g_loadNotNew)
	{
		g_Data.Hits[0] = 0;
		g_Data.AI_death = tank_AI::count_death = 0;
		g_Data.Fire_AI = g_Data.Fire_player[0] = 0;
		g_Data.Life_left[0] = g_v_tanks_player[0].life_left;
		g_Data.GetScore();
		//打印统计数据
		//g_obj_remind.show_data_wipe();
		g_obj_remind.show_data_start(g_Data.Hits, g_Data.Score, g_Data.Life_left, g_Data.Fire_player, g_Data.AI_death);
	}
	else
	{
		//打印统计数据
		//g_obj_remind.show_data_wipe();
		tank_AI::count_death = g_Data.AI_death;
		tank_AI::count_born = g_Data.AI_count_born;
		g_obj_remind.show_data_start(g_Data.Hits, g_Data.Score, g_Data.Life_left, g_Data.Fire_player, g_Data.AI_death);
	}

	//初始化档案地图
	if (g_loadNotNew)
	{
		g_obj_map_buffer.map_editor_init();
	}
	//时间修改
	if (g_loadNotNew)
	{
		obj_ctrl.time_clock();
	}
	//加载初始化子弹
	if (g_loadNotNew)
	{
		v_bullet_player.swap(g_v_bullet_player);
		v_bullet_AI.swap(g_v_bullet_AI);
	}
	while (true)
	{
		//Sleep(1);
		//游戏结束
		if (g_v_tanks_player.empty())
		{
			static bool flag_print = 1;
			//static bool Reset = 0;
			if (flag_print)
			{
				g_obj_remind.cls_news();
				WriteChar(2, N1 + 2, (char*)"你已阵亡！", 1, 0xA);
				flag_print = 0;
			}
			

			//倒计时打印
			static int time = count_down;
			static time_t seconds_count = clock();
			if (flag_Reset)
			{
				time_t buffer = clock();
				seconds_count = buffer;
				time = count_down;
				flag_Reset = 0;
			}
			if (clock() - seconds_count > count_down*1000)
			{
				g_v_tanks_AI.clear();
				v_bullet_player.clear();
				v_bullet_AI.clear();

				//重置
				flag_Reset = 1;

				login_flag = 1;
				return login_flag;
			}

			static time_t buffer_second = seconds_count;
			if (clock() - buffer_second >= 1000)
			{
				buffer_second = clock();
				time--;
			}
			char second[5] = { '\0' };
			sprintf_s(second, 5, "%d", time);
			WriteChar(60, N1 + 4, (char*)second, 1, 0xF);
			WriteChar(60, N1 + 4, (char*)second, 1, 0xF);


		}


		//实时更新数据
		//printf("%d",g_Data.Hits[0]);
		if (!g_v_tanks_player.empty())
		{
			g_Data.AI_death = tank_AI::count_death;
			g_Data.AI_count_born=tank_AI::count_born;
			g_Data.Fire_player[0] = g_v_tanks_player[0].Fires;
			g_Data.Life_left[0] = g_v_tanks_player[0].life_left;
			g_Data.GetScore();
			//实时打印数据
			g_obj_remind.show_data_renew(g_Data.Hits, g_Data.Score, g_Data.Life_left, g_Data.Fire_player, g_Data.AI_death);
		}
		
		//地图自动刷新

		//if (clock()-g_obj_map_buffer.init_time> map_editor_renew_speed)
		//{
		//	g_obj_map_buffer.init_time = clock();
		//	g_obj_map_buffer.map_renew();
		//	g_obj_map_buffer.GetEffObstacle();
		//}

		g_obj_map_buffer.map_renew();
		
		g_obj_map_buffer.GetEffObstacle();
		

		//随机生成坦克初始化

		if (g_v_tanks_AI.empty())
		{
			auto number_AI = 1+rand() % 3;
			for (int i = 0; i < number_AI; i++)
			{
				tank_AI obj_AI(1);
				//obj_AI.GetDistance(g_v_tanks_player[0].pos);
				//printf("%u\n", obj_AI.distance);
				g_v_tanks_AI.push_back(obj_AI);
			}
		}
		//if (flag_LoadAI_empty)
		//{
		//	flag_LoadAI_empty = 0;
		//}

		
		if (!g_v_tanks_player.empty())
		{
			//玩家坦克自动刷新
			for (auto& ele : g_v_tanks_player)
			{
				if (clock() - ele.tank_time > tank_renew_speed)
				{
					ele.tank_time = clock();
					//Sleep(30);
					ele.draw_tank();
				}
			}
		}
		

		//AI坦克自动刷新
		for (auto it = g_v_tanks_AI.begin(); it != g_v_tanks_AI.end(); it++)
		{
			if (clock() - it->tank_time> tank_renew_speed)
			{
				it->tank_time = clock();
				//printf("ccccccccc");
				it->draw_tank();
			}
		}
		
		//自动寻路
		//vector<vector<COORD>>vec_GetPathList;
		//vector<AStar>vec_obj_AStar;

		//for (auto it = g_v_tanks_AI.begin(); it != g_v_tanks_AI.end(); it++)
		//{
		//	printf("%d,%d  %d\n",it->pos.X,it->pos.Y,it->distance);
		//}
		

		//system("pause");
		//for (auto it = g_v_tanks_AI.begin(); it != g_v_tanks_AI.end(); it++)
		//{
		//	printf("%d,%d  %d\t", it->pos.X, it->pos.Y,it->distance);
		//}

		//AI操作设计

		//就近重排

		if (!g_v_tanks_player.empty()) {

			//sort(g_v_tanks_AI.begin(), g_v_tanks_AI.end(), comp);

			int length = g_v_tanks_AI.size();
			for (int i = 0; i < length; i++)
			{
				vector<COORD>vec_GetPath;

				//设置寻路开关
				//后续可以完善寻路判断

				for (auto ele_player : g_v_tanks_player) {
					for (auto& ele_AI : g_v_tanks_AI)
					{
						//ele_AI.GetAngle(ele_player.pos);
						if (/*ele_AI.GetDistance(ele_player.pos) <= 40*/ele_AI.distance<AI_DISTANCE&&!ele_AI.CheckMapBlock())
						{
							ele_AI.flag_GetPath = 1;
							ele_AI.HunterTarget = ele_player.id;
						}
						else
						{
							//printf("xxxxxxxxxxx");
							ele_AI.flag_GetPath = 0;
							ele_AI.HunterTarget = 0;
						}
					}

				}
				//团队合作Z追捕
				//for (auto& ele_AI : g_v_tanks_AI)
				//{
				//	if (ele_AI.flag_GetPath ==1)
				//	{
				//		tank_AI::group_GetPath = 1;
				//		tank_AI::group_targetID = ele_AI.id;
				//	}
				//}


				if (g_v_tanks_AI[i].flag_GetPath)
				{
					COORD pos_target = { 0 };
					for (auto& ele : g_v_tanks_player) {
						if (ele.id == g_v_tanks_AI[i].HunterTarget)
						{
							pos_target = ele.pos;
						}
					}
					if (0/*g_v_tanks_AI[i].SearchTables(pos_target, vec_GetPath)*/)
					{
						//for (auto it = vec_GetPath.begin(); it != vec_GetPath.end(); it++)
						//{
						//	printf("%d,%d\t",it->X,it->Y);
						//}
						//system("pause");

					}
					else
					{
						AStar obj_AStar;
						//g_obj_map_buffer.GetEffObstacle();
						obj_AStar.SetMap(g_v_tanks_AI[i].pos, pos_target);
						obj_AStar.GetPath(vec_GetPath, g_v_tanks_AI[i].stuck, g_v_tanks_AI[i].id);


						//调试打印代码
						//int length = vec_GetPath.size();
						//for (int i = 3; i < length - 2; i++)
						//{
						//	WriteChar(vec_GetPath[i].X, vec_GetPath[i].Y, (char*)"☆", 1, 4);
						//}
						//Sleep(2);
						//for (int i = 3; i < length - 2; i++)
						//{
						//	WriteChar(vec_GetPath[i].X, vec_GetPath[i].Y, (char*)"☆", 2, 4);
						//}
						//Sleep(50);
						//system("pause");

					}

				}
				else
				{
					//printf("yyyy");
					//随机和坦克以及子弹检测
					if (clock() - g_v_tanks_AI[i].tank_time > g_v_tanks_AI[i].velocity) {
						g_v_tanks_AI[i].tank_time = clock();
						AI_operation operation = (AI_operation)(rand() % 5);
						switch (operation)
						{
						case up:
						{
							g_v_tanks_AI[i].move_tank(UP);
						}
						break;
						case down:
						{
							g_v_tanks_AI[i].move_tank(DOWN);
						}
						break;
						case left:
						{
							g_v_tanks_AI[i].move_tank(LEFT);
						}
						break;
						case right:
						{
							g_v_tanks_AI[i].move_tank(RIGHT);
						}
						break;
						case fire:
						{
							//更新数据
							g_v_tanks_AI[i].Fires++;
							//坦克传递给子弹对象
							obj_ctrl.tank_fire(g_v_tanks_AI[i], v_bullet_AI);

						}
						break;
						default:
							break;
						}
						//坦克和地图以及边界碰撞
						char cross_tank_AI_border = g_v_tanks_AI[i].collision_TankBorder();
						char cross_tank_AI_map = g_v_tanks_AI[i].collision_TankMap();
						char cross_tank_inter_both = g_v_tanks_AI[i].collision_TankInter();

						//printf("%d ",cross_tank_inter_both);
						//system("pause");

						char cross = cross_tank_AI_border || cross_tank_AI_map || cross_tank_inter_both;
						g_v_tanks_AI[i].execute(cross);
						//if (!cross_tank_inter_both){
						//	stuck = 0;
						//}
					}
				}


				obj_ctrl.AI_attack(g_v_tanks_AI[i], vec_GetPath, v_bullet_player, v_bullet_AI);
				g_v_tanks_AI[i].GetDistance(g_v_tanks_player[0].pos);
				g_v_tanks_AI[i].GetAngle(g_v_tanks_player[0].pos);
				//system("pause");


			}
		}
			//AI子弹遍历打印

			for (unsigned int i = 0; i < v_bullet_AI.size(); i++)
			{
				//子弹的异步打印输出
				if ((clock() - v_bullet_AI[i].init_time) > v_bullet_AI[i].bullet_conf[v_bullet_AI[i].type].speed)
				{
					v_bullet_AI[i].init_time = clock();
					//擦除
					v_bullet_AI[i].bullet_wipe();

					//玩家子弹状态码：1，0,-1,-2

					v_bullet_AI[i].BulletBorder();
					v_bullet_AI[i].BulletMap();

					obj_ctrl.collision_BulletInter(v_bullet_AI[i], v_bullet_player);
					//绘画
					v_bullet_AI[i].bullet_draw();


					short victim_ID = obj_ctrl.collision_TankBullet(v_bullet_AI[i]);

					//子弹处理
					vector<bullet>::iterator it = v_bullet_player.begin();
					if (v_bullet_AI[i].bullet_conf[v_bullet_AI[i].type].max_length <= 0)//射程消失--max_length
					{
						v_bullet_AI[i].bullet_wipe();
						vec_erase_optimize_index(v_bullet_AI, i);
					}
					else if (v_bullet_AI[i].state == 0)//遇到地图障碍物消失--state
					{
						v_bullet_AI[i].bullet_wipe();
						vec_erase_optimize_index(v_bullet_AI, i);
					}
					//命中player坦克
					else if (victim_ID)
					{
						//WriteChar(20, N1 + 4, (char*)"11111", 1, 0xA);
						//Sleep(1000);
						//WriteChar(20, N1 + 4, (char*)"      ", 1, 0xA);
						//打击坦克,返回非0时表示应该清除的player对象ID
						short death_playerID = obj_ctrl.hit_tank_player(g_v_tanks_player, victim_ID);
						if (death_playerID)
						{
							//WriteChar(20,N1+4,(char*)"error",1,0xA);
							//Sleep(2000);
							vec_erase_optimize_item(g_v_tanks_player, death_playerID);
						}

						//消除子弹
						v_bullet_AI[i].bullet_wipe();
						vec_erase_optimize_index(v_bullet_AI, i);


					}



				}
			}
			//玩家操作输入
			if (!g_v_tanks_player.empty()) {

				if (_kbhit())
				{
					char c = 0;
					while (_kbhit() != 0) {
						c = _getch();
					}
					//if (_kbhit() != 0)
					//{
					//	c = _getch();
					//}

					//坦克移动速度
					//Sleep(20);

					//记录历史
					if (MODE == c || UP == c || DOWN == c || LEFT == c || RIGHT == c)
					{
						history_info stc_history;
						stc_history.mode = g_v_tanks_player[0].mode;
						stc_history.dir = g_v_tanks_player[0].dir;
						stc_history.pos = g_v_tanks_player[0].pos;
						//g_v_tanks_player[0].v_history_tank.push_back(stc_history);
						//if (g_v_tanks_player[0].v_history_tank.size() > MAX_tank_history)
						//{
						//	vector<history_info>::iterator it = g_v_tanks_player[0].v_history_tank.begin();
						//	g_v_tanks_player[0].v_history_tank.erase(it);
						//}
						g_v_tanks_player[0].flag_back = 0;
					}

					switch (c)
					{
					case MODE:
					{						//消息区域显示选项
			/*			short mode = 1;
						scanf_s("%hd", &mode);
						g_v_tanks_player[0].wipe_tank((char*)"  ", g_v_tanks_player[0].pos, g_v_tanks_player[0].p, g_v_tanks_player[0].mode, g_v_tanks_player[0].dir);
						g_v_tanks_player[0].mode = mode;*/

						//切换模式
						g_v_tanks_player[0].wipe_tank();
						g_v_tanks_player[0].last_mode = g_v_tanks_player[0].mode;
						g_v_tanks_player[0].last_dir = g_v_tanks_player[0].dir;
						g_v_tanks_player[0].last_pos = g_v_tanks_player[0].pos;
						if (g_v_tanks_player[0].mode == 5)
						{
							g_v_tanks_player[0].mode = 0;
						}
						else
						{
							g_v_tanks_player[0].mode++;
						}
					}
					break;
					case UP:
					{
						g_v_tanks_player[0].move_tank(UP);
						//g_v_tanks_player[0].history_tank();
					}
					break;
					case DOWN:
					{
						g_v_tanks_player[0].move_tank(DOWN);
						//g_v_tanks_player[0].history_tank();
					}
					break;
					case LEFT:
					{
						g_v_tanks_player[0].move_tank(LEFT);
						//g_v_tanks_player[0].history_tank();
					}
					break;
					case RIGHT:
					{
						g_v_tanks_player[0].move_tank(RIGHT);
						//g_v_tanks_player[0].history_tank();
					}
					break;
					case VK_BACK:
					{
						g_v_tanks_player[0].back_tank();
						//g_v_tanks_player[0].history_tank();
					}
					break;
					case VK_ESCAPE:
					{
						//坦克全局对象
						if (!g_v_tanks_player.empty())
						{
							g_v_tanks_player.clear();//玩家坦克
						}
						if (!g_v_tanks_AI.empty())
						{
							g_v_tanks_AI.clear();//坦克敌方
						}

						//所有的静态变量都需要重置！！！.。。
						//tank_player1::count = 0;
						//tank_AI::count_death = 0;
						//bullet::count_AI = bullet::count_player = 0;
						//g_loadNotNew = 0;
						login_flag = 1;
						return login_flag;
					}
					break;
					case FIRE:
					{
						//更新统计数据
						g_v_tanks_player[0].Fires++;
						//坦克传递给子弹对象
						obj_ctrl.tank_fire(g_v_tanks_player[0], v_bullet_player);
					}
					break;
					case PAUSE:
					{
						obj_ctrl.pause_save(v_bullet_AI, v_bullet_player);
					}
					break;
					default:
						break;
					}

					//玩家坦克和地图以及边界碰撞
					char cross_tank_player_border = g_v_tanks_player[0].collision_TankBorder();
					char cross_tank_player_map = g_v_tanks_player[0].collision_TankMap();
					char cross_tank_inter_both = g_v_tanks_player[0].collision_TankInter();
					char cross = cross_tank_player_border || cross_tank_player_map || cross_tank_inter_both;
					//printf("%d",collision);
					g_v_tanks_player[0].execute(cross);

				}

			}
		
			//玩家子弹遍历打印

			for (unsigned int i = 0; i < v_bullet_player.size(); i++)
			{
				//子弹的异步打印输出
				if ((clock() - v_bullet_player[i].init_time) >
					v_bullet_player[i].bullet_conf[v_bullet_player[i].type].speed)
				{
					v_bullet_player[i].init_time = clock();
					//Sleep(100);
					//擦除
					v_bullet_player[i].bullet_wipe();

					//玩家子弹状态码：1，0,-1,-2

					v_bullet_player[i].BulletBorder();
					v_bullet_player[i].BulletMap();

					//子弹碰撞
					obj_ctrl.collision_BulletInter(v_bullet_player[i], v_bullet_AI);

					//小心双发子弹遍历匹配时忽略停在半路上的另一颗
					//-1忽略[0],-2忽略[1]

					//绘画
					v_bullet_player[i].bullet_draw();



					//击中坦克检测
					short victim_ID = obj_ctrl.collision_TankBullet(v_bullet_player[i]);



					//子弹处理
					vector<bullet>::iterator it = v_bullet_player.begin();
					if (v_bullet_player[i].bullet_conf[v_bullet_player[i].type].max_length <= 0)//射程消失
					{
						v_bullet_player[i].bullet_wipe();
						vec_erase_optimize_index(v_bullet_player, i);
						//v_bullet_player.erase(it + i);
					}
					else if (v_bullet_player[i].state == 0)//遇到地图障碍物消失
					{
						v_bullet_player[i].bullet_wipe();
						vec_erase_optimize_index(v_bullet_player, i);

						//v_bullet_player.erase(it + i);
					}
					//命中敌方坦克
					else if (victim_ID)
					{
						//打击坦克
						obj_ctrl.hit_tank_AI(g_v_tanks_AI, victim_ID);
						//消除子弹
						v_bullet_player[i].bullet_wipe();
						vec_erase_optimize_index(v_bullet_player, i);
					}

				}
			}


		


		

	}
	login_flag = 0;
	return login_flag;
}

//bool double_player_game(bool login_flag, short v_size) {
//
//	tank_player1 obj_tank1(8, 8);
//	tank_player1 obj_tank2(78, 34);
//	g_v_tanks_player.push_back(obj_tank1);
//	g_v_tanks_player.push_back(obj_tank2);
//
//	control obj_ctrl;				//初始化控制引擎
//	vector<bullet>v_obj_bullet;			//初始化子弹vector
//	//clock_t bullet_start1 = clock();//初始化子弹时间vector
//	//vector<clock_t>v_bullet_start_time;
//	//clock_t tank_init1 = clock();
//	//vector<clock_t>v_tank_start_time;//初始化坦克时间vector
//	vector<vector<bullet>>v_bullets_init;//初始化子弹vector
//
//	for (short i = 0; i < v_size; i++)
//	{
//		bullet obj_bullet;
//		v_obj_bullet.push_back(obj_bullet);
//
//		//clock_t bullet_start_time = clock();
//		//v_bullet_start_time.push_back(bullet_start_time);
//
//		clock_t tank_start_time = clock();
//		g_v_tanks_player[i].tank_time=tank_start_time;
//
//		vector<bullet>v_bullet_init;
//		v_bullets_init.push_back(v_bullet_init);
//	}
//
//	g_obj_remind.cls_news();
//	WriteChar(2, N1 + 2, (char*)"游戏开始！", 1, 0xA);
//	Show_cursor(0);
//
//	short tank_index = 2;
//	while (true)
//	{
//		Sleep(50);
//		//地图自动刷新
//		g_obj_map_buffer.map_renew();
//
//		//坦克自动刷新
//		for (short i = 0; i < v_size; i++)
//		{
//			if (clock() - g_v_tanks_player[i].tank_time > tank_renew_speed)
//			{
//				g_v_tanks_player[i].tank_time = clock();
//				g_v_tanks_player[i].draw_tank();
//			}
//		}
//
//		//printf("xxxx");
//
//		if (KEYDOWN(VK_ESCAPE))
//		{
//			login_flag = 1;
//			break;
//		}
//
//		//函数参数为坦克对象
//		//坦克1
//		tank_index= 0;
//
//		//模式
//		if (KEYDOWN('E'))
//		{
//			g_v_tanks_player[0].wipe_tank();
//			g_v_tanks_player[0].last_mode = g_v_tanks_player[0].mode;
//			g_v_tanks_player[0].last_dir = g_v_tanks_player[0].dir;
//			g_v_tanks_player[0].last_pos = g_v_tanks_player[0].pos;
//			if (g_v_tanks_player[0].mode == 5)
//			{
//				g_v_tanks_player[0].mode = 0;
//			}
//			else
//			{
//				g_v_tanks_player[0].mode++;
//			}
//			g_v_tanks_player[0].history_tank();
//		}
//		//方向
//		if (KEYDOWN('W'))
//		{
//			g_v_tanks_player[0].move_tank(UP);
//			g_v_tanks_player[0].history_tank();
//
//		}
//		if (KEYDOWN('S'))
//		{
//			g_v_tanks_player[0].move_tank(DOWN);
//			g_v_tanks_player[0].history_tank();
//
//		}
//		if (KEYDOWN('A'))
//		{
//			g_v_tanks_player[0].move_tank(LEFT);
//			g_v_tanks_player[0].history_tank();
//			//printf("111111111");
//
//		}
//		if (KEYDOWN('D'))
//		{
//			g_v_tanks_player[0].move_tank(RIGHT);
//			g_v_tanks_player[0].history_tank();
//
//		}
//
//		if (KEYDOWN(VK_BACK))
//		{
//			g_v_tanks_player[0].wipe_tank();
//			//赋值vector中最后一个的信息
//			if (!g_v_tanks_player[0].flag_back)
//			{
//				g_v_tanks_player[0].flag_back = 1;
//			}
//			else
//			{
//				g_v_tanks_player[0].flag_back++;
//			}
//			int index = g_v_tanks_player[0].v_history_tank.size() - g_v_tanks_player[0].flag_back;
//			//int index = total_size - flag_back;
//			if (index < 0)
//			{
//				index = 0;
//			}
//			g_v_tanks_player[0].mode = g_v_tanks_player[0].v_history_tank[index].mode;
//			g_v_tanks_player[0].dir = g_v_tanks_player[0].v_history_tank[index].dir;
//			g_v_tanks_player[0].pos = g_v_tanks_player[0].v_history_tank[index].pos;
//		}
//		//g_v_tanks_player[tank_index].draw_tank(0x7, g_v_tanks_player[tank_index].design, g_v_tanks_player[tank_index].pos,
//		//	g_v_tanks_player[tank_index].p, g_v_tanks_player[tank_index].mode, g_v_tanks_player[i].dir);
//		if (KEYDOWN('F'))
//		{
//			//坦克传递给子弹对象
//			PCOORD p_muzzle = g_v_tanks_player[0].get_muzzzle();
//			char bullet_type = g_v_tanks_player[0].mode - 1;
//			char bullet_dir = g_v_tanks_player[0].dir;
//
//			bullet obj_bullet;
//			obj_bullet.origin[0].X = (*p_muzzle).X;
//			obj_bullet.origin[0].Y = (*p_muzzle).Y;
//			obj_bullet.origin[1].X = (*(p_muzzle + 1)).X;
//			obj_bullet.origin[1].Y = (*(p_muzzle + 1)).Y;
//			//	obj_bullet.origin[1] = *(p_muzzle+1);
//			if (g_v_tanks_player[0].mode)
//			{
//				obj_bullet.type = bullet_type;
//			}
//			else
//			{
//				break;
//			}
//			obj_bullet.dir = bullet_dir;
//
//			clock_t this_time = clock();
//			obj_bullet.init_time = this_time;
//
//			v_bullets_init[0].push_back(obj_bullet);
//
//			//初始子弹和边界判断
//			char collision_bullet_border = v_bullet_player[i].BulletBorder();
//			char collision_bullet_map = v_bullet_player[i].BulletMap();
//			v_bullet_player[i].bullet_draw(collision_bullet_map);
//			char collison = collision_bullet_border || collision_bullet_map;
//
//			v_bullets_init[0][v_bullets_init.size() - 1].bullet_conf->hp= v_bullets_init[0][v_bullets_init.size() - 1].bullet_draw
//			();
//			if (!v_bullets_init[0][v_bullets_init.size() - 1].bullet_conf->hp)
//			{
//				v_bullets_init[0].pop_back();
//			}
//		}
//
//		//坦克2
//		tank_index = 1;
//		if (KEYDOWN('O'))
//		{
//			g_v_tanks_player[1].wipe_tank();
//			g_v_tanks_player[1].last_dir = g_v_tanks_player[1].dir;
//			g_v_tanks_player[1].last_pos = g_v_tanks_player[1].pos;
//			if (g_v_tanks_player[1].mode == 5)
//			{
//				g_v_tanks_player[1].mode = 0;
//			}
//			else
//			{
//				g_v_tanks_player[1].mode++;
//			}
//			g_v_tanks_player[1].history_tank();
//
//		}
//
//		if (KEYDOWN('I'))
//		{
//			g_v_tanks_player[1].move_tank(UP2);
//			g_v_tanks_player[1].history_tank();
//
//		}
//		if (KEYDOWN('K'))
//		{
//			g_v_tanks_player[1].move_tank(DOWN2);
//			g_v_tanks_player[1].history_tank();
//
//		}
//		if (KEYDOWN('J'))
//		{
//			g_v_tanks_player[1].move_tank(LEFT2);
//			g_v_tanks_player[1].history_tank();
//			printf("22222222222");
//
//		}
//		if (KEYDOWN('L'))
//		{
//			g_v_tanks_player[1].move_tank(RIGHT2);
//			g_v_tanks_player[1].history_tank();
//
//		}
//
//		if (KEYDOWN(VK_DELETE))
//		{
//			g_v_tanks_player[1].wipe_tank();
//			//赋值vector中最后一个的信息
//			if (!g_v_tanks_player[1].flag_back)
//			{
//				g_v_tanks_player[1].flag_back = 1;
//			}
//			else
//			{
//				g_v_tanks_player[1].flag_back++;
//			}
//			int index = g_v_tanks_player[1].v_history_tank.size() - g_v_tanks_player[1].flag_back;
//			//int index = total_size - flag_back;
//			if (index < 0)
//			{
//				index = 0;
//			}
//			g_v_tanks_player[1].mode = g_v_tanks_player[1].v_history_tank[index].mode;
//			g_v_tanks_player[1].dir = g_v_tanks_player[1].v_history_tank[index].dir;
//			g_v_tanks_player[1].pos = g_v_tanks_player[1].v_history_tank[index].pos;
//		}
//		if (KEYDOWN('H'))
//		{
//			//坦克传递给子弹对象
//			PCOORD p_muzzle = g_v_tanks_player[1].get_muzzzle();
//			char bullet_type = g_v_tanks_player[1].mode - 1;
//			char bullet_dir = g_v_tanks_player[1].dir;
//
//			bullet obj_bullet;
//			obj_bullet.origin[0].X = (*p_muzzle).X;
//			obj_bullet.origin[0].Y = (*p_muzzle).Y;
//			obj_bullet.origin[1].X = (*(p_muzzle + 1)).X;
//			obj_bullet.origin[1].Y = (*(p_muzzle + 1)).Y;
//			//	obj_bullet.origin[1] = *(p_muzzle+1);
//			if (g_v_tanks_player[1].mode)
//			{
//				obj_bullet.type = bullet_type;
//			}
//			else
//			{
//				break;
//			}
//			obj_bullet.dir = bullet_dir;
//
//			clock_t this_time = clock();
//			obj_bullet.init_time = this_time;
//
//			v_bullets_init[1].push_back(obj_bullet);
//
//			//初始子弹和边界判断
//			v_bullets_init[1][v_bullets_init.size() - 1].bullet_conf->hp = 
//				v_bullets_init[1][v_bullets_init.size() - 1].bullet_draw
//			();
//			if (!v_bullets_init[1][v_bullets_init.size() - 1].bullet_conf->hp)
//			{
//				v_bullets_init[1].pop_back();
//			}
//		}
//
//		//坦克和地图以及边界碰撞
//		for (short i = 0; i < v_size; i++)
//		{
//			char cross_tank_player_border = g_v_tanks_player[1].collision_TankBorder();
//			char cross_tank_player_map = g_v_tanks_player[1].collision_TankMap();
//			char cross = cross_tank_player_border || cross_tank_player_map;
//			//printf("%d",collision);
//			g_v_tanks_player[1].execute(cross);
//		}
//
//		//子弹处理
//		for (unsigned int j = 0; j < v_bullets_init[1].size(); j++)
//			{
//				for (short i = 0; i < v_size; i++)
//				{
//					if ((clock() - v_bullets_init[i][j].init_time) > v_bullets_init[i][j].bullet_conf->speed)
//					{
//						v_bullets_init[i][j].init_time = clock();
//						//擦除
//						v_obj_bullet[i].bullet_wipe();
//						//绘画
//						short& distance = v_bullets_init[i][j].bullet_conf->max_length;//射程
//
//						char bullet_state = v_obj_bullet[i].bullet_draw();
//
//
//						if (distance <= 0)//射程消失
//						{
//							v_obj_bullet[i].bullet_wipe();
//							vector<bullet>::iterator it = v_bullets_init[i].begin();
//							v_bullets_init[i].erase(it + i);
//
//						}
//						else if (!bullet_state)//遇到地图障碍物显示
//						{
//							vector<bullet>::iterator it = v_bullets_init[i].begin();
//							v_bullets_init[i].erase(it + i);
//						}
//
//					}
//				}
//				
//			}
//	}
//	return login_flag;
//}
