
void exampleTRandom3( ){

  TRandom3* r3 = new TRandom3();

  for(int i=0; i<10; i++){

    double g = r3->Gaus();
    double r = r3->Rndm();

    std::cout << g << " " << r << std::endl;

  }
  
}
