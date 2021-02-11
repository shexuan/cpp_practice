//
// Created by shexuan on 2021/2/11.
//

#ifndef CHAPTER12__POINT3D_H
#define CHAPTER12__POINT3D_H
#pragma once
#include <iostream>
#include <string>

using namespace std;

/* 12.5.2 三维坐标系
 * 三维坐标可以使用不同的精度。并实现一个点到当前点的距离。
 */


template <class T>
class Point3d{
public:
    Point3d(T x, T y, T z){
        m_x = x;
        m_y = y;
        m_z = z;
    }

    T calc_distance(const Point3d<T> &p){
        T dist = (p.m_z-m_z)*(p.m_z-m_z) + (p.m_x-m_x)*(p.m_x-m_x) + (p.m_y-m_y)*(p.m_y-m_y);
        cout << "两点之间的距离为：" << dist << endl;
    }

    T m_x;
    T m_y;
    T m_z;
};




#endif //CHAPTER12__POINT3D_H
