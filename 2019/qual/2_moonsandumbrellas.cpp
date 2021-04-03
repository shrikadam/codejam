#include <iostream>

using namespace std;

char nextCJ(string s, int n){
    for(int i=n; i<s.length(); i++){
        if(s[i]!='?'){
            return s[i];
        }
    }
    return '?';
}

int cost(char a, char b, int x, int y){
    if(a=='C' && b=='J'){
        return x;
    }
    else if(a=='J' && b=='C'){
        return y;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t, x, y, p=0;
    string s;
    cin >> t;
    while(t--){
        cin >> x >> y >> s;
        int ans = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]=='C' && s[i+1]=='?'){
                s[i+1] = nextCJ(s, i+1);
                ans += cost(s[i], s[i+1], x, y);
            }
            else if(s[i]=='J' && s[i+1]=='?'){
                s[i+1] = nextCJ(s, i+1);
                ans += cost(s[i], s[i+1], x, y);
            }
            else if(s[i]=='?' && s[i+1]=='?'){
                if(nextCJ(s, i+1)=='?'){
                    if(i!=0){
                        s[i] = s[i-1];
                        s[i+1] = s[i-1];
                    }
                    else{
                        s[i] = (x<=y)?'C':'J';
                        s[i+1] = (x<=y)?'C':'J';
                    }
                }
                else{
                    s[i] = nextCJ(s, i+1);
                    s[i+1] = nextCJ(s, i+1);
                }
            }
            else{
                ans += cost(s[i], s[i+1], x, y);
            }
        }
        cout << "Case #" << ++p << ": " << ans << "\n";
    }

    return 0;

}