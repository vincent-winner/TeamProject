#pragma once
#ifndef LOGO_H

#define LOGO_H

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

namespace logo {
	
	//输出Logo的速度，数值越大速度越快
	#define PRINT_LOGO_SPEED 6
	
	const char* const name[6]={ "\t\t朱琳","\t\t高浩然","\t\t王雪","\t\t周海龙","\t\t杨志蕊","\t\t龚俊" };

	string ZhuLin() {  return string("\t\t\t _______             _      _       \n\t\t\t\t\t|___  / |           | |    (_)      \n\t\t\t\t\t   / /| |__  _   _  | |     _ _ __  \n\t\t\t\t\t  / / | '_ \\| | | | | |    | | '_ \\ \n\t\t\t\t\t / /__| | | | |_| | | |____| | | | |\n\t\t\t\t\t/_____|_| |_|\\__,_| |______|_|_| |_|\n\t\t\t\t\t"); }
	string GaoHaoRan() { return string("\t\t\t  _____               _    _               _____             \n\t\t\t\t\t / ____|             | |  | |             |  __ \\            \n\t\t\t\t\t| |  __  __ _  ___   | |__| | __ _  ___   | |__) |__ _ _ __  \n\t\t\t\t\t| | |_ |/ _` |/ _ \\  |  __  |/ _` |/ _ \\  |  _  // _` | '_ \\ \n\t\t\t\t\t| |__| | (_| | (_) | | |  | | (_| | (_) | | | \\ \\ (_| | | | |\n\t\t\t\t\t \\_____|\\__,_|\\___/  |_|  |_|\\__,_|\\___/  |_|  \\_\\__,_|_| |_|\n\t\t\t\t\t"); }
	string WangXue() { return string("\t\t\t__          __                                 \n\t\t\t\t\t\\ \\        / /                                 \n\t\t\t\t\t \\ \\  /\\  / /_ _ _ __   __ _  __  ___   _  ___ \n\t\t\t\t\t  \\ \\/  \\/ / _` | '_ \\ / _` | \\ \\/ / | | |/ _ \\\n\t\t\t\t\t   \\  /\\  / (_| | | | | (_| |  >  <| |_| |  __/\n\t\t\t\t\t    \\/  \\/ \\__,_|_| |_|\\__, | /_/\\_\\\\__,_|\\___|\n\t\t\t\t\t                        __/ |                  \n\t\t\t\t\t                       |___/                   \n\t\t\t\t\t"); }
	string ZhouHaiLong() { return string("\t\t\t _______                   _    _       _   _                       \n\t\t\t\t\t|___  / |                 | |  | |     (_) | |                      \n\t\t\t\t\t   / /| |__   ___  _   _  | |__| | __ _ _  | |     ___  _ __   __ _ \n\t\t\t\t\t  / / | '_ \\ / _ \\| | | | |  __  |/ _` | | | |    / _ \\| '_ \\ / _` |\n\t\t\t\t\t / /__| | | | (_) | |_| | | |  | | (_| | | | |___| (_) | | | | (_| |\n\t\t\t\t\t/_____|_| |_|\\___/ \\__,_| |_|  |_|\\__,_|_| |______\\___/|_| |_|\\__, |\n\t\t\t\t\t                                                               __/ |\n\t\t\t\t\t                                                              |___/ \n\t\t\t\t\t"); }
	string YangZhiRui() { return string("\t\t\t__     __                 _______     _   _____       _ \n\t\t\t\t\t\\ \\   / /                |___  / |   (_) |  __ \\     (_)\n\t\t\t\t\t \\ \\_/ /_ _ _ __   __ _     / /| |__  _  | |__) |   _ _ \n\t\t\t\t\t  \\   / _` | '_ \\ / _` |   / / | '_ \\| | |  _  / | | | |\n\t\t\t\t\t   | | (_| | | | | (_| |  / /__| | | | | | | \\ \\ |_| | |\n\t\t\t\t\t   |_|\\__,_|_| |_|\\__, | /_____|_| |_|_| |_|  \\_\\__,_|_|\n\t\t\t\t\t                   __/ |                                \n\t\t\t\t\t                  |___/                                 \n\t\t\t\t\t"); }
	string GongJun() { return string("\t\t\t  _____                          _             \n\t\t\t\t\t / ____|                        | |            \n\t\t\t\t\t| |  __  ___  _ __   __ _       | |_   _ _ __  \n\t\t\t\t\t| | |_ |/ _ \\| '_ \\ / _` |  _   | | | | | '_ \\ \n\t\t\t\t\t| |__| | (_) | | | | (_| | | |__| | |_| | | | |\n\t\t\t\t\t \\_____|\\___/|_| |_|\\__, |  \\____/ \\__,_|_| |_|\n\t\t\t\t\t                     __/ |                     \n\t\t\t\t\t                    |___/                      \n\t\t\t\t\t"); }
	
	void PrintLogo(string logo)
	{
		if(logo.compare(ZhuLin())==0){
			cout << "\t\t朱琳";
		}
		else if (logo.compare(GaoHaoRan()) == 0) {
			cout << "\t\t高浩然";
		}
		else if (logo.compare(WangXue()) == 0) {
			cout << "\t\t王雪";
		}
		else if (logo.compare(ZhouHaiLong()) == 0) {
			cout << "\t\t周海龙";
		}
		else if (logo.compare(YangZhiRui()) == 0) {
			cout << "\t\t杨志蕊";
		}
		else if (logo.compare(GongJun()) == 0) {
			cout << "\t\t龚俊";
		}
		char* logoArray = new char[strlen(logo.c_str())+1];
		strcpy(logoArray,logo.c_str());
		for (int i = 0; i < strlen(logo.c_str()); i++) 
		{ 
			cout << logoArray[i]; 
			if (i % PRINT_LOGO_SPEED == 0) Sleep(10);
		}
		cout << endl << endl;
		delete[] logoArray;
	}

	void PrintAllLogo(){
		system("color 06");
		PrintLogo(ZhuLin());
		PrintLogo(GaoHaoRan());
		PrintLogo(WangXue());
		PrintLogo(ZhouHaiLong());
		PrintLogo(YangZhiRui());
		PrintLogo(GongJun());
		system("pause > nul");
	}
}

#endif // !LOGO_H
