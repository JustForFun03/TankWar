
#include "welcome_image.h"
#include <stdio.h>
#include <windows.h>
#include "show.h"
#include "map.h"

#define Nx 80  
#define Ny 34
//#define path_login_image "D:\\Files_and_doc\\visual_studio2017\\tank_war\\resource\\WelcomeImage.txt"//��Ҫ�޸�����
#define path_login_image "..\\resource\\WelcomeImage.txt"
 
extern map_border g_obj_map_border;//��ͼ�߽�

void welcome_image::image() {
	map_editor obj_map_buffer;
	FILE* pfile_load=NULL;
	fopen_s(&pfile_load, path_login_image, "rb");
	for (short coord_x = 0; coord_x < N2 - 1; coord_x++)
	{
		for (short coord_y = 0; coord_y < N1 - 1; coord_y++)
		{
			fread_s(obj_map_buffer.Stc_arr_map, (N1 - 1)*(N2 - 1) * sizeof(Stc_map_element), sizeof(Stc_map_element), (N1 - 1)*(N2 - 1), pfile_load);

		}
	}
	fclose(pfile_load);

	obj_map_buffer.map_editor_init();
	g_obj_map_border.show_map_border();

	WriteChar(Nx + 20, Ny, (char*)"��л ", 1, 0xF);
	WriteChar(Nx + 16, Ny, (char*)"\t\t 15PB", 1, 6);
	WriteChar(Nx + 16, Ny + 1, (char*)"\t\t ��̩��", 1, 6);
	WriteChar(Nx + 36, Ny + 1, (char*)"\t����ɭ", 1, 6);
	WriteChar(Nx + 16, Ny + 2, (char*)"\t\t ������", 1, 6);
	WriteChar(Nx + 36, Ny + 2, (char*)"\t������ ������", 1, 6);
	WriteChar(Nx + 20, Ny + 4, (char*)"��Ȩ", 1, 0xF);
	WriteChar(Nx + 20, Ny + 6, (char*)"����", 1, 0xF);
	WriteChar(Nx + 16, Ny + 4, (char*)"\t\t ��Ц��", 1, 6);
	WriteChar(Nx + 16, Ny + 6, (char*)"\t\t 2022/06/23", 1, 6);
	WriteChar(2, N1 + 1, (char*)"��ӭ����̹�˴�ս��Ϸ", 1, 0xA);
}