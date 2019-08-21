#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
string str1 ;

bool helper(int n,int m,int i,string str){
    if(m==0&&n==0){
        str1=str;
        return true;
    }
    if(m==0&&n>2)
        return false;
    // if(m==0&&str[i-1]=='A'&&n==2)
    //     return false;
    if(n==0&&m>2)
        return false;
    // if(n==0&&str[])
    for (int k = 0; k < 1;k++){
         if (n > 0 && ((str.size() < 2) || (str.size() >= 2 && (str[i - 1] != 'A' || str[i - 2] != 'A')))) {
            if (helper(n - 1, m, i + 1, str + 'A')) {
                return true;
            }
        }
        if(m>0&&((str.size() < 2) || (str.size() >= 2 && (str[i-1]!='B'||str[i-2]!='B')))){
            if(helper(n,m-1,i+1,str+'B'))
                return true;
        }
    }
       
    
}
string res(int n,int m){
    string str = "";
    helper(n,m,0,str);
    return str1;
}
int main(){
    int n, m;
    cin >> n>> m;
    string str2 = res(n, m);
    cout << str2 << endl;
    system("pause");
    return 0;
}