//
// Created by shexuan on 2021/1/26.
//

#pragma once
#include <iostream>
#include <string>
using namespace std;

#ifndef SPEECH_COMPETITION_SPEAKER_H
#define SPEECH_COMPETITION_SPEAKER_H


class Speaker {
public:
    // 构造函数
    Speaker();

    //

    //

    //

    string m_name;
    double m_score[2]; // 平均分数，最多比赛两轮，因此两轮得分
};


#endif //SPEECH_COMPETITION_SPEAKER_H
