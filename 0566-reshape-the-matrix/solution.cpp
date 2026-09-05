class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> res(r, vector<int>(c, 0));
        int cr=0,cc=0;
        if (mat.size() * mat[0].size() != r * c)
        return mat;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {

                res[cr][cc] = mat[i][j];

                cc++;

                if (cc == c) {
                    cc = 0;
                    cr++;
                }
            }
        }
        return res;
    }
};
