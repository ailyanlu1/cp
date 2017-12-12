/*

I will leave my heart at the door
I won't say a word
They've all been said before, you know
So why don't we just play pretend
Like we're not scared of what is coming next
Or scared of having nothing left

Look, don't get me wrong
I know there is no tomorrow

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again?

I don't need your honesty
It's already in your eyes
And I'm sure my eyes, they speak for me
No one knows me like you do
And since you're the only one that matters
Tell me who do I run to?

Let this be our lesson in love
Let this be the way we remember us
I don't wanna be cruel or vicious
And I ain't asking for forgiveness

All I ask is if this is my last night with you
Hold me like I'm more than just a friend
Give me a memory I can use
Take me by the hand while we do what lovers do
It matters how this ends
'Cause what if I never love again? 

*/

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 155;

long long dp[N][N];
int goal, sumgoal;

long long dfs(int gcd, int sum) {
  if (gcd % goal) return 0;
  if (sum == 0) return gcd == goal;
  if (dp[gcd][sum] != -1) return dp[gcd][sum];
  dp[gcd][sum] = 0;
  for (int i = 1; i <= sum; i++) {
    dp[gcd][sum] += dfs(__gcd(gcd, i), sum - i);
    dp[gcd][sum] %= mod;
  }
  return dp[gcd][sum];
}

int main() {
  for (int i = 1; i <= 100; i++) {
    goal = i;
    memset(dp, -1, sizeof(dp));
    for (int j = 1; j <= 100; j++) {
      long long ans = 0;
      sumgoal = j;
      ans += dfs(0, j);
      printf("%d %d: %d\n", i, j, (int) ans);
    }
  }

  return 0;
}
