#include <bits/stdc++.h>
using namespace std;
vector<string> data;
void add(string &x){
    if(x == "one")data.push_back("01");
    else if(x == "two")data.push_back("04");
    else if(x == "three")data.push_back("09");
    else if(x == "four")data.push_back("16");
    else if(x == "five")data.push_back("25");
    else if(x == "six")data.push_back("36");
    else if(x == "seven")data.push_back("49");
    else if(x == "eight")data.push_back("64");
    else if(x == "nine")data.push_back("81");
    else if(x == "ten")data.push_back("00");
    else if(x == "eleven")data.push_back("21");
    else if(x == "twelve")data.push_back("44");
    else if(x == "thirteen")data.push_back("69");
    else if(x == "fourteen")data.push_back("96");
    else if(x == "fifteen")data.push_back("25");
    else if(x == "sixteen")data.push_back("56");
    else if(x == "seventeen")data.push_back("89");
    else if(x == "eighteen")data.push_back("24");
    else if(x == "nineteen")data.push_back("61");
    else if(x == "twenty")data.push_back("00");
    else if(x == "a")data.push_back("01");
    else if(x == "both")data.push_back("04");
    else if(x == "another")data.push_back("09");
    else if(x == "first")data.push_back("01");
    else if(x == "second")data.push_back("04");
    else if(x == "third")data.push_back("09");
}
int main(){
    string a;
    while(cin >> a){
        a[0] = tolower(a[0]);
        add(a);
    }
    sort(data.begin(),data.end(),[](string a,string b){return a+b < b+a;});
    string ans = "";
    for(auto it = data.begin();it != data.end();it++)ans+=*it;
    bool ok = false;
    bool out = false;
    for(auto it = ans.begin();it != ans.end();it++){
        if(*it != '0')ok = true;
        if(*it == '0' && !ok)continue;
        cout << *it;
        out = true;
    }
    if(!out)cout << "0";
    cout << endl;
    return 0;
}
