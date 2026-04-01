class Solution {
public:
    bool differbyone(string beginWord, string endWord){
        int diff = 0;
        for(int i = 0; i < beginWord.size(); i++){
            if (beginWord[i] != endWord[i]) diff++;
            if (diff > 1) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        std::queue<string> q;
        if (words.find(endWord) == words.end()) return 0;
        q.push(beginWord);
        if(beginWord == endWord) return 0;
        int out = 1;
        while(q.size()){
            out++;
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                string current_word = q.front();
                q.pop();
                    for (auto it = words.begin(); it != words.end(); ) {
                        if (differbyone(current_word, *it)) {
                            if (*it == endWord) return out;
                            q.push(*it);
                            it = words.erase(it); // Η erase επιστρέφει τον επόμενο έγκυρο iterator
                        }else {
                            ++it;
                        }
                    }
                }
        }
        return 0;
    }
};
