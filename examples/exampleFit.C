
void exampleFit( ){

  TH1D* h1 = new TH1D("h1", "h1", 10, 0, 10);

  for(int ibin = 1; ibin <= h1->GetXaxis()->GetNbins(); ibin++) {

    double x = h1->GetXaxis()->GetBinCenter(ibin);
    double y = 4*x*x + 3*x +7;

    h1->SetBinContent(ibin, y);
  }

  
  TF1* f1 = new TF1("f1","pol2", 0., 10.);
  f1->SetLineColor(kRed);
    
  h1->Fit("f1");
  h1->Draw();
  f1->Draw("same");
}
