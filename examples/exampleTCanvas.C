
void exampleTCanvas( ){

  TCanvas* c1 = new TCanvas("cname", "ctitle", 600, 1500);
  c1->Divide(1,2);
  
  TH2D* h1 = new TH2D("hname", "htitle", 20, -10, 10, 20, -10, 10);

  for(int xbin = 1; xbin <= 20; xbin++) {
    for(int ybin = 1; ybin <= 20; ybin++) {

      double x = h1->GetXaxis()->GetBinCenter(xbin);
      double y = h1->GetYaxis()->GetBinCenter(ybin);
      
      double r = TMath::Sqrt(x*x + y*y);
    

      h1->SetBinContent(xbin, ybin, r);

    }
  }
  c1->cd(1);
  h1->Draw("colz");

  c1->cd(2);
  h1->ProjectionX()->Draw();
}
