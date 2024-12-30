#include<iostream>
using namespace std;

//dinh nghia node
struct Node{
	int info;
	Node*next;
};
//dinh nghia mot danh sach
struct List{
	Node *head,*tail;
};
//ham khoi tao danh sach rong
void init(List &L){
	L.head = L.tail = NULL;
}
//ham tao mot node moi
Node * getNode(int x){
	Node *p = new Node;
	p->info = x;
	p->next = NULL;
	return p;
}
//ham them node vao dau
void addHead(List &L){
    int x;
    cout<<"Nhap phan tu muon them vao,nhap -1 de dung!"<<endl;
    while(true){
        cin>>x;
        if(x==-1)
            break;
        else{
        	Node* p = getNode(x);
        	if(L.head==NULL)
        	    L.head = L.tail = p;
        	else{
        		p->next = L.head;
        		L.head = p;
    	       }
	       }
    }
}
//ham them node vao cuoi
void addTail(List &L){
    int x;
    cout<<"Nhap phan tu muon them vao,nhap -1 de dung!"<<endl;
    while(true){
        cin>>x;
        if(x==-1)
            break;
        else{
        	Node * p = getNode(x);
        	if(L.head == NULL)
        	L.head = L.tail = p;
        	else{
        		L.tail->next = p;
        		L.tail = p;
        	}
        }
    }
}
//ham in danh sach
void printList(List &L){
	Node *p = L.head;
	if(p==NULL){
		cout<<"Danh sach rong!";
		return;
	}else{
		while(p!=NULL){
			cout<<p->info<<" ";
			p=p->next;
		}
	}
}
//hamm xoa node dau
void deleteHead(List &L){
	Node *p = L.head;
	if(p==NULL){
		cout<<"List is empty.Not delete!"<<endl;
		return;
	}else{
		L.head = p->next;
		delete p;
	}
}
//ham xóa node cuoi
void deleteTail(List &L){
	Node *p = L.head;
	if(p==NULL){
		cout<<"List is empty.Not delete!"<<endl;;
		return;
	}else{
		while(p->next->next!=NULL){
			p=p->next;
		}
		L.tail = p;
		p->next = NULL;
	}
}
//ham tim kiem
Node *Search(List &L, int x){
    Node *p = L.head;
    if(p==NULL){
        cout<<"Danh sach rong khong the tim kiem"<<endl;
        return NULL;
    }else{
        while(p!=NULL){
            if(p->info == x)
            return p;
            else
            p=p->next;
        }
        return NULL;
    }
}
//ham chuyen ptu cuoi len dau
void moveLastToFront(List &L){
    Node *p = L.head;
    if(p==NULL){
        cout<<"Danh sach rong"<<endl;
        return ;
    }else{
        while(p->next->next!=NULL){
            p=p->next;
        }
        Node * k =L.tail;
        L.tail = p;
        p->next = NULL;
        k->next = L.head;
        L.head = k;
    }
}
//ham chuyen phan tu dau ve cuoi
void moveFrontToLast(List &L){
    Node *p = L.head;
    L.head = p->next;
    L.tail->next = p;
    L.tail = p;
    p->next =NULL;
}
//
void addAfter(List &L, Node *p,int x){
	Node *k =getNode(x);
	if(p==NULL){
		cout<<"Khong có gia tri nay trong mang"<<endl;
		return;
	}
	if(p->next == NULL){
		p->next = k;
		L.tail = k;
	}
	else{
		k->next = p->next;
		p->next = k;
	}
}
int main(){
	List L;
	init(L);
	int n;
	Node *p =NULL;
	while(true){
	    cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
	    cout<<"\033[1;32m|             Menu                     |\033[0m"<<endl;
	    cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|1.Them phan tu vao dau danh sach:     |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|2.Them phan tu vao cuoi danh sach     |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|3.Xóa phan tu o dau danh sach         |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|4.Xóa phan tu o cuoi danh sach        |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|5.In ra danh sach hien tai            |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|6.Tìm kiem mot phan tu trong danh sach|\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|7.Chuyen so dau danh sach ve cuoi     |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|8.Chuyen so cuoi danh sach len dau    |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|9.Them mot so vao sau mot so          |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32m|10.Thoat!                              |\033[0m"<<endl;
		cout<<"\033[1;32m+--------------------------------------+\033[0m"<<endl;
		cout<<"\033[1;32mMoi nhap lua chon cua ban:"<<endl;
		cin>>n;
		switch(n){
			case 1:
				addHead(L);
				break;
			case 2:
				addTail(L);
				break;
			case 3:
				deleteHead(L);
				break;
			case 4:
				deleteTail(L);
				break;
			case 5:
				cout<<"Danh sach:";
				printList(L);
				cout<<endl;
				break;
			case 6:
				cout<<"Nhap phan tu muon tim kiem:";
				int k;
				cin>>k;
			    p = Search(L,k);
			    if(p)
			    cout<<"Tim thay phan tu "<<k<<" trong danh sach"<<endl;
			    else
			     cout<<"Khong tim thay phan tu "<<k<<" trong danh sach"<<endl;
			    break;
			 case 7:
			    moveFrontToLast(L);
			    break;
			 case 8:
			    moveLastToFront(L);
		        break;
		    case 9:
		    	int x,y;
		    	cout<<"Nhap gia tri muon them so vao sau:";
		    	cin>>x;
		    	cout<<"Nhap so muon them vao sau:";
		    	cin>>y;
		    	addAfter(L,Search(L,x),y);
		    	break;
		      case 10:
                cout << "Thoat chuong trinh." << endl;
                return 0;  // Thoát kh?i chuong trình
            default:
                cout << "Lua chon khong hop le!" << endl;
                break;
		    
		}
	}
}
