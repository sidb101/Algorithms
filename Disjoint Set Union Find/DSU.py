""" An implementation of Union-Find Disjoint Set in Python"""
""" Source: self"""

""" Key Ideas:
- by virtue of the `parent`, DSU is essentially a reversed-tree
- We can add support for a third-query `count_sets` by introducing a `uniq`
    counter, each time we perform union and we find that the two sets weren't
    already part of the same set we decrement `uniq` allowing the O(1) query
- TODO: fill this
"""

class DSU:
    def __init__(self, n):
        self.n = n
        self.parent = [i for i in range(n)]
        self.rank = [0 for _ in range(n)]
        self.uniq = n

    def union(self, i, j):
        pi, pj = self.find(i), self.find(j)
        if pi == pj:
            return
        if self.rank[pi] < self.rank[pj]:
            self.parent[pi] = pj
        elif self.rank[pi] > self.rank[pj]:
            self.parent[pj] = pi
        else:
            self.parent[pi] = pj
            self.rank[pj] += 1
        self.uniq -= 1

    def find(self, i):
        if self.parent[i] == i:
            return i
        self.parent[i] = self.find(self.parent[i])
        return self.parent[i]
    
    def count_sets(self):
        return self.uniq