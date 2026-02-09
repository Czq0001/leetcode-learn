#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <utility>
using namespace std;
int main() { return 0; }
/*
 * @lc app=leetcode.cn id=146 lang=cpp
 * @lcpr version=30305
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache {
public:
  int maxcap = 0;
  list<int> lt;
  unordered_map<int, pair<list<int>::iterator, int>> mp;
  LRUCache(int capacity) { maxcap = capacity; }

  int get(int key) {
    if (mp.count(key)) {
      moveToHead(key);
      return mp[key].second;
    }
    return -1;
  }

  void put(int key, int value) {
    if (mp.count(key)) {
      moveToHead(key);
      mp[key].second = value;
      return;
    }
    if (mp.size() == maxcap) {
      deleteSpace();
    }
    lt.push_front(key);
    mp[key] = {lt.begin(), value};
  }
  void moveToHead(int key) {
    auto emt = mp[key];
    lt.erase(emt.first);
    lt.push_front(key);
    mp[key].first = lt.begin();
  }
  void deleteSpace() {
    auto emt = lt.back();
    lt.pop_back();
    mp.erase(emt);
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

/*
// @lcpr case=start
//
["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]\n
// @lcpr case=end

 */
