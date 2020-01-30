// NecursDetector.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "util.h"



BOOL getRkInfo(wchar_t* str_tid, RK_INFO_S* info);
BOOL checkRk(wchar_t* str_tid);
void printRkInfo(RK_INFO_S* info);
void printNecsistsLogo();
void colorPrint(WORD color, char* str,DWORD param);




int main()
{
	DWORD tid;
	RK_INFO_S info;
	wchar_t str_tid[10];

	tid = GetCurrentThreadId();
	_itow_s((int)tid, str_tid, 10, 10);
	
	printNecsistsLogo(); 

	colorPrint(RED, "\n Necurs Detection Utility\n", NULL);
	colorPrint(WHITE, "\n Detecting Necurs Driver :)\n", NULL);

	if (checkRk(str_tid)) {
		colorPrint(RED, "\n Necurs found on system!!\n", NULL);
		getRkInfo(str_tid, &info);
		printRkInfo(&info);
		colorPrint(GREEN, "\n You could use NeCure to clean system!!\n", NULL);
	}
	else
		colorPrint(GREEN, "\n Necurs not found on system\n", NULL);

	colorPrint(WHITE, "\n Press any key to Continue\n", NULL);
	getchar();

	return 0;
}