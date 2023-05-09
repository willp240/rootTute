
void exercise5( ){

  // First make sure there's some data in "exercise5.txt"

  // Declare the TTree
  TTree* t = new TTree("tree","Event Tree");

  // Read in data
  t->ReadFile("exercise5.txt","birthdate:height:shoesize:pets:favnum");

  // Save the TTree in a root file
  TFile* f = new TFile("exercise5.root","RECREATE");
  t->Write();

  
  // Now open that file and plot some correlations:

  // > root -l exercise5Tree.root
  // > tree->Draw("height:shoesize","","colz")
  // > tree->Draw("pets:birthdate", "height < 190", "colz")  
}
