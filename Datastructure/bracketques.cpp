#include <iostream>
#include <stack>
#include <string>
using namespace std;
// bool check(string str)
// {
//     stack <char> s;
//     for (int i=0;i<str.size();i++)
//     {
//         if(str[i]=='(')
//         {
//             s.push(str[i]);
//         }
//         else{
//             if(str.empty()) return 0;
//             else{
//                 s.pop();
//             }
//         }
//     }
//     return s.empty();
// }
bool check(string str)
{
    stack<char>s;
    int left=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]=='(') left++;
        else{
            if (left ==0) return 0;
            else left--;
        }
    }
    return left==0;
}
int main()
{
    string str;
    cin >> str;
    if(check(str))
    {
        cout<<"valid"<<endl;
    }
    else cout<<"invalid"<<endl;
    return 0;
}