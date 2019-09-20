#include <iostream>      
#include <thread>     
#include <atomic>  

using namespace std;

atomic<bool> digit1(false);
atomic<bool> digit2(false);
atomic<bool> digit3(false);

atomic<int> numeral1 (0);
atomic<int> numeral2 (0);
atomic<int> numeral3 (0);

void lottonumber_1(int id) {
  while (!digit1) {           
    this_thread::yield();
  }
for (volatile int i=1; i<55; ++i) {
++numeral1;
if(numeral1 <= 6) {
    cout << id;
}
}
}
void lottonumber_2(int id) {
  while (!digit2) {           
    this_thread::yield();
  }
for (volatile int i=1; i<55; ++i) {
++numeral2;
if(numeral2 <= 6) {
    cout << id;
}
}
}
void lottonumber_3(int id) {
   while (!digit3) {    
    this_thread::yield();
  }
for (volatile int i=1; i<55; ++i) {
++numeral3;
if(numeral3 <= 6) {
    cout << id;
}
}
}
int main ()
{
int i = 1;
  thread lists1[55];
  thread lists2[55];
  thread lists3[55];
  cout << "THESE ARE THE WINNING NUMBERS FOR TODAY'S LOTTERY!!!!!!!!!!\n";
  
  for (int i=1; i<7; ++i) lists1[i]=std::thread(lottonumber_1,i);
  cout << "\nFirst Lucky Number ";
  digit1 = true;
  this_thread::sleep_for(chrono::seconds(1));
  lists1[i].join();
  cout << "\nSo this the 1st lottery number that has been chosen\n";
  
  for (int i=1; i<7; ++i) lists2[i]=std::thread(lottonumber_2,i);
  cout << "\nSecond Lucky Number ";
  digit2 = true;
  this_thread::sleep_for(chrono::seconds(2));
  lists2[i].join();
  cout << "\n2nd number!!!!!\n";
  
  for (int i=1; i<7; ++i) lists3[i]=std::thread(lottonumber_3,i);
  cout << "\nThird Lucky Number ";
  digit3 = true;
  this_thread::sleep_for(chrono::seconds(3));
  lists3[i].join();
  cout << "\nThe last set of number for today!!!!\n";
  
  exit (0);
 
}


