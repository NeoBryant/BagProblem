//
//  main.cpp
//  BagProblem
//
//  Created by 彭 on 2017/9/27.
//  Copyright © 2017年 彭. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void fun(vector<int>& bag, vector<int>& tmp, int num);
void check(int &num);
int vol = 0;

int main() {
    int n = 0, weight = 0;
    vector<int> bag;
    cout << "Please input the volume of the bag: ";
    check(vol);
    //cin >> vol;
    cout << "Please input the number of the things: ";
    check(n);
    //cin >> n;
    cout << "Please input the weight of each thing: ";
    for (int i = 0; i < n; ++i) {
        check(weight);
        bag.push_back(weight);
    }
    
    vector<int> tmp;
    fun(bag, tmp, 0);
    
    return 0;
}


void fun(vector<int>& bag, vector<int>& tmp, int num){
    
    if (num == bag.size()) {
        int sum = 0;
        for (int j = 0; j < tmp.size(); ++j) {
            sum += tmp[j];
        }
        if (sum == vol) {
            cout << '(';
            for (int j = 0; j < tmp.size(); ++j) {
                cout << tmp[j];
                
                if (j != tmp.size()-1) {
                    cout << ',';
                }
            }
            cout << ')' << endl;
        }
        return;
    }
    
    fun(bag, tmp, num+1);
    tmp.push_back(bag[num]);
    
    fun(bag, tmp, num+1);
    tmp.pop_back();
}
void check(int &num) {
    string str;
    cin >> str;
    stringstream sstr(str);
    sstr >> num;//（即从sstr中提取数据)
}

