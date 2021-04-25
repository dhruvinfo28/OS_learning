//In this algorithm we service the requests in one direction only, circular scan
#include<bits/stdc++.h>
using namespace std;
int main(){
    int number_of_tracks, curr_pos, n;
    cin>>number_of_tracks>>curr_pos>>n;
    vector<int> ready(n);
    for(auto &s: ready){
        cin>>s;
    }
    //Assumed the head services while going right and is currently also moving right
    int moves = number_of_tracks - curr_pos;
    //Find smallest in the reference string, if was behind curr_pos we need to move it to zero
    sort(ready.begin(), ready.end());
    int min_=ready[0];
    if(min_<curr_pos){
        moves+= number_of_tracks;
        int i=0;
        //Finding lower bound of curr_pos i.e. track on the left side and closest to curr_pos
        while(ready[i]<curr_pos){
            i++;
        }
        moves+=ready[i-1];
    }
    cout<<moves<<endl;
    return 0;
}