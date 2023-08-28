
**Q1) TERNARY NUMERIC NOTATION**

Ternary numeric notation is quite popular in Berland. To telegraph the ternary number the Borze alphabet is used. Digit 0 is transmitted as «.», 1 as «-.» and 2 as «--». You are to decode the Borze code, i.e. to find out the ternary number given its representation in Borze alphabet.

Input Format:

The first line contains a number in Borze code. The length of the string is between 1 and 200 characters. It's guaranteed that the given string is a valid Borze code of some ternary number (this number can have leading zeroes).

Constraints:

time limit per test : 2 seconds

Output Format:

Output the decoded ternary number. It can have leading zeroes.




**Q2) SWAP GAME**

Alice and Bob are playing a game on an array a of n positive integers. Alice and Bob make alternating moves with Alice going first. In his/her turn, the player makes the following move:

If a0=0, the player loses the game, otherwise:

Player chooses some i with 1≤i≤n-1.Then player decreases the value of a0 by 1 and swaps a0 with ai

Note : here ai is the number in array a in ith position Determine the winner of the game if both players play optimally.

Input Format:
The input consists of multiple test cases. The first line contains a single integer t denoting number of test cases

The first line of each test case contains a single integer n,the length of the array a

The second line of each test case contains n integers , elements of array

Constraints:

1≤t≤2*10^4

2≤n≤10^5

1≤ai≤10^9

It is guaranteed that sum of n over all test cases does not exceed 2*10^5

Output Format:
For each test case, if Alice will win the game, output "Alice". Otherwise, output "Bob".




**Q3) Playlist**

You use the Dotify app to store and play your favorite songs. You have a total of N different songs in the app, numbered from 1 to N. The ith song is Mi minutes long, and is in the language Li.

You are going on a long drive, and your friend only knows the language L. So you want to create a playlist which satisfies these conditions:

There should be exactly K songs in the playlist and they should all be distinct.
Every song in the playlist should be from your list of N songs in the app.
Every song in the playlist should be in the language L.
The length of a playlist is the sum of the lengths of all the songs in it. Find the maximum length of the playlist that you can create while satisfying the conditions above. If such a playlist cannot be created, output -1.

Input Format:

The first line of input will contain a single integer T, denoting the number of test cases.
Each test case consists of multiple lines of input

The first line of each test case contains three space-separated integers N,K, and L : the total number of songs in the app, the number of songs needed in the playlist, and the language of the songs in the playlist, respectively.

The next N lines describe the songs. The i-th of these N lines contains two space-separated integers Mi and Li, denoting the length and language of the ith song in the app.

Constraints:

1<= T <= 200

1<= N <= 1000

1<= K <= n

1<= L <= 5

1<= Mi <= 100

1<= Li <= 5

Output Format:

For each test case, output on a new line the length of the longest playlist that you can create.




**Q4) MAXIMUM SUM PERMUTATION**

You are given an array A of size N. The array will be used to perform Q queries, where each query is comprised of a pair of integers, denoted by Li and Ri.

Before the queries are executed, you are allowed to rearrange the elements in array A as desired.

Next, an integer variable X is initialized to 0. For each of the i-th queries, calculate the sum of elements from position li, through position Ri inclusive (i.e. A[Li]+ A[Li+1]+...+A[Ri]), and add this sum to X.

The objective of this problem is to find an arrangement of array A that maximizes the final value of X after all Q queries have been processed.

If there are multiple possible arrangements of A which achieve this maximum value, you can output any.

Input Format:

The first line of input will contain a single integer T, denoting the number of test cases.

Each test case consists of multiple lines of input.

The first line of each test case contains two space-separated integers N and Q — the length of array and number of queries, respectively.

The next line contains N space-separated integers denoting the elements of the array.

The next Q lines describe the queries. The i-th of these Q lines contains two space-separated integers Li and Ri, describing the range for the i-th query.

Constraints:

1≤T≤10000

1≤N≤200000

1≤Q≤200000

1≤Ai≤100000

1≤Li≤Ri≤N

The sum of N over all test cases won't exceed 2*10^5

The sum of Q over all test cases won't exceed 2*10^5

Output Format:

For each test case, output on a new line the maximum possible value of X. And in the next line, output the rearranged array A, which achieves that maximum possible value.
