#include <iostream>
#include <vector>
#include <math.h>
#include<queue>

using namespace std;
void firstNonRepeatingElement(string a){

    int freq[26]={0};
    queue<char>q;
    for(int i=0;i<a.size();i++){
        char ch = a[i];
        freq[ch - 'a']++;

        q.push(ch);
        while(!q.empty()){
            if(freq[q.front()-'a'] >1){
                q.pop();
            }
            else{
                cout<<q.front()<<" ";
                break;
            }
        }

        if(q.empty()){
            cout<<"# ";
        }
    }
}
int main(){
    string a = "ababcd";
    queue<char>q;
    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    q.push('e');
    q.push('f');

    firstNonRepeatingElement(a);
return 0;
}