
void exampleTMath( ){

  double a = TMath::Pi()/2;
  std::cout << a << std::endl;
  
  double b = TMath::Sin(a);
  std::cout << b << std::endl;

  std::cout << TMath::Gaus(a, 0, 1) << std::endl;
}

