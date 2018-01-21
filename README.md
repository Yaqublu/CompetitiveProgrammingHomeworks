#20/09/2017
----
Leaders in an array [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/LeadersInArray.cpp)
---
The best way of finding all leader elements in the array, which are greater than all the elements to its right side, is to start from the right end of the array. It is clear that the last element A[n-1] is the Leader element, as there is no element in its right side. Let's take a variable 'max' and give initial value as -1 (it is ensured that all elements are not less than 0). Then by scanning all the elements from right to left in the given array, if the element A[i] is greater than 'max' we change the value of 'max' to A[i] and save it in a stack. By printing all elements of the stack in a reverse order we will get Leaders in our given array.

*Coplexity*

We scan elements of array once, so this algorithm will take linear time O(n)

Kadane's Algorithm [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/KadanesAlgorithm.cpp)
----
First we take 2 variables sum = 0 and max = A[i] (that will contain maximum sum of the array). By scanning elements from left to right, we start to calculate the sum and each time if 'sum' is greater than 'max' we change the value of 'max' to 'sum'. As we need the maximum sum of the contiguous sub-array if 'sum' becomes less than 0 we change the value of 'sum' to 0 (because summarizing negative elements will decrease our sum). As soon as we find new sum that is greater than our 'max', we update 'max'.

*Coplexity*

We scan elements of array one time, so this algorithm will take linear time O(n)

Missing Number In Array [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/MissingNumberInArray.cpp)
----
We know that the sum of elements from 1 to n is (1+n)*n/2 . By subtracting the sum of the elements in the array that contains elements from 1 to n with one missing from this sum will give us that missing number.

*Coplexity*
 
We will spend O(n) time for calculating the sum of the element in the array and O(1) constant time for finding the missing number.

TrappingRainWater [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/TrappingRainWater.cpp)
----

Sliding Window Maximum [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/SlidingWindowMaximum.cpp)
-----
To solve this problem we use Dequeue. The capacity of our dequeue will be k (the size of subarray). We push the indexes of first k elements of the array to our dequeue. For each element in the dequeue, the previous smaller elements are useless, that's why we pop them from the dequeue. The front element od dequeue will contain the largest element of our window.
Then starting from k-th element of the array to n-1 
-We print the first element of the dequeue
-We remove element which is already out of our window
-We remove the elements with are smaller than newly added element
-We push new element to our dequeue 
At the end, we print the last large element for our last window.

*Coplexity*
 
As the all elements of the array will push and pop only one time, so we will spend O(2n)=O(n) time. Beside array that contains our elements, we will use O(k) space for our dequeue

#22/09/2017
-----

Next larger element [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Next%20larger%20element.cpp)
-----
To calculate Next Large Element we will use a stack.
-We push the index of the first element to the stack.
-For all elements from 1 to n-1
  -while our stack is not empty, we give the value of the first element of the stack to 'element' and pop it from the stack. If our current element A[next] (where next=i) is greater than A[element]. We change the value of A[element] to A[next]. Otherwise, we push 'element' to our stack and break our loop.
   -Then we also push index of our current element 'next' to our stack.
-After the loop, if our stack is still not empty, then it means that these elements do not have any next greater element. So we change all these elements in the array to -1.

*Coplexity*
 
The worse case is when our array sorted in a decreasing order. So, we push element to stack, then pop it for prosses our algorithm. As there is not any greater element,  we push it back to our stack. At the end, we again pop them from the stack. O(4n)=O(n)

Tower [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Tower.cpp)
-----
To find the total number of towers, we need to calculate wooden bars with different height. So the best way is to use vector. After sorting them we can easily calculate it. Then we need to count the amount of each different numbers. The largest amount will be the height of the largest tower.

*Coplexity*
 
The complexity of std::sort is O(n Logn). Then for finding the height of the largest tower and their total number will take O(n) time.

