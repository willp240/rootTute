
void exampleTLegend( ){

  TCanvas* c1 = new TCanvas("cname", "ctitle", 800, 600);
  gStyle->SetOptStat(0);
  c1->SetFrameLineWidth(2);
  c1->SetGrid(1);
  
  TH1D* h1 = new TH1D("h1", "h1", 10, 0, 10);

  for(int ibin = 1; ibin <= h1->GetXaxis()->GetNbins(); ibin++) {

    double x = h1->GetXaxis()->GetBinCenter(ibin);
    double y = 4*x*x + 3*x +7;

    h1->SetBinContent(ibin, y);
  }

  
  TF1* f1 = new TF1("f1","pol2", 0., 10.);
  f1->SetLineColor(kRed);
  f1->SetLineWidth(2);
  f1->SetParameters(0, 10);
  f1->SetParameters(1, 5);
  f1->SetParameters(2, 5);

  TLegend* leg = new TLegend(0.22, 0.6, 0.47, 0.8);
  leg->AddEntry(h1, "Histogram", "l");
  leg->AddEntry(f1, "Fitted Function", "l");
  leg->SetLineWidth(2);
  
  h1->GetXaxis()->SetTitle("X Values");
  h1->GetYaxis()->SetTitle("Y Values");
  h1->SetTitle("Example of Fitting a 2nd Order Polynomial to a Histogram");
  h1->SetLineWidth(2);
  
  h1->Fit("f1");
  h1->Draw();
  f1->Draw("same");
  leg->Draw("same");
  
}
