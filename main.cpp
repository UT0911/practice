#include "DxLib.h"
#include "test.hpp"

//プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    if (DxLib_Init() == -1) //DXライブラリ初期化処理
    {
        return -1; //エラーが起きたら直ちに終了
    }

    ChangeWindowMode(true); //ウィンドウのモード切替
    SetGraphMode(800, 800, 32); //画面サイズ、解像度指定
    SetMouseDispFlag(true); //マウスの表示設定
    SetFontSize(60);

    while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
        ClearDrawScreen();

        DrawFormatString(0, 0, GetColor(255, 255, 255),"%d",member1());
        DrawFormatString(0, 100, GetColor(255, 255, 255),"%d",member2());
        DrawFormatString(0, 200, GetColor(255, 255, 255),"%d",member3());
        DrawFormatString(0, 300, GetColor(255, 255, 255),"%d",member4());
        DrawFormatString(0, 400, GetColor(255, 255, 255),"%d",member5());
        DrawFormatString(0, 500, GetColor(255, 255, 255),"%d",member6());

        ScreenFlip();
    }

    DxLib_End(); //DXライブラリ使用の終了処理

    return 0; //ソフトの終了 
}