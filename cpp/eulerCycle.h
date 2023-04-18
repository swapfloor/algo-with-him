欧拉回路 Hierholzer 算法
从起点 u 开始沿边走到 v，每个点只能访问一次，如果走到尽头，回来时的路即为欧拉回路。
伪代码
seen := set()
path := []
void dfs(int u):
  seen[u] = true
  for (auto v : to[u]):
    if (not seen[v]):
      dfs(v)
      path.append(v)
print(path) # ans = path
要求：
- din == dout 入度 = 出度
- 图连通