Finding Team Member [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Finding%20Team%20Member.cpp)
------
In order to find teammate of each contestant, we can take vector 'v' which will contain 2 contestants and their strength. Then we will sort our vector in decreasing order of strength of teams. Also, we will take another vector 't' which will initially 0. By scanning our vector, for i-th and j-th contestants if t[i] and t[j] are 0, then t[i]=j and t[j]=i.

*Coplexity*
 
For m=(1+(2*n-1))*(2*n-1)/2 where 2n is the number of contestants it will take O(m) time to create vector 'v'. O(mlogm) for sorting and O(m) time to find teammates.

#27/09/2017
-------
Mega City [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/MegaCity.cpp)
------
For each location, we will calculate radius by measuring a distance between 2 points: (0,0) and (x,y). We will use pair vector that will store radius if each location and its population. After sorting our vector by radius, we will sum population of each location. As it is asked to find the minimum radius of the circle that the city needs to expand to in order to become a megacity, we will stop as soon as the sum of the population will increase 1000000.

*Coplexity*
 
For sorting our vector we need O(nlogn) time. In order to find the minimum radius, in the worst case, it will take O(n).

Find Pair [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/FindPair.cpp)
------
We can calculate k-th pair with a formula without generating and sorting all pairs. After sorting of the given array of numbers, we will calculate the index of first and second members separately. In order to find the index of the first number of our k-th pair, we should divide that k by the number of our elements (which is 'n'). Let's say l=k/n (l is the index of the first number of our k-th pair). Then we count how many a[l] do we have ('amount'). 
 - if there is only one value with a[l], then the second number of our k-th pair will be k mod n.
 - Otherwise, we take the index of the first element that is equal to a[l] ('i') and then the index of the second number of our k-th pair will be (k - i*n)/amount

*Coplexity*
 
It will take O(n) time to fill our vector and O(nlogn) time for sorting it. If there is a repeated element in worth case it will take at most O(n) time to find it and a linear time to calculate first and last element of our pair

Two Heaps [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Two%20Heaps.cpp)
-----
In order to create 2 heaps, we will use pair vector that will contain from elements of our array and their indexes. Then we will sort it. In order to get the maximum possible number of distinct four-digit numbers, we should first start to place numbers, amount of which are not more than 1. Only after this, we can start to places other numbers.
While doing it, each time we should generate how many elements we put to each heap. Note that, if there is a number, amount of which is greater than 2, it is enough to count them once for each heap.

*Coplexity*
 
Let's say we will have 'm' elements. Then it will take O(2m) time for filling our vector and O(mlogm) time sorting. To decide where we will put each element will take O(m) time.

#05/10/2017
-------

Invertion Count [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Invertion%20Count.cpp)
-------

Largest Even Number [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Largest%20Even%20Numbers.cpp)
------
In order to find the largest even number, we should first find the smallest even element of our string and sort other elements in decreasing order and put that smallest element to end.
If there is not any even element, then just sort our elements in decreasing order and print them.
It is clear that all elements of our string will be consist of {0,1,2..9}. So by scanning the elements of our string, we can count the number of each element, therefore, we will need a new array a[10]. While counting them, we will also search for minimum even element.

*Coplexity*
 
It will take O(n) time to count, and O(n) time to print them in order that we need.

#11/10/2017
-------
Firing Employees [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/FiringEmployees.cpp)
-------
Lets look at example:

