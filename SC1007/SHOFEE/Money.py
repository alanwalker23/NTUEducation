def printSets(set1, set2) :

	# Print set 1.
	for i in range(0, len(set1)) :
		print ("{} ".format(set1[i]), end ="");
	print ("")

	# Print set 2.
	for i in range(0, len(set2)) :
		print ("{} ".format(set2[i]), end ="");
	print ("")

def findSets(arr, n, set1, set2, sum1, sum2, pos) :
	if (pos == n) :
		if (sum1 == sum2) :
			printSets(set1)
			return True
		else :
			return False	

	set1.append(arr[pos])

	res = findSets(arr, n, set1, set2,
			sum1 + arr[pos], sum2, pos + 1)

	# If this inclusion results in an equal sum
	# sets partition then return true to show
	# desired sets are found.
	if (res) :
		return res

	# If not then backtrack by removing current
	# element from set1 and include it in set 2.
	set1.pop()
	set2.append(arr[pos])

	# Recursive call after including current
	# element to set 2 and removing the element
	# from set 2 if it returns False
	res= findSets(arr, n, set1, set2, sum1,
					sum2 + arr[pos], pos + 1)
	if not res:	
		set2.pop()
	return res

# Return true if array arr can be partitioned
# into two equal sum sets or not.
def isPartitionPoss(arr, n) :

	# Calculate sum of elements in array.
	sum = 0

	for i in range(0, n):
		sum += arr[i]

	# If sum is odd then array cannot be
	# partitioned.
	if (sum % 2 != 0) :
		return False

	# Declare vectors to store both the sets.
	set1 = []
	set2 = []

	# Find both the sets.
	return findSets(arr, n, set1, set2, 0, 0, 0)

# Driver code
size = int(input())
arr = []
for i in range(size):
    arr.append(int(input()))
if (isPartitionPoss(arr, size) == False) :
	print ("0")