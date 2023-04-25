class Fenwick2D {
  public:
    int n;
    vector<vector<int>> BIT;

    Fenwick2D(int x) {
      n = x;
      BIT = vector<vector<int>> (n + 1, vector<int> (n + 1));
    }

    int getSum(int x, int y) {
      int sum = 0;
      for(int i = x; i > 0; i -= i & -i)
        for (int j = y; j > 0; j -= j & -j)
          sum += BIT[i][j];
      return sum;
    }

    void update(int x, int y, int v) {
      for (int i = x; i <= n; i += i & -i)
        for (int j = y; j <= n; j += j & -j)
          BIT[i][j] += v;
    } 

    int query(int x1, int y1, int x2, int y2) {
      int sum = getSum(x2, y2) + getSum(x1 - 1, y1 - 1);
      sum -= getSum(x2, y1 - 1) + getSum(x1 - 1, y2);
      return sum;
    }
};
