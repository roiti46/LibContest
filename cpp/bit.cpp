
/**
   0-indexed BIT (Binary Indexed Tree)

   Verified: AOJ DSL_2_B
**/

template<class T> struct BIT {
  vector<T> bit;
  int size;
  BIT(int n, T v = 0) {
    size = n;
    bit.resize(size + 1, v);
  }
  // sum [0, i)
  T sum(int i) {
    T s = 0;
    while (i > 0) {
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }
  // sum [i, j)
  T sum(int i, int j) {
    return sum(j) - sum(i);
  }
  void add(int i, T x) {
    i++;
    while (i <= size) {
      bit[i] += x;
      i += i & -i;
    }
  }
};
