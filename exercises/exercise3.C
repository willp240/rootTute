
void exercise3()
{
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);

  TCanvas *c1 = new TCanvas("c1", "c1", 1000, 800);
  c1->SetFrameLineWidth(2);
  c1->SetGrid(1);

  std::vector< double > mean_vector{ 5, 10, 25, 50, 100 };

  TLegend* leg = new TLegend(0.42, 0.5, 0.82, 0.8);

  for(int i_plot = 0; i_plot < mean_vector.size(); i_plot++){

    TString gaus_name = Form("gaus_%.0f", mean_vector.at(i_plot));
    TString gaus_title = Form("Gaus (#mu = %.0f, #sigma = %.2f)", mean_vector.at(i_plot), sqrt(mean_vector.at(i_plot)));
    TF1* gaus_function = new TF1(gaus_name, "gaus", 0, 140);
    gaus_function->SetParameter(0, 1 / sqrt(mean_vector.at(i_plot) * 2 * TMath::Pi()));
    gaus_function->SetParameter(1, mean_vector.at(i_plot));
    gaus_function->SetParameter(2, sqrt(mean_vector.at(i_plot)));
    gaus_function->SetNpx(1000);
    
    TString poisson_dist = Form("TMath::Poisson(x, %.0f)", mean_vector.at(i_plot));
    TString poisson_name = Form("poisson_%.0f", mean_vector.at(i_plot) );
    TString poisson_title = Form("Poisson ( #lambda = %.0f)", mean_vector.at(i_plot) );
    TF1* poisson_function = new TF1(poisson_name, poisson_dist, 0, 140);
    poisson_function->SetNpx(1000);
    
    gaus_function->SetLineWidth(2);
    gaus_function->SetLineStyle(2);
    gaus_function->SetLineColor(i_plot+1);
    poisson_function->SetLineWidth(2);
    poisson_function->SetLineStyle(1);
    poisson_function->SetLineColor(i_plot+1);

    gaus_function->GetXaxis()->SetTitle("X");
    gaus_function->GetYaxis()->SetTitle("Probability");

    leg->AddEntry(gaus_function, gaus_title, "l");
    leg->AddEntry(poisson_function, poisson_title, "l");
    
    if(i_plot == 0)
      gaus_function->Draw();
    else
      gaus_function->Draw("same");
    poisson_function->Draw("same");
    
  }

  leg->Draw("same");

  c1->SaveAs("./exercise3Canvas.pdf");
  c1->SaveAs("./exercise3Canvas.C");
  
}
