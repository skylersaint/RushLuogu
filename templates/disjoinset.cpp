int fa[1e5 + 5];
int find(int x) { return fa[x] = x ? x : fa[x] = find(fa[x]); }
void uinte(int x, int y) { fa[find(x)] = find(y); }