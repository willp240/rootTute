
void exercise3()
{
  gStyle->SetOptStat(0); // Don't print the stats box

  // Declare our canvas and set some aesthetic parameters
  TCanvas *c1 = new TCanvas("c1", "c1", 1000, 800);
  c1->SetFrameLineWidth(2);
  c1->SetGrid(1);

  // Declare vector of mean we want to plot for
  std::vector< double > mean_vector{ 5, 10, 25, 50, 100 };

  // Declare legend
  TLegend* leg = new TLegend(0.42, 0.5, 0.82, 0.8);

  // Loop over means
  for(int i_plot = 0; i_plot < mean_vector.size(); i_plot++){

    // Set the name and title for our Gaussian function
    TString gaus_name = Form("gaus_%.0f", mean_vector.at(i_plot));
    TString gaus_title = Form("Gaus (#mu = %.0f, #sigma = %.2f)", mean_vector.at(i_plot), sqrt(mean_vector.at(i_plot)));
    // We can use the predefined "gauus" function, over a range of 0 to 100
    TF1* gaus_function = new TF1(gaus_name, "gaus", 0, 140);
    // And now set the parameters of the function
    gaus_function->SetParameter(0, 1 / sqrt(mean_vector.at(i_plot) * 2 * TMath::Pi()));
    gaus_function->SetParameter(1, mean_vector.at(i_plot));
    gaus_function->SetParameter(2, sqrt(mean_vector.at(i_plot)));
    gaus_function->SetNpx(1000); // Draw more points so line is smoother

    // Now do the same for the Poisson
    // This time instead of using the SetParameter method, let's directly put the mean in the parenthesis 
    TString poisson_dist = Form("TMath::Poisson(x, %.0f)", mean_vector.at(i_plot));
    TString poisson_name = Form("poisson_%.0f", mean_vector.at(i_plot) );
    TString poisson_title = Form("Poisson ( #lambda = %.0f)", mean_vector.at(i_plot) );
    TF1* poisson_function = new TF1(poisson_name, poisson_dist, 0, 140);
    poisson_function->SetNpx(1000);

    // Set the draw options for both functions
    gaus_function->SetLineWidth(2);
    gaus_function->SetLineStyle(2);
    gaus_function->SetLineColor(i_plot+1);
    poisson_function->SetLineWidth(2);
    poisson_function->SetLineStyle(1);
    poisson_function->SetLineColor(i_plot+1);

    gaus_function->GetXaxis()->SetTitle("X");
    gaus_function->GetYaxis()->SetTitle("Probability");

    // Add entries to the legend for each distribution
    leg->AddEntry(gaus_function, gaus_title, "l");
    leg->AddEntry(poisson_function, poisson_title, "l");

    // A bit inelegant, if it's the first draw without same option
    if(i_plot == 0)
      gaus_function->Draw();
    else
      gaus_function->Draw("same");
    poisson_function->Draw("same");
    
  }

  // Draw the legend
  leg->Draw("same");

  // And finally, save as C file and PDF
  c1->SaveAs("./exercise3Canvas.pdf");
  c1->SaveAs("./exercise3Canvas.C");
  
}
