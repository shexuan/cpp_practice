//
// Created by shexuan on 2021/1/26.
//
#pragma once
#include "speech_manager.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <numeric>
#include <set>
#include <fstream>
using namespace std;

SpeechManager::SpeechManager() {
    // 容器初始化
    this->init_speech();
    // 创建选手
    this->create_speaker();
}

void SpeechManager::show_menu() {
    cout << "*******************************************" << endl;
    cout << "************** 欢迎参加演讲比赛 *************" << endl;
    cout << "************** 1、开始演讲比赛 **************" << endl;
    cout << "************** 2、查看往届纪录 **************" << endl;
    cout << "************** 3、清空比赛记录 **************" << endl;
    cout << "************** 0、退出比赛程序 **************" << endl;
    cout << endl;
}

void SpeechManager::init_speech() {
    // 容器初始化
    this->v1.clear();
    this->v11.clear();
    this->v12.clear();
    this->v2.clear();
    this->vVictory.clear();
    this->m_speaker.clear();
    this->m_index = 1;
    this->m_record.clear();
}

void SpeechManager::create_speaker() {
    string names = "ABCDEFGHIJKL";
    for (int i=0;i<12;i++){
        Speaker sp;
        string name="选手";
        name += names[i];
        sp.m_name = name;
        sp.m_score[0] = 0.;
        sp.m_score[1] = 0.;
        // 选手编号
        int sp_num = 1001 + i;
        this->v1.push_back(sp_num);
        this->m_speaker.insert(pair<int, Speaker>(sp_num, sp));
    }
}


