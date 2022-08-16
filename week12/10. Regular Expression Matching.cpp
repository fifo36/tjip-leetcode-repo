//TC: O(|s| x |p|)
//MC: O(|s| x |p|)

class Solution {
public:
    string str, pat;
    vector<vector<int>> cache;

    bool checkMatching(int strPos, int patPos){
        if(patPos == pat.size()) return strPos == str.size();
        if(strPos > str.size()) return false;
        if(cache[strPos][patPos] != -1) return cache[strPos][patPos];

        bool status_1 = 0, status_2 = 0;
        if(pat[patPos] == '.' || str[strPos] == pat[patPos]){
            status_1 = checkMatching(strPos+1, patPos+1);
        }

        if(pat[patPos+1] == '*'){
            if(pat[patPos] == '.' || pat[patPos] == str[strPos]){
                status_2 = checkMatching(strPos+1, patPos);
            }

            status_2 |= checkMatching(strPos, patPos+2);
        }

        return cache[strPos][patPos] = status_1 | status_2;
    }

    bool isMatch(string s, string p) {
        str = s, pat = p;
        cache.resize(s.size()+1, vector<int>(p.size()+1, -1));

        return checkMatching(0, 0);
    }
};
