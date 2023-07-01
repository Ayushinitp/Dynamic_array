#include <iostream>
#include <stdio.h>
using namespace std;
class dynamic_array{
    private :
    int capacity, li;
    int *ptr;
    protected:
    void half_array();
    void double_array();
    public :
    dynamic_array();
    void create_array(int);
    void insert_value(int,int);
    void append(int);
    int getitem(int);
    bool is_empty();
    bool is_full();
    void del(int);
    void edit(int,int);
    int count();
    int getcapcity();
    
};
dynamic_array::dynamic_array(){
    ptr=NULL;
}
int dynamic_array::count(){
    return li+1;
}
int dynamic_array::getcapcity(){
    return capacity;
}
void dynamic_array::create_array(int size){
    capacity=size;
    li=-1;
    ptr=new int[capacity];
}
bool dynamic_array::is_empty(){
    return li==-1;
}
bool dynamic_array::is_full(){
    return li==capacity-1;
}
void dynamic_array::append(int data){
    if(is_full())
    double_array();
    li++;
    ptr[li]=data;
}
 void dynamic_array::insert_value(int data,int index){
    try{
        if(index<0 || index>li+1)
        throw 1;
        if(is_full()){
            double_array();
        }
        else
        {
            int i;
            for(i=li;i>=index;i--){
                ptr[i+1]=ptr[i];
            }
            ptr[index]=data;
            li++;
        }
    }
    catch(int e ){
        if(e==1)
        cout<<"insertion not possible";
    }
 }

 void dynamic_array::del(int index){
    try{
        if(index<0 || index>li+1)
        throw 1;
        int i;
        for(i=index;i<li;i++){
            ptr[i]=ptr[i+1];
        }
        li--;
        if(capacity>1 && li+1<=capacity/2)
        half_array();
    }
    catch(int e ){
        if(e==1)
        cout<<"deletion not possible";
    }
 }
 void dynamic_array::double_array(){
    int *temp=new int[capacity*2];
    int i;
    for(i=0;i<=li;i++)
    {
        temp[i]=ptr[i];
    }
    delete []ptr;
    ptr=temp;
    capacity=capacity*2;
 }
 void dynamic_array::half_array(){
int *temp=new int[capacity/2];
    int i;
    for(i=0;i<=li;i++)
    {
        temp[i]=ptr[i];
    }
    delete []ptr;
    ptr=temp;
    capacity=capacity/2;
 }

  void dynamic_array::edit(int data,int index){
    try{
        if(index<0 || index>li+1)
        throw 1;
        ptr[index]=data;
    }
    catch(int e){
        if(e==1)
        cout<<"invalid index";
    }
  }

  int main(){
    dynamic_array obj1;
    obj1.create_array(5);
    obj1.append(10);
    obj1.append(20);
    obj1.append(30);
    obj1.append(40);
    obj1.append(50);
    obj1.append(60);
    cout<<"Total elments ====";
    cout<<obj1.count();
    return 0;
  }