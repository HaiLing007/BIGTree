#include <windows.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <direct.h>
using namespace std;

string GetFullPath(const string& fileName) {
    char buffer[MAX_PATH];
    _getcwd(buffer, MAX_PATH);
    string fullPath = string(buffer) + "\\" + fileName;
    return fullPath;
}

void ChangeWallpaper(const string& imagePath) {
    if (SystemParametersInfoA(
            SPI_SETDESKWALLPAPER,
            0,
            const_cast<char*>(imagePath.c_str()),
            SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
        )) {
        cout << "Wallpaper changed successfully!" << endl;
        cout << "Path: " << imagePath << endl;
    } else {
        cout << "Failed to change wallpaper. Error: " << GetLastError() << endl;
    }
}

int main() {
    string imagePath = GetFullPath("main.png");
	cout << "反希沃强制更换壁纸系统已启动"<<endl;
	cout << "请不要退出可能会出现无法解释的Bug"<<endl;
	cout << "放心，很快的"<<endl;
    cout << "Program started. Will change wallpaper in 10 seconds..." << endl;
    cout << "Image path: " << imagePath << endl;
    cout << "Waiting..." << endl;

    this_thread::sleep_for(chrono::seconds(10));

    cout << "Time's up! Changing wallpaper..." << endl;
    cout << "成功更换！程序在3秒后自动退出" << endl;
    ChangeWallpaper(imagePath);

    cout << "Program will exit in 3 seconds..." << endl;
    this_thread::sleep_for(chrono::seconds(3));

    return 0;
}
