#ifndef CAR_H
#define CAR_H
#include<vector>
using namespace std;

class Car 
{
public:
    int position; // 节点编号
    int num; // 乘客数量
    vector<int> passenger;  // 乘客目的地节点编号
};

#endif