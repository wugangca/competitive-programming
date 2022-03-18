#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void prevSmaller(vector<int>& nums, vector<int> &prevS) {
        stack <int> s;
        for (int i = 0; i < nums.size(); i++) {
          int num = nums[i];
          while (!s.empty() && nums[s.top()] > num) {
                s.pop();
          }
          if (!s.empty()) {
            prevS[i] = s.top();
          }
          s.push(i);
        }
    }
    
    void prevGreater(vector<int>& nums, vector<int> &prevG) {
        stack <int> s;
        for (int i = 0; i < nums.size(); i++) {
          int num = nums[i];
          while (!s.empty() && nums[s.top()] < num) {
                s.pop();
          }
          if (!s.empty()) {
            prevG[i] = s.top();
          }
          s.push(i);
        }
    }
    
    void nextSmaller(vector<int>& nums, vector<int> &nextS) {
        stack <int> s;
        for (int i = nums.size() - 1; i>=0; i--) {
          int num = nums[i];
          while (!s.empty() && nums[s.top()] >= num) {
                s.pop();
          }
          if (!s.empty()) {
            nextS[i] = s.top();
          }
          s.push(i);
        }
    }
    
    void nextGreater(vector<int>& nums, vector<int> &nextG) {
        stack <int> s;
         for (int i = nums.size() - 1; i>=0; i--) {
          int num = nums[i];
          while (!s.empty() && nums[s.top()] <= num) {
                s.pop();
          }
          if (!s.empty()) {
            nextG[i] = s.top();
          }
          s.push(i);
        }
    }
              
    
    //1 3 3
    // 1: -2
    // 3: +9 -3
    // 3: +6 -3
              
    long long subArrayRanges(vector<int>& nums) {
       int n = nums.size();
       vector<int> prevS(n, -1);
       vector<int> prevG(n, -1);
       vector<int> nextS(n, -1);
       vector<int> nextG(n, -1);
       prevSmaller(nums, prevS); 
       prevGreater(nums, prevG);
       nextSmaller(nums, nextS);
       nextGreater(nums, nextG);
       long long ans = 0; 
       for (int i = 0; i < n; i++) {
            long long num = (long long) nums[i];
            int ps = prevS[i];
            int ns = nextS[i];
            if (ns < 0) {
                ns = n;
            }
            int leftCount = i - ps - 1;
            int rightCount = ns-i-1;
            ans -=  num*(leftCount + rightCount + leftCount* rightCount);
                                 
            int pg = prevG[i];
            int ng = nextG[i];
            if (ng < 0) {
                ng = n;
            }
            leftCount = i - pg - 1;
            rightCount = ng-i-1;
            ans += num*( leftCount + rightCount + leftCount * rightCount);
         
       }
       
        return ans;
        
    }
};