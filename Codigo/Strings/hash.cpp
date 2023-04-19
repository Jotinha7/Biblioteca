const long long mod1 = 1000015553, mod2 = 1000028537;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count()); // Random number generator
static long long base1 = uniform_int_distribution<int>(356, mod1 - 1)(rng);	// In case TL, use const
static long long base2 = uniform_int_distribution<int>(356, mod2 - 1)(rng);
// Remember (alfabet < base < mod)
 
struct hash_s{
  string s; 
  long long n;
  vector<long long> hsh1, pwr1, hsh2, pwr2;
 
  hash_s() : n(0) {}
  hash_s(string _s) : n(_s.size()), s(_s), hsh1(n), pwr1(n), hsh2(n), pwr2(n){	
    pwr1[0] = pwr2[0] = 1;
    for (int i = 1; i < n; i++){
      pwr1[i] = (base1 * pwr1[i - 1]) % mod1;
      pwr2[i] = (base2 * pwr2[i - 1]) % mod2;
    }
    hsh1[0] = hsh2[0] = s[0];
    for (int i = 1; i < n; i++){
      hsh1[i] = (hsh1[i - 1] * base1 + (long long)(s[i]))%mod1;
      hsh2[i] = (hsh2[i - 1] * base2 + (long long)(s[i]))%mod2;
    }
  }
  long long hash(int i, int j){ // hash no intervalo [i, j]
    if (i == 0) return (hsh1[j] << 30)^(hsh2[j]);;
    long long ret1 = ((hsh1[j] - (hsh1[i - 1] * pwr1[j - i + 1])) % mod1 + mod1) % mod1;
    long long ret2 = ((hsh2[j] - (hsh2[i - 1] * pwr2[j - i + 1])) % mod2 + mod2) % mod2;
    return (ret1 << 30)^(ret2);
  }
};
 
