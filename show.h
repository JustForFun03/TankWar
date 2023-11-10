#pragma once
#include<windows.h>

void Show_cursor(bool is_show);
void WriteChar(short x, short y, char* pStr, int, WORD);
//void WriteChar(short x, short y, int,WORD);
void WriteChar(short x, short y, char,WORD);
void WriteChar(short x, short y, unsigned int,WORD);
void WriteChar(short x, short y, double,WORD);
