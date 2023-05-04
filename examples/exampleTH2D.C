
void exampleTH2D( ){
  
  TH2D* h1 = new TH2D("hname", "htitle", 20, -10, 10, 20, -10, 10);

  for(int xbin = 1; xbin <= h1->GetXaxis()->GetNbins(); xbin++) {
    for(int ybin = 1; ybin <= h1->GetYaxis()->GetNbins(); ybin++) {

      double x = h1->GetXaxis()->GetBinCenter(xbin);
      double y = h1->GetYaxis()->GetBinCenter(ybin);
      
      double r = TMath::Sqrt(x*x + y*y);
    

      h1->SetBinContent(xbin, ybin, r);

    }
  }
      
  h1->Draw("colz");
}

