/**
   0-indexed Segment TreeによるRMR.

   Verified: AOJ DSL_2_A
**/
template<class T> class RangeMinQuery {
 public:
  vector<T> dat;
  int n;
  // you may need to change MAX!
  static T const MAX = 2147483647; //INT_MAX
  RangeMinQuery() {}
  RangeMinQuery(int N) {
    n = 1;
    while (n < N) n *= 2;
    dat.resize(2 * n - 1, MAX);
  };

  void update(int k, T x) {
    k += n - 1;
    dat[k] = x;
    while (k > 0) {
      k = (k - 1) / 2;
      dat[k] = min(dat[2 * k + 1], dat[2 * k + 2]);
    }
  }

  // get minimum val [a, b)
  T query(int a, int b) {
    return query(a, b, 0, 0, n);
  }

  T query(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) return MAX;
    if (a <= l && r <= b) return dat[k];
    T vl = query(a, b, 2 * k + 1, l, (l + r) / 2);
    T vr = query(a, b, 2 * k + 2, (l + r) / 2, r);
    return min(vl, vr);
  }
};
