class Solution {
public:
    bool isValid(string s) {
        stack<char> para;
        for(int i=0;i<s.length();i++){
            char temp=s[i];
            if(temp=='(' || temp=='{' || temp=='[' || para.empty()){
                para.push(temp);
            }
            else if((para.top()=='(' && temp==')') || (para.top()=='{' && temp=='}')||(para.top()=='['&&temp==']')){
                para.pop();
            }
            else{
                return false;
            }
        }
        return para.empty();
    }
};