#include <iostream>
#include <string>
void logCall(const std::string &funcName) {
  std::cout << funcName << std::endl;
};
class Date {
 private:
  std::string data;
};
class Customer {
 public:
  Customer() { logCall("Customer default constructor"); }
  Customer(const Customer &rhs);
  Customer &operator=(const Customer &rhs);

 private:
  std::string name_;
  Date lastTransaction_;
};
Customer::Customer(const Customer &rhs) : name_(rhs.name_) {
  logCall("Customer copy constructor");
}
Customer &Customer::operator=(const Customer &rhs) {
  logCall("Customer copy assignment operator");
  this->name_ = rhs.name_;
  return *this;
}

class PriorityCustomer : public Customer {
 public:
  PriorityCustomer(int i) : priority_(i) {
    logCall("PriorityCustomer default constructor");
  }
  PriorityCustomer(const PriorityCustomer &rhs)
      : Customer(rhs), priority_(rhs.priority_) {
    logCall("PriorityCustomer copy constructor");
  }

  //      no matching function for call to ‘Customer::Customer(
  //     PriorityCustomer(const PriorityCustomer& rhs) :
  //     priority_(rhs.priority_) { logCall("PriorityCustomer copy
  //     constructor");
  //   }

  PriorityCustomer &operator=(const PriorityCustomer &rhs) {
    logCall("PriorityCustomer copy assignment operator");
    Customer::operator=(rhs);
    /*
      static_cast<Customer>(*this).operator=(rhs);
      
      This is not a correct implementation which will create a new base obj and modify it.
      That is to say it will not modify this->obj's base part.
    */
    priority_ = rhs.priority_;
    return *this;
  }

 private:
  int priority_;
};
int main() {
  PriorityCustomer pc(1);
  PriorityCustomer pc22(2);
  logCall("----------------");
  pc22 = pc;
  logCall("----------------");
  PriorityCustomer pc33(pc);
}