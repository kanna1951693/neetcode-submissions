class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;

        int left = 0;
        int answer = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];

            if (lastSeen.count(c)) {
                left = max(left, lastSeen[c] + 1);
            }

            lastSeen[c] = right;
            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};