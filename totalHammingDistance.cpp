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
