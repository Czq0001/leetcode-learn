#include<iostream>
#include<algorithm>
#include<set>
#include<unordered_map>
#include<queue>
#include<vector>
#include<list>
#include<iterator>
using namespace std;
int main(){
    return 0;
}
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
public:
    int MaxSize = 0;
    list<int> lt;
    unordered_map<int,pair<list<int>::iterator,int>> cache;
    LRUCache(int capacity) {
        MaxSize = capacity;
    }
    int get(int key) {
        if(cache.count(key)){
            MoveToHead(key);
            return cache[key].second;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(cache.count(key)){
            MoveToHead(key);
            cache[key].second = value;
        }else{
            if(MaxSize == cache.size()) {
                EraseSpace();
            }
            lt.push_front(key);
            cache[key].second = value;
            cache[key].first = lt.begin();
        }
    }


    void MoveToHead(int key){
        lt.erase(cache[key].first);
        lt.push_front(key);
        cache[key].first = lt.begin();
    }

    void EraseSpace(){
        int key = lt.back();
        lt.pop_back();
        cache.erase(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

