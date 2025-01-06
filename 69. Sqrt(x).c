int mySqrt(int x) {
    long long low = 1;
    long long high = x;
    long long result = 0;
    long long mid = low + (high - low) / 2;

    if (x == 0 || x == 1)
        return x;

    while (low <= high) {
        mid = low + (high - low) / 2;
        long long mult_res = mid * mid;

        if (mult_res == x) {
            return mid;
        } else if (mult_res > x) {
            high = mid - 1;
        } else {
            low = mid + 1;
            result = mid;
        }
    }

    return result;
}
