class Solution {
public:
    void helper(string path, map<string,vector<string>>&mp){
        stringstream ss(path);
            string root;
            string s;
            getline(ss, root, ' ');
            while (getline(ss, s, ' ')) {
                string fileName = root + '/' + s.substr(0, s.find('('));
                string fileContent = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
                mp[fileContent].push_back(fileName);
	    }
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans;
        map<string,vector<string>>mp;
        for (auto x : paths) {
            helper(x,mp);
        }
        for (auto x : mp) {
            if (x.second.size() > 1)
                ans.push_back(x.second);
        }
        return ans;
    }
};