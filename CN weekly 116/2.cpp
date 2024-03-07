// Problem statement
// Given a string 'S' containing lowercase English alphabets, where each letter
// represents the elevation of a land. Where 'a' has the lowest elevation,
// increasing gradually up to 'z'.

// Find the maximum length of a substring with strictly increasing or strictly
// decreasing slopes.

// Note: A substring Is a contiguous Sequence of characters in a string

// Example:
// ‘S’ : “ninjas”

// Return 3
// The substring “nja” is longest strictly decreasing.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= ‘T’ <= 10
// 1 <= ‘N’ <= 10^6 where ‘N’ is the length of ‘S’.

// Time Limit: 1 sec

int dec(string &s) {
    int st = 0;
    int n = s.size();
    int c = 1;

    for (int e = 0; e < n; e++) {
        // if((s[e]>s[e-1]&&s[e-1]+1==s[e])||(s[e]<s[e-1]&&s[e-1]==s[e])){
        //     c=max(c,e-s+1);
        // }else{
        //     s=e;
        // }
        if (s[e] < s[e - 1]) {
            c = max(c, e - st + 1);
        } else {
            st = e;
        }
    }
    return c;
}
int inc(string &s) {
    int st = 0;
    int n = s.size();
    int c = 1;

    for (int e = 0; e < n; e++) {
        // if((s[e]>s[e-1]&&s[e-1]+1==s[e])||(s[e]<s[e-1]&&s[e-1]==s[e])){
        //     c=max(c,e-s+1);
        // }else{
        //     s=e;
        // }
        if (s[e] > s[e - 1]) {
            c = max(c, e - st + 1);
        } else {
            st = e;
        }
    }
    return c;
}
int solve(string &s) { return max(dec(s), inc(s)); }