#include <bits/stdc++.h>

using namespace std;

class no {
  public:
  
    int occ;
    string txt;
    no* left;
    no* right;
    
    no(int _n = 0, string str = "") : occ(_n), txt(str), left(NULL), right(NULL) {} 
};

class huffman {
  public:
    map<string, string> encoder, decoder;
    huffman(string t = "") {
      encode(t);
    }
    
    void merge(no* a, no* b, no* c) {
      if(a->occ > b->occ) {
        swap(a, b);
      }
      c->occ = a->occ + b->occ;
      c->txt = a->txt + b->txt;
      c->left = a;
      c->right = b;
    }
    
    no* build(string t) {
      map<string, int> rem;
      for(auto x : t) {
        string c = "";
        c += x;
        rem[c] += 1;
      }
      
      priority_queue<pair<int, no*>, vector<pair<int, no*>>, greater<pair<int, no*>>> pq;
      
      for(auto [a, b] : rem) {
        no* x = new no(b, a);
        pq.push({b, x});
      }
      
      while((int) pq.size() > 1) {
        no* x = pq.top().second;
        pq.pop();
        no* y = pq.top().second;
        pq.pop();
        no* z = new no;
        merge(x, y, z);
        pq.push({z->occ, z});
      }
      return pq.top().second;
    }
    
    void encode(string t) {
      no* root = build(t);
      
      auto dfs = [&](auto self, no* u, string bin) {
        if(u->left == NULL) {
          encoder[u->txt] = bin;
          decoder[bin] = u->txt;
          return;
        }
        self(self, u->left, bin + "0");
        self(self, u->right, bin + "1");
      };
      
      dfs(dfs, root, ((int) set<char> (t.begin(), t.end()).size() == 1 ? "0" : ""));
    }
    
    void printBin(string t) {
      for(auto x : t) {
        string c = "";
        c += x;
        cout << encoder[c];
      }
      cout << '\n';
    }
    
    void printTxt(string t) {
      cout << t << '\n';
    }
    
    void dic() {
      for(auto [a, b] : decoder) {
        cout << b << ": " << a << '\n';
      }
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  string txt;
  getline(cin, txt);
  huffman x(txt);
  x.dic();
  x.printBin(txt);
  return 0;
}

