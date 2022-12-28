
#include <iostream>
#include <cstdio>
using namespace std;
template <typename T>
/*class vector {
private:
    int idx;
    T *container;
public:
    vector() : idx(0) , container(new T[1]) {}
    ~vector() {
        delete[] container;
    }
    void push_back(T num) {
        container[idx] = num;
        idx += 1;
        if((idx & (idx-1)) == 0) {
            T *temp = new T[(idx<<1)];
            for(int i = 0; i < idx; i++) {
                temp[i] = container[i];
            }
            delete[] container;
            container = temp;
        }
    }
    T operator[](int k) {
        return container[k];
    }
    int size() {
        return idx;
    }
};
*/
class vector {
private:
    int idx;
    T *container;
public:
    vector() : idx(0), container(new T[1]) {}
    ~vector() {
    delete[] container;
    }
    void push_back(T num){
    container[idx] = num;
    idx +=1;

    if(idx & (idx-1) == 0){
        T *temp = new T[(idx<<1)];
        for(int i=0; i<idx; i++){
            temp[i] = container[i];
        }
        delete[] container;
        container = temp;
    }
    }
    T operator[] (int k){
    return container[k];
    }
    int size(){
    return idx;
    }
};
vector<int> g[100005];
int vis[100005];
int cnt = 0;


void dfs(int u){
    if(vis[u]==1) return;
    vis[u] = 1;
    cnt++;
    for(int i = 0; i<g[u].size(); i++){
        dfs(g[u][i]);
    }
}

int main() {
	int n, m, u, v, w;
	cin >> n >> m;
	for(int i = 0; i<m; i++){
	    cin >> u >> v;
	    g[u].push_back(v);
	    g[v].push_back(u);
	}
	dfs(1);
	if(cnt == n) printf("Connected!\n");
	else printf("Dis Connected!\n");

	return 0;
}
