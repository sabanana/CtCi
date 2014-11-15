def UniqueChar1(str1):
	# use hash table
	# Running time O(n). (Search in dict is O(1))
	charhash = {}
	for c in str1:
		if c in charhash.keys():
			return False
		else:
			charhash[c] = 0

	return True


def UniqueChar2(str2):
	# not using additional data structures
	# running time O(n^2)
	l = len(str2)
	for i1 in range(l-1):
		for i2 in range(i1+1 , l):
			if str2[i1] == str2[i2]:
				return False

	return True


def main():
	stest1 = "adxisf"
	stest2 = "scisdefg"
	stest3 = "abcdefg"

	print "Func1: "
	print "Test1: ", UniqueChar1(stest1)
	print "Test2: ", UniqueChar1(stest2)
	print "Test3: ", UniqueChar1(stest3)

	print "Func2: "
	print "Test1: ", UniqueChar2(stest1)
	print "Test2: ", UniqueChar2(stest2)
	print "Test3: ", UniqueChar2(stest3)


if __name__ == '__main__':
	main()