#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t, a[100]={0}, m, p=0;
    string s;
    cin >> t >> m;
    while(t--){
        for(int i=0; i<100; i++){
            cin >> s;
            for(int j=0; j<10000; j++){
                a[i] += s[j]-48;
            }
        }
        for(int i=0; i<100; i++){
            cout << a[i] << "\n";
        }
        //cout << "Case #" << ++p << ": " << ans << "\n";
    }

    return 0;

}