class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {

        int n = s.length();

        queue<int> q;
        q.push(0);

        int farthest = 1;

        while(!q.empty()) {

            int i = q.front();
            q.pop();

            int start = max(i + minJump, farthest);
            int end = min(i + maxJump, n - 1);

            for(int j = start; j <= end; j++) {

                if(s[j] == '0') {

                    if(j == n - 1) {
                        return true;
                    }

                    q.push(j);
                }
            }

            farthest = end + 1;
        }

        return n == 1;
    }
};