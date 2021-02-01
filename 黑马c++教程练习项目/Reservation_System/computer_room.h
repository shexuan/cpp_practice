//
// Created by shexuan on 2021/1/31.
//
#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;

#ifndef RESERVATION_SYSTEM_COMPUTER_ROOM_H
#define RESERVATION_SYSTEM_COMPUTER_ROOM_H


class computerRoom {
public:
    // 构造函数
    computerRoom()= default;

    int m_roomId;
    int m_maxNum;
};


#endif //RESERVATION_SYSTEM_COMPUTER_ROOM_H
