""" An implementation of 0-indexed Fenwick Tree in Python"""
""" Source: https://cp-algorithms.com/data_structures/fenwick.html"""

""" Key Ideas:
- Is characterized by a Associative Binary Operator `f`: +, min, max, etc.
- Is characterized by an invertible function `g` that specifies the lower end 
    of the included range [g(i), i] note that 0 <= g(i) <= i must hold. Let 
    inverse of g be represented by h
- When g(i) = i, the "tree" degenerates to plain array and updates are O(1) 
    and query are O(n)
- When g(i) = 0, the "tree" degenerates to prefix array and udpates are O(n) 
    and query are O(1)
- Overall, FenwickTree (T) takes O(n) space
- Each idx in T stores value f(A[g(idx)], A[g(idx) + 1], ..., A[idx])
- Typically this Data Structure is used for keeping track of frequency and
    answering queries about cumulative frequency
"""

class FenwickTree:
    """ An example Fenwick Tree where f: sum, g: unset all trailing set bits """
    def __init__(self, size: int):
        self.n = size
        self.tree = [0] * size

    def update(self, idx: int, delta: int):
        while idx < self.n:
            self.tree[idx] += delta
            idx = idx | (idx + 1) # h(idx)
    
    def query(self, idx: int):
        res: int = 0
        while idx >= 0:
            res +=  self.tree[idx]
            idx = (idx & (idx + 1)) - 1 # g(idx) - 1
        return res

if __name__ == '__main__':
    t = FenwickTree(8)
    t.update(0, 1)
    t.update(3, 2)
    t.update(5, 1)
    t.update(7, 12)
    for i in range(8):
        print(f"{i}: {t.query(i)}")
    