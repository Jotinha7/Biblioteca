class FenwickTree {
  public:
    int n;
    vector<int> BIT;

    FenwickTree(int _n) : n(_n) {
      BIT = vector<int> (n + 1);
    }

    void update(int i, int x) {
      for (int j = i; j <= n; j += j & -j)
        BIT[j] += x;
    }

    int getSum(int i) {
      int sum = 0;
      for (int j = i; j > 0; j -= j & -j)	
        sum += BIT[j];
      return sum;
    }

    int query(int l, int r) { return getSum(r) - getSum(l - 1); }
};
