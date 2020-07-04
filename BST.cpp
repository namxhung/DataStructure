// STT: 02
// HỌ VÀ TÊN: NGUYỄN NAM HÙNG
// 

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

struct NODE
{
    int data;
    NODE *pLeft;
    NODE *pRight;
};

typedef NODE* TREE;

void CreateEmptyTree(TREE &root) {
    root = NULL;
}

NODE *CreateNode(int value)
{
    NODE *p = new NODE;
    p->data = value;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}







// 1
// Hàm tìm vị trí chèn phù hợp BST
/*
NODE* FindInsert(NODE* root, int value) 
{
    if (root == NULL)
    {
        return NULL;
    }
    NODE* p = root;
    NODE* f = p;
    while (p != NULL)
    {
        f = p;
        if (p->data > x)
        {
            p = p->pLeft;
        }
        else
        {
            p = p->pRight;
        }
    }        
    return f;
}
*/

void AddNode(TREE &root, NODE *node)
{
    
    if (root)
    {
        if (root->data == node->data) 
            return;
        if (node->data < root->data) 
            AddNode(root->pLeft, node);
        else
            AddNode(root->pRight, node); 
    }
    else
    {
        root = node; 
    }
}

// Hàm nhập giá trị thủ công
void CreateTreeM(TREE &root){
    int x;
    cout<<"***** Nhap gia tri thu cong tu ban phim. Nhap -1 de dung... \n";
    
    do {
        cin >> x;
        if(x==-1) break;
        AddNode(root, CreateNode(x));
    }while(true);
}

//=================================== 2 ===================================

void CreateTreeAuto(TREE &root)
{
    int value;
    srand(time(NULL));
  //  int n = 5 + rand() % (10 + 1 - 5);
   int n = 10 + rand() % (20 + 1 - 10);
    for (int i = 0; i < n; i++)
    {   
   //     value=5 + rand() % (20 + 1 - 5);
        value = -358 + rand()% (1359+358);
        AddNode(root, CreateNode(value));
    }
}


//====================  3 =========================================

//Tièn tự PreOrder
 void NLR(TREE root)
{
    
    if (root)
    {   
        

        // Xử lý nút gốc (root)
       cout<< setw(15) << left << root->data;
        cout<< setw(30) << left <<root;
        cout<<"pLeft: "<< setw(30) << left<<root->pLeft;
        cout<<"pRight: "<<root->pRight;
        cout<<"\n";
        NLR(root->pLeft);
    //    cout<<"\n";
        NLR(root->pRight);


    }
}
/// Trung tự InOrder 
void LNR(TREE root)
{
    if (root)
    {
        LNR(root->pLeft);

        cout<< setw(15) << left << root->data;
        cout<< setw(30) << left <<root;
        cout<<"pLeft: "<< setw(30) << left<<root->pLeft;
        cout<<"pRight: "<<root->pRight;
        cout<<"\n";
        // Xử lý nút gốc (root)
        LNR(root->pRight);
    }
}


// Hậu tự PostOrder
void LRN(TREE root)
{
    if (root)
    {
        
        LRN(root->pLeft);
        LRN(root->pRight);
        cout<< setw(15) << left << root->data;
        cout<< setw(30) << left <<root;
        cout<<"pLeft: "<< setw(30) << left<<root->pLeft;
        cout<<"pRight: "<<root->pRight;
        cout<<"\n";
        // Xử lý nút gốc (root)
    }
}

//============= 4 ====================================================
bool searchNode(TREE root, int value) 
{
    while (root != NULL) {
        if (value == root->data)
            return true;
        if (value < root->data)
            root = root->pLeft;
        else
            root = root->pRight;
    }
    return false;
}

//=================== 5 ==================================
void delNote(TREE &root,int value)
{
    if(root==NULL){
        return;
    }
    if(root->data<value)
    {
        delNote(root->pRight,value);
    }
    else if(root->data>value)
    {
        delNote(root->pLeft,value);
    }
    else{
            NODE *X  =root;
        if(root->pLeft==NULL)
        {

            root=root->pRight;
        }else if(root->pRight==NULL)
        {
            root=root->pLeft;
        }

        delete X;
    }
}
//=============== 6 ===========================================
void Free (TREE &root)
{
    if (root==NULL)
        cout<<"=>Xoa xong\n";

    Free(root->pLeft );
    Free(root->pRight );
    Free(root);
    
}
//============== 7 ==========================================
int CountNode(TREE root)
 {
   if( root == NULL)
      return 0;
   else
      return 1 + CountNode(root->pLeft) + CountNode(root->pRight);
}


//================ 8 =======================================
int CountLeaf(TREE root)
{   if(root==NULL) return 0;
    else
       if(root->pLeft==NULL && root->pRight==NULL) return 1;
       else return CountLeaf(root->pLeft)+CountLeaf(root->pRight);
}

//========================== 12 ============================
void Xuat(TREE root, int x, int y)
{
    if (root!=NULL)
    {
        if (root->pLeft != NULL)
            Xuat(root->pLeft,x,y);
        if (x<root->data && root->data<y)
            cout<<root;
        if (root->pRight != NULL)
            Xuat(root->pRight,x,y);
    }
}

