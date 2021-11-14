/*

To understand the approach used in this question, read the analysis part of Test Set 3 on official problem statement page: https://codingcompetitions.withgoogle.com/kickstart/round/00000000004362d6/00000000008b44ef#analysis




#Problem Statement:
Barbara goes to Alan's banana farm, where the N banana trees are organized in one long line represented by an array B. The tree at position i has Bi banana bunches. Each tree has the same cost. Once Barbara buys a tree, she gets all the banana bunches on that tree.

Alan has a special rule: because he does not want too many gaps in his line, he allows Barbara to buy at most 2 contiguous sections of his banana tree line.

Barbara wants to buy some number of trees such that the total number of banana bunches on these purchased trees equals the capacity K of her basket. She wants to do this while spending as little money as possible. How many trees should she buy?


#Input Format:
The first line of the input gives the number of test cases, T. T test cases follow.
Each test case begins with a line containing two integers integer N, the number of trees on Alan's farm, and K, the capacity of Barbara's basket.
The next line contains N non-negative integers B1,B2,…,BN representing array B, where the i-th integer represents the number of banana bunches on the i-th tree on Alan's farm.


#Output Format:
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the minimum number of trees Barbara must purchase to obtain K banana bunches using at most 2 contiguous sections of the farm, or -1 if it is impossible to do so.


#Limits:
Time limit: 20 seconds.
Memory limit: 1 GB.
1≤T≤100.
0≤Bi≤K, for each i from 1 to N.

Test Set 1
1≤K≤10^4.
1≤N≤50.

Test Set 2
1≤K≤10^4.
1≤N≤500.

Test Set 3
1≤K≤10^6.
For at most 25 cases:
1≤N≤5000.
For the remaining cases:
1≤N≤500.

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int ca=0;
    int n,k;
    while(t--){
        cin>>n>>k;
        int *B = new int[n+1];
        B[0] = 0;
        for(int i=1;i<=n;i++){
            cin>>B[i];
        }
        int *Best2nd = new int[k+1];
        for(int i=1;i<=k;i++){
            Best2nd[i] = n;
        }
        Best2nd[0] =0;
        int ans =n+1;
        for(int i=n;i>0;--i){
            int sum1=0;
            for(int j=i;j>0;--j){
                sum1+= B[j];
                if(sum1>k)
                    break;
                ans = min(ans,i-j+1+Best2nd[k-sum1]);
            }
            int sum2=0;
            for(int j=i;j<=n;++j){
                sum2+= B[j];
                if(sum2>k)
                    break;
                Best2nd[sum2] = min(Best2nd[sum2],j-i+1);
            }
            
        }
        if(ans == n+1)
            ans = -1;
        printf("Case #%d: %d\n",++ca,ans);
        delete[] B;
        delete[] Best2nd;
    }
    return 0;
}
