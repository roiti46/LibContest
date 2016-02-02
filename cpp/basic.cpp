typedef long long ll;

// GCD and LCM
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}


//pow and pow_mod
ll pow(int a, int p) {
    ll res = 1;
    while (p) {
        if (p & 1) res *= a;
        a *= a;
        p /= 2;
    }
    return res;
}

ll pow_mod(int a, int p, int mod) {
    ll res = 1;
    while (p) {
        if (p & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        p /= 2;
    }
    return res;
}



bool isprime(int n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;
    return true;
}


vector<int> prime_sieve(int n) {
    vector<int> p(n + 1, 1);
    p[0] = p[1] = 0;
    for (int i = 0; i < (int)sqrt(n) + 1; i++) {
        if (p[i])
            for (int j = 2 * i; j <= n; j += i) p[j] = 0;
    }
    return p;
}


vector<pair<int, int>> prime_factorize(int n) {
    vector<pair<int, int>> res;
    for (int i = 2; i * i <= n; i++) {
        int cnt = 0;
        while (n % i == 0) {
            n /= i;
            cnt++;
        }
        if (cnt > 0) res.push_back(make_pair(i, cnt));
    }
    if (n > 1) res.push_back(make_pair(n, 1));
    return res;
}


// Longest Increasing Subsequence
// Verified: AOJ DPL_1_D
int lis(const vector<int> A) {
    int n = A.size();
    vector<int> L(n, 0);
    L[0] = A[0];
    int length = 1;
    for (int i = 1; i < n; i++) {
        if (L[length - 1] < A[i])
            L[length++] = A[i];
        else
            *lower_bound(L.begin(), L.begin() + length, A[i]) = A[i];
    }
    return length;
}
