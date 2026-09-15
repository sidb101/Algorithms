""" Manacher: all sub-palindromes in O(n), then the longest one """
""" Source: https://cp-algorithms.com/string/manacher.html """

""" Key Ideas:
- s of length n can have O(n^2) palindromic substrings, but they compact:
    palindromes that share a center form a chain of lengths l, l-2, l-4, ...
    so it is enough to store, per center, how far that chain goes. Odd and
    even lengths are different centers: `d_odd[i]` counts odd palindromes
    centered on `s[i]`; `d_even[i]` counts even ones whose two middle
    characters are `s[i-1]`, `s[i]`.
- The trivial algorithm (for each center, grow by 1 while the two new
    characters match) is exactly that chain, computed from scratch, O(n^2).
    Manacher reuses already-computed radii inside the current rightmost
    palindrome so the trivial expansions across the whole string are O(n).
- Maintain exclusive borders `(l, r)` of the rightmost palindrome found so
    far: the palindrome itself is `s[l+1 .. r-1]`. Initially `(l, r) = (0, 1)`
    (empty). For the next center `i`:
      - if `i >= r`, we have no information, launch trivial from 0
      - if `i < r`, the mirror of `i` about `(l+r)/2` is `j = l + (r - i)`.
        Symmetry says we can copy `d[j]`, except when that inner palindrome
        reaches the outer borders (`j - d[j] <= l`, equiv. `i + d[j] >= r`):
        outside `(l, r)` we have no symmetry, so clip to `d[i] = r - i` and
        then launch trivial to try growing into the unknown region
- `r` never decreases, and every successful trivial comparison increases `r`
    by 1, hence O(n) total. Same amortization as Z-function.
- Even-length Manacher is the same idea and an off-by-one factory. Reduce
    to the odd case by interleaving `#`:

        abcbcba -> # a # b # c # b # c # b # a #

    Odd palindromes of `s` stay centered on letters; even palindromes of `s`
    become odd palindromes of `t` centered on `#`. If `d` is Manacher on `t`,
    `d[2i] = 2 d_even[i] + 1` and `d[2i+1] = 2 d_odd[i]`. Under this
    transform `d[i]` is also the palindrome length in `s`.
- This impl keeps `(center, right)` with `right` inclusive (`right` here is
    the article's `r - 1`). Mirror is written `center - (i - center)` rather
    than `2*center - i` / `l + (r - i)`: it is "same offset, other side".
    The trivial step compares `t[i - (radii[i] + 1)]` vs
    `t[i + (radii[i] + 1)]` rather than pre-decrementing; that is "the next
    unset character on each side". Bounds checks instead of `$`/`^` sentinels.
    Building `t` by appending `[ch, "#"]` and recovering the original
    substring with `.replace("#", "")` are left as-is; the transform is 2n+1,
    a JIT can eat it.
- Slice `t[i - radii[i] : i + radii[i]]` is python-exclusive on the right.
    `i + radii[i]` is always a `#` (center and radius have the same parity),
    so dropping it is harmless. Longest substring is argmax over `radii`.
"""

def longest_palindrome(s: str) -> str:
    t_str = ["#"]
    for ch in s:
        t_str += [ch, "#"]

    t_str = "".join(t_str)
    n = len(t_str)

    radii = [0] * n
    center = right = 0

    for i in range(n):
        if i < right:
            mirror = center - (i - center)
            radii[i] = min(right - i, radii[mirror])

        while i - (radii[i] + 1) >= 0 and \
            i + (radii[i] + 1) < n and \
            t_str[i - (radii[i] + 1)] == t_str[i + (radii[i] + 1)]:
            radii[i] += 1

        if radii[i] > right - i:
            center = i
            right = center + radii[i]

    ans, ansl = s[0], 1
    for i in range(n):
        if radii[i] > ansl:
            ansl = radii[i]
            ans = t_str[i-radii[i]:i+radii[i]].replace("#", "")
    return ans

if __name__ == '__main__':
    s = "mississippi"
    print(longest_palindrome(s))
