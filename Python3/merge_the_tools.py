#!/usr/bin/python3

def merge_the_tools(string, k):
	# your code goes here
	r = len(string)/k
	print("r: ", r)
	
	for i, e in enumerate(string):
		if (i+1)%k == 0:
			word=string[i-k+1:i+1]
			word2 = word[0]
			for j, c in enumerate(word):
				for q, d in enumerate(word2):
					if word[j] == word2[q]:
						break
					if q == (len(word2)-1):
						word2 =word2 + c
			
			print(word2)

if __name__ == '__main__':
	string, k = input(), int(input())
	merge_the_tools(string, k)
