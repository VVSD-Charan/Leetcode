class Twitter {

    map<int,vector<pair<int,int>>>userTweet;
    map<int,set<int>>followw;
    map<int,set<int>>followed;

    int curr_tweets;

public:
    Twitter() {
        curr_tweets = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        userTweet[userId].push_back({tweetId,curr_tweets});
        curr_tweets++;
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        priority_queue<pair<int,int>>pq;

        if(userTweet.find(userId) != userTweet.end())
        {
            for(auto it : userTweet[userId])
            {
                pq.push({it.second,it.first});
            }
        }   

        for(auto it : followw[userId])
        {
            if(userTweet.find(it) == userTweet.end())continue;

            for(auto i : userTweet[it])
            {
                pq.push({i.second,i.first});
            }
        }

        vector<int>arr;

        while(pq.size()>0 && arr.size()<10)
        {
            arr.push_back(pq.top().second);
            pq.pop();
        }

        return arr;
    }
    
    void follow(int followerId, int followeeId) {
        followw[followerId].insert(followeeId);
        followed[followeeId].insert(followerId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followw[followerId].erase(followeeId);
        followed[followeeId].erase(followerId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */