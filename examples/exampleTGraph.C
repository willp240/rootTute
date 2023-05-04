
void exampleTGraph( ){
  
  TGraph* g = new TGraph();

  int npoints = 20;
  
  for(int ipoint = 0; ipoint < npoints; ipoint++) {

    double x = ipoint;
    double y = x*x;

    g->SetPoint(ipoint, x, y);
  }

  g->SetMarkerStyle(2);
  g->SetMarkerSize(4);
  g->Draw("AP");
}
