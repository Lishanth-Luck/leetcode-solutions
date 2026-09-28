//Lishanth-Luck
class Solution {
public:
    int maxDepth(string s) {
    int depth=0;
    int maxdepth=0;
    for (char c : s){
        if(c == '(') {
            depth++;
            maxdepth= max(maxdepth, depth);
        }
        else if (c == ')'){
            depth--;
        }
    }
        return maxdepth;
    }
};  
