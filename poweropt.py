#!/usr/bin/env python3
p = 1
base = 2
a = [base,base]
a[0] = base
for i in range(99999):
	a[1] = a[0] * base
	a[0] = a[1]
print(a[0])
