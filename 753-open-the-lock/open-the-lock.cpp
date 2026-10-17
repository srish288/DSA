class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(),deadends.end());
        if(dead.count("0000")){
            return  -1;
        }
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        int turns=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                string curr=q.front();
                q.pop();
                if(curr==target) return turns;

                for(int j=0;j<4;j++){
                    string up=curr;
                    string down=curr;
                    up[j]=(curr[j] - '0' + 1) % 10 + '0';
                    down[j]=(curr[j]-'0'+9)%10 +'0';
                     if (!dead.count(up) &&
                        !visited.count(up)) {
                        visited.insert(up);
                        q.push(up);
                    }
                     if (!dead.count(down) &&
                        !visited.count(down)) {
                        visited.insert(down);
                        q.push(down);
                    }
            }
            
        
            }
            turns++;
        }
      return -1;

    }
   
};