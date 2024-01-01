/* Question 1 - 2513. Minimize the Maximum of Two Arrays
*/

#include<iostream>
#include<vector>
using namespace std;

long long int gcd(long long int a, long long int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int minimizeSet(long long divisor1, long long divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        long long lcm = (divisor1 * divisor2) /gcd(divisor1, divisor2);
        long long total = uniqueCnt1 + uniqueCnt2;
        long long l = total, r = 1e12;
        long long ans = 0;
        while (l <= r)
        {
            long long mid = (l + r) / 2;
            long long both = mid / lcm;
            long long onlyA = mid / divisor2 - both;
            long long onlyB = mid / divisor1 - both;
            total = max(0ll, uniqueCnt1 - onlyA) + max(0ll, uniqueCnt2 - onlyB);
            if (mid - onlyA - onlyB >= total + both)
            {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
}

int main(){
   long long divisor1 = 2, divisor2 = 7;
   int uniqueCnt1 = 1, uniqueCnt2 = 3;
   cout<<"Minimum possible maximum integer that can be present in either array is "<<minimizeSet(divisor1,divisor2,uniqueCnt1,uniqueCnt2);

}

/*
Practice Problem link - 
https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/
*/

