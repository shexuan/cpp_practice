//
// Created by shexuan on 2021/1/30.
//

#pragma once

#include <iostream>
#include <string>

using namespace std;


#ifndef RESERVATION_SYSTEM_GLOBALFILE_H
#define RESERVATION_SYSTEM_GLOBALFILE_H


/* 添加全局文件名
 *  （1）不同身份可能会用到不同的文件操作，这里将所有文件名宏定义到一个头文件中；
 *
 */

// 管理员文件
#define ADMIN_FILE "/Users/shexuan/BlackHorseCpp/Reservation_System/admin.txt"

// 学生文件
#define STUDENT_FILE "/Users/shexuan/BlackHorseCpp/Reservation_System/student.txt"

// 教师文件
#define TEACHER_FILE "/Users/shexuan/BlackHorseCpp/Reservation_System/teacher.txt"

// 机房信息文件
#define COMPUTER_FILE "/Users/shexuan/BlackHorseCpp/Reservation_System/computerRoom.txt"

// 预约信息文件
#define ORDER_FILE "/Users/shexuan/BlackHorseCpp/Reservation_System/order.txt"



#endif //RESERVATION_SYSTEM_GLOBALFILE_H
