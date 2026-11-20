class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string token;
        stringstream ss(path);
        while(getline(ss,token,'/')){
             if(token.empty()||token =="."){
               continue;
             }
             if(token==".."){
             if(!st.empty()){
                st.pop();
             }
             }
        else{
                st.push(token);
             }
         
        }
         if(st.empty()){
            return "/";
         }
         string ans="";
         while(!st.empty()){
            ans="/"+st.top()+ ans;
            st.pop();
         }
         return ans; 
        


    }
};