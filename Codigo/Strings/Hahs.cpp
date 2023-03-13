class Hash {
  public:
    vector<int> primes = {31, 37}, mods = {1000000007, 1000000009}, hashes;
    Hash(const string& str, const int& qnt) {
      for(int i = 0; i < qnt; i++) {
        compute_hash(str, primes[i], mods[i]);
      }
    }
    void compute_hash(const string& str, const int& prime, const int& mod) {
      int p = 1, h = 0;
      for(auto c : str) {
        h = (h + (c - 'a' + 1) * p) % mod;
        p = (p * prime) % mod;
      }
      hashes.push_back(h);
    }
    bool operator == (const Hash& other) {
      for(int i = 0; i < sz(hashes); i++) {
        if(hashes[i] != other.hashes[i]) {
          return 0;
        }
      }
      return 1;
    }
}; // prototipo de hash
