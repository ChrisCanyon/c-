#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

void run_philosopher(int threadNum){
  printf("I am thread %d", threadNum);
}

void run_waiter(){
  printf("I am waiter");
}

int main(){
  cout<<"Hello world";
  thread* threads[5];
  int numPhilosophers = 5;

// spawn philosophers
  for (int i = 0; i < numPhilosophers; i++){
    thread t(run_philosopher, i);
    threads[i](&t);
  }


//spawn waiter
  std::thread waiter(run_waiter);

// join threads
  for (int i = 0; i < threads.size(); i++){
    *(threads.[i]).join();
  }

  waiter.join();

  printf("Finished joining. Main done.");
  return 0;
}
