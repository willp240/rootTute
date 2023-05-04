
void exampleTH1D( ){

  TH1D* h1 = new TH1D("hname", "htitle", 10, 0, 10);

  h1->FillRandom("gaus", 5);
  
  h1->Draw();
}

