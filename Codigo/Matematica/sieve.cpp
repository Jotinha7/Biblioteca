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

// crivo segmentado O(n long n + sqrt(r) log r)
// retorna um vetor do size do intervalo
// para saber se o numero é primo basta fazer v[i - l] | l <= i <= r

vector<char> segmentedSieve(long long L, long long R) {
  long long lim = sqrt(R);
  vector<char> mark(lim + 1, false);
  vector<long long> primes;
  for (long long i = 2; i <= lim; ++i) {
    if (!mark[i]) {
      primes.emplace_back(i);
      for (long long j = i * i; j <= lim; j += i)
        mark[j] = true;
    }
  }
  vector<char> isPrime(R - L + 1, true);
  for (long long i : primes)
    for (long long j = max(i * i, (L + i - 1) / i * i); j <= R; j += i)
        isPrime[j - L] = false;
  if (L == 1)
    isPrime[0] = false;
  return isPrime;
}
