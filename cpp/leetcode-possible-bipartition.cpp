// https://leetcode.cn/problems/possible-bipartition
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& disk) {
        vector<vector<int>>obey(n+1);
        for(auto v:disk){
            obey[v[0]].push_back(v[1]);
            obey[v[1]].push_back(v[0]);
        }
        vector<set<int>> a(2);
        vector<int>vis(n+1);
        auto tour=[&](auto self,int u,int bi)->bool{
            vis[u]=1;
            a[bi].insert(u);
            for(auto v:obey[u]){
                if(!vis[v]){
                    if(!self(self,v,bi^1)){
                        return false;
                    }
                }else if(a[bi].find(v)!=a[bi].end()){
                    return false;
                }
            }
            return true;
        };
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                if(!tour(tour,i,0)) {
                    return false;
                }
            }
        }
        return true;
    }
};
