class Solution {
public:
    int myAtoi(string s) {
        map <char,int> st{{'0',1},{'1',1},{'2',1},{'3',1},{'4',1},{'5',1},{'6',1},{'7',1},{'8',1},{'9',1}};
        bool flag=true;
        bool stdigit=false;
        int c=0;
        int sign=1;
        string ans="";
        bool signflag=false;
        while(flag==true){
            while(stdigit==false){
                if(st[s[c]]==1){
                stdigit=true;
                }
                else if(s[c]=='-' ||s[c]=='+'){
                    if(signflag==true){
                        return 0;
                    }
                    sign=(s[c]=='-')? -sign:sign;
                    c++;
                    signflag=true;
                }
                else if(s[c]==' '&& signflag==true) return 0;
                else if(s[c]==' '){
                    c++;
                    continue;
                }
                else if(st[s[c]]!=1){
                    return 0;
                }
            }
            if(st[s[c]]==1&&stdigit==true){
                ans+=s[c];
                c++;
            }
            else if(c==s.length()-1 || st[s[c]]!=1){
                flag=false;
            }


        }
        try{
        int a=(ans=="")? 0:stoi(ans);
        return sign*a;
        }
        catch(const out_of_range& e){
            if(sign>0) return sign*(pow(2,31)-1);
            else return sign*pow(2,31);
        }
        return 0;
    }
};