void SpeechManager::speech_sample() {
    cout << "第 <" << this->m_index << "> 轮比赛选手正在抽签 ... ..." << endl;
    cout << "-------------------------------" << endl;
    std::random_device rd;
    std::mt19937 rng(rd());
    shuffle(this->v1.begin(), this->v1.end(), rng);
    vector<int>::iterator start=v1.begin();
    for (int i=0;i<6;i++){
        start++;
    }
    this->v11.assign(this->v1.begin(), start);
    this->v12.assign(start, this->v1.end());
    cout << "抽签完毕，抽签后演讲顺序如下：" << endl;
    if(this->m_index==1){
        for (vector<int>::iterator it=this->v1.begin();it!=this->v1.end();it++){
            cout << *it << " ";
        }
        cout << endl;
    }else{
        shuffle(this->v2.begin(), this->v2.end(), rng);
        for(vector<int>::iterator it=v2.begin(); it!=this->v2.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
    cout << "---------------------------------" << endl;
}

void SpeechManager::battle(const vector<int> &v){
    // 开始评委打分
    // 根据第几轮比赛来确定选手
    cout << "开始第 <" << this->m_index << "> 轮比赛！" << endl;
    vector<int> scores;
    for (vector<int>::const_iterator it=v.begin();it!=v.end();it++){
        //cout << "第 <" << n << "> 位选手开始演讲 ... ... " << endl;
        //cout << "第 <" << n << "> 位选手开始演讲完毕，请评委打分：" << endl;
        std::random_device rd; // Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
        std::uniform_int_distribution<> dist(0, 101);
        for (int i=0;i<12;i++){
            int s = dist(gen);
            scores.push_back(s);
        }
        sort(scores.begin(), scores.end());
        vector<int>::iterator start=scores.begin();
        start++;
        vector<int>::iterator end=scores.end();
        end--;
        double avg = (double) accumulate(start, end, 0)/10.;
        this->m_speaker[*it].m_score[this->m_index - 1] = avg;
        cout << "评委评分完毕，选手"<<this->m_speaker[*it].m_name
             <<"的最终得分为：" << avg << endl;
        scores.clear();
    }
    this->filter_victory(v);
}

void SpeechManager::filter_victory(const vector<int> &v) {
    // 第一轮每个小组选出3个，第二轮一个小组也是选出3个
    multimap<double, int, greater<double>> mmap;
    // 排序
    for (vector<int>::const_iterator it=v.begin();it!=v.end();it++){
        mmap.insert(pair<double, int>(this->m_speaker[*it].m_score[m_index-1], *it));
    }
//    for (multimap<double, int>::iterator it=mmap.begin();it!=mmap.end();it++){
//        cout << this->m_speaker[it->second].m_name << " "
//            << this->m_speaker[it->second].m_score[m_index-1] << endl;
//    }

    int n=0;
    vector<int> &vp = this->m_index-1==1?vVictory:v2;
    cout << "胜出选手为：";
    for (multimap<double, int>::iterator it=mmap.begin();it!=mmap.end();it++){
        if (n<3){
            cout << this->m_speaker[it->second].m_name << " ";
            vp.push_back(it->second); // 将胜出者加入到名单中
            n++;
        }else{
            break;
        }
    }
    cout << endl;
}

void SpeechManager::saveRecord() {
    ofstream ofs;
    // 多次比赛需要追加记录
    ofs.open("/Users/shexuan/BlackHorseCpp/Speech_competition/contest_records.csv", ios::out|ios::app);

    // 将胜出者信息记录入文件中
    int idx;
    for (int i:this->vVictory){
        ofs << this->m_speaker[i].m_name
            << "," << this->m_speaker[i].m_score[1] << ",";
    }
    ofs << endl;
    ofs.close();
    cout << "最终比赛结果已保存!" << endl;
    this->fileIsEmpty = false;
}

void SpeechManager::load_records() {
    fstream ifs;
    // 只读的方式读取文件
    ifs.open("/Users/shexuan/BlackHorseCpp/Speech_competition/contest_records.csv", ios::in);

    if(!ifs.is_open()){
        this->fileIsEmpty = true;
        cout << "文件不存在!" << endl;
        ifs.close();
        return;
    }

    // 文件被清空
    char ch;
    ifs >> ch;
    if(ifs.eof()){
        cout << "文件为空!" << endl;
        this->fileIsEmpty = true;
        ifs.close();
        return;
    }

    // 文件不为空
    this->fileIsEmpty = false;
    ifs.putback(ch); // 将上面读取的单个字符放回来

    string data;
    int idx = 1;
    // 一次读取一行
    while (ifs>>data){
        // cout << data << endl;
        // 选手J,69.3,选手F,54.7,选手C,54.3,
        int pos=-1;
        int start = 0;
        vector<string> v;
        while (true){
            pos = data.find(",", start);
            if (pos==-1){
                // 没找到
                break;
            }
            string temp = data.substr(start, pos-start);
            v.push_back(temp);
            start = pos+1;
        }
        this->m_record.insert(pair<int, vector<string>>(idx, v));
        idx ++ ;
    }
    ifs.close();
}

void SpeechManager::show_records() {
    this->load_records();
    if(this->fileIsEmpty){
        cout << "文件不存在或文件为空!" <<endl;
        return;
    }
    for (map<int, vector<string>>::iterator it=this->m_record.begin(); it!=this->m_record.end();it++){
        cout << "第" << it->first <<"届冠军：" << it->second[0] << "\t得分：" << it->second[1]
            << "\t亚军：" << it->second[2] << "\t得分：" << it->second[3]
                << "\t季军：" << it->second[4] << "\t得分：" << it->second[5] << endl;
    }
    cout << endl;
}

void SpeechManager::clear_records() {
    ofstream ofs;
    ofs.open("/Users/shexuan/BlackHorseCpp/Speech_competition/contest_records.csv", ios::trunc);
    ofs.close();
    this->fileIsEmpty = true;
    cout << "比赛记录已清空！" << endl;
    cout << endl;
}

void SpeechManager::start_speech() {
    // 初始化选手信息
    this->init_speech();
    this->create_speaker();
    // 第一轮比赛
    // 1、抽签
    this->speech_sample();
    // 2、比赛并显示晋级结果
    this->m_index = 1;
    this->battle(this->v11);
    this->battle(this->v12);
    //this->filter_victory(this->v11);
    //this->filter_victory(this->v12);

    // 3、显示晋级结果
    cout << "第一轮比赛结束，晋级选手为：" << endl;
    for (vector<int>::iterator it=this->v2.begin();it!=this->v2.end();it++){
        cout << "选手编号：" << *it << " "
            << this->m_speaker[*it].m_name << " "
            << this->m_speaker[*it].m_score[this->m_index-1] << endl;
    }
    this->m_index++;
    // 第二轮比赛
    // 1、抽签
    this->speech_sample();
    // 2、比赛
    this->battle(this->v2);
    // 3、显示最终结果
    cout << endl;
    cout << "第二轮比赛结束：" << endl;
    cout << "\t冠军为：" << this->m_speaker[this->vVictory[0]].m_name
        << "\t得分：" << this->m_speaker[this->vVictory[0]].m_score[this->m_index-1] << endl;
    cout << "\t亚军为：" << this->m_speaker[this->vVictory[1]].m_name
         << "\t得分：" << this->m_speaker[this->vVictory[1]].m_score[this->m_index-1] << endl;
    cout << "\t季军为：" << this->m_speaker[this->vVictory[2]].m_name
         << "\t得分：" << this->m_speaker[this->vVictory[2]].m_score[this->m_index-1] << endl;
    // 4、保存分数
    this->saveRecord();
//    this->load_records();
//    this->show_records();
}

void SpeechManager::exitSystem() {
    cout << "欢迎下次再次使用！" << endl;
    system("clear");
    exit(0);
}

SpeechManager::~SpeechManager() {}
