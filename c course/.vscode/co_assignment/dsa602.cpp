#include<iostream>
using namespace std;
class Node{
   public:
   string branch;
   string name;
   int reg_num;
   int CGPA;
   Node* next;
   Node(string b,string n,int num,int CG){
    this->branch = b;
    this->name = n;
    this->reg_num = num;
    this->CGPA = CG;
    this->next = NULL;
   }
};

void insertAtTail(Node* &head,Node* &tail,string branch,string name,int reg,int CGPA){
    if(head==NULL && tail == NULL){
        Node* temp = new Node(branch,name,reg,CGPA);
        head = temp ;
        tail = temp;
    }
    else {
        Node* temp = new Node(branch,name,reg,CGPA);
        tail->next = temp;
        tail = temp;
    }
}
Node* linearSearch(Node* head,int key){
    Node* curr = head;
    while(curr!=NULL){
        if(curr->reg_num == key){
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}
void bubbleSort(Node* head){
    Node* curr = head;
    while(curr!=NULL){
        Node* temp = curr->next;
        while(temp!=NULL){
            if(curr->reg_num > temp->reg_num){
                swap(curr->branch,temp->branch);
                swap(curr->reg_num,temp->reg_num);
                swap(curr->name,temp->name);
                swap(curr->CGPA,temp->CGPA);
            }
            temp = temp->next;
        }
        curr = curr->next;
    }
}
Node *findmid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next;
        fast = fast->next;
    }
    return slow;
}
Node* binarySearch(Node* head,int key){
   Node* start = head;
   Node* last = NULL;
   do{
      Node* mid = findmid(start);
      if(mid==NULL) return NULL;
      if(mid->reg_num == key) return mid;
      if(mid->reg_num < key) {
        start = mid->next;
      }
      else last = mid;
   }while(last==NULL || last!=start);
}
Node* insertionSortList(Node* head){
   Node* dummy = new Node("hello","hello",-1,-1);
   dummy->next = head;
   Node* prev = head;
   Node* curr = head->next;
   while(curr){
    if(curr->CGPA >=prev->CGPA){
        prev = curr;
        curr = curr->next;
        continue;
    }
    Node* temp = dummy;
    while(curr->CGPA > temp->next->CGPA){
        temp = temp->next;
    }
    prev->next = curr->next;
    curr->next = temp->next;
    temp->next = curr;
    curr = prev->next;
   }
  return dummy->next;
}
int main(){
  Node* head = NULL;
  Node* tail = head;
  cout << "Enter total Number of Students : " ;
  int n;
  cin >> n;
  for(int i = 0;i<n;i++){
    string branch;
    cout << "Enter Branch : " ;
    cin >> branch;
    string name;
    cout << "Enter Name : ";
    cin >> name;
    int reg_num ;
    cout << "Enter reg-num : ";
    cin >> reg_num;
    int CGPA;
    cout << "Enter CGPA : ";
    cin >> CGPA;
    insertAtTail(head,tail,branch,name,reg_num,CGPA);
  }
  // A part 
//   cout << endl; 
//   int key ;
//   cout << "Enter reg number for linearSearch : ";
//   cin >> key;
//   cout << endl;
//   Node* find = linearSearch(head,key);
//   if(find==NULL) cout << "Key not found" << endl;
//   else {
//     cout << "Key found" << endl;
//     cout << "Data of student ..."<< endl;
//     cout << "Name : " << find->name << endl;
//     cout << "Branch : "<<find->branch << endl;
//     cout << "Reg-Num : " << find->reg_num << endl;
//     cout << "CGPA : " << find->CGPA << endl; 
//   }

//   //B part  

//   bubbleSort(head);
//   cout << endl;
//   //C part 
//    cout << "Enter reg number for binarySearch : " ;
//    cin >> key;
//    find = binarySearch(head,key);
//    cout << endl;
//   if(find == NULL) cout << "Key not Found" << endl;
//   else {
//     cout << "Key Found " << endl;
//     cout << "Data of student ..."<< endl;
//     cout << "Name : " << find->name << endl;
//     cout << "Branch : "<<find->branch << endl;
//     cout << "Reg-Num : " << find->reg_num << endl;
//     cout << "CGPA : " << find->CGPA << endl; 
//   }
    Node* newHead = insertionSortList(head);
    Node* curr = newHead;
    while(curr){
        cout << curr->CGPA << " " << curr->reg_num << endl;
        curr = curr->next;
    }
    
}