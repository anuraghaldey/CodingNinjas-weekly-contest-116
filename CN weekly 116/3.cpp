// Problem statement
// You are given an array ‘A’ of length ‘N’ where elements are numbered from ‘0’
// to ‘N - 1’. You are also given an integer ‘M’. For a fixed value of ‘K’, you
// can perform following operation on array ‘A’ any number of times:

// Choose a subarray from some index ‘i’ to ‘j’, where ‘i’ <= ‘j’.
// You can replace every ‘A[x]’ to the value ‘Floor(A[x] / K)’, where ‘i’ <= ‘X’
// <= ‘j’. You have to find the smallest positive value of ‘K’ such that you can
// make all the elements of array ‘A’ equal to ‘0’ in at most ‘M’ operations.

// Your task is to tell the smallest positive value of ‘K’ such that you can
// make all the elements of the array ‘A’ equal to ‘0’ and return it. If there
// is no such possible value of ‘K’, return ‘-1’. Please note that no input
// contains an array where all the elements are equal to ‘0’.

// Example:
// ‘N’ = 4
// ‘M’ = 3
// ‘A’ = [1, 9, 2, 0]

// Let’s take ‘K’ = ‘2’:
// Choose a subarray from ‘0’ to ‘2’ and apply the given operation. The array
// will get changed to: [0, 4, 1, 0].

// Now, let's take a subarray from ‘1’ to ‘2’ and apply the given operation. Our
// array will get converted to: [0, 2, 0, 0].

// Now, take a subarray from ‘1’ to ‘1’ and repeat the process, The array will
// get converted to: [0, 1, 0, 0].

// Again apply the operation on the subarray from ‘1’ to ‘1’ and we get: ‘A’ =
// [0, 0, 0, 0].

// It is taking ‘4’ operations which is greater than ‘M’. So we can’t take ‘K’
// = 2.

// Let's take ‘K’ = ‘3’.
// Choose a subarray from ‘0’ to ‘2’ and apply the given operation. The array
// will get changed to: [0, 3, 0, 0].

// Now, take a subarray from ‘1’ to ‘1’ and repeat the process, The array will
// get converted to: [0, 1, 0, 0].

// Again apply the operation on the subarray from ‘1’ to ‘1’ and we get: ‘A’ =
// [0, 0, 0, 0].

// Here, it is taking ‘3’ operations which is equal to ‘M’. So, this is the
// minimum value of ‘K’ for the given array. Detailed explanation ( Input/output
// format, Notes, Images ) Constraints: 1 <= ‘T’ <= 10 1 <= ‘N’ <= 10^5 0 <= ‘M’
// <= 10^9 ‘0’ <= ‘A[i]’ <= 10^9

// Time Limit: 1 sec

int c(vector<int> &a, int mid, int m) {
    int st = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        if (!(a[i])) {
            continue;
        }
        int q = (log2(a[i]) / log2(mid)) + 1;
        st = max(st, q);
    }
    return st <= m;
}
int bs(vector<int> &a, int l, int h, int &ans, int m) {
    if (l > h) {
        return ans;
    }
    int mid = l + (h - l) / 2;
    if (c(a, mid, m)) {
        ans = mid;
        return bs(a, l, mid - 1, ans, m);
    }
    return bs(a, mid + 1, h, ans, m);
}
int minKValue(int n, int m, vector<int> &a) {
    int ans = -1;
    int l = 2;
    int h = *max_element(a.begin(), a.end());
    h = max(h, l + 1);
    return bs(a, l, h, ans, m);
}
