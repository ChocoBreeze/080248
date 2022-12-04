#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

std::mutex coutMutex;

class Worker{
public:
  Worker(std::string n):name(n){};
 
    void operator() (){
      for (int i= 1; i <= 3; ++i){
	    // begin work
	    std::this_thread::sleep_for(std::chrono::milliseconds(200));
	    // end work
	    coutMutex.lock();
	    std::cout << name << ": " << "Work " << i << " done !!!" << std::endl;
	    coutMutex.unlock();
      }
	}
private:
  std::string name;
};


int main(){

  std::cout << std::endl;
  
  std::cout << "Boss: Let's start working." << "\n\n";
 
  std::thread herb= std::thread(Worker("Herb"));
  std::thread andrei= std::thread(Worker("  Andrei"));
  std::thread scott= std::thread(Worker("    Scott"));
  std::thread bjarne= std::thread(Worker("      Bjarne"));
  std::thread andrew= std::thread(Worker("        Andrew"));
  std::thread david= std::thread(Worker("          David"));
  
  herb.join();
  andrei.join();
  scott.join();
  bjarne.join();
  andrew.join();
  david.join();
  
  std::cout << "\n" << "Boss: Let's go home." << std::endl;
  
  std::cout << std::endl;

}

/*
스레드들이 std::cout을 동일한 뮤텍스 객체 mutexCout으로 보호하기 때문에,
한 스레드가 출력하는 도중 다른 스레드가 끼어들어서 출력이 엉망이 되는 일은 생기지 않는다.
*/