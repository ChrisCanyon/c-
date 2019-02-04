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
  thread t1(run_philosopher, i);
  thread t2(run_philosopher, i);
  thread t3(run_philosopher, i);
  thread t4(run_philosopher, i);
  thread t5(run_philosopher, i);

//spawn waiter
  std::thread waiter(run_waiter);

// join threads
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  t5.join();

  printf("Finished joining. Main done.");
  return 0;
}
