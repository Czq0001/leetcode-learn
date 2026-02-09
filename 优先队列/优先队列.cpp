#include <functional>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Node{
    int id;
    int score;
};
struct Cmp{
    bool operator()(const Node &a,const Node &b)const{
        return a.id > b.id;
    }
};
int main(){
    //默认大根堆
    priority_queue<int> pq1;
    //小根堆
    priority_queue<int,vector<int>,greater<int>> pq2;
    //自定义排序
    priority_queue<Node,vector<Node>,Cmp> pq3;
    return 0;
}