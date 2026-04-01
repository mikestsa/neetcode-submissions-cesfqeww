class Twitter {
public:
unordered_map<int, unordered_set<int>> followers;
unordered_map<int, vector<std::pair<int,int>>> tweets;

int time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(std::make_pair(time, tweetId));
        time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        std::unordered_set<int> f = followers[userId];
        f.insert(userId);
        std::priority_queue<std::pair<int, int>> heap;
        for(auto user : f){
            int c = 10;
            auto tw = tweets[user];
            int j = tw.size();
            while(c-- && --j >=0){
                heap.push(tw[j]);
            }
        }
        vector<int> out;
        while(heap.size() && out.size() < 10){
            out.push_back(heap.top().second);
            heap.pop();
        }
        return out;
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);

        
    }
};
