//Lishanth-Luck
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        st.push("");
        for(char c: s){
            if(c== '(')
            {
                st.push("");
            }
            else if( c == ')'){
                string temp =st.top();
                st.pop();
                reverse(temp.begin(),temp.end());
                st.top() += temp;
            }
            else{
                st.top() += c;
            }
        }
        return st.top();
    }
};