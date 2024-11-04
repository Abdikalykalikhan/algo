#include <bits/stdc++.h> 
using namespace std; 

struct Node{ 
    string data; 
    Node* next; 
    Node(string name){ 
        this->data=name; 
        this->next=NULL; 
 
    } 
 
}; 
class Linkedlist{ 
    public: 
    Node* head; 
    Linkedlist(){ 
        head=NULL; 
 
    } 
    void add(string name){ 
        if(!head){ 
            head=new Node(name); 
        } 
        else if(head->data!=name){ 
            Node* newNode=new Node(name); 
        newNode->next=head; 
        head=newNode; 
        } 
 
 
    } 
    void print(){ 
        Node* temp=head; 
        int cnt=0; 
        while(temp){ 
            cnt++; 
            temp=temp->next; 
        } 
            cout<<"All in all: "<<cnt<<"\n"; 
            cout<<"Students: \n"; 
            temp=head; 
            while(temp){ 
                cout<<temp->data<<endl; 
                temp=temp->next; 
            } 
             
         
 
    } 
}; 
int main(){ 
    int n; 
    cin>>n; 
    Linkedlist list; 
    string prev=" "; 
    for(int i=0;i<n;i++){ 
        string name; 
        cin>>name; 
        if(name!=prev){ 
            list.add(name); 
 
        } 
        prev=name; 
    } 
    list.print(); 
    return 0; 
}

/*#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin>>n;

    vector<string> v;
    set<string> s;

    string k;
    
    int x=0; 

    for(int i =0;i<n;i++){
        cin>>k;

        x = s.size();
        s.insert(k);
        if(x!=s.size()){
            v.push_back(k);
        }
    }

    sort(v.rbegin(), v.rend());
    int q = v.size();
    cout << "All in all: "<< q << endl;
    cout << "Students:" << endl;

    for(int i = 0;i<v.size();i++){
            cout<<v[i] << endl;
        }
    
    
}

*/