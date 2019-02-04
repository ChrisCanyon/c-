#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex LOCK;
boolean FORKS = [true, true, true, true, true];
int NUM_PHILOSOPHERS = 5;
void run_philosopher(int threadNum){
  int hunger = 100;
  while (hunger > 0) {
    LOCK.lock();
    printf("Philosopher %d picking up forks", threadNum);
    if (FORKS[threadNum - 1]){
      printf("Philosopher %d picked up fork %d", threadNum, threadNum - 1);
      FORKS[threadNum - 1] = false;
    } else {
      printf("Philosopher %d fork not available", threadNum);
      return;
    }
    if (FORKS[threadNum % NUM_PHILOSOPHERS]){
      printf("Philosopher %d picked up fork %d", threadNum, threadNum % NUM_PHILOSOPHERS);
      FORKS[threadNum % NUM_PHILOSOPHERS] = false;
    } else {
      printf("Philosopher %d fork not available", threadNum);
      printf("Philosopher %d putting back fork %d", threadNum, threadNum - 1);
      FORKS[threadNum - 1] = true;
    }

    printf("Philosopher %d eating", threadNum);
    hunger -= 10;
    printf("Philosopher %d putting down forks", threadNum);

    FORKS[threadNum - 1] = true;
    FORKS[threadNum % NUM_PHILOSOPHERS] = true;

    LOCK.unlock();
  }
  printf("Philosopher %d done eating", threadNum);
  return;
}

void run_waiter(){

}

int main(){
  thread t1(run_philosopher, 1);
  thread t2(run_philosopher, 2);
  thread t3(run_philosopher, 3);
  thread t4(run_philosopher, 4);
  thread t5(run_philosopher, 5);

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
