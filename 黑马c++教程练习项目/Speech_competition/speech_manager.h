//
// Created by shexuan on 2021/1/26.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "speaker.h"
using namespace std;

#ifndef SPEECH_COMPETITION_SPEECH_MANAGER_H
#define SPEECH_COMPETITION_SPEECH_MANAGER_H


/* 管理类
 * 功能：
 *  - 提供菜单界面与用户交互；
 *  - 对演讲比赛流程进行控制；
 *  - 与文件的读写交互.
 *
 */
class SpeechManager {
public:
    // 构造函数
    SpeechManager();

    // 展示菜单
    void show_menu();

    // 初始化程序
    void init_speech();

    // 创建选手
    void create_speaker();

    // 人员抽签
    void speech_sample();

    // 开始比赛，创建比赛流程
    void start_speech();

    // 开始演讲评分
    void battle(const vector<int> &v);

    // 选出优胜者
    void filter_victory(const vector<int> &v);

    // 保存比赛最后前三甲信息
    void saveRecord();

    // 从文件中加载往届比赛信息
    void load_records();

    // 显示往届比赛信息
    void show_records();

    // 清空比赛记录
    void clear_records();

    // 退出程序
    void exitSystem();

    // 析构函数
    ~SpeechManager();

    // 成员属性
    // 保存第一轮选手编号容器, 第一轮分两个组
    vector<int> v1;
    vector<int> v11;
    vector<int> v12;

    // 保存第二轮选手编号容器
    vector<int> v2;

    // 胜出前3名选手容器
    vector<int> vVictory;

    // 存放编号以及对应的选手信息
    map<int, Speaker> m_speaker;

    // 记录第几轮比赛
    int m_index;

    // 文件是否为空
    bool fileIsEmpty;

    // 存放往届纪录的容器, map中key表示第几届，vector中为从文件读取出来的数据
    map<int, vector<string>> m_record;
};


#endif //SPEECH_COMPETITION_SPEECH_MANAGER_H
