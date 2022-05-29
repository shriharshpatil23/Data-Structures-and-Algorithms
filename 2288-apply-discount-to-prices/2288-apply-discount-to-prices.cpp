class Solution {
public:
     bool check(string& word) {
        if(word[0] != '$' || word.size() == 1)
            return false;
        for(int i=1;i<word.size();i++) {
            if(word[i] == '$' || isalpha(word[i]))
                return false;
        }
        return true;
    }
    string discountPrices(string sentence, int discount) {
        string res = "";
        string word;
        stringstream iss(sentence);
         while (iss >> word) {
             if(check(word)) {
                 long double num = stoll(word.substr(1));
                 // cout << num << endl;
                 long double dis = num - (ceil((num)*discount))/100;
                 // dis = std::ceil(dis * 100.0) / 100.0;
                 // cout << dis << endl;
                 long int tempp = dis;
                 string temppstr = to_string(tempp);
                 long int temppsz = temppstr.size();
                 string temp = to_string(dis);
                 // cout << temp << endl;
                 res.push_back('$');
                 res.append(temp.substr(0,temppsz+3) + ' ');
             }
             else {
                 res.append(word + ' ');
             }
         }
        res.pop_back();
        return res;
    }
};