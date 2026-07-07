#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<thread>
#include <cmath>
#include <mutex>
#include <map>
#include <chrono>
using namespace std;
using namespace std::chrono;
int ans=0;
atomic<bool> access(false);  
std::mutex m;
void run(){
    for(int i=0;i<100000;i++){
        if(m.try_lock())
        {
            ans++;
            m.unlock();
        }
    }
}
int main() {
 
    std::thread t1(run);
    std::thread t2(run);
    std::thread t3(run);
    t1.join();
    t2.join();
    t3.join();
    cout<<ans<<endl;
}
/*
g++ -std=c++17 -pthread Threading.cpp -o a
*/


