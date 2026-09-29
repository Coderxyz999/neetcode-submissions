class Solution {
public:
    string reorganizeString(string s) {
         int n=s.size();
        vector<int>count(26,0);
        for(int i=0;i<n;i++)
            {
                count[s[i]-'a']++;
                if(count[s[i]-'a']>(n+1)/2)
                return "";
            }
        priority_queue<pair<int,char>> pq;
        for(char ch='a';ch<='z';ch++)
        {
            if(count[ch-'a']!=0)
                pq.push({count[ch-'a'],ch});
        }
        string res="";
        while(pq.size()>=2)
        {
            auto p1=pq.top();
            pq.pop();
            auto p2=pq.top();
            pq.pop();
            res+=p1.second;
            res+=p2.second;
            p1.first--;
            p2.first--;
            if(p1.first>0)
                pq.push({p1.first,p1.second});
            if(p2.first>0)
                pq.push({p2.first,p2.second});
        }
        if(!pq.empty())
        {
            res+=pq.top().second;
        }
        return res;
    }
};