
void partC()
{

  gStyle->SetOptStat(0);

  int num_points = 100; // Number of radial cuts we will try
  double detector_radius = 5000;

  // Open file and get tree
  TFile *f1 = TFile::Open("partA.root");
  TTree *t1 = (TTree*)f1->Get("eve_tree");

  TCanvas *c1 = new TCanvas("c1", "c1", 1000, 800);
  c1->SetFrameLineWidth(2);
  c1->SetGrid(1);

  // Set up graph
  TString gname = Form("ROC");
  TString gtitle = Form("ROC");
  TGraph* g = new TGraph( );
  g->GetYaxis()->SetTitle("Purity");
  g->GetXaxis()->SetTitle("Sacrifice");
  g->GetYaxis()->SetTitleOffset(1.2);
  g->GetXaxis()->SetRangeUser(0,1);
  g->GetYaxis()->SetRangeUser(0,1);
  g->SetMarkerColor(kRed);
  g->SetMarkerStyle(50);
  g->SetMarkerSize(2);


  // Loop over values or radial cut
  for(int i_point = 1; i_point <= num_points; i_point++){

    double r_cut = 5000 - (i_point * detector_radius / (float)num_points );

    // Calculate how many signal events there are, and how many pass the cut
    TString cut = Form("signal == 1");
    t1->Draw("true_r", cut);
    TH1* h_signal = (TH1*) gPad->GetListOfPrimitives()->FindObject("htemp");
    int tot_signal;
    if(!h_signal){
      tot_signal = 0;}
    else
      tot_signal = h_signal->Integral();
    cut = Form("signal == 1 && recon_r < %f", r_cut);
    
    t1->Draw("true_r", cut);
    TH1* h_signal_cut = (TH1*) gPad->GetListOfPrimitives()->FindObject("htemp");
    int	accepted_signal;
    if(!h_signal_cut){
      accepted_signal = 0;}
    else
      accepted_signal = h_signal_cut->Integral();

    // Calculate how many background events there are, and how many pass the cut
    cut = Form("signal == 0 ");
    t1->Draw("true_r", cut);
    TH1* h_bg = (TH1*) gPad->GetListOfPrimitives()->FindObject("htemp");
    int tot_bg;
    if(!h_bg){
      tot_bg = 0;}
    else
      tot_bg = h_bg->Integral();

    cut = Form("signal == 0 && recon_r < %f", r_cut);
    t1->Draw("true_r", cut);
    TH1* h_bg_cut = (TH1*) gPad->GetListOfPrimitives()->FindObject("htemp");
    int accepted_bg;
    if(!h_bg_cut){
      accepted_bg = 0;}
    else
      accepted_bg = h_bg_cut->Integral();

    // Calculate the purity and sacrifice, and set the point in the TGraph
    double purity = 1 - (accepted_bg / (double) (accepted_bg + accepted_signal) );
    double sacrifice =  1 - (accepted_signal / (double) tot_signal);

    g->SetPoint(i_point, sacrifice, purity);
  }

  g->Draw("AP");
}
