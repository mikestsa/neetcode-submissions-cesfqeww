class Solution {
public:

    string encode(vector<string>& strs) {
        std::string out;
        for(auto str : strs){
            out += to_string((int)str.size());
            out += '#';
            out += str;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        int i = 0;
        while ( i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            string n = s.substr(i, j - i);
            int num = stoi(n);
            i = j + 1;
            string str = s.substr(i, num);
            out.push_back(str);
            i += num;
        }
        return out;

    }
};
