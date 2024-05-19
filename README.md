# Bag Secured

## Make our program communicated with the server

```bash
socat exec:"nc 83.136.253.219 32490" exec:./build/BagSecured
```

## Input that this program can parse

```
You will be given a number of s = 100 salesmen offering their products. You have a bag with a capacity C, where 1 <= C <= 10 ** 5
For every product bench you will have the below values:
	1. The number of products N, using 1-based indexing (1, 2, ..., N), where 1 <= N <= 100
	2. The capacity C
	3. Every product i will have 2 values, a weight w_i, and a value v_i, where 1 <= w_i <= C, and 1 <= v_i <= 10 ** 10 
Find the maximum value of products you can fit in your bag.

You will receive N and C, then after that the product values w_i and v_i.
Example Input:
	4 14
	6 3
	7 9
	5 4
	2 1

Example Output:
	14

Test 1/100
4 14
6 3
7 9
5 4
2 1

Test 2/100
4 14
6 3
...
```
