template<typename T = int, T mod = 1'000'000'007, typename U = long long>
struct umod{
  T val;
  umod(): val(0){}
  umod(U x){ x %= mod; if(x < 0) x += mod; val = x;}
  umod& operator += (umod oth){ val += oth.val; if(val >= mod) val -= mod; return *this; }
  umod& operator -= (umod oth){ val -= oth.val; if(val < 0) val += mod; return *this; }
  umod& operator *= (umod oth){ val = ((U)val) * oth.val % mod; return *this; }
  umod& operator /= (umod oth){ return *this *= oth.inverse(); }
  umod& operator ^= (U oth){ return *this = pwr(*this, oth); }
  umod operator + (umod oth) const { return umod(*this) += oth; }
  umod operator - (umod oth) const { return umod(*this) -= oth; }
  umod operator * (umod oth) const { return umod(*this) *= oth; }
  umod operator / (umod oth) const { return umod(*this) /= oth; }
  umod operator ^ (long long oth) const { return umod(*this) ^= oth; }
  bool operator < (umod oth) const { return val < oth.val; }
  bool operator > (umod oth) const { return val > oth.val; }
  bool operator <= (umod oth) const { return val <= oth.val; }
  bool operator >= (umod oth) const { return val >= oth.val; }
  bool operator == (umod oth) const { return val == oth.val; }
  bool operator != (umod oth) const { return val != oth.val; }
  umod pwr(umod a, U b) const { umod r = 1; for(; b; a *= a, b >>= 1) if(b&1) r *= a; return r; }
  umod inverse() const {
    U a = val, b = mod, u = 1, v = 0;
    while(b){
      U t = a/b;
      a -= t * b; swap(a, b);
      u -= t * v; swap(u, v);
    }
    if(u < 0)
      u += mod;
    return u;
  }
};

using U = umod<int, 1000000007>;

template<typename U>
struct NCR {
  vector<U> fact, ifact;
  NCR(int size){
    fact.resize(size + 1); ifact.resize(size + 1);
    fact[0] = 1;
    for(int i = 1; i <= size; i++) fact[i] = fact[i - 1] * i;
    ifact[size] = U(1) / fact[size];
    for(int i = size - 1; i >= 0; i--) ifact[i] = ifact[i + 1] * (i + 1);
  }
  U ncr(int n, int r){
    if(n < r) return 0;
    return fact[n] * ifact[r] * ifact[n - r];
  }
};

using N = NCR<U>;
