#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
class StackEmpty 
{
public:
  StackEmpty(string B){
    s = B;
  }
  string GetMessage(){
    return s;
  }
private:
  string s;
};
class StackFull
{
public:
  StackFull(string A, int B){
    a = A;
    b = B;
  }
  string GetMessage(){
    return a;
  }
  int GetValue(){
    return b;
  }
private:
  string a;
  int b;
};
class InvalidSize
{
public:
  InvalidSize(string A){
    messaG = A;
  }
  string getMessage(){
    return messaG;
  }
private:
  string messaG;
};

class IntStack
{
public:
  // MaxSize should be an unsigned int, but for the sake of example...
  IntStack(int MaxSize)
  {
    //throw InvalidSize("invalid size");
    if(MaxSize < 0)
      {
	throw InvalidSize("invalid size");
	//cerr << "Cannot create a negative size stack" << endl;
	//exit(1);
      }
		
    data.resize(MaxSize);
    cur_index = 0;
  }

  void push(int new_data)
  {
    if(cur_index == data.size())
      {
	throw StackFull("stack is full", new_data);	
	//cerr << "Push to full stack" << endl;
	//exit(1);
      }
    else
      {
	data.at(cur_index) = new_data;
	cur_index++;
      }
  }
  int pop()
  {
    if(cur_index == 0)
      {
	throw StackEmpty("stack is empty");
	//cerr << "Pop from empty stack" << endl;
	//exit(1);
      }
    else
      {
	// pop off the int and return it
	cur_index--;
	return data.at(cur_index);
      }
  }

private:
  vector<int> data;
  unsigned int cur_index;
};

int main()
{
  try
    {
      IntStack s(-10);
    }
  catch(InvalidSize e)
    {
      cerr << e.getMessage() << endl;
    }
  // Testing Constructor
  
  try
    {
      IntStack c_test(-10);
    }
  catch (InvalidSize d){
    cout << "heres another test" << endl;
    cerr << d.getMessage() << endl;
  }

  
 /* c_test.push(4);
      c_test.pop();
      c_test.pop();*/
    
  
  /*c_test.push(3);
  c_test.push(4);
  c_test.pop();
  c_test.pop();*/
	
	
  // Testing push
  try{
    IntStack push_test(4);
    for(unsigned int i = 0; i < 7; i++) {
      push_test.push(i);
    }
  }
  catch(StackFull obj){
    cerr << obj.GetMessage() << endl;
    cerr << obj.GetValue() << endl;
  }
  
  
  // Testing pop
  
 

  
  try{
    IntStack pop_test(5);
    pop_test.pop();
  }    
  catch(StackEmpty c){
    cerr << c.GetMessage() << endl;
  }
  //StackEmpty b;
  
  // b.GetMessage();
  
  //pop_test.pop();
  // pop_test.pop();
	
  cout << "Completed!" << endl;
  return 0;
}
