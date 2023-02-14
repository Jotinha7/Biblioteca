class kmp {
  public:
    int sz;
    string word;
    vector<int> match;
    vector<pair<int, int>> found;

    kmp(string& str) {
      sz = (int)str.size();
      match.resize(sz);
      word = str;
    }
    
    void prefix_function() {
      int j = 0;
      match[0] = 0;
      for(int i = 1; i < sz; i++) {
        while(j > 0 && word[i] != word[j]) {
          j = match[j - 1];
        }
        if(word[i] == word[j]) {
          j++;
        }
        match[i] = j;
      }
    }

    bool find(string& text) {
      prefix_function();
      bool show = 0;
      int j = 0, tam = (int)text.size();
      for(int i = 0; i < tam; i++) {
        while(j > 0 && text[i] != word[j]) {
          j = match[j - 1];
        }
        if(text[i] == word[j]) {
          j++;
        }
        if(j == sz) {
          found.push_back({i - j + 1, i - j + sz});
          show = 1;
        }
      }
      return show;
    }
    
    vector<pair<int, int>> occurrences(string& text) {
      find(text);
      return found;
    } 
};
