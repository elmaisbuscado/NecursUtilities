// NecursRemover.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include "util.h"


void printNecureLogo();
int sendNoBufferCommand(wchar_t* str_tid, DWORD command, LPCSTR message, WORD color);
BOOL checkRk(wchar_t* str_tid);
int getOut(int code, WORD color, char* str);
void colorPrint(WORD color, char* str, DWORD param);
 
int main()
{
	DWORD uninstallCommand = 0x00228000;
	LSTATUS status;
	int attempts = 0;
	wchar_t str_tid[10];

	printNecureLogo();
	_itow_s((int)GetCurrentThreadId(), str_tid,10,10);

	printf(" I will now try to uninstall Necurs Driver :)\n");


	status = sendNoBufferCommand(str_tid, uninstallCommand, " Stage 1 - Trying to remove Necurs Rootkit",WHITE);
	if (status != ERROR_ACCESS_DENIED)
		return getOut(1, YELLOW, "\n I do not detect Necurs presence\n");

	printf(" Stage 2 - Testing infection status\n");
	while (attempts++ < 7 && status!= ERROR_SUCCESS) {
		status = sendNoBufferCommand(str_tid, uninstallCommand, NULL,NULL);
		printf("   `--> ATTEMPT %d\n", attempts);
		Sleep(1000*attempts);
	}

	return checkRk(str_tid) ? 
		getOut(1, RED, " Something went wrong! Rootkit possibly not removed from system!"):
		getOut(0, GREEN, "\n Rootkit successfully uninstalled") ;


	

}