#include<iostream>
#include<vector>
using namespace std;
class Set{
public:
vector<int> data;
bool Belongs_to(int dataValue) {
    int left = 0;
    int right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (data[mid] == dataValue) {
            return true; // Data found, return true
        } else if (data[mid] < dataValue) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return false; // Data not found, return false
}
void insert(int dataValue) {
    if (!Belongs_to(dataValue)) {
        int left = 0;
        int right = data.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (data[mid] < dataValue)
                left = mid + 1;
            else
                right = mid - 1;
        }

        data.insert(data.begin() + left, dataValue);
        
    }
}
vector<int>::iterator it;
void Delete(int dataValue){
    int j=1;
    for(it=data.begin();it!=data.end();it++){
        if(*it==dataValue){
            data.erase(it,it+1);
            j=0;
            break;
        }
    }
}

void size(){
    cout<<data.size()<<endl;
}
void Union(Set &v2){//here the vectors v1 and v2 are sorted.So using mergesort approach.
    int i=0;
    int j=0;
    vector<int> c;
    //vector<int> a=v1.data;
    vector<int> b=v2.data;
   
   
   while(i<(data.size()) && j<b.size()){
    if(data[i]<b[j]){
        c.push_back(data[i]);
        i++;
    }
    else if(b[j]<(data[i])){//don't use one more if, if is used again it will analyse it again inpedently but I don't want that if , first if is executed skip below else-if and else.
        c.push_back(b[j]);
        j++;
    }
    else{
        c.push_back(data[i]);
        i++;
        j++;
    }
   }
    while(i<(data.size())){//remaining elements if any and as the vectors are sorted I can append directly.
        c.push_back(data[i]);
        i++;
    }
     while(j<b.size()){
        c.push_back(b[j]);
        j++;
    }
   

   data=c;
   cout<<(data.size())<<endl;
}
void intersection(Set v2){
    int i=0;
    int j=0;
    vector<int> b=v2.data;
    vector<int> c;
    while(i<(data.size())&&j<b.size()){
        if(data[i]==b[j]){
            c.push_back((data[i]));
            i++;
            j++;
        }
        else if(data[i]<b[j]){
            i++;
        }
        else{
             j++;
        }
    }
    data=c;
    cout<<data.size()<<endl;
}
void diffrence(Set v2){
    int i;
    vector <int> c;
    for(i=0;i<data.size();i++){
    if(v2.Belongs_to(data[i])==false){
        c.push_back(data[i]);
    }
    }
    data=c;

}
void symmetricdiff(Set v2){
    for(int i=0;i<v2.data.size();i++){
        if(!Belongs_to(v2.data[i])){
            insert(v2.data[i]);
        }
        else{
            Delete(v2.data[i]);
        }
    }
    
}
void print(){
    if(data.size()==0){
        cout<<endl;
    }
    for(int i=0;i<data.size();i++){
        if(i!=data.size()-1){
            cout<<data[i]<<",";
        }
        else{
            cout<<data[i]<<endl;
        }
    }
}   

};
int main(){
    vector<Set> v;
    while(true){
    int command,setnum,dataval;
    cin>>command;
    if(command==1){
        cin>>setnum>>dataval;
        if(setnum<v.size()){
            v[setnum].insert(dataval);
            cout<<v[setnum].data.size()<<endl;
        }
        else{
            // cout<<setnum<<endl;
            v.push_back(Set());
            // cout<<v.size()<<endl;
            v[setnum].data.push_back(dataval);
            cout<<v[setnum].data.size()<<endl;
            // cout<<v.size()<<endl;
            
        }
    }
    else if(command==9){
        cin>>setnum;
        if(setnum<v.size()){
            v[setnum].print();
        }
        else{
            cout<<endl;
        }
    }
    else if(command==2){
        cin>>setnum>>dataval;
        if(setnum<v.size()){
            v[setnum].Delete(dataval);
            cout<<v[setnum].data.size()<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    else if(command==3){
        cin>>setnum>>dataval;
        if(setnum<v.size()){
            cout<<v[setnum].Belongs_to(dataval)<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    else if(command==4){
        int setnum1,setnum2;
        cin>>setnum1>>setnum2;
        if(setnum1==setnum2 && setnum1>=v.size()){
            Set setnum1;
            v.push_back(setnum1);
            cout<<0<<endl;
        }
        else if(setnum1<v.size() && setnum2<v.size()){
            v[setnum1].Union(v[setnum2]);
        }
        else if(setnum1>=v.size()&&setnum2<v.size()){
            // Set setnum1;


            v.push_back(v[setnum2]);
            // setnum1.Union(v[setnum2]);
            v[setnum2].size();
        }
        else if(setnum1<v.size()&&setnum2>=v.size()){
            Set setnum2;
            v.push_back(setnum2);
            v[setnum1].size();
        }
        else if(setnum1>=v.size()&&setnum2>=v.size()){
            int a=setnum1;
            int b=setnum2;
            Set setnum1,setnum2;
            if(a<b){
                v.push_back(setnum1);
                v.push_back(setnum2);
            }
            else if(a>b){
                v.push_back(setnum2);
                v.push_back(setnum1);
            }
            cout<<0<<endl;
        }
    }
    else if (command==5){
        int setnum1,setnum2;
        cin>>setnum1>>setnum2;
        if(setnum1==setnum2&&setnum1>=v.size()){
            Set setnum1;
            v.push_back(setnum1);
            cout<<0<<endl;
        }
        else if(setnum1<v.size() && setnum2<v.size()){
            v[setnum1].intersection(v[setnum2]);
        }
        else if(setnum1>=v.size()&&setnum2<v.size()){
            Set a=Set();
            // cout<<"p"<<v.size()<<endl;
            v.push_back(a);
            // cout<<"p"<<v.size()<<endl;
            cout<<0<<endl;
        }
        else if(setnum1<v.size()&&setnum2>=v.size()){
            Set setnum2;
            v.push_back(setnum2);
            cout<<0<<endl;
        }
        else if(setnum1>=v.size()&&setnum2>=v.size()){
            int a=setnum1;
            int b=setnum2;
            Set setnum1,setnum2;
            if(a<b){
                v.push_back(setnum1);
                v.push_back(setnum2);
            }
            else if(a>b){
                v.push_back(setnum2);
                v.push_back(setnum1);
            }
            cout<<0<<endl;
        }
    }
    else if(command==6){
            cin>>setnum;
            if(setnum<v.size()){
                v[setnum].size();
            }
            else{
                Set setnum;
                v.push_back(setnum);
                cout<<0<<endl;
            }
        }
    else if(command==7){
        int setnum1,setnum2;
        cin>>setnum1>>setnum2;
        if(setnum1==setnum2&&setnum1>=v.size()){
            Set setnum1;
            v.push_back(setnum1);
            cout<<0<<endl;
        }
        else if(setnum1<v.size() && setnum2<v.size()){
            v[setnum1].diffrence(v[setnum2]);
            v[setnum1].size();

        }
         else if(setnum1>=v.size()&&setnum2<v.size()){
            Set setnum1;
            v.push_back(setnum1);
            cout<<0<<endl;
        }
        else if(setnum1<v.size()&&setnum2>=v.size()){
            Set setnum2;
            v.push_back(setnum2);
            v[setnum1].size();
        }
        else if(setnum1>=v.size()&&setnum2>=v.size()){
            int a=setnum1;
            int b=setnum2;
            Set setnum1,setnum2;
            v.push_back(setnum1);
            v.push_back(setnum2);
            cout<<0<<endl;
        }
    }
    else if(command==8){
        int setnum1,setnum2;
        cin>>setnum1>>setnum2;
         if(setnum1==setnum2&&setnum1>=v.size()){
            Set setnum1;
            v.push_back(setnum1);
            cout<<0<<endl;
        }
        else if(setnum1<v.size() && setnum2<v.size()){
            v[setnum1].symmetricdiff(v[setnum2]);
            v[setnum1].size();
        }
         else if(setnum1>=v.size()&&setnum2<v.size()){
            Set setnum1=v[setnum2];
            v.push_back(setnum1);
            v[setnum2].size();
        }
        else if(setnum1<v.size()&&setnum2>=v.size()){
            Set setnum2;
            v.push_back(setnum2);
            v[setnum1].size();
        }
        else if(setnum1>=v.size()&&setnum2>=v.size()){
            int a=setnum1;
            int b=setnum2;
            Set setnum1,setnum2;
            if(a<b){
                v.push_back(setnum1);
                v.push_back(setnum2);
            }
            else if(a>b){
                v.push_back(setnum2);
                v.push_back(setnum1);
            }
            cout<<0<<endl;
        }
    }
    else{
        return 0;
    }
    if(!cin){
        return 0;
    }
    command=10;
    }
    return 0;
}