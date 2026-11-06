class Solution {
public:
    int mirrorFrequency(string s) {
        vector<int> freq(128, 0);

        // Count frequencies
        for (char c : s) {
            freq[c]++;
        }

        int ans = 0;

        for (char c : s) {
            if (freq[c] == -1) continue; // already processed

            char mirror;

            if (isdigit(c)) {
                mirror = '9' - (c - '0');
            } else {
                mirror = 'z' - (c - 'a');
            }

            ans += abs(freq[c] - freq[mirror]);

            // Mark both as processed
            freq[c] = -1;
            freq[mirror] = -1;
        }

        return ans;
    }
};