//================ 14 =======================================
int CountEven(TREE root)
{
    if (root!=NULL)
    {
        int a = CountEven(root->pLeft);
        int b = CountEven(root->pRight);
        if (root->data%2==0)
            return 1 + a + b;
        return a + b;
    }
    return 0;
}

int CountOdd(TREE root)
{
    return CountNode(root)-CountEven(root);
   
}



//================ 15 =======================================
int SumNode(TREE root)
{  
   int S=0;
   if (root==NULL) return 0;
   else S=root->data+SumNode(root->pLeft)+SumNode(root->pRight);
   return S;

}
//================ 16 =======================================


int SumEven(TREE root)
{
    if (root!=NULL)
    {
        int a=SumEven(root->pLeft);
        int b=SumEven(root->pRight);
        if (root->data % 2 == 0)
        {
            
            if (root->pLeft == NULL && root->pRight == NULL)
                return root->data + a + b;
        }
        return a + b;
    }
    return 0;
}
//========================= 17 ========================
int SumOdd(TREE root)
{
    return SumNode(root)-SumEven(root);

}

//========== 19 ==================================
//Node lon nhat trong cay
int MaxNode(TREE root) {
	if(root->pRight == NULL)
		return root->data;
	else
		return MaxNode(root->pRight);
}

//Node nho nhat trong cay
int MinNode(TREE root) {
	if(root->pLeft == NULL)
		return root->data;
	else
		return MinNode(root->pLeft);
}


//========================================================
int main(){
    TREE myTREE;
    CreateEmptyTree(myTREE);
    int S=0;
    int x,y;
   // CreateTreeM(myTREE);
  //  CreateTreeAuto(myTREE);

    // NLR
   // cout<<"LNR: \n";
 //   LNR(myTREE);
 //   cout<<"LRN: \n";
 //   LRN(myTREE);

    int chon;
    cout<<"========= MENU LUA CHON ======\n";
    cout<<"---Nhap so 1-19 de hien cau tuong ung, go 0 de thoat---\n";
    
    
    
    
    do
    { cin>>chon;
      if (chon==0) break;
      switch (chon)
    {
    case 1:
        CreateTreeM(myTREE);
        break;
    case 2:
        cout<<"****** Dang khoi tao gia tri tu dong.Nhap 3 de xuat kq......\n";
        CreateTreeAuto(myTREE);
        break;
    case 3:
        cout<<"***** Duyet cay theo tung truong hop....\n\n";
        cout<<"--------------------------------------------------------------------------------------------------------------\n";
        cout<<"NLR: \n\n";
        NLR(myTREE);
        cout<<"\n\n";
        cout<<"LNR: \n\n";
        cout<<"\n\n";
        LNR(myTREE);
        cout<<"\n\n";
        cout<<"LRN: \n\n";
        LRN(myTREE);
        cout<<"----------------------------------------------------------------------------------------------------------------\n";
        break;
    case 4:
        cout<<"***** Tim X1 co gia tri ngau nhien tu [300-800] trong BST\n";
        int key;
        key=300 + rand()%(800+1-300);
        cout<<"Dang tim X="<<key<<" trong BST\n";
        if(searchNode(myTREE,key))
                cout<<"=>TRUE";
        else    cout<<"=>FALSE";

        break;  
    case 5:
        int s;
        cout<<"\n Nhap gia tri X2 can xoa trong BST \n";
        cin>>s;
        delNote(myTREE,s);
        cout<<"\n=> X2 da duoc xoa trong BST, nhap 3 de xem ket qua X\n";
        break;
    case 6:
        cout<<"\n=>Da xoa toan bo Node tren cay. Chuong trinh ket thuc\n";
        Free(myTREE);
    case 7:
        cout<<"\n=> So Node trong BST la: "<<CountNode(myTREE)<<"\n";
        break;
    case 8:
        cout<<"\n=> So Node la trong BST la: "<<CountLeaf(myTREE)<<"\n";
        break;
    case 15:
        cout<<"\nTong tat ca cac Node trong BST la: "<<SumNode(myTREE)<<"\n";
        break;
    case 14: 
        cout<<"\n So Node chan co trong BST la: "<<CountEven(myTREE);
        cout<<"\n So Node le co trong BST la: "<<CountOdd(myTREE);

        if(CountEven(myTREE)<CountOdd(myTREE))
            cout<<"\n\n BST co nhieu node chan hon \n";
        if(CountEven(myTREE)>CountOdd(myTREE))
            cout<<"\n\n BST co nhieu node le hon \n";
        else cout<<"\n\n BST co so node chan bang so node le \n";
        break;
    case 12:
        cout<<" Dem số node có giá trị lớn hơn X và nhỏ hơn Y\n";
        cout<<"Nhap X,Y"<<endl;
        cin>>x;
        cin>>y;
        Xuat(myTREE,x,y);
        break;
    case 16:
        cout<<"\nTong tat ca cac Node chan trong BST la: "<<SumEven(myTREE)<<"\n";
        break;
    case 17:
        cout<<"\nTong tat ca cac Node le trong BST la: "<<SumOdd(myTREE)<<"\n";
        break;

    case 19:
        cout<<"\nNode MAX trong BST la: "<<MaxNode(myTREE)<<"\n";
        cout<<"\nNode MIN trong BST la: "<<MinNode(myTREE)<<"\n";

        break;
    default:
        break;
    }  

    } while (true);
    


    return 0;    


}