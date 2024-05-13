test_list = [(2, 3), (4, 1), (8, 11), (-1, 6)]

# printing original list
print("The original list is : " + str(test_list))

# using min() and max()
# to get min and max in list of tuples
res1 = min(test_list)[0], max(test_list)[0]
res2 = min(test_list)[1], max(test_list)[1]

# printing result
print("The min and max of index 1 : " + str(res1))
print("The min and max of index 2 : " + str(res2))
