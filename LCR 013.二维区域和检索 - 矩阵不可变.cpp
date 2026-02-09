#include <iostream>
#include<vector>
using namespace std;
/*
 * @lc app=leetcode.cn id=LCR 013 lang=cpp
 * @lcpr version=30305
 *
 * [LCR 013] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
class NumMatrix {
public:
    vector<vector<int>> psum;
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i= 0;i < matrix.size();i++){
            int sum = 0;
            vector<int> presum;
            presum.push_back(0);
            for(int j =0;j < matrix[i].size();i++){
                sum += matrix[i][j];
                presum.push_back(sum);
            }
            psum.push_back(presum);
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(int i = row1;i <= row2;i ++){
            res += psum[i][col2+1] - psum[i][col1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end



/*
// @lcpr case=start
// ["NumMatrix","sumRegion","sumRegion","sumRegion"]\n[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]\n
// @lcpr case=end

 */

