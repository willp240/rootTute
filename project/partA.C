
void partA()
{

  int num_signal_events = 100000;
  //int num_bg_events = 100000;
  // For part D we will rerun this with:
  int num_bg_events = 10000;
  
  double detector_radius = 5000;
  double pos_resolution = 100;
  double e_resolution = 0.03;
  double res_scale = 0.02; // How the resolutions scale as function of true radius
  
  TRandom3* random = new TRandom3();
  
  TTree* t = new TTree("eve_tree","Event Tree");
  //TFile* f = new TFile("partA.root","RECREATE");
  // For part D we will rerun this with:
  TFile* f = new TFile("partA_supressed_bg.root","RECREATE");
  
  // Declare the variables we want to save in our tree
  double true_x;
  double true_y;
  double true_z;
  double true_r;
  double true_e;
  
  double recon_x;
  double recon_y;
  double recon_z;
  double recon_r;
  double recon_e;

  bool signal;
  
  t->Branch("true_x", &true_x, "true_x/D");
  t->Branch("true_y", &true_y, "true_y/D");
  t->Branch("true_z", &true_z, "true_z/D");
  t->Branch("true_r", &true_r, "true_r/D");
  t->Branch("true_e", &true_e, "true_e/D");

  t->Branch("recon_x", &recon_x, "recon_x/D");
  t->Branch("recon_y", &recon_y, "recon_y/D");
  t->Branch("recon_z", &recon_z, "recon_z/D");
  t->Branch("recon_r", &recon_r, "recon_r/D");
  t->Branch("recon_e", &recon_e, "recon_e/D");

  t->Branch("signal", &signal, "signal/O");

  // Loop over signal events
  for(int i_event = 0; i_event < num_signal_events; i_event++){

    // Generate a true position in polar coordinates
    double true_phi = random->Rndm() * 2.0 * TMath::Pi();
    double true_costheta = random->Rndm() * 2.0 - 1.0;
    double true_theta = TMath::ACos( true_costheta );

    // Generate the radius and calculate cartesian coordinates
    true_r = random->Rndm() * detector_radius;
    true_x = true_r * TMath::Cos( true_phi ) * TMath::Sin( true_theta );
    true_y = true_r * TMath::Sin( true_phi ) * TMath::Sin( true_theta );
    true_z = true_r * true_costheta;
    true_e = 2.5;

    // Calculate reconstructed variables
    recon_x = random->Gaus(true_x, res_scale*true_r + pos_resolution );
    recon_y = random->Gaus(true_y, res_scale*true_r + pos_resolution );
    recon_z = random->Gaus(true_z, res_scale*true_r + pos_resolution );
    recon_r = sqrt(recon_x*recon_x + recon_y*recon_y + recon_z*recon_z);
    recon_e = random->Gaus(true_e, res_scale*true_r + e_resolution*true_e );

    signal = true;
    
    t->Fill();
  }

  // Repeat for background events with different radial distribution
  for(int i_event = 0; i_event < num_bg_events; i_event++){


    double true_phi = random->Rndm() * 2.0 * TMath::Pi();
    double true_costheta = random->Rndm() * 2.0 - 1.0;
    double true_theta = TMath::ACos( true_costheta );

    true_r = pow( (random->Rndm() * pow(detector_radius,3)), 1./3.);
    true_x = true_r * TMath::Cos( true_phi ) * TMath::Sin( true_theta );
    true_y = true_r * TMath::Sin( true_phi ) * TMath::Sin( true_theta );
    true_z = true_r * true_costheta;
    true_e = 2.5;

    recon_x = random->Gaus(true_x, res_scale*true_r + pos_resolution );
    recon_y = random->Gaus(true_y, res_scale*true_r + pos_resolution );
    recon_z = random->Gaus(true_z, res_scale*true_r + pos_resolution );
    recon_r = sqrt(recon_x*recon_x + recon_y*recon_y + recon_z*recon_z);
    recon_e = random->Gaus(true_e, res_scale*true_r + e_resolution*true_e );

    signal = false;
    
    t->Fill();
  }

  t->Write();
}
