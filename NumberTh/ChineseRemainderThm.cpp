Given (M1,M2,M3.....Mn) & (y1,y2,y3.....yn)
such that (M1,M2...Mn) are co-prime with one another
Find X.?

LCM=(M1*M2*M3....Mn)
Range Of X=[0,LCM-1]

Eg[Naive Method]:

1. X % 5 = 3 -------> 3, 8, 13, 18, 23, 28.....
2. X % 3 = 2 -------> 2, 5, 8, 11, 14, 17, 20, 23, 23, 26, 29.....
3. X % 2 = 1 -------> 1, 3, 5, 7, 9, 11, ......, 21, 23 25.....
  
solution => 23 + k*(LCM) [0,1,2....]  
            23,53,83,113,143....
 
Eg[Optimal Method]:
the starting point will be the first no. from prev numbers that satisfy the current modulus y
ex: 381 % 7 = 3 (381 is the first no. whose modulus is 3)

1. X % 4 = 1 -------> 1, 5, 9, 13, 17, 21....
2. X % 5 = 1 -------> 1, 21, 41, 61,......(+20[lcm(4,5)])
3. X % 3 = 0 -------> 21, 81, 141, 201, 261, 321, 381,......(+60[lcm(3,20)])
4. X % 7 = 3 -------> 381, 801,......(+420[lcm(7,60)])

Solution => 381 + k*(420)
