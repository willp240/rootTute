
void exampleTF1( ){

  TF1* f1 = new TF1("f1","sin(x)/x", 0., 10.);
  f1->SetLineColor(kRed);

  TF1* f2 = new TF1("f2","gaus", 0., 10.);
  f2->SetParameter(0, 1.); // Set normalisation of gaus
  f2->SetParameter(1, 5.); // Set mean of gaus
  f2->SetParameter(2, 2.); // Set wdith of gauus
  f2->SetLineColor(kBlue);
  
  f1->Draw();
  f2->Draw("same");
}
