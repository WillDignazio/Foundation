import cython 

@cython.profile(False)
cdef int cython_terminus():
	cdef int num
	while True: 
		num += 1	
