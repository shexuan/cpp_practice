//
// Created by shexuan on 2021/2/25.
//

#ifndef CHAPTER6____Q341_FLATTEN_NESTED_LIST_ITERATOR_H
#define CHAPTER6____Q341_FLATTEN_NESTED_LIST_ITERATOR_H

#include <vector>

using namespace std;

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};


class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // flatten初始化vector
        flatten(nestedList, vec);
    }

    void flatten(vector<NestedInteger> &nestedList, vector<int> &v){
        // flatten
        while(!nestedList.empty()){
            if(nestedList.back().isInteger()){
                v.push_back(nestedList.back().getInteger());
            }else{
                flatten(nestedList.back().getList(), v);
            }
            nestedList.pop_back();
        }
    }

    int next() {
        int val = vec.back();
        vec.pop_back();
        return val;
    }

    bool hasNext() {
        return !vec.empty();
    }

    vector<int> vec;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

#endif //CHAPTER6____Q341_FLATTEN_NESTED_LIST_ITERATOR_H
