#include<cstdio>
#include<stack>
using namespace std;

const int MAXN = 1000 + 10;

int n, target[MAXN];
/* target is the very sequence that is to be checked */
int  main(){
    while(scanf("%d", &n) == 1){
        stack<int> s;
        int A = 1, B = 1;/* A is the common sequence:1, 2, ..., n; while B is pointer of target */
        for(int i = 1; i <= n; i++) scanf("%d", &target[i]);
        int ok = 1;
        while(B <= n){
            if(A == target[B]){
                A++;
                B++;
            }
            /* situation 1: track not stay in C, directly go into B */
            else if(!s.empty() && s.top() == target[B]){
                s.pop();
                B++;
            }
            /* situation 2: some tracks are in C, pop one and that is the next B */
            else if(A <= n) s.push(A++);
            /* situation 3: C is empty, but it is not the track that directly go into B, must be some track pile in C. push one into C and start next turn */
            else{
                ok = 0;
                break;
            }
            /* if A > n and situations above didn't happen, the target is wrong. */
        }
        printf("%s\n", ok ? "Yes" : "No");
    }
    return 0;
}

