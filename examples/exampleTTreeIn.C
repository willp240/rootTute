
void exampleTTreeIn( ){

  TFile *f1 = TFile::Open("outfile2.root");

  TTree *t1 = (TTree*)f1->Get("eve_tree");

  float x,y,z;

  t1->SetBranchAddress("x", &x);
  t1->SetBranchAddress("y", &y);
  t1->SetBranchAddress("z", &z);

  for (int i_entry = 0; i_entry < t1->GetEntries(); i_entry++) {
    t1->GetEntry(i_entry);
    std::cout << x << " " << y << " " << z << std::endl;
  }

  t1->Draw("y", "z>1");

}
