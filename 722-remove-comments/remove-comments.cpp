class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool inBlock = false;
        string curr;

        for (string &line : source) {
            if (!inBlock)
                curr = "";

            for (int i = 0; i < line.size(); i++) {

                if (!inBlock) {

                    // Start of block comment
                    if (i + 1 < line.size() &&
                        line[i] == '/' && line[i + 1] == '*') {
                        inBlock = true;
                        i++;
                    }

                    // Start of line comment
                    else if (i + 1 < line.size() &&
                             line[i] == '/' && line[i + 1] == '/') {
                        break;
                    }

                    // Normal character
                    else {
                        curr.push_back(line[i]);
                    }

                } else {

                    // End of block comment
                    if (i + 1 < line.size() &&
                        line[i] == '*' && line[i + 1] == '/') {
                        inBlock = false;
                        i++;
                    }

                }
            }

            if (!inBlock && !curr.empty())
                ans.push_back(curr);
        }

        return ans;
    }
};