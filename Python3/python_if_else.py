#!/usr/bin/python3

import math
import os
import random
import re
import sys

if __name__ == '__main__':
	n = int(input().strip())
	str1 = "Weird"
	str2 = "Not Weird"
	if n%2 != 0:
		print(str1)
	else:
		if n>=2 and n<=5:
			print(str2)
		elif n>=6 and n<=20:
			print(str1)
		elif n>20:
			print(str2)
