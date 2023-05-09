
void exampleTTreeOut( ){

  TTree* t = new TTree("eve_tree","Event Tree");

  TFile* f = new TFile("outfile.root","RECREATE");

  float var1, var2;
  int var3;

  t->Branch("var1", &var1, "var1/F");
  t->Branch("var2", &var2, "var2/F");
  t->Branch("var3", &var3, "var3/I");

  var1 = 0.5;
  var2 = 1.3;
  var3 = 5;
  t->Fill();

  var1 = -1.2;
  var2 = 4.5;
  var3 = 10;
  t->Fill();

  t->Print();
  t->Show(1);

  t->Write();

}
