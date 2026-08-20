class Twitter {
private:
    // counter to enforce ordering of newsFeed, attached to every tweet and updated when a tweet is posted
    int tweetCtr = 0;
    // map of userId to hash set of their follower's id's
    unordered_map<int, unordered_set<int>> following;
    // map of userId to vector list of int pairs, with format of {counter, tweetid}
    unordered_map<int, vector<pair<int,int>>> tweetList;
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        tweetList[userId].push_back({tweetCtr++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        // queue of tweets in the form {tweetCtr, {userId, index_of_tweet}}
        priority_queue<pair<int, pair<int,int>>> ordered_tweets;
        // initially populate pq with most recent tweets and indexes from userId's followers and self
        for (auto& [id, tweet] : tweetList) {
            if (id == userId || following[userId].find(id) != following[userId].end()) {
                ordered_tweets.push({tweet.back().first, {id, tweet.size() - 1}});
            }
        }
        // pop the most recent tweet from the pq, and replace with the next oldest by decrementing position index in pq entry
        while (!ordered_tweets.empty() && newsFeed.size() < 10) {
            // pop the newest tweet ({tweetCtr, {userId, index_of_tweet}}) add its tweetId to the newst feed
            pair<int, pair<int,int>> newestTweet = ordered_tweets.top();
            ordered_tweets.pop();
            newsFeed.push_back(tweetList[newestTweet.second.first][newestTweet.second.second].second); // horrid syntax

            // get the next newest tweet from that user and enqueue it
            vector<pair<int,int>>& currTweetList = tweetList[newestTweet.second.first];
            if (currTweetList.size() > 0 && newestTweet.second.second > 0) {
                int nextCtrVal = currTweetList[newestTweet.second.second - 1].first;
                ordered_tweets.push({nextCtrVal, {newestTweet.second.first, --newestTweet.second.second}});
            }
        }
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) 
            following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
