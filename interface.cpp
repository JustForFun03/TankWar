#include "interface.h"
#include<stdlib.h>
#include<windows.h>
#include"show.h"
#pragma comment(lib,"winmm.lib")

void C_interface::console_set() {
	system("title Tank War");//…Ë÷√øÿ÷∆Ã®±ÍÃ‚
	system("mode con cols=186 lines=52");
	//	system("mode con cols=200 lines=80");
	Show_cursor(0);
}

//±≥æ∞“Ù¿÷
void C_interface::sound_set() {
	//PlaySoundA("D:\\Files_and_doc\\visual_studio2017\\Ã∞≥‘…ﬂ\\1.wav",NULL,SND_ASYNC | SND_NODEFAULT| SND_LOOP);
	PlaySound(TEXT("D:\\save_Ã∞≥‘…ﬂ\\1.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NODEFAULT);
}
