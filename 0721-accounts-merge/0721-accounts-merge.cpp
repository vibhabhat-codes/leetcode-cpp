
class Solution {
public:
    vector<int> parent, size;

    int findParent(int node) {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSet(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    vector<vector<string>> accountsMerge(
        vector<vector<string>>& accounts
    ) {
        int n = accounts.size();

        parent.resize(n);
        size.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        unordered_map<string, int> emailToAccount;

        // Step 1: Merge accounts sharing an email
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];

                if (emailToAccount.count(email)) {
                    unionSet(i, emailToAccount[email]);
                } else {
                    emailToAccount[email] = i;
                }
            }
        }

        // Step 2: Group emails by their final parent
        unordered_map<int, vector<string>> mergedEmails;

        for (auto& entry : emailToAccount) {
            string email = entry.first;
            int account = entry.second;

            int root = findParent(account);
            mergedEmails[root].push_back(email);
        }

        // Step 3: Sort emails and construct the answer
        vector<vector<string>> answer;

        for (auto& entry : mergedEmails) {
            int root = entry.first;
            vector<string>& emails = entry.second;

            sort(emails.begin(), emails.end());

            vector<string> mergedAccount;
            mergedAccount.push_back(accounts[root][0]);

            for (string& email : emails) {
                mergedAccount.push_back(email);
            }

            answer.push_back(mergedAccount);
        }

        return answer;
    }
};
