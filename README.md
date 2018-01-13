#20/09/2017
----
Leaders in an array [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks)
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
#29/09/2017
-------
#05/10/2017
-------
#11/10/2017
-------
#13/10/2017
-------
#18/10/2017
-------
#20/10/2017
-------
#25/10/2017
-------
#27/10/2017
-------
#08/11/2017
-------
#10/11/2017
-------
#15/11/2017
-------
#17/11/2017
-------
#22/11/2017
-------
#24/11/2017
-------
#29/11/2017
-------
#01/12/2017
-------
#06/12/2017
-------
#13/12/2017
-------
#15/12/2017
-------

















Alice, Bob and Chocolate [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Alice%2C%20Bob%20and%20Chocolate.cpp)
----
First, wi will calculate prefix sum of the amount of bars on the table. As Alice starts to eat from left to right it will also show the amount of bars that Alica can it. 
-Let's say Alice stands in position i=0 and Bob stands in position j=n-1.
-It is clear that while they eat chocolates 'i' cannot be greater than 'j'.
-Also, the amount of bars are representing the time that should be spent to eat them. So if the amount of bars that Alice eat is greater than the amount of bars that Bob eat, Bob will take next chocolate. Or if the amount of bars that Alice eat is less than the amount of bars that Bob eat, then Alice will take next chocolate.

*Coplexity*

The time complexity of this algorithm is linear O(n) for creating a prefix-sum vector and O(n) time to find the amount of bars consumed by Alice and Bob. O(n)+O(n)=O(2n)


Alternative Thinking [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Alternative%20Thinking.txt)
----

if in our array a[i]!=a[i-1], then we do not need to change them, because it will not affect the result. Lets look at example: for '10101' we will find 4 where str[i]!=str[i-1]. But length is 5. So we initialize s=1. It does not matter how long will be our contiguous non-empty substring because it only will add to our alternating subsequence 2 more {1,0}. So s will be s+2. As the length can be increase n (length of our initial array), we will take min(n, s).

*Coplexity*

We will scan our array once that will take O(n) time.


Chat Room [code](https://github.com/Yaqublu/CompetitiveProgrammingHomeworks/blob/master/Chat%20Room.cpp)
----

It is better to start searching from right to left in the string for each character of the word "hello" in the reverse order. As soon as we find the character that we are looking for we break our loop and start to look for next character of the word "hello" from where we broke our loop. 

*Coplexity*

It will take O(n) time in the worse case and linear time O(1) to decide if it is "YES" or "NOT" 











![image1](https://user-images.githubusercontent.com/32219705/34911030-f95c43b0-f8c9-11e7-9833-6f036afb38a9.jpg)
