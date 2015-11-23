import random
import string
import sys
data_N = int(sys.argv[1])
datafile = open('student_data.txt','w')
for i in range(data_N):
    strings = []
    random.seed()
    N = 8
    datafile.write(''.join(random.choice(string.digits) for _ in range(N))+'\n')
    N = random.randint(5,8) 
    datafile.write(''.join(random.choice(string.ascii_lowercase) for _ in range(N))+'\n')
    N = 10
    datafile.write(''.join(random.choice(string.digits) for _ in range(N))+'\n')
    datafile.write(str( 3 + random.random())+'\n')
    #print ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(N))
    #datafile.writelines(strings)
