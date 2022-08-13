/* Why is the complexity of binary search O(logN) where N is the size of the list? Explain. */

/*
ANS: Time Complexity of binary search is O(logN) because after every iteration n will become n/2. Ex:
After 1st Iteration: n = MainN/2;
After 2nd Iteration: n = MainN/2/2 = MainN/2^2;
After 3rd Iteration: n = MainN/2/2/2 = MainN/2^3;
After Last Iteration(Worst Case): MainN/2^k == 1 || MainN/2^k < 1

So, the loop will stop when  MainN/2^k == 1 || MainN/2^k < 1
=> MainN/2^k = 1
=> MainN = 2^k
=> log2 MainN = log2 2^k
=> log2 MainN  = k log2 2
=> log2 MainN = k

So the complexity of binary search is O(logN)
 */
