#include<iostream>
#include<vector>
using namespace std;


int main(){
    vector<int>v{0,1,3,4,3,2,5,4,3,7,3,2,4,6};
    int n = 8;
    for (int i = 0; i < v.size();i++){
        v[v[i] % n] += n;
    }
    for (int i = 0; i < n;i++){
        cout <<to_string(i)+":"<< v[i] / n<<endl;
    }

    return 0;
}