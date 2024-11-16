#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        vector<int> count_lens;
        string ans = "";
        ans = ans + to_string(strs.size());
        for (auto &s : strs)
        {
            ans += to_string(s.length());
            ans += s;
        }
        // cout << ans << "--s--s--" << endl;
        return ans;
    }

    vector<string> decode(string s)
    {
        int n = s[0] - '0';
        vector<string> ans(n);
        int i = 1;
        while (i < s.length())
        {
            cout << "start " << i << " -- " << endl;
            int n = s[i] - '0';
            string ss = "";
            while (n)
            {
                ss += s[++i];
                n--;
            }
            cout << "end " << i << " -- " << ss << endl;
            i++;
            if (ss.length() > 0)
                ans.push_back(ss);
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"abc", "def", "ghi"};
    cout << s.encode(strs) << endl;

    vector<string> ans = s.decode(s.encode(strs));
    for (auto &a : ans)
    {
        cout << "-" << a << "-";
    }
    cout << endl;

    return 0;
}

class Solution
{
public:
    string encode(vector<string> &strs)
    {
        string res;
        for (const string &s : strs)
        {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int i = 0;
        while (i < s.size())
        {
            int j = i;
            while (s[j] != '#')
            {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            i = j + 1;
            j = i + length;
            res.push_back(s.substr(i, length));
            i = j;
        }
        return res;
    }
};