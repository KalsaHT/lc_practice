# -*- coding: utf-8 -*-
"""
@time: 2017/9/14

@author: leilei
"""


def selection_sort(one_list):
    '''one_list: list to be sorted'''

    if not one_list:
        return one_list

    min_num = one_list[0]
    min_idx = 0
    for i in xrange(len(one_list)-1):
        for j in xrange(i, len(one_list)):
            if one_list[j] < min_num:
                min_num = one_list[j]
                min_idx = j

        tmp_num = one_list[i]
        one_list[i] = min_num
        one_list[min_idx] = tmp_num

        min_num = one_list[i+1]
        min_idx = i+1

    return one_list


def insertion_sort(one_list):
    if not one_list:
        return one_list

    new_list = []
    for i in xrange(len(one_list)):
        idx = 0
        num = one_list[i]
        for j in xrange(len(new_list)):
            if num < new_list[j]:
                idx = max(0, j-1)
                break
            elif j == len(new_list)-1:
                idx = j+1

        new_list.insert(idx, num)
    return new_list


def shell_sort(one_list):
    if not one_list:
        return one_list

    h = len(one_list)/2  #interval
    while h:
        for i in xrange(h, len(one_list)):
            while i>0:
                if one_list[i] < one_list[i-h]:
                    tmp = one_list[i]
                    one_list[i] = one_list[i-h]
                    one_list[i-h] = tmp
                i -= h
        h /= 2

    return one_list

one_list = [0]
print insertion_sort(one_list)