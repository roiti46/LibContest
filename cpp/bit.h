/**
   0-indexed BIT (Binary Indexed Tree)
**/

template<class T, int MAX_N> class BIT {
 public:
    int size = MAX_N;
    T bit[MAX_V + 1];

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
