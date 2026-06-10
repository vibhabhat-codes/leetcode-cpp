class Twitter {
private:
    int timeStamp;

    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;

    struct Node {
        int time;
        int tweetId;
        int userId;
        int index;
    };

    struct Compare {
        bool operator()(Node &a, Node &b) {
            return a.time < b.time;
        }
    };

public:
    Twitter() {
        timeStamp = 0;
    }

    void postTweet(int userId, int tweetId) {
        timeStamp++;
        tweets[userId].push_back({timeStamp, tweetId});
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> result;

        following[userId].insert(userId);

        priority_queue<Node,
                       vector<Node>,
                       Compare> pq;

        for (int user : following[userId]) {

            if (!tweets[user].empty()) {

                int idx = tweets[user].size() - 1;

                pq.push({
                    tweets[user][idx].first,
                    tweets[user][idx].second,
                    user,
                    idx
                });
            }
        }

        while (!pq.empty() && result.size() < 10) {

            Node curr = pq.top();
            pq.pop();

            result.push_back(curr.tweetId);

            if (curr.index > 0) {

                pq.push({
                    tweets[curr.userId][curr.index - 1].first,
                    tweets[curr.userId][curr.index - 1].second,
                    curr.userId,
                    curr.index - 1
                });
            }
        }

        return result;
    }
};