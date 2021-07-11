#include <stdio.h>
#include <assert.h>
#define MAXN 20000000


/* My solution
*/
#include <bits/stdc++.h>
using namespace std;
vector <int> fragole_cost;

#define DEBUG

int solve(int N, int K, int* S);
int solve2(int K, int my_init, int my_end);

int solve(int N, int K, int* S)
{
    {
        int partial = 0;
        for (int i = 0; i < N; ++i)
        {
            if(S[i] == 0)
            {
                fragole_cost.push_back(partial);
                partial = 0;
            }
            else
            {
                partial += S[i];
            }
        }
        fragole_cost.push_back(partial);
    }
#ifdef DEBUG
    for (int i = 0; i < fragole_cost.size(); ++i)
        cout << fragole_cost[i] << "\t";
    cout << endl;
#endif // DEBUG

    return solve2(K, 0, fragole_cost.size() - 1);
}

int solve2(int new_K, int my_init, int my_end)
{
#ifdef DEBUG
    cout << "Solve2: " << new_K << "\t" << my_init << "\t" << my_end << endl;
#endif // DEBUG

    if(my_init > my_end || new_K <= 0)
        return 0;

    if(fragole_cost[my_init] == 0)
        return 1 + solve2(new_K, my_init + 1, my_end);

    if(fragole_cost[my_end] == 0)
        return 1 + solve2(new_K, my_init, my_end - 1);

    if(fragole_cost[my_init] <= new_K && fragole_cost[my_end] <= new_K)
        return 1 + max(solve2(new_K - fragole_cost[my_init], my_init + 1, my_end), solve2(new_K - fragole_cost[my_end], my_init, my_end - 1));

    if(fragole_cost[my_init] <= new_K)
        return 1 + solve2(new_K - fragole_cost[my_init], my_init + 1, my_end);

    if(fragole_cost[my_end] <= new_K)
        return 1 + solve2(new_K - fragole_cost[my_end], my_init, my_end - 1);

    return 0;
}

/* Default
*/

static int N, K, i;
static int s[MAXN];

int solve(int N, int K, int* S);

static FILE *fin, *fout;

int main()
{
    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");
    assert(2 == fscanf(fin, "%d%d", &N, &K));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fin, "%d", &s[i]));
    fprintf(fout, "%d\n", solve(N, K, s));
    fclose(fin);
    fclose(fout);
    return 0;
}
