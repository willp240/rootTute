
void exercise3( )
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetTextFont(132);
  TGaxis::SetMaxDigits(3);

  // Declare Canvas
  TCanvas *c2 = new TCanvas("c2", "c2", 1000, 1000);
  c2->SetFrameLineWidth(2);

  // Declare the histograms
  TH1D *h_data = new TH1D("data", "data", 20, 0, 2);
  TH1D *h_MC = new TH1D("mc", "mc", 20, 0, 2);

  // Fake some data and MCM
  double data[20] = {10, 10, 20, 30, 50, 90, 100, 110, 110, 100, 90, 90, 80, 70, 70, 60, 50, 40, 40, 30 };
  double mc[20] = {10, 13, 18, 27, 45, 89, 112, 115, 114, 102, 94, 93, 82, 72, 71, 60, 49, 38, 39, 32};

  // Put the values into the histograms
  for(int i_bin = 0; i_bin < h_data->GetXaxis()->GetNbins(); i_bin++){
    h_data->SetBinContent(i_bin+1, data[i_bin]);
    h_data->SetBinError(i_bin+1, TMath::Sqrt(data[i_bin]));
    h_MC->SetBinContent(i_bin+1, mc[i_bin]);
  }
  
  // First clone the data histograms for the ratio & difference plots
  TH1D *h_ratio = (TH1D*)h_data->Clone("h_ratio");   
  TH1D *h_diff = (TH1D*)h_data->Clone("h_diff");

  // Divide to get ratio plot
  h_ratio->Divide(h_MC);

  // Loop over bins and calculate fractional difference
  for (int i_bin = 1; i_bin <= h_data->GetXaxis()->GetNbins(); i_bin++)
    {
      double data_val = h_data->GetBinContent(i_bin);
      double mc_val = h_MC->GetBinContent(i_bin);
      double data_uncertainty = TMath::Sqrt(data_val);
      double diff_val = mc_val - data_val;

      h_diff->SetBinContent(i_bin, diff_val/data_uncertainty);
    }

  // Make one canvas with three pads
  double uppermin = 0.35;
  double middlemin = 0.237;
  TPad *lower = new TPad("lower", "pad", 0, 0, 1, middlemin);
  TPad *middle = new TPad("middle", "pad", 0, middlemin, 1, uppermin);
  TPad *upper = new TPad("upper", "pad", 0, uppermin, 1, 1);

  // Some drar options for these pads
  upper->SetBottomMargin(0.0);
  upper->SetFrameLineWidth(2);
  upper->SetGrid(1);
  middle->SetTopMargin(0.0);
  middle->SetBottomMargin(0.0);
  middle->SetFrameLineWidth(2);
  middle->SetGrid(1);
  lower->SetTopMargin(0.0);
  lower->SetBottomMargin(0.58);
  lower->SetFrameLineWidth(2);
  lower->SetGrid(1);
  
  upper->Draw();
  middle->Draw();
  lower->Draw();
  c2->cd();

  // Set sxis ranges for ratio plot
  h_ratio->GetYaxis()->SetRangeUser(0.7,1.3);
  h_ratio->GetXaxis()->SetRangeUser(0,2);
  // Set axis ranges for difference plot
  h_diff->GetYaxis()->SetRangeUser(-1.3,1.3);
  h_diff->GetXaxis()->SetRangeUser(0,2);

  // Draw difference plot
  lower->cd();
  h_diff->SetLineWidth(2);
  h_diff->SetLineColor(kRed);
  h_diff->SetTitle("");
  h_diff->GetXaxis()->SetTitle("Energy (GeV)");
  h_diff->GetYaxis()->SetTitle("#Delta/#delta");
  h_diff->GetYaxis()->CenterTitle();
  h_diff->GetYaxis()->SetTitleSize(0.16);
  h_diff->GetYaxis()->SetTitleOffset(0.25);
  h_diff->GetYaxis()->SetNdivisions(305,kTRUE);
  h_diff->GetYaxis()->SetLabelSize(0.1);
  h_diff->GetXaxis()->SetTitleSize(0.17);
  h_diff->GetXaxis()->SetTitleOffset(1.2);
  h_diff->GetXaxis()->SetLabelSize(0.13);
  h_diff->Draw("L hist");

  // Draw a line at y = 0
  TLine* l1 = new TLine(0,0,2.0,0);
  l1->SetLineWidth(2);
  l1->SetLineColor(kBlue);
  l1->Draw("same");
 
  // Draw ratio plot
  middle->cd();
  h_ratio->SetTitle("");
  h_ratio->SetLineColor(kRed);
  h_ratio->SetLineWidth(2);
  h_ratio->GetYaxis()->SetTitle("Ratio");
  h_ratio->GetYaxis()->CenterTitle();
  h_ratio->GetYaxis()->SetTitleSize(0.31);
  h_ratio->GetYaxis()->SetTitleOffset(0.13);
  h_ratio->GetYaxis()->SetNdivisions(305,kTRUE);
  h_ratio->GetYaxis()->SetLabelSize(0.2);
  h_ratio->GetXaxis()->SetLabelSize(1);
  h_ratio->Draw("L hist");

  // Draw a line at y = 1
  TLine* l2 = new TLine(0,1.00,2.0,1.0);
  l2->SetLineWidth(2);
  l2->SetLineColor(kBlue);
  l2->Draw("same");
  
  // Draw the top plot
  upper->cd();
  upper->SetTitle("Data-MC Comparison");
  h_data->SetLineColor(kRed);
  h_data->SetLineWidth(2);
  h_data->SetMarkerStyle(20);
  h_MC->SetLineColor(kBlue);
  h_MC->SetLineWidth(2);
  h_data->GetYaxis()->SetTitleSize(0.05);
  h_data->GetYaxis()->SetLabelSize(0.04);
  h_data->GetYaxis()->SetTitleOffset(2.0);
  h_data->GetYaxis()->SetTitle("Events");
  h_data->GetYaxis()->SetTitleOffset(0.83);
  h_data->GetYaxis()->SetRangeUser(0.1, 130);
  h_data->SetTitle("Data-MC Comparison");
  h_data->GetXaxis()->SetLabelOffset(1);
  h_data->Draw("p e");
  h_MC->Draw("same");

  // Draw a legend
  TLegend *l = new TLegend(0.7, 0.75, 0.85, 0.85);
  l->AddEntry(h_data, "Data", "lp");
  l->AddEntry(h_MC, "MC", "lp");
  l->SetFillColor(0);
  l->SetLineWidth(2);
  l->Draw("same");

  return;
}

