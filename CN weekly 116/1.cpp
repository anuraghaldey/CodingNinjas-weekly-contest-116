// Problem statement
// You are given an array 'A' of 'N' integers which contains integers in
// ascending order followed by integers in descending order.

// For example in the array [1, 3, 5, 2, 1], the ascending part is [1, 3, 5],
// and the descending part is [5, 2, 1].

// You want to find out which part has the larger sum of the values.

// Return '0' if the sum of the values in the ascending part is greater than the
// descending part, '1' if the sum of the values in the descending part is
// greater than the ascending part, and '-1' if both the sums are equal.

// Example:
// N = 6
// A = [1, 2, 5, 3, 2]
// The ascending and descending parts of the array are ['1', '2', '5'] and ['5',
// '3', '2']. The sum of the values in descending part i.e., '10' is greater
// than the ascending part i.e., '8'. So the answer for this case is '1'.
// Detailed explanation ( Input/output format, Notes, Images )
// Constraints:
// 1 <= 'N' <= 10^5
// 1 <= A[i] <= 10^5
// There is some fixed value 'j' ('0' <= 'j' <= 'N - 1') such that 'A[i - 1]' <
// 'A[i]' if 'i' <= 'j' and 'A[i - 1]' > 'A[i]' otherwise.

// Time limit: 1 sec

int findTheLarger(int n, vector<int> &v) {
    int ls = 0, rs = 0;
    int mx = INT_MIN;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > mx) {
            mx = v[i];
            j = i;
        }
    }

    for (int i = 0; i <= j; i++) {
        ls += v[i];
    }
    for (int i = j; i < n; i++) {
        rs += v[i];
    }
    return rs == ls ? -1 : (ls > rs ? 0 : 1);
}
