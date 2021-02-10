//
// Created by shexuan on 2021/2/10.
//

#ifndef CHAPTER11__POLYGON_H
#define CHAPTER11__POLYGON_H
#pragma once

#include <iostream>
#include <string>

using namespace std;

/* 11.9.3 等边多边形类
 * 等边三角形和正方形都属于多边形。设计类计算等边三角形和正方形的周长和面积.
 * 注：等边三角形的面积计算公式可以取0.433倍的边长的平方.
 */

class Polygon{
public:
    virtual double get_area()=0;
    virtual double get_perimeter()=0;
    virtual ~Polygon()= default;

    double edge;
};

class Triangle:public Polygon{
public:

    explicit  Triangle(double edge){
        this->edge = edge;
    }

    double get_perimeter() override{
        cout << "三角形的周长为：" << edge*3 << endl;
        return this->edge*3;
    }

    double get_area() override{
        cout << "三角形的面积为：" << (this->edge*0.433)*(this->edge*0.433) << endl;
        return (this->edge*0.433)*(this->edge*0.433);
    }
};

class Square:public Polygon{
public:
    explicit Square(double edge){
        this->edge = edge;
    }

    double get_perimeter() override{
        cout << "正方形的周长为：" << edge*4 << endl;
        return edge*4;
    }

    double get_area() override{
        cout << "正方形的面积为：" << this->edge * this->edge << endl;
        return this->edge * this->edge;
    }
};


#endif //CHAPTER11__POLYGON_H
