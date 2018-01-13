Alice, Bob and Chocolate
----
First, wi will calculate prefix sum of the amount of bars on the table. As Alice starts to eat from left to right it will also show the amount of bars that Alica can it. 
-Let's say Alice stands in position i=0 and Bob stands in position j=n-1.
-It is clear that while they eat chocolates 'i' cannot be greater than 'j'.
-Also, the amount of bars are representing the time that should be spent to eat them. So if the amount of bars that Alice eat is greater than the amount of bars that Bob eat, Bob will take next chocolate. Or if the amount of bars that Alice eat is less than the amount of bars that Bob eat, then Alice will take next chocolate.

*Coplexity*

The time complexity of this algorithm is linear O(n) for creating a prefix-sum vector and O(n) time to find the amount of bars consumed by Alice and Bob. O(n)+O(n)=O(2n)



Alternative Thinking
----

if in our array a[i]!=a[i-1], then we do not need to change them, because it will not affect the result. Lets look at example: for '10101' we will find 4 where str[i]!=str[i-1]. But length is 5. So we initialize s=1. It does not matter how long will be our contiguous non-empty substring because it only will add to our alternating subsequence 2 more {1,0}. So s will be s+2. As the length can be increase n (length of our initial array), we will take min(n, s).

*Coplexity*

We will scan our array once that will take O(n) time.

[code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Alternative%20Thinking.txt)


![image1](https://user-images.githubusercontent.com/32219705/34911030-f95c43b0-f8c9-11e7-9833-6f036afb38a9.jpg)
