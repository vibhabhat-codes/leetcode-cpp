class Solution {
public:
    long long solve(vector<int>& startA, vector<int>& durA,
                    vector<int>& startB, vector<int>& durB) {

        int m = startB.size();

        vector<pair<long long,long long>> rides;
        for (int i = 0; i < m; i++) {
            rides.push_back({startB[i], durB[i]});
        }

        sort(rides.begin(), rides.end());

        vector<long long> starts(m);
        vector<long long> prefMinDur(m);
        vector<long long> suffMinStartDur(m);

        for (int i = 0; i < m; i++) {
            starts[i] = rides[i].first;
        }

        prefMinDur[0] = rides[0].second;
        for (int i = 1; i < m; i++) {
            prefMinDur[i] = min(prefMinDur[i - 1], rides[i].second);
        }

        suffMinStartDur[m - 1] =
            rides[m - 1].first + rides[m - 1].second;

        for (int i = m - 2; i >= 0; i--) {
            suffMinStartDur[i] =
                min(suffMinStartDur[i + 1],
                    rides[i].first + rides[i].second);
        }

        long long ans = LLONG_MAX;

        int n = startA.size();

        for (int i = 0; i < n; i++) {

            long long finishA =
                (long long)startA[i] + durA[i];

            int idx =
                upper_bound(starts.begin(),
                            starts.end(),
                            finishA)
                - starts.begin();

            if (idx > 0) {
                ans = min(ans,
                          finishA + prefMinDur[idx - 1]);
            }

            if (idx < m) {
                ans = min(ans,
                          suffMinStartDur[idx]);
            }
        }

        return ans;
    }

    long long earliestFinishTime(vector<int>& landStartTime,
                                 vector<int>& landDuration,
                                 vector<int>& waterStartTime,
                                 vector<int>& waterDuration) {

        long long ans1 =
            solve(landStartTime, landDuration,
                  waterStartTime, waterDuration);

        long long ans2 =
            solve(waterStartTime, waterDuration,
                  landStartTime, landDuration);

        return min(ans1, ans2);
    }
};