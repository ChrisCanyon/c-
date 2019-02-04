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
  cout<<"Hello world"<<endl;
  thread threads[5];
  int numPhilosophers = 5;

// spawn philosophers
  for (int i = 0; i < numPhilosophers; i++){
    cout<<"Spawning thread "<<i<<endl;
    thread t(run_philosopher, i);
    cout<<"Spawned thread "<<i<<endl;
    threads[i] = t;
  }

  cout<<"Spawning waiter"<<endl;
//spawn waiter
  std::thread waiter(run_waiter);

// join threads
  for (int i = 0; i < numPhilosophers; i++){
    cout<<"Joining thread "<<i<<endl;
    threads[i].join();
  }

  waiter.join();

  printf("Finished joining. Main done.");
  return 0;
}
