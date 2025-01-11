import numpy as np

size: int = 80
times: int = 10
mtrx_list = []
print(mtrx_list)
for i in range(0,size):
    mtrx_list.append([])
    for j in range(0,i):
        mtrx_list[-1].append(0)
    for j in range(i,size):
        mtrx_list[-1].append(1)
matrix = np.array(mtrx_list)
print("The matrix is \n",matrix)

vector = np.array([int(x==0) for x in range(0,size)])
print("The initial vector is\n",vector)

for i in range(0,times):
    vector = np.dot(vector,matrix)
    print("The No.",i+1," Operation:\n",vector)