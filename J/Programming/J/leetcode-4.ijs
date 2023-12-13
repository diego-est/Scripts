#!/usr/bin/env ijconsole
nums1 =: 1 2
nums2 =: 3 4
s =: /:]
n =: nums1,nums2
t =: <. 1+ 2%~ # /:] n
k1 = t {. n
k2 = t }. |. n
2%~ +/ k2 * k1 e. k2
