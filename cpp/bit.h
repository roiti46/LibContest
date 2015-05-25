/**
   0-indexed BIT (Binary Indexed Tree)
**/

template<class T> class BIT {
  public:
    vector<T> bit;
    int size;

    BIT() {}
    BIT(int n, T v = 0) {
        size = n;
        bit.resize(n + 1, v);
    }

    T sum(int i) {
        i++;
        T s = 0;
        while (i > 0) {
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }

    void add(int i, T x) {
        i++;
        while (i <= size) {
            bit[i] += x;
            i += i & -i;
        }
    }
};
