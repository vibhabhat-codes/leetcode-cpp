class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int n = machines.size();

        long long sum = 0;
        for (int x : machines)
            sum += x;

        if (sum % n != 0)
            return -1;

        int target = sum / n;

        long long balance = 0;
        int ans = 0;

        for (int x : machines) {
            int diff = x - target;

            balance += diff;

            ans = max(ans,
                     (int)max(abs(balance),
                              (long long)diff));
        }

        return ans;
    }
};