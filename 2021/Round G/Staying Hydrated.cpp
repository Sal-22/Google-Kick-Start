/*
#Problem Statement:
With online classes in full swing, it is important for Grace to take breaks and keep herself hydrated at all times. She has decided to place a water bottle in her room in the most convenient place. This means that the position of this water bottle should be close to all the places in the room where she generally hangs out like the study desk, bed and coffee table among other places.

The room is represented in the form of a coordinate plane. The number of steps Grace needs to go from Point A to Point B is equal to the Manhattan distance between the 2 points. This means, Grace can only walk parallel to the axes of the coordinate plane and with each step, she can move one unit in either of the four directions.

Can you help her find a position in the room to keep the bottle, such that the sum of steps from the bottle to all her favourite furniture pieces will be minimum?

Notes:
All the furniture (like study desk, bed, or coffee table) can be represented as rectangles of non-zero area in the plane with edges parallel to the axes.
It is possible for furniture pieces to overlap, as she likes to work on her bed-table too.
Assume that Grace can simply pass through the furniture while walking and does not need to go around them.


#Input Format:
The first line of the input gives the number of test cases, T. T test cases follow.
The first line of each test case contains an integer K which represents the number of objects in Grace's room.
K lines follow, each of them describing one object. The i-th line contains four integers, Xi1, Yi1, Xi2, Yi2, where (Xi1, Yi1) represents coordinates of the bottom left corner and (Xi2, Yi2) represents coordinates of the top right corner of the i-th rectangular object.


#Output Format:
For each test case, output one line containing Case #i: x y, where i is the test case number (starting from 1) and x and y are coordinates of the water bottle such that the sum of steps from these coordinates to all the furniture pieces will be minimum.
Note, the bottle can lie on the floor or on top of any furniture but should be placed on integer coordinates only.
If multiple solutions exist, output the one with minimum x coordinate, if multiple solutions have the same x coordinate output the one with minimum y coordinate.

#Limits:

Memory limit: 1 GB.
1≤T≤100.
Xi1<Xi2, for all i.
Yi1<Yi2, for all i.

Test Set 1
Time limit: 40 seconds.
1≤K≤20.
−100≤Xi1,Xi2,Yi1,Yi2≤100, for all i.

Test Set 2
Time limit: 90 seconds.
1≤K≤10^5
−10^9≤Xi1,Xi2,Yi1,Yi2≤10^9, for all i.

*/

#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked

void scanint(int &x){
    register int c = gc();
    x = 0;
    bool sign = false;
    for(;(c<48 || c>57) && c!='-';c=gc());
    if(c=='-'){
        sign = true;
        c=gc();
    }
    for(;c>47 && c<58;c=gc()){x = (x<<1) + (x<<3) + c-48; }
    if(sign)
        x = -x;
}

int location(int *arr1, int *arr2, int k){
    sort(arr1,arr1+k);
    sort(arr2,arr2+k);
    int func = k, x=arr1[0];
    int i=0,j=0;
    for(;x<=arr2[k-1];){
        for(;arr1[i]<=x && i<k;i++)
            --func;
        for(;arr2[j]<=x && j<k;j++)
            --func;
        if(func<=0)
            break;
        x = (arr1[i]<arr2[j])?(arr1[i]):(arr2[j]);
    }
    return x;
}

int main(){
    int t;
    cin>>t;
    int ca=0;
    while(t--){
        int k;
        cin>>k;
      
        int *x1 = new int[k];
        int *x2 = new int[k];
        int *y1 = new int[k];
        int *y2 = new int[k];
        
        for(int i=0;i<k;i++){
            scanint(x1[i]);
            scanint(y1[i]);
            scanint(x2[i]);
            scanint(y2[i]);
        }
        int x = location(x1,x2,k);
        int y = location(y1,y2,k);
        
        printf("Case #%d: %d %d\n",++ca,x,y);
        
        delete[] x1;
        delete[] y1;
        delete[] x2;
        delete[] y2;
        
        
    }
}
