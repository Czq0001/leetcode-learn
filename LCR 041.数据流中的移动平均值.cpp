#include<iostream>
#include <list>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 041 lang=cpp
 * @lcpr version=30307
 *
 * [LCR 041] 数据流中的移动平均值
 */

// @lc code=start
class MovingAverage {
public:
    /** Initialize your data structure here. */
    int maxsize = 0;
    int sum = 0;
    list<int> lt;
    MovingAverage(int size) {
        maxsize = size;
    }
    
    double next(int val) {
        lt.push_back(val);
        if(lt.size() < maxsize){
            sum += val;
            return 1.0 * sum / lt.size();
        }else{
            sum += val;
            sum -= lt.front();
            lt.pop_front();
            return 1.0 * sum / lt.size();
        }
        return 0;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
// @lc code=end



/*
// @lcpr case=start
// ["MovingAverage","next","next","next","next"]\n[[3],[1],[10],[3],[5]]\n
// @lcpr case=end

 */

