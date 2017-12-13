# atoms
solves the schrodinger equation for the first 4 elements

using numerical approximation for solving the schrodinger equation. the idea is to simply take the infinitesimal iterations
of calculus and turning them into finite iterations

Example:
    U_x = U_t     (U_x stands for derivative with respect to x)
    U(0,t) = 0
    U(L,t) = 0
    U(x,0) = f(x)
    
    U_x = U_t turns into the equation below when converting the function to one of discrete incremental change
    
    (U(x1) - U(x0))/(x1-x0) = (U(t1) - U(t0))/(t1-t0)
    
    from the initial conditions we know the U(x,t) at time zero so we need to solve for what it will be in future time which is U(t1)
    
    (U(x1) - U(x0))* ((x1-x0)/(t1-t0)) + U(t0) = U(t1)
    
    using this we can solve for what U(x,t) will be at later times. but this only describes U(x,t) with respect to time at the point
    between x1 and x0 to find the rest of the function of U(x,t) you have to iterate through each X position which makes computers a 
    very useful tool in solving U(x,t) this way.
    
 
 To run the program simply type "make" in terminal followed by "./output1 n" to display hydrogens wave function. 
 (n represents the energy level to display. output1 is the only one with this feature).
 
 first ground state of hydrogen (n = 1)
 ![hydrogen](https://user-images.githubusercontent.com/29937430/33965057-7b475974-e00f-11e7-9a45-9ba01a185bbf.png)

 distance represents the most probable location to find the electron and energy is just the energy of that 
 electron or technically the first ionization energy. Also the energy is negative because the electron is 
 trapped in the negative potential well because of the nucleus as in the energy displayed is the energy required 
 to remove the electron from the grasp of the nucleus
 
 second ground state of hydrogen (n = 2)
 ![2nd-hydrogen](https://user-images.githubusercontent.com/29937430/33965275-22c0a57a-e010-11e7-9509-e4a2f48df2e8.png)
 
 Other atom wave functions can be seen by running output2, output3, and output4. The number at the end
 of output represents the atomic number of the atom to display
 
 If any problems occur just run "make clean" then "make" again and should fix things
 
 Dependencies:
     MatPlotLib,
     python,
     C compiler
     
    
