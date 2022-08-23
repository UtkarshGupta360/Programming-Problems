// Problem Link : https://www.interviewbit.com/problems/0-1-knapsack/
int Solution::solve(vector<int> &A, vector<int> &B, int C) 
{
    int n = A.size() + 1;
    int *dp = new int[C + 1];
    for(int i = 0; i < C + 1; i++)dp[i]  = 0;
    for(int i = 0; i < n - 1; i++) for(int j = C; j >= B[i] j--) p[j] = max(dp[j - B[i]] + A[i], dp[j]);
    return dp[C];
}

