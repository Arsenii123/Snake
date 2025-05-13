#include <iostream>
#include <windows.h>
using namespace std;
#pragma comment(lib, "winmm.lib")

DWORD WINAPI MusicThread(void* param)
{
	PlaySoundA("C:\\Snake_music\\Cipher2_chosic.com_.WAV", NULL, SND_NODEFAULT | SND_LOOP);
	return 0;
}
