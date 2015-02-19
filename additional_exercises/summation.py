for N in range(20):
	forward_sum = 0
	reverse_sum = 0
	for i in range(1,N+1):
		forward_sum += 1./i
	for i in range(N):
		reverse_sum += 1./(N-i)
#	print 2*(forward_sum - reverse_sum)/(forward_sum + reverse_sum)
	print forward_sum - reverse_sum
