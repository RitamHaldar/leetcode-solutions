class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();

        vector<int> pre(n + 1, 0);
        vector<int> suf(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + (customers[i - 1] == 'N');
        }
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + (customers[i] == 'Y');
        }
        int minloss = INT_MAX;
        int minidx = 0;
        for (int i = 0; i <= n; i++) {
            int loss = pre[i] + suf[i];
            if (loss < minloss) {
                minloss = loss;
                minidx = i;
            }
        }

    return minidx;
    }
};
