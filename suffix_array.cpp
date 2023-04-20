// Suffix Array - Construção O(n*log(n))
// 
// Implementação pra estudos, pouquinho mais longa que a de qualquer caderno
// provavelmente, mas funciona (eu espero)
// https://cp-algorithms.com/string/suffix-array.html

class SuffixArray {
private:
  void sort_cyclic_shifts(string const& s){
    int n = s.size(), classe, nalfabeto = 256;
    p = vector<int>(n);
    vector<int> c(n), pn(n), cn(n), cont(max(nalfabeto, n), 0);
    
    // faz ordenação inicial pela primeira letra da string
    for(int i = 0; i < n; i++)
      cont[s[i]]++;
    for(int i = 1; i < nalfabeto; i++)
      cont[i] += cont[i-1];
    for(int i = 0; i < n; i++)
      p[--cont[s[i]]] = i;

    // setando vetor de classes de equivalência inicialmente
    c[p[0]] = 0; classe = 0;
    for(int i = 1; i < n; i++){
      if(s[p[i]] != s[p[i-1]]) classe++;
      c[p[i]] = classe;
    }

    // ordenando com preffix doubling
    for(int k = 0; (1 << k) < n; k++){
      // ordenamos as substrings de tamanho 2^(k+1) pela combinação das de tamanho 2^k
      // já ordenadas na iteração/fase anterior. Ordenando pela segunda parte:
      for(int i = 0; i < n; i++)
        pn[i] = (p[i] - (1 << k) + n) % n;

      // ordenando pela primeira parte:
      fill(cont.begin(), cont.begin() + classe + 1, 0);
      for(int i = 0; i < n; i++)
        cont[c[pn[i]]]++;
      for(int i = 1; i <= classe; i++)
        cont[i] += cont[i-1];
      for(int i = n-1; i >= 0; i--)
        p[--cont[c[pn[i]]]] = pn[i];

      // setando vetor de classes de equivalência pra próxima iteração
      cn[p[0]] = 0; classe = 0;
      for(int i = 1; i < n; i++){
        pair<int, int> cur = mp(c[p[i]], c[(p[i] + (1 << k)) % n]);
        pair<int, int> prev = mp(c[p[i-1]], c[(p[i-1] + (1 << k)) % n]);
     
        if(cur != prev) classe++;
        cn[p[i]] = classe;
      }
      c.swap(cn);
    }
  }

  void get_rank(){ // rank, função inversa do suffix array
    r = vector<int>(p.size(), 0);
    for(int i = 0; i < p.size(); i++)
      r[p[i]] = i;
  }

  void kasai(string const& s){ // LCP
    int n = s.size();

    int k = 0;
    lcp = vector<int>(n-1, 0);
    for(int i = 0; i < n; i++){
      if(r[i] == n-1){ // chegamos no último sufixo
        k = 0;
        continue;
      }

      int j = p[r[i] + 1]; // próximo cara dps do sufixo i na ordenação do suffix array
      while(i + k < n && j + k < n && s[i+k] == s[j+k])
        k++;

      lcp[r[i]] = k;
      if(k)
        k--;
    }
  }

public:
  vector<int> p, r, lcp;

  SuffixArray(string s){
    s += "$";
    sort_cyclic_shifts(s);
    get_rank();
    kasai(s);
  }

  void debug(string const& s){
    for(int i = 0; i < s.size(); i++){
      if(i != s.size()-1) cout << lcp[i] << " ";
      else cout << "- ";
      for(int j = p[i]; j < s.size(); j++) cout << s[j];
      cout << endl;
    }
  }
};

