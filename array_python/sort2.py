# -*- coding: utf-8 -*-
"""
@time: 2017/9/15

@author: leilei
"""

def merge(a, lo, mid, hi):
    '''a 是一个在一半位置已排序的列表,当区间是一个偶数时,mid选择偏前一位'''

    i = lo
    j = mid + 1

    a_copy = a[:]

    for k in xrange(lo, hi+1):
        if i > mid:
            a[k] = a_copy[j]
            j += 1
        elif j > hi:
            a[k] = a_copy[i]
            i += 1
        elif a_copy[i] > a_copy[j]:
            a[k] = a_copy[j]
            j += 1
        else:
            a[k] = a_copy[i]
            i += 1
    return a


def merge_sort_top_down(a, lo, hi):
    if hi <= lo:
        return
    mid = lo + (hi - lo)/2
    merge_sort_top_down(a, lo, mid)
    merge_sort_top_down(a, mid+1, hi)
    merge(a, lo, mid, hi)


def merge_sort_bottom_up(a):
    N = len(a)
    sz = 1
    while sz < N:
        lo = 0
        while lo < N-sz:
            mid = lo + sz -1
            hi = min(lo + 2*sz -1, N-1)
            merge(a, lo, mid, hi)
            lo += 2*sz

        sz += sz


def _partition(a, lo, hi):
    tmp = a[lo]
    i = lo
    j = hi
    while i < j:
        # 从后向前
        print a
        while(i < j and a[j] >= tmp):
            j -= 1

        if i<j:
            a[i] = a[j]
            i += 1

        # 从前往后
        while(i < j and a[i] <= tmp):
            i += 1

        if i < j:
            a[j] = a[i]
            j -= 1
    a[i] = tmp
    return i


def quick_sort(a, lo, hi):
    if hi <= lo:
        return
    pivot = _partition(a, lo, hi)
    quick_sort(a, lo, pivot)
    quick_sort(a, pivot+1, hi)





a = [2, 1, 0, 2, 2, 3, 3, 6, 7]
lo = 0
mid = 0
hi = 1

# merge_sort_top_down(a, 0, 8)
# print a
# b = [2, 1, 2, 3, 6, 3, 0, 7, 2]
# merge_sort_bottom_up(b)
# print b
print _partition(a, 0, 3)
print a