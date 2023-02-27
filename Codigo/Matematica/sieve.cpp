// crivo - O(n log n)

vector<int> sieve(int maxn) {
  bool prime[maxn + 1];
  memset(prime, true, sizeof prime);
  for(int i = 2; i <= maxn; i++) {
    if(prime[i] == true) {
      for(long long j = (long long) i * i; j <= maxn; j += i) {
        prime[j] = false;
      }
    }
  }
  vector<int> p;
  for(int i = 2; i <= maxn; i++) {
    if(prime[i]) {
      p.push_back(i);
    }
  }
  return p;
}
