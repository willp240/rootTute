# ROOTTute
ROOT Tutorial for 2023 EIEIO Workshop

<h2>Examples</h2>

All the macros shown in the slides are in the examples directory. These can be run as:

> root -l macro_name.C

and should produce the outputs shown in the slides.


<h2>Exercise and Project Solutions</h2>

Example solutions to the five exercises can be found in the exercises directory. There's always a lot of different ways you can go about any of these problems, so try them out yourself and check these solutions if you get stuck. The first two exercises are fairly basic and open ended, so don't have solutions.
A solution to the project can be found in the project directory. <br>
The solution scripts can be run like the examples:

> root -l exercises_solution.C

<h2>Exercises</h2>

<h3>Exercise 1</h3>
<b>Getting used to the ROOT command line </b> <br>

- Open ROOT <br>
- Declare some variables and do some calculations <br>
- Draw a TCanvas <br>
- Open the TBrowser and explore! <br>

<h3>Exercise 2</h3>
<b>Writing and running a basic macro </b> <br>

- In a macro, declare a histogram <br>
- Fill it with some values, in any way you choose <br>
- Declare a new TFile, and save the histogram <br>
- Open the new ROOT file and draw the histogram <br>
- Play with the aesthetics of the plot via the GUI <br>

<h3>Exercise 3</h3>
<b>Plotting the Gaussian approximation to the Poisson distribution </b> <br>

- Plot the Poisson distribution for λ = 5, 10, 25, 50, 100 <br>
- For each, also plot the Gaussian distribution with μ = λ, σ = √λ <br>
- Use a different colour for each λ, and different line styles for Poisson and Gaussian <br>
- Save the canvas to a PDF file <br>

<h3>Exercise 4</h3>
<b> Recreate the data - Monte Carlo comparison plot from the slides (also in exercises/exercise4Canvas.pdf) exactly (or as close as you can!)</b> <br>

- You will have to judge the bin contents of the two histograms <br>
  
<h3>Exercise 5</h3>
<b> Collecting real data and plotting correlations </b> <br>
This is a bonus exercise in case we run out of material. The idea is to collect numerical data of some sort, and then make some plots. <br>
  
- Ask your friends >= 5 questions about themselves with numeric answers (eg, birthdate, age, height, shoe size, favourite number, number of pets/pairs of shoes/hammocks they own). Get creative! <br>
- Record each answer in a text file, separated by a space, with a new line for a new friend <br>
- Read this into a TTree, and save the TTree to file <br>
- Open the file and plot different variables against each other. You can cut on variables (including ones your not plotting) <br>
- See if you can pull out any amusing correlations! <br>
&emsp; - But remember this does not necessarily imply causation!!! <br>


<h2>Project</h2>
<b>Simulating a dataset from a particle detector</b> <br>

<h3>Part A:</h3>

- Imagine you have a 5m radius spherical target mass, surrounded by PMTs <br>
- Generate x, y, z and energy for 1000 events <br>
&emsp;- Assume this signal is uniformly distributed in position <br>
&emsp;- Assume an energy of, say, 2.5 MeV <br>
&emsp;- You can use ROOT's TRandom3 class to generate random numbers
- Now generate x, y, z and energy for 1000 background events <br>
&emsp;- Let’s say it has the same energy as our signal <br>
&emsp;- But radially drops off as 1/r^2 away from the edge of the detector. Maybe there’s some external radiation that leaches into the target mass but only penetrates so far <br>
- Now let’s generate some reconstructed values <br>
&emsp;- Assume a position resolution of 100 mm in each coordinate <br>
&emsp;- Assume an energy resolution of 5 % <br>
&emsp;- What if the resolution is a weak function of the radius? <br>
&emsp;- This smearing of the true values with the width of the resolution is a common way to account for detector effects in simulation
- Now repeat for 100,000 events and save these values in a TTree in a file <br>

<h3>Part B:</h3>

- Check the radial distributions look as expected <br>
- Plot True vs Reconstructed R for all events <br>
- Plot the bias in energy [(Reconstructed E - True E) / True E] as a function of True R <br>

<h3>Part C:</h3>

- We are now going to try and reject those background events by cutting on radius <br>
- Make a ROC curve (purity against sacrifice) for different values for a radial cut <br>

<h3>Part D:</h3>

- Now repeat this whole process but for a background rate reduced by a factor of 10. How does the ROC curve change? <br>
