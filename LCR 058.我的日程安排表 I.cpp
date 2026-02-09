#include <algorithm>
#include<iostream>
#include <iterator>
#include <set>
#include <utility>
#include "map"
using namespace std;

/*
 * @lc app=leetcode.cn id=LCR 058 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 058] 我的日程安排表 I
 */

// @lc code=start
class MyCalendar {
public:
    map<int,int> mp;
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        auto it = mp.lower_bound(start);
        if(it!=mp.end() && it->first < end) return false;
        if(it!=mp.begin()){
            auto pre = prev(it);
            if(pre->second > start) return false;
        }
        mp[start] = end;
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MyCalendar","book","book","book"]\n[[],[10,20],[15,25],[20,30]]\n
// @lcpr case=end

 */

