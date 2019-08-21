#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;


bool helper(vector<int>v,map<int,int>&mp,int cur,int cur_cnt){
    if(cur_cnt==mp.size()){
        return ((cur - 1) & cur) == 0;
    }
    for (int i = 0; i < v.size();i++){
        if(cur==0&&v[i]==0)
            continue;
        if(mp[i]==-1){
            mp[i] = 1;
            cur = cur * 10 + v[i];
            if(helper(v, mp, cur, cur_cnt + 1)){
                return true;
            }
            cur = cur / 10;
            mp[i] = -1;
        }
    }
}
bool istwo(int n){
    vector<int> cfen;
    int cnt = 0;
    while(n){
        cfen.push_back(n % 10);
        n = n / 10;
        cnt++;
    }
    map<int, int> mp;
    for (int i = 0; i < cnt;i++) {
        mp[i] = -1;
    }
    bool res = helper(cfen, mp, 0, 0);
    return res;
}
int main(){
    int N;
    cin >> N;
    if((N&(N-1))==0)
        cout << true << endl;
    else {
        bool res = istwo(N);
        cout << res << endl;
    }
    system("pause");
    return 0;
}