# cook your dish here
def maxCrossSubarraySum(A, low, mid, high):
    l_sum = -10**9
    c_sum = 0
    max_left = mid
    for i in range(mid, low-1, -1):
        c_sum+=A[i]
        if c_sum>l_sum:
            l_sum=c_sum
            max_left=i
    r_sum = -10**9
    c_sum = 0
    max_right = mid+1
    for j in range(mid+1, high+1):
        c_sum+=A[j]
        if c_sum>r_sum:
            r_sum=c_sum
            max_right=j
    return (max_left, max_right, l_sum+r_sum)
    
def maxSubarraySum(A, low, high):
    if low==high:
        print(low)
        return tuple([low,high,A[low]])
    else:
        mid = (low+high)//2
        low_l, high_l, max_l = maxSubarraySum(A, low, mid)
        low_r, high_r, max_r = maxSubarraySum(A, mid+1, high)
        cro_l, cro_r, max_cr = maxCrossSubarraySum(A, low, mid, high)
        if max_l>=max_r and max_l>=max_cr:
            return (low_l, high_l, max_l)
        if max_r>=max_l and max_r>=max_cr:
            return (low_r, high_r, max_r)
        else:
            return (cro_l, cro_r, max_cr)

if __name__=='__main__':
    A= [13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7]
    ans = maxSubarraySum(A, 0, 15)
    print("left index: ", ans[0])
    print("right index: ", ans[1])
    print("max sub sum: ", ans[2])
    
