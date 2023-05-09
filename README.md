# ROOTTute
ROOT Tutorial for 2023 EIEIO Workshop

<h2> Examples </h2>

All the macros shown in the slides are in the examples directory. These can be run as:

root -l macroName.C

and should produce the outputs shown in the slides.


<h2> Exercise and Project Solutions </h2>

Example solutions to the five exercises can be found in the exercises directory. There's always a lot of different ways you can go about any of these problems, so try them out yourself and check these solutions iff you get stuck. <br>
The first two exercises are fairly basic and open ended, so don't have solutions. <br>
A solution to the project can be found in the project directory.


<h2> Exercises </h2>

<h3> Exercise 1 </h3>
<b>Getting used to the ROOT command line </b> <br>
Open ROOT <br>
Declare some variables and do some calculations <br>
Draw a TCanvas <br>
Open the TBrowser and explore! <br>

<h3> Exercise 2 </h3>
<b>Writing and running a basic macro </b> <br>
In a macro, declare a histogram <br>
Fill it with some values, in any way you choose <br>
Declare a new TFile, and save the histogram <br>
Open the new ROOT file and draw the histogram <br>
Play with the aesthetics of the plot via the GUI <br>

<h3> Exercise 3 </h3>
<b>Plotting the Gaussian approximation to the Poisson distribution </b> <br>
Plot the Poisson distribution for λ = 5, 10, 25, 50, 100 <br>
For each, also plot the Gaussian distribution with μ = λ, σ = √λ <br>
Use a different colour for each λ, and different line styles for Poisson and Gaussian <br>
Save the canvas to a PDF file <br>

<h3> Exercise 4 </h3>
<b> Recreate the data - Monte Carlo comparison plot from the slides (also in exercises/exercise4Canvas.pdf) exactly (or as close as you can!)
You will have to judge the bin contents of the two histograms <br>
  
<h3> Exercise 5 </h3>
<b> Collecting real data and plotting correlations </b> <br>
This is a bonus exercise in case we run out of material. The idea is to collect numerical data of some sort, and then make some plots. <br>
  
Ask your friends >= 5 questions about themselves with numeric answers (eg, birthdate, age, height, shoe size, favourite number, number of pets/pairs of shoes/hammocks they own). Get creative! <br>
Record each answer in a text file, separated by a space, with a new line for a new friend <br>
Read this into a TTree, and save the TTree to file <br>
Open the file and plot different variables against each other. You can cut on variables (including ones your not plotting) <br>
See if you can pull out any amusing correlations! <br>
But remember this does not necessarily imply causation!!! <br>


<h2> Project </h2>
