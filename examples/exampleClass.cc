class Car {
  public:                     // Public access specifier
    std::string number_plate; // Public attribute
  private:                    // Private access specifier
    int chassis_id;           // Private attribute
};

int main() {
  Car myCar;
  myCar.number_plate = "A123CDE";  // Allowed (public)
  myCar.chassis_id = 1234;         // Not allowed (private)
  return 0;
}
