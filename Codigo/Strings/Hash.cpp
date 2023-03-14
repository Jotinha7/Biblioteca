class Hash { // dont forget to use #define int long long
  public:
        int qnt;
        string str;
        vector<int> base = {31, 37}, mod = {1000000007, 1000000009}; // bases and mods
    vector<vector<int>> hashes, inv_pow;
    int binpow(int a, int b, int m) {
      a %= m;
      int x = 1;
      while (b > 0) {
        if (b & 1) x = x * a % m;
        a = a * a % m; b >>= 1;
      }
      return x;
    }
    int inverse(int x, int m) {
      return binpow(x, m - 2, m);
    }
    Hash(const string& word, const int& num) {
            qnt = num, str = word;
            hashes.assign(qnt, vector<int>(sz(str), 0)); // hashing using prime nums 
            for(int i = 0; i < qnt; i++) {
                int pt = 1, h = 0;
                for(int j = 0; j < sz(str); j++) {
                    h = (h + str[j] * pt) % mod[i];
                    pt = (pt * base[i]) % mod[i];
                    hashes[i][j] = h;
                }
            }
      int inv = 1; // inverse modulo magic :D
      while(inv < sz(str)) { inv <<= 1; }
      inv_pow.assign(qnt, vector<int>(inv, -1));
      for(int i = 0; i < qnt; i++) {
        inv_pow[i][inv - 1] = inverse(binpow(base[i], inv - 1, mod[i]), mod[i]);
      }
      for(int i = 0; i < qnt; i++) {
        for(int j = inv - 2; j >= 0 && inv_pow[i][j] == -1; j--) {
          inv_pow[i][j] = (inv_pow[i][j + 1] * base[i]) % mod[i];
        }
      }
        }
        vector<int> get_hash(const int& l, const int& r) { // range hashing using inverse modulo and preffix diffs
      vector<int> multiple_hash;
            if(l == 0) {
        for(int i = 0; i < qnt; i++) {
          multiple_hash.push_back(hashes[i][r]);
        }
        return multiple_hash;
      }
      for(int i = 0; i < qnt; i++) {
        int range_hash = hashes[i][r] - hashes[i][l - 1];
        range_hash += (range_hash < 0 ? mod[i] : 0);
        range_hash = (range_hash * inv_pow[i][l]) % mod[i];
        multiple_hash.push_back(range_hash);
      }
      return multiple_hash;
        }
};
