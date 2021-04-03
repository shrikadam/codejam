#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t, n, c, a[105], p=0;
    cin >> t;
    while(t--){
        cin >> n >> c;
        if(c<n-1 || c>n*(n+1)/2-1){
            cout << "Case #" << ++p << ": IMPOSSIBLE" << "\n";
            continue;
        }
        for(int i=0; i<n; i++){
            a[i] = i+1;
        }
        int cost=n-1, cmin=n-1, i=0;
        while(cost != c){
            if(i%2==0){
                reverse(a+i/2, a+min(n-i/2, i/2+c-cost+1));
                cost += min(n-1-i, c-cost);
            }
            else{
                reverse(a+max(i/2, n-i/2-2-c+cost), a+n-i/2-1);
                cost += min(n-1-i, c-cost);
            }
            i++;
        }
        cout << "Case #" << ++p << ": ";
        for(int i=0; i<n; i++){
        cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}