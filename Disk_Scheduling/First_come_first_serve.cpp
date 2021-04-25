#include<bits/stdc++.h>
using namespace std;
int main(){
    int curr_pos, size;  
    cin>>curr_pos>>size;
    vector <int> ready_queue(size);
    for(int i=0; i<size; i++){
        cin>>ready_queue[i];
    }
    int ans{0};
    for(int i=0;i<ready_queue.size();i++){
        ans+=abs(curr_pos-ready_queue[i]);
        curr_pos = ready_queue[i];
    }
    cout<<ans<<endl;
    return 0;
}