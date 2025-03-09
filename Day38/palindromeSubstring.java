
class Solution {
    public int countPS(String s) {
        int n = s.length();
        int count = 0;

        // Expand Around Center to count palindromes
        for (int i = 0; i < n; i++) {
            // Count even length palindromes
            count += expandAroundCenter(s, i, i + 1);
            // Count odd length palindromes (excluding single-character substrings)
            count += expandAroundCenter(s, i, i);
        }
        return count;
    }

    private int expandAroundCenter(String s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            if (right - left + 1 >= 2) { // Consider only length >= 2
                count++;
            }
            left--;
            right++;
        }
        return count;
    }
}