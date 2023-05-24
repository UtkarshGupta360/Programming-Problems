'''The Hamming distance between two integers is the number of positions at which the corresponding bits are different. Given an integer array nums, return the sum of Hamming distances between all the pairs of the integers in nums. '''
'''Problem Link: https://leetcode.com/problems/total-hamming-distance/description/'''
int totalHammingDistance(vector<int>& ans) 
    {
        vector<int> one(32,0);
        int p = 0;
        for(auto x : ans)
        {
            for(int i=0; i < 32; i++)
            {
                if(x & 1<<i) one[i]++;
            }
        }
        for(auto x : one)p += x*(ans.size() - x);
        return p;
    }
