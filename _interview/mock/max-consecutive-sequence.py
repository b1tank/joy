1 7 2 9 4 5 8

1 .. 1 


def binary_search(buckets, i):
    l = 0
    r = len(buckets)
    while l <= r:
        mid = l + (r - l) / 2
        tmp = buckets[mid][1]
        if i == tmp:
            pass
        elif i < tmp:
            r = mid - 1
        else:
            l = mid + 1
    return l

def maxConsecutive(li):
    if not li:
        return 0
    buckets = [] 
    res = 1
    for i in li:    
        if not buckets:
            buckets.append([i, i])
            continue
        insert_i = binary_search(buckets, i)
        ## 0 end
        if insert_i == 0:
            if i >= buckets[0][0]:
                continue
            else:
                buckets.insert(insert_i, [i, i])
        elif buckets[insert_i-1][1] == i-1:
            buckets[insert_i-1][1] += 1
        else:
            buckets.insert(insert_i, [i, i]) 
    
    cur_len = buckets[0][1] - buckets[0][0]+1
    for k in xrange(1, len(buckets)):
        if buckets[k-1][1] != buckets[k][0]-1:
            cur_len = 0
        cur_len += buckets[k][1]-buckets[k][0]+1
        res = max(res, cur)
    return res
