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

    int t, n, a[105], p=0;
    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            auto itr = min_element(a+i,a+n);
            int len = distance(a+i,itr);
            ans += len+1;
            reverse(a+i, a+i+len+1);
        }
        cout << "Case #" << ++p << ": " << --ans << "\n";
    }

    return 0;
}