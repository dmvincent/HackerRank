#!/usr/bin/python3

import numpy as np

arr = input().strip().split(' ')
size = np.array(arr, dtype="uint8")
i = 0
height, width = size[0], size[1]
zero=np.zeros((height,width), dtype="uint8")
while i < int(height):
	j = 0
	inLine = input().strip().split(' ')
	row = np.array(inLine, dtype="uint8")
	while j < len(row-1):
		zero[i][j] = row[j]
		j = j+1
	i = i+1	
tPosed = zero.T
print(tPosed)
flat = zero.flatten()
print(flat)
