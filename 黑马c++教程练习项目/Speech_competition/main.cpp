#include <iostream>

/* 项目案例：演讲比赛
 * 比赛规则：
 *  - 学校举行一场演讲比赛，共12人参加。比赛共两轮，第一轮为淘汰赛，第二轮为决赛；
 *  - 每名选手都有对应的编号，如10001~10012；
 *  - 比赛方式：分组比赛，每组六个人；
 *  - 第一轮分为两个小组，整体按照抽前后的选手编号顺序进行比赛；
 *  - 十个评委给每名选手打分，去除最高分和最低分，求得平均分为本轮选手的成绩；
 *  - 当小组演讲完后，淘汰组内排名最后的三个选手，前三名晋级，进入下一轮比赛；
 *  - 第二轮为决赛，前三名胜出；
 *  - 每轮比赛过后，都要显示晋级选手信息；
 *
 * 程序功能：
 *  - 开始演讲比赛：完成整届比赛的流程，每个比赛阶段需要给用户一个提示，用户按下任意键后继续下一阶段；
 *  - 查看往届纪录：查看之前比赛前三名结果，每次比赛都会记录到文件中，文件用.csv后缀名保存；
 *  - 清空比赛记录：将文件中数据清空；
 *  - 退出比赛：退出当前程序；
 *
 */

#pragma once

#include <iostream>
#include <string>
#include "speech_manager.h"
using namespace std;

int main() {
    SpeechManager sm;
//    sm.m_index = 1;
//    sm.speech_sample();
//    sm.battle(sm.v11);
//    sm.battle(sm.v12);
    // sm.start_speech();
    // sm.m_index = 2;
    // sm.speech_sample();
    // sm.show_menu();
    //sm.load_records();
    //sm.show_records();

//    for (map<int, Speaker>::iterator it=sm.m_speaker.begin(); it!=sm.m_speaker.end();it++){
//        cout << "选手编号: " << it->first
//            << "\t选手名字：" << it->second.m_name
//            << "\t选手得分：" << it->second.m_score[0] << "," << it->second.m_score[1] << endl;
//    }

    int select;
    while (true){
        sm.show_menu();
        cout << "请输入您的选择：" << endl;
        cin >> select;
        switch (select){
            case 0:
                // 退出
                sm.exitSystem();
                break;
            case 1:
                // 开始比赛
                sm.start_speech();
                break;
            case 2:
                // 查看往届比赛记录
                sm.show_records();
                break;
            case 3:
                // 清空比赛记录
                sm.clear_records();
                break;
            default:
                system("clear"); // 清屏
                break;
        }
    }

    return 0;
}