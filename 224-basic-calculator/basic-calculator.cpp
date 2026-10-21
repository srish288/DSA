class Solution {
public:
    int calculate(string s) {
        long long result=0;
        long long sign=1;
        stack<int> st;
        st.push(1);
        long long num=0;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(isdigit(c)){
                num=num*10+(c-'0');
               }
            else if(c=='+'){
                result+=num*sign;
                num=0;
                sign=st.top();
            }
            else if(c=='-'){
                result+=num*sign;
                num=0;
                sign=-st.top();
            }
            else if (c == '(') {
                st.push(sign);
            }
            else if (c == ')') {
                result += sign * num;
                num = 0;
                st.pop();
            }

        }
        result+=num*sign;
        return (int)result;
    }
};