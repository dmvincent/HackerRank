#!/usr/bin/python3
def is_leap(year):
	if year%4 == 0:
		if year%100 != 0:
			return True
		else:
			if year%400 == 0:
				return True
			else:
				return False
	else:
		return False

if __name__ == "__main__":
	year = int(input())
	print(is_leap(year))