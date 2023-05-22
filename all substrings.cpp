#include <bits/stdc++.h>
#include <bitset>
using namespace std;

vector<string> unisubset(string abc)
{
    int length  = (int)abc.length();
    int si = (1 << length) - 1;
    
    vector<string> ans(si + 1);
    
    for(int i = 0; i <= si; i++)
    {
        for(int j = 0; j < length; j++)
        {
            if(i & (1 << j)) ans[i] += abc[j];
        }
    }
    return ans;
}

int main() 
{
    /*vector<int> arr = {1,1,1,2,3,4,5,5,2,2,3,3,4,4,5,6};
    cout<<uniqueno(arr);
    */
    string abc = "abc";
    vector<string> ans = unisubset(abc);
    for(auto x : ans) cout << x <<'\n';
	return 0;
}
