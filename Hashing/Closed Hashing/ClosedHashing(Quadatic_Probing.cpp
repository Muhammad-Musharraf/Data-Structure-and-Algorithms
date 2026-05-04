# include<iostream>
using namespace std;

const int Size=5;
int table[Size];

int hash(int key){
    return (key % Size);
}

void insert(int key){
    int count=0;
    
    int index= key % Size;
    int i=1;

    while(table[index]!=-1)// collision
    {
        index=(index+i*i) %Size; // linear probing
        count++;
        if(count >Size){
            cout<<"hash table is full"<<endl;
            return;
        }
        i++;
    }
    table[index]=key;
}
void search(int key){
    bool isFound=true;
    for(int i=0;i<Size;i++){
        if(table[i]==key){
            cout<<"Value Found"<<endl;
            isFound=false;
        }
    }
    if(isFound)
    {
        cout<<"value not found"<<endl;

    }

}
void display(){
    for(int i=0;i<Size;i++){
        
        cout<<table[i]<<endl;
    }
}


int main(){
    for(int i=0; i<Size; i++) { 
        table[i]=-1;

    }
    insert(9);// 4
    insert(12); // 2
    insert(11); // 1
    insert(44); // 0
    insert(55); //3
    //insert(99);
    display();
    search(7);

    return 0;
}