void exampleMacro( ) {

  TH1D* h = new TH1D("histogram_name", "histogram title", 100, 0, 100);

  std::cout << h->GetXaxis()->GetNbins() << std::endl;

  for (int i=0; i<5; i++) {
    std::cout << i << endl;
  }

  std::cout << "done!" << std::endl;

}
