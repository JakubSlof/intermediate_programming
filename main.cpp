#include<thread>
#include<iostream>
#include<atomic>
#include<mutex>
std::mutex mutex;
void do_stuff(int index){
std::cout<<"cekam"<<index<<std::endl;
mutex.lock();
std::cout<<"je muj"<<index<<std::endl;
mutex.unlock();
std::cout<<"odemknut "<<index<<std::endl;





}

int a = 0;
void sayhallo(){
    for(int i = 0;i<10;i++){
    a++;
    }
}
void sayhall(){
    for(int i = 0;i < 99999999999999;i++){
    a=a-1;
    }
}
int main(){
std::thread t(do_stuff,0);
std::thread l(do_stuff,1);
l.join();
t.join();
std::cout<<a;
return 0;


}