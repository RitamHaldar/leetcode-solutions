class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        for (int i=0;i<students.size();i++){
            st.push(students[i]);
        }
        int count=0,i=0;
        while(st.size()>0 && st.size()!=count){
            if (st.front()==sandwiches[i]){
                st.pop();
                i++;
                count=0;
            }else{
                st.push(st.front());
                st.pop();
                count++;
            }
        }
        return st.size();
    }
};
