Problem -
=======
[Manacher's Algorithm - Finding all sub-palindromes in O(N)](https://cp-algorithms.com/string/manacher.html)

Given string `s` of length `n`. Find all pairs `(i, j)` such that `s[i..j]`
is a palindrome. Compact form: for each center, the length of the longest
palindrome there (`d_odd[]`, `d_even[]`); the rest of the chain is implied.

Longest palindromic substring is argmax over those radii.

Solution -
========
Manacher. Trivial expand-around-center is O(n^2). Inside the current
rightmost palindrome `(l, r)`, the mirror `j = l + (r - i)` is a lower
bound on `d[i]`, clipped by `r - i`. Extra expansions only happen when
`r` grows, so O(n).

`#` transform reduces even length to the odd case.

See `longest_palindromic_substring.py` for the notes + impl.
