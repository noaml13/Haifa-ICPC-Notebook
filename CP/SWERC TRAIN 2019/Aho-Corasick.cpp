/*
Aho-Corasick algorithm/data structure
Complexity: O(M) when M is the sum of length of all words
To search in text (after build) is O(N) when N is the length of the text
insert words into trie using "push_word"
create the links for the automaton using "create_links" (use after all word had been pushed)
use the automaton using "next_state"
*/
struct AhoCorasick{
    vector<map<char,int>> to;
    vector<bool> endw; //in which state a word is ended (if want which word, maintain a vvb
    vector<int> link;
    int sz=1;
    AhoCorasick(): to(vector<map<char,int>>(1)), endw(vector<bool>(1,0)){}
    void push_word(string& s){
        int cur = 0;
        for(auto& c: s){
            if (!to[cur][c]) {
                to[cur][c] = sz++;
                to.pb(map<char,int>());
                endw.pb(0);
            }
            cur = to[cur][c];
        }
        endw[cur] = 1;
    }
    void create_links(){
        queue<int> q;
        q.push(0);
        link.resize(to.size(),0);
        link[0] = -1;
        int v,u,j;
        char c;
        while(q.size()){
            v = q.front();
            q.pop();
            for(auto& it:to[v]){
                c = it.x;
                u = it.y;
                j = link[v];
                while(j!=-1 && !to[j][c]) j = link[j];
                if (j!=-1) link[u] = to[j][c];
                else link[u] = 0;
                q.push(u);
                endw[u]=endw[u] || endw[link[u]]; //merge the endw (if endw[i] is vector merge them)
            }
        }
    }
    int next_state(int cur, char c){
        while(cur!=-1 && !to[cur][c]) cur = link[cur];
        if (cur==-1) return 0;
        return to[cur][c];
    }
};
