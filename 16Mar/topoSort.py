from collections import deque

def topo_sort_bfs(n, adj):
    indegree = [0] * n

    for u in range(n):
        for v in adj[u]:
            indegree[v] += 1

    q = deque()
    for i in range(n):
        if indegree[i] == 0:
            q.append(i)

    topo = []

    while q:
        node = q.popleft()
        topo.append(node)

        for neighbor in adj[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                q.append(neighbor)

    if len(topo) != n:
        return "Cycle detected"

    return topo


def topo_sort_dfs(n, adj):
    visited = [False] * n
    stack = []

    def dfs(node):
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                dfs(neighbor)
        stack.append(node)

    for i in range(n):
        if not visited[i]:
            dfs(i)

    stack.reverse()
    return stack


n = 6
adj = [
    [2, 3],
    [3, 4],
    [5],
    [5],
    [],
    []
]

print(topo_sort_bfs(n, adj))

print(topo_sort_dfs(n, adj))