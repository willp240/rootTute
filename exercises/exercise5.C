
void exercise5( ){
  
  TTree* t = new TTree("tree","Event Tree");

  t->ReadFile("exercise5.txt","birthdate:height:shoesize:pets:favnum");
  
  TFile* f = new TFile("exercise5.root","RECREATE");
  
  t->Write();

  
  // Now open that file and plot some correlations:

  // > root -l exercise5Tree.root
  // > tree->Draw("height:shoesize","","colz")
  // > tree->Draw("pets:birthdate", "height < 190", "colz")  
}
