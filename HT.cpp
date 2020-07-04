#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string.h>
//#define NULLKEY null
#define M 101
    
using namespace std;

typedef struct tagNODE
{
        string key;
}NODE, *NODEPTR;
NODE  hashtable[M];    
//Ham bam thu nhat
int hashfunc1(int key)
{
        return (key % M);
}
 
//Ham bam thu hai
int hashfunc2(int key)
{
        return ((M-2) -key % (M-2));
}

void Initialize()
{
        for (int i = 0 ; i<M ; i++ )
                hashtable [i].key = "";
}

void Search(string k,int x)
{
	int kt =0;
       for(int i=0; i<x;i++)
       {
       		if(hashtable [i].key == k)
       		{
       			cout<<"H["<<i<<"] = " << hashtable [i].key<<endl;
       			kt=1;
			}
       			
	   }
	if(kt==0)
		cout<<"Khong Tim Thay \n";
}

void Insert(string k,int x)
{
        /*if (Search (k) < m)
        {
                printf ("Da co khoa nay trong bang bam") ;
                return m ;
        }*/
        int i = hashfunc1 (x) ;
        int j = hashfunc2 (x) ;
        while (hashtable[i].key != "")
                i = (i + j) % M;// Bam lai (theo phuong phap bam kep)
        hashtable [i].key = k ;
}

void Print(int x)
{
	 for(int i=0; i<x;i++)
        cout<<"H["<<i<<"] = " << hashtable [i].key<<endl;
}

void Remove(int x,int n)
{
	hashtable [x].key ="";
	for(int i=0; i<n;i++)
        hashtable [i].key = hashtable [i+1].key;
}
//
int random(int minN, int maxN)
{
    return minN + rand() % (maxN + 1 - minN);
}
//
void RandomStringGenerator(char* code, int codeLength)
{
	char *box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
	int boxLength = strlen(box);
	
	for (int i = 0; i < codeLength; i++)
	{
		code[i] = box[rand() % boxLength];
	}
	code[codeLength] = '\0';
}
int main()
{
	srand(time(0));
	int s;
	int n=0;
	do
	{
		cout<<"---------------------- MENU -----------------------\n";
		cout<<"0. Thoat Chuong Trinh \n";
		cout<<"1. Tao Du Lieu Tu Dong \n";
		cout<<"2. Nhap Du Lieu Tu Ban Phim \n";
		cout<<"3. In Bang Bam \n";
		cout<<"4. Xoa Gia Tri Trong Bang Bam\n";
		cout<<"5. Tim Gia Mot Gia Tri Trong Bang Bam \n";
		cout<<"----------------------- END ----------------------\n Xin Moi Lua Chon :...!!! \n \n";
		cin>>s;
		switch(s)
	{
		case 1: {
					n=random(1,101);
					Initialize();
					for(int i=0;i<n;i++)
					{
						int length = 5;
						char code[5 + 1];
						RandomStringGenerator(&code[0], length);
						Insert(code,i);
					}
					cout<<"Da Tao Xong Du Lieu. \n";
					break;
				}
		case 2:{
					cout<<"Nhap So Luong Nut Cho Bang Bam (n<100)";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						string a;
						fflush(stdin);
						cout<<"H["<<i<<"] =";
						getline(std::cin,a);
						Insert(a,i);
					}
					break;
		}
		case 3:{
					cout<<"In Bang Bam : \n";
					if(n!=0)
					{
						Print(n);
					}
					else
					{
						cout<<"Bang Bam Rong. \n";
					}
					break;
		}
		case 4:{
					if(n!=0)
					{
						int k;
						cout<<"Nhap Vi Tri Can Xoa : ";
						cin>>k;
						if(k>n)
						{
							cout<<"vi tri khong ton tai";
						}
						else
						{
							Remove(k,n);
							n--;
							cout<<"Da Xoa \n";
						}
						
					}
					else
					{
						cout<<"Bang Bam Rong. \n";
					}
					break;
			}
		case 5:{
					if(n!=0)
					{
						string k;
						cout<<"Nhap gia tri Can Tim : ";
						fflush(stdin);
						getline(std::cin,k);
						cout<<"Gia Tri Can Tim La : ";
						Search(k,n);
					}
					else
					{
						cout<<"Bang Bam Rong. \n";
					}
					break;
			}
	}
	}while(s!=0);
	return 0;
}
