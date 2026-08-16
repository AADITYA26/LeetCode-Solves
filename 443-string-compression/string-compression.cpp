class Solution {
public:
    int compress(vector<char>& chars) {
        int read = 0;
        int write = 0;

        while (read < chars.size()) {
            char ch = chars[read];
            int start = read;

            while (read < chars.size() && chars[read] == ch) {
                read++;
            }

            int count = read - start;

            chars[write++] = ch;

            if (count > 1) {
                string s = to_string(count);

                for (char c : s) {
                    chars[write++] = c;
                }
            }
        }

        return write;
    }
};