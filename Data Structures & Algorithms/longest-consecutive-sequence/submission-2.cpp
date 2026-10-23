class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++)
            st.insert(nums[i]);
        int count=1;
        int ans=1;
        for(int x : st)
        {
            if(st.find(x-1)!=st.end())
                continue;
            else
            {
                int i=x;
                i=i+1;
                while(st.find(i)!=st.end())
                {
                    i++;
                    count++;

                }
                ans=max(ans,count);
            }
            count=1;
        }
        return ans;
    }
};
