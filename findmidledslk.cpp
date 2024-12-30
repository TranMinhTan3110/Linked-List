/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

//###INSERT CODE HERE -
//dinh nghia mot node
struct node{
	int info;
	node*next;
};
// khai báo ds
struct List{
	node *pHead,*pTail;
};	
//ham tao node moi
node* getNode(int x){
	node*p=new node();
	p->info=x;
	p->next=NULL;
	return p;
	}
//ham them cuoi ds
void addTail(List &L, int x){
	node*p=getNode(x);
	if(L.pHead==NULL){
	L.pHead=L.pTail=p;
	}
	else{
	L.pTail->next=p;
	L.pTail=p;
	}
	}
//ham nhap và them phan tu vao cuoi
void inputList(List &L, int n){
	 int x;
    for (int i=0; i<n; i++) {
        cin >> x;
        addTail(L,x);
    }
}
	//ham xuat danh sach
void outputList(List &L) {
    node* p=L.pHead;
    if (p==NULL) {
        cout<<"List is empty ";
    } else{
        while (p != NULL){
            cout<<p->info<<" ";
            p=p->next;
        }
    }
}
//tim so chính giua
node* findMiddle(List &L){
	node* p=L.pHead;
 	if(p==NULL){
 	return NULL;
 	}
//dem so node trong ds
	int count =0;
	while(p!=NULL){
		p=p->next;
		count++;
		}
	if(count==0)
	return NULL;
	node* newnode=L.pHead;
	int k=0;
//nesu so node trong ds la le
	if(count%2==0){
		while(newnode!=NULL){
			if(k==(count/2)){
				return newnode;
			}
			k++;
			newnode=newnode->next;
		}
	}
//neu so neu trong ds la chan
	else if(count%2==1){
		while(newnode!=NULL){
			if(k==(count/2)){
				return newnode;
				}
				k++;
			newnode=newnode->next;
		}
	}
	return NULL;
}
int main()
{
    List L;
    L.pHead=L.pTail=NULL;
    int n; cin>>n;
    inputList(L,n);
    cout<<"Created List: "<<endl;
    outputList(L);
    cout<<endl;

    node *p=findMiddle(L); //Neu so phan tu chan thi co 2 phan tu chinh giua, chi xuat phan tu chinh giua thu 2
    if(p)cout<<"The middle element is "<<p->info;

    return 0;
}
