#include<bits/stdc++.h>
using namespace std;
void display(priority_queue<int>queue)
{
    cout<<queue.top()<<endl;
    while(!queue.empty())
    {
        cout<<queue.top()<<" ";
        queue.pop();
    }
}
int main()
{
    priority_queue<int>queue;
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int key;
        cin>>key;
        queue.push(key);
    }
    display(queue);
    return 0;
}