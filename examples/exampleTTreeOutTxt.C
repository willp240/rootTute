
void exampleTTreeOutTxt( ){

  TTree* t = new TTree("eve_tree","Event Tree");

  t->ReadFile("data.txt","x:y:z");

  TFile* f = new TFile("outfile2.root","RECREATE");

  t->Write();
}
