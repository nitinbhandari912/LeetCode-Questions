class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1]!='0') return false;
        if(s.size()<1) return true;
        queue<int> q;
        q.push(0);
        int far=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            int start=max(a+minJump,far+1);
            int node=min(a+maxJump,(int)s.size()-1);
            for(int i=start;i<=node;i++){
                if(s[i]=='0'){
                    q.push(i);
                }
                if(i==s.size()-1) return true;
            }
            if(a==s.size()-1) return true;
            far=max(far,node);
        }
        return false;
    }
};