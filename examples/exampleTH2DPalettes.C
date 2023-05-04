
void exampleTH2DPalettes( ){

  gStyle->SetNumberContours(100);
  //gStyle->SetPalette(75);
  //  TColor::InvertPalette();

  TH2D* h1 = new TH2D("hname", "h1->Draw('lego')", 20, -10, 10, 20, -10, 10);

  for(int xbin = 1; xbin <= 20; xbin++) {
    for(int ybin = 1; ybin <= 20; ybin++) {

      double x = h1->GetXaxis()->GetBinCenter(xbin);
      double y = h1->GetYaxis()->GetBinCenter(ybin);
      
      double r = TMath::Sqrt(x*x + y*y);
    

      h1->SetBinContent(xbin, ybin, r);

    }
  }
      
  h1->Draw("lego");
  //h1->Draw("surf");
  //h1->Draw("surf2");
  //h1->Draw("surf3");
}
