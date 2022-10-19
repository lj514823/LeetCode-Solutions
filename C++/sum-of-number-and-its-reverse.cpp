// Time:  O(log10(n) * 2^(log10(n)/2)) = O(log10(n) * n^(1/(2*log2(10))))
// Space: O(log10(n))

// backtracking
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        const function<int(int, int)> backtracking = [&](int num, int total) {
            if (num == 0) {
                return true;
            }
            if (total == 1) {
                return false;
            }
            if (num <= 18) {
                return (num % 2 == 0) || (num == 11 && (total == 0 || total == 11));
            }
            for (const auto& x : {num % 10, 10 + num % 10}) {
                int base = 11;
                if (!(1 <= x && x <= 18 && x * base<= num)) {
                    continue;
                }
                for (; x * ((base - 1) * 10 + 1) <= num; base = (base - 1) * 10 + 1);
                if (!(total == 0 || total == base)) {
                    continue;
                }
                if (backtracking((num - x *base) / 10, base / 100 + 1)) {
                    return true;
                }
            }
            return false;
        };

        return backtracking(num, 0);
    }
};

// Time:  O(nlogn)
// Space: O(1)
// brute force
class Solution2 {
public:
    bool sumOfNumberAndReverse(int num) {
        const auto& reverse = [](int n) {
            int result = 0;
            for (; n; n /= 10) {
                result = result * 10 + n % 10;
            }
            return result;
        };

        for (int x = num / 2; x <= num; ++x) {
            if (x + reverse(x) == num) {
                return true;
            }
        }
        return false;
    }
};
