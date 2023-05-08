
void partB()
{
  
  gStyle->SetOptStat(0);
  
  TFile *f1 = TFile::Open("partA.root");
  // For part D we can rerun this with:
  // TFile *f1 = TFile::Open("partA_supressed_bg.root");
  TTree *t1 = (TTree*)f1->Get("eve_tree");


  //////// Radial distribution of signal events
  TCanvas *c1 = new TCanvas("c1", "c1", 1000, 800);
  c1->SetFrameLineWidth(2);
  c1->SetGrid(1);

  t1->Draw("true_r", "signal == 1");
  TH1* h_signal_true_r = (TH1*) gPad->GetListOfPrimitives()->FindObject("htemp");
  h_signal_true_r->GetXaxis()->SetTitle("True Radius, mm");
  h_signal_true_r->GetYaxis()->SetTitle("Events");
  h_signal_true_r->SetLineWidth(2);
  h_signal_true_r->GetYaxis()->SetTitleOffset(1.4);


  //////// Radial distribution of background events
  TCanvas *c2 = new TCanvas("c2", "c2", 1000, 800);
  c2->SetRightMargin(0.13);
  c2->SetFrameLineWidth(2);
  c2->SetGrid(1);
  c2->cd();
  
  t1->Draw("true_r", "signal == 0");
  TH1* h_bg_true_r = (TH1*) gPad->GetListOfPrimitives()->FindObject("htemp");
  h_bg_true_r->GetXaxis()->SetTitle("True Radius, mm");
  h_bg_true_r->GetYaxis()->SetTitle("Events");
  h_bg_true_r->SetLineColor(kRed);
  h_bg_true_r->SetLineWidth(2);
  h_bg_true_r->GetYaxis()->SetTitleOffset(1.4);


  
  //////// True vs reconstructed radius
  TCanvas *c3 = new TCanvas("c3", "c3", 1000, 800);
  c3->SetRightMargin(0.13);
  c3->SetFrameLineWidth(2);
  c3->SetGrid(1);
  c3->cd();

  t1->Draw("true_r:recon_r","","colz");
  TH2* h_true_recon_r = (TH2*) gPad->GetListOfPrimitives()->FindObject("htemp");
  h_true_recon_r->GetXaxis()->SetTitle("True Radius, mm");
  h_true_recon_r->GetYaxis()->SetTitle("Reconstructed Radius, mm");
  h_true_recon_r->GetYaxis()->SetTitleOffset(1.4);



  //////// Fractional error in energy reconstruction as a function of true energy
  TCanvas *c4 = new TCanvas("c4", "c4", 1000, 800);
  c4->SetRightMargin(0.13);
  c4->SetFrameLineWidth(2);
  c4->SetGrid(1);
  c4->cd();

  t1->Draw("(recon_e-true_e)/true_e:true_r","","colz");
  TH2* h_true_recon_e = (TH2*) gPad->GetListOfPrimitives()->FindObject("htemp");
  h_true_recon_e->GetXaxis()->SetTitle("True Radius, mm");
  h_true_recon_e->GetYaxis()->SetTitle("(Reconstructed E - True E) / True E");
  h_true_recon_e->GetYaxis()->SetTitleOffset(1.4);
  
}