![image1](https://user-images.githubusercontent.com/32219705/34911273-ebdbf0d6-f8cf-11e7-9674-25a2516b20a1.jpg)

We will take vector<int> v[n+1] and push the rank of immediate seniors. So here it will be:

v[2][0] = 1

v[3][0] = 2

v[5][0] = 3

v[3][1] = 4

v[0][0] = 5

v[5][1] = 6

v[2][0] = 7

![image2](https://user-images.githubusercontent.com/32219705/34911282-2dc5d12e-f8d0-11e7-975b-53092b4d38fe.jpg)

*Coplexity*
 
Here v[0][0] is Mr Alfred.  So we start from the top and go 
down of the tree. And each time we will add to the number of 
siniors of the current employee, the number of seniors of its root. 
Time complexity of such algorithm is O(n).

ChechForBST [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/ChechForBST.cpp)
------
it is clear that in BST left-child should be less than its parent and right-child greater than its parent. Checking it recursively if one of the conditions above is not met for any parent root then it is not BST.

*Coplexity*
 
The time complexity will be O(n) since each node is examined once.

Preorder Traveler [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Preorder%20Traveler.cpp)
-------
After creating our tree by given input, in preorder tree travel we will print:
1. left child of root
2. root
3. right child of root

*Coplexity*
 
Time complexity is O(n)

Max Path Sum [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Max%20Path%20Sum.cpp)
---------
Starting form the root we will recurcively calculate left and right sub trees and return max of them.

*Coplexity*
 
Time complexity is O(n)
 
#13/10/2017
-------
Ilya and Queries [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Ilya%20and%20Queries.cpp)
------
In order to find the number of characters such that s[i]=s[i-1] in the given string s, we should use prefix sum.
-it is clear that for the first element of our sting there is no element that can be equal to it. So we take a vector and push 0. 
-Starting from the second element if there are any s[i]=s[i-1], then we increase our 'sum' and push it to our vector. Otherwise, we only push 'sum' without increasing it.
For given l[i] and r[i] the number of elements such taht s[i]=s[i-1] is v[r[i]]-v[r[i]].

*Coplexity*
 
The time complexity of this algorithm is linear O(n) for creating a prefix-sum vector and constant time O(1) to find the number of elements such that s[i]=s[i-1] in the given interval.

Alice, Bob and Chocolate [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Alice%2C%20Bob%20and%20Chocolate.cpp)
----
First, wi will calculate prefix sum of the amount of bars on the table. As Alice starts to eat from left to right it will also show the amount of bars that Alica can it. 
-Let's say Alice stands in position i=0 and Bob stands in position j=n-1.
-It is clear that while they eat chocolates 'i' cannot be greater than 'j'.
-Also, the amount of bars are representing the time that should be spent to eat them. So if the amount of bars that Alice eat is greater than the amount of bars that Bob eat, Bob will take next chocolate. Or if the amount of bars that Alice eat is less than the amount of bars that Bob eat, then Alice will take next chocolate.

*Coplexity*
 
The time complexity of this algorithm is linear O(n) for creating a prefix-sum vector and O(n) time to find the amount of bars consumed by Alice and Bob. O(n)+O(n)=O(2n)

Number of Ways [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Number%20of%20Ways.cpp)
-----
First, we should check our array can be split into three contiguous parts so that the sum of elements in each part is the same. If the sum of arrays is divisible by 3 then it can be split into three contiguous parts. Also if the length of the array is less then 3, it can not be split into three parts.
To find the number of ways of splitting we will need prefix and suffix sums of our array. Let's take a new array of 'c' with the initial value of 0 and for each suffix sum of 'i' if the sum divisible by 3, c[i]=1. Then we will calculate suffix sum of c[i]. After it, for each 'i' (starting from 0 to n-2) if the prefix sum of our given array is divisible by 3, we will sum c[i+2] that will give the number of ways.

*Coplexity*
 
We will calculate a prefix and suffix sum of given array and a suffix sum of c[i] that will take O(3n) time.

Little girl and Maximum Sum [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Little%20girl%20and%20Maximum%20Sum.cpp)
------
To solve this problem we need 2 vectors. One of them will contain elements of our array (vector<int>array) and the other will contain our queries (vector<int>count). For each i-th query, we will increase count[l-1] for left bound, and decrease count[r] for right bound. The prefix-sums of our 'count' vector will give us how many times we used the element in the given indexes for all queries. After sorting both vectors ('array' and 'count') we can subscribe count[i] with array[i] and summarize. This sum will be the maximum sum.

*Coplexity*
 
The complexity of creating 2 vectors will take O(2n), O(n) time for prefix-sum. As we are sorting both our array it will take 2*O(nlogn) and O(n) time for calculating the maximum sum. O(2n)+O(n)+2*O(nlogn)+O(n)=O(nlogn)

Update array [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/UpdateArray.cpp)
----
For the operation of the update, we do not need to update the whole array. It is enough to just increase left bound and decrease right bound with the given value. After calculating prefix sum of the array will give us the new value of the array.

*Coplexity*
 
For u update operations we will use O(2u) time and O(n) time for calculating prefix sum. 

#18/10/2017
-------
#20/10/2017
-------
Powerful Array [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Powerful%20Array.cpp)
-----

The best solution for this problem is Mo's algorithm. First, we divide our array into sqrt(n) buckets with the length of sqrt(n). The query will belong to Pth bucket if the opening of that query is fall in Pth bucket. Then we will reorder our queries q(L,R) in ascending order of R (whose L are in the same bucket).
After sorting we can apply Mo's algorithm which will take O(n*sqrt(n))

#25/10/2017
-------
#27/10/2017
-------
X Total Shapes [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/X%20Total%20Shapes.cpp)
------
Starting from the top we will scan our matrix and we will mark all the nodes as visited. if str[i][j]=='O' then we do nothing. Otherwise, if  str[i][j]=='X' and was already visited then look its neighbours if there is any 'X' (str[i+1][j], str[i][j+1], str[i-1][j], str[i][j-1]) and mark them as visited.
But, if str[i][j]=='X' and was not visited, then we have 2 ways. 1. If str[i+1][j] and str[i][j+1] was not visited then it means it is a new shape of 'X' so we increase total number of shapes
2. Otherwise, We just visit  str[i+1][j] and str[i][j+1].

*Coplexity*
 
As we scan our matrix once, So it will take O(n*m). Also, Besides our matrix, we need a new matrix visited[n][m] to mark all visited nodes (O(n*m) memory).

IsBipartite [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/IsBipartite.cpp)
------
First of all, if our graph is bipartite graph then there should not be a path from vertex u to u. So if G[u][u]==1 then ve return false.
For every vertex u, we check if there is an edge to any other vertex v and it does not have color then we give it a new color. However, if that vertex v has already been colored and its color is same as vertex u, then we return false.

*Coplexity*
 
We will check the connection of each vertex with others and with itself. So it will take O(V*V), where V is number of vertices

Fox and Names
------

#08/11/2017
-------
#10/11/2017
-------

Minimum Spanning Tree [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Minimum%20Spanning%20Tree.cpp)
-----

#15/11/2017
-------

N meetings in one room [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/N%20Meetings.cpp)
-----
It is better to use a vector that will contain the beginning, ending times of meetings as well as the index of them. In order to find the maximum number of meetings that can be accommodated in the meeting room, we should sort our vector by their beginning time. For each accommodated meeting we save their finishing time and compare it with the others starting time.

*Coplexity*
 
It will take O(n) time to fill our vector and O(nlogn) for sorting our vector. O(n) time for finding which of the meetings will take place 

Chat Room [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Chat%20Room.cpp)
-----
It is better to start searching from right to left in the string for each character of the word "hello" in the reverse order. As soon as we find the character that we are looking for we break our loop and start to look for next character of the word "hello" from where we broke our loop. 

*Coplexity*
 
It will take O(n) time in the worse case and linear time O(1) to decide if it is "YES" or "NOT" 

Magic Number [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Magic%20Number.cpp)
---------
It is better to start look to each character of our string ('str') from right to left.
-if the character str[i] is equal 4 then:
   -if (s[i-1]==4 and s[i-2]==1) or if s[i-1]==1, then we can continue to search
   -Otherwise, it is not magic number
-Also if s[i]==1, we can continue to search
-Otherwise, it is not magic number

*Coplexity*
 
In the worse case, we will scan all the characters of our string, that will take O(n) time.

Wilbur and Array [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Wilbur%20and%20Array.cpp)
-----
'count' will represent the number of operations. Initially, count=a[0] (note that the number of operations cannot be negative, so if a[0]<0 then count=-a[0])
By scanning elements of array from 1 to n
-if a[i]<a[i-1], then count += a[i-1]-a[i]
-else if a[i]>a[i-1] then count += a[i]-a[i-1]

*Coplexity*
 
We scan our array once, so it will take O(n) time

Alternative Thinking [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Alternative%20Thinking.cpp)
----
if in our array a[i]!=a[i-1], then we do not need to change them, because it will not affect the result. Lets look at example: for '10101' we will find 4 where str[i]!=str[i-1]. But length is 5. So we initialize s=1. It does not matter how long will be our contiguous non-empty substring because it only will add to our alternating subsequence 2 more {1,0}. So s will be s+2. As the length can be increase n (length of our initial array), we will take min(n, s).
 
*Coplexity*
 
We will scan our array once that will take O(n) time.

#17/11/2017
-------
Lexicographically Maximum Subsequence [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Lexicographically%20Maximum%20Subsequence.cpp)
--------
It is better to start to scan our string from right to left. Let's take max=a[n-1]. We will collect all characters in one array, which are greater than or equal to max. As soon as we find such character we change the value of max to a[i].
 
*Coplexity*
 
As we scan our string once it will take O(n) time.

Woodcutters [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Woodcutters.cpp)
------
In order to cut maximum trees, it is better to cut tree and fell it to left. It is clear that the first tree can be cut and fell to the left as well as the last tree can be cut and fell to the right. For other trees:
-If x[i]-h[i]>x[i-1] we can cut it and fell to left
-Else if x[i]+h[i]<x[i+1] we can cut it and fell to right
-Otherwise, we cannot cut it.
 
*Coplexity*
 
As we scan our array of tree once, the time complexity will be O(n)

Queue [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Queue.cpp)
-----
First we will sort our given array. It is clear that if a[i]>i, it means that there's no acceptable order of the people in the queue. Otherwise, for each person we will increase it value if before it there is a person whose value is greater or equal to his/her value.
 
*Coplexity*
 
It will take O(log n) for sorting and O(n^2) for finding the length of each person.

#22/11/2017
-------
IWGBS0110SS [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/IWGBS0110SS.cpp)
------
Let say we are looking for F(n). Then, by taking any F(n-1) where digits number are n-1 and by appending a 1, or by taking any F(n-2) where digits number are n-2 and by appending 01 will us F(n). Thus, F(N) = F(n - 1) + F(n - 2). Also, it is clear that F(1) = 2 and F(0) = 1. As we are working with big numbers it is better to save all digits of our number in an array and do adding operation with arrays.
 
*Coplexity*
 
It will take O(n) time for finding F(n).

Longest Common Subsequence [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Longest%20Common%20Subsequence.cpp)
------
This problem can be solved with Dynamic programming using recursion and memorization. We will take matrix and for 2 strings str1 and st2 with length n and m respectively:

1. for(i=0 to n) LCS[i][0];
2. for(i=0 to m) LCS[0][j];

![lcs](https://user-images.githubusercontent.com/32219705/34917783-532c21b0-f953-11e7-939e-2b2c5e723f68.jpg)

LCS[n][m] will be our result.
 
*Coplexity*
 
The algorithm takes O(n*m) memory and to build our matrix O(n*m). O(1) to report our result.

Knapsack problem [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Knapsack%20problem.cpp)
------
For n items we have v[1, ..., n] that represents value of these items and w[1, ..., n] that represents weight of these items. Also  we are given W which is the maximum total value in the knapsack. Again we will take matrix:

![knapsack](https://user-images.githubusercontent.com/32219705/34917798-9d7c758a-f953-11e7-98de-3397ff9aecd3.jpg)
 
*Coplexity*
 
We will use O(n*W) memory and the same for building this matrix. O(1) to report the result.

#24/11/2017
-------
Longest Increasing Subsequence [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/LongestIncreasingSubsequence.cpp)
------
For each element of our array, we will find prefix LIS (Longest Increasing Subsequence) (for a[i] we will look at a[0, ..., i-1]

If a[j]<a[i], LIS[i] = max(LIS[j]) (0<j<i); LIS[i]=1, otherwise.
 
*Coplexity*
 
So the problem runs in O(n^2) time.

Minimum Jump [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/MinJump.cpp)
------
First of all, we should look at some cases. If the length of our array is less than 2, we will not jump (return 0;). Or if our any element of our array is equal 0 (except last one), it means that we cannot jump anymore and stuck (return -1;).
As the value of elements of array shows max number of jumps that we can do, we will take a new variable ‘s’ and initialize it with a[0]. Starting from the 2nd element of the array we will make s steps. While going through array s steps, we will remember maximum element of the array in the range (i, i+s). It is clear that we need bigger element but it should be near to the end of our array. For example, we will go s=4 steps through {7, 2, 6, 3}, so we will take as a jump element {6}. So how decide that which element we should take?   

![image1](https://user-images.githubusercontent.com/32219705/34911030-f95c43b0-f8c9-11e7-9833-6f036afb38a9.jpg)

As shown in the picture above we can jump 6 steps. We go through these 6 elements and memorize bigger number among a[i]+i. Here 7+5 > 8 +2. Now our ‘maxx’=7+5=12 and we are in the position j=7 (a[7]). From the picture, it is clear that we already went 2 steps out of 7 steps and there are left 5 steps. So how we can get it? Maxx-j will give us the number of steps that left.
 
*Coplexity*
 
Edit Distance [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/EditDistance.cpp)
-----

![edit distance](https://user-images.githubusercontent.com/32219705/34917879-8fba25a4-f954-11e7-8cc7-3ca2f1ce6271.jpg)

In order to find the number of changes in str1 it is better to use similar algorithm with Longest common sub sequence, but with some differentions. We will use matrix LS[][]. Lets first initialize LP[i][0]=i and LP[0][i] where 0<i<n. if str1[i-1]==str[j-1] then LP[i][j]=LP[i-1][j-1], because LP[i-1][j-1] saves changes on the part of the string str1 with length i and the part of the string str2 with length j. Otherwise, we will look at minimum of LP[i-1][j-1], LP[i][j-1] and LP[i][j-1] that will give us minimum changes on the different lengths of our strings.
 
*Coplexity*
 
The algorithm will take quadratics memory and run time ( O(n*m)). 

#29/11/2017
-------
Longest Bitonic Subsequence (LBS) [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Longest%20Bitonic%20Subsequence.cpp)
-----
In order to find Longest Bitonic Subsequence we will first calculate Longest Increasing Subsequence and Longest Decreasing Subsequence of our array. The algorithm will look the same as Longest Increasing Subsequence (LIS), except we will not put the number of previous increasing subarray instead of putting the value of i-th element. Same for Longest Decreasing Subsequence (LDS) excep now we will start from end point. After it we will calculate LBS for each element: LBS[i] = LIS[i]-LDS[n-1-i]-1.

The greater value of array LBS will be our answer.
 
*Coplexity*
 
It will take O(3*n) time to build arrays LIS, LDS and LBS. also O(n) for finding greatest value of LBS.

Subset Sum Problem [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Subset%20Sum%20Problem.cpp)
----
We will find the total sum of the array. After dividing our sum by 2, we will construct a matrix with n + 1 rows and sum/2+1 columns. Here the matrix contains booleans. M[i][j] is true if and only if there exists a subset of the first i items with sum j. The entries of the first row M[i][0] are set to true while entries of the first column M[0][i] with false where 0<i<=n. 

![sum](https://user-images.githubusercontent.com/32219705/34917949-395889d4-f955-11e7-829d-57aac48baf9a.jpg)

M[n][sum/2+1] will be our result.
 
*Coplexity*
 
Let say v=sum/2+1. To calculate total sum will take O(n) time. For construct a matrix we will use O(n*v) memory and O(n*v) time.

#01/12/2017
-------

Vertex Cover
------

Longest Palindromic Subsequence [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Longest%20Palindromic%20Subsequence.cpp)
------
We will construct a matrix with n rows and n columns (where we will scan characters of our string in reverse order in rows, and in order in columns) 

![lps](https://user-images.githubusercontent.com/32219705/34918041-e5a8ddb0-f955-11e7-9826-308c2143d2f4.jpg)

Here LPS[0][n-1] is the result.
 
*Coplexity*
 
It will take O(n^2) as a memory of matrix and O(n^2) time to build this matrix.

#06/12/2017
-------

Masha and Forest [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Masha%20and%20Forest.cpp)
--------
The best way of finding the number of edges and the edges of the initial graph is to start from the leaf of trees. It is clear that, if the degree of a vertex is 1, then it is a leaf. Let's take an array leaf[] which will initially contain indexes of all leafs. Then for each leaf (v[i]), we will print its edge which is the value of that vertex and its XOR sum. After it, we can delete that vertex from our graph. It is enough just to change XOR sum of vertex 'u' that was adjacent to 'v' by calculating XOR sum of initial XOR sum of u  and value of v.
 
*Coplexity*
 
It will take O(n) time to create a vector where we will save degree and XOR sum of vertexes, as well as finding all leafs of initial graph. After it, it will take O(m) time for finding edges where m is the number of edges.

#13/12/2017
-------
Longest Prefix Suffix [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Longest%20Prefix%20Suffix.cpp)
------
We will use Knuth-Morris-Pratt (KMP) algorithm to solve this problem. we should be able after one pass through the text, to identify all positions where an existing match with the pattern ends.
let's take k which will represent the length of prefix subset which is also suffix of our array. Initially, it will be 0.
for q=2 to m (where m is the length of our pattern), if A[k+1]==P[q] then we will increase k++ and save this value of k in our newly created array pi in q-th position (this array will give us information about length of array till i-th position). But if A[k+1]!=P[q], then we redefine k=pi[k], so we will not need to start from the beginning because we already know which part of our pattern matched.
 
*Coplexity*
 
it will take O(m) time.

Shift The String [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Shift%20The%20String.cpp)
------
We will use Knuth-Morris-Pratt (KMP) algorithm to solve this problem. Let’s suppose that we are able, after one pass through the text, to identify all positions where an existing match with the pattern ends. Obviously, this will solve our problem. Since we know the length of the pattern, we can easily identify the starting position of every match.

let's take k which will represent the length of prefix subset which is also suffix of our pattern. Initially, it will be 0.
for q=2 to m (where m is the length of our pattern), if A[k+1]==P[q] then we will increase k++ and save this value of k in our newly created array pi in q-th position (this array will give us information about length of array till i-th position). But if A[k+1]!=P[q], then we redefine k=pi[k], so we will not need to start from the beginning because we already know which part of our pattern matched.

it will take O(m) time.

The same algorithm will go for finding str2 in str1. First str1=str1+str2. Then for i=1 to n (where n is the length of our new str1), if str2[q+1]==str1[i] then we will increase q++ and save this value of k in our newly created array pi in q-th position (this array will give us information about length of array till i-th position). But if str2[q+1]!=str1[i], then we redefine q=pi[q], so we will not need to start from the beginning because we already know which part of our str2 matches with str1.
 
*Coplexity*
 
So this algorithm will take O(n) time.

#15/12/2017
-------
New Distinct Substring
------
