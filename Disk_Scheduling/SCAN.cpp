//Scan until one end and then when we come back going till the last request
#include<bits/stdc++.h>
using namespace std;

int main(){
    //curr_pos current position of read write header, n is the size of ready queue
    int number_of_tracks, curr_pos, n; 
    cin>>number_of_tracks>>curr_pos>>n;
    vector<int> ready_queue(n);
    for(auto &s: ready_queue){
        cin>>s;
    }
    //This  algorithm is for when head moves right and then back
    int moves = number_of_tracks-curr_pos;
    sort(ready_queue.begin(), ready_queue.end());
    if(ready_queue[0]<curr_pos){
        moves+= (number_of_tracks-ready_queue[0]) ;
    }
    cout<<moves<<endl;

    return 0;
}