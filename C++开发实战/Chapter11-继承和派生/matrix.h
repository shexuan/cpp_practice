//
// Created by shexuan on 2021/2/10.
//

#ifndef CHAPTER11__MATRIX_H
#define CHAPTER11__MATRIX_H
#pragma once
#include <iostream>
#include <string>
#include <random>
#include <cassert>
using namespace std;

// 通过重载运算符来实现方阵间的运算
// 为简单，这里直接将声明与定义均写在头文件中

class Matrix{
public:
    // 构造函数
    Matrix(){
        nrows = 2;
        ncols = 2;
        for (int i=0; i<nrows; i++){
            for (int j=0; j<ncols; j++){
                m_matrix[i][j] = gen_num(1,100);
            }
        }
    }

    Matrix operator+(const Matrix &m){
        assert(m.ncols==this->ncols && m.nrows==this->nrows);
        Matrix new_m;

        for (int i=0; i<nrows; i++){
            for (int j=0; j<ncols; j++){
                new_m.m_matrix[i][j] = this->m_matrix[i][j]+m.m_matrix[i][j];
            }
        }

        return new_m;
    }

    Matrix operator-(const Matrix &m){
        assert(m.ncols==this->ncols && m.nrows==this->nrows);
        Matrix new_m;

        for (int i=0; i<nrows; i++){
            for (int j=0; j<ncols; j++){
                new_m.m_matrix[i][j] = this->m_matrix[i][j]-m.m_matrix[i][j];
            }
        }

        return new_m;
    }

    Matrix operator*(const Matrix &m){
        assert(m.ncols==this->ncols && m.nrows==this->nrows);
        Matrix new_m;

        for (int i=0; i<nrows; i++){
            for (int j=0; j<ncols; j++){
                new_m.m_matrix[i][j] = this->m_matrix[i][j]*m.m_matrix[i][j];
            }
        }

        return new_m;
    }

    Matrix operator/(const Matrix &m){
        assert(m.ncols==this->ncols && m.nrows==this->nrows);
        Matrix new_m;

        for (int i=0; i<nrows; i++){
            for (int j=0; j<ncols; j++){
                new_m.m_matrix[i][j] = this->m_matrix[i][j]/m.m_matrix[i][j];
            }
        }

        return new_m;
    }

    int gen_num(int min_, int max_){
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> dist(min_, max_); // 最小值为1，防止出现除数为0的情况
        return dist(gen);
    }

    int m_matrix[2][2];
    int nrows;
    int ncols;


};

#endif //CHAPTER11__MATRIX_H
