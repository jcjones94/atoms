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
    
 
 To run the program simple type make in terminal then ./output1 n to display hydrogens wave function. 
 (n represents the energy level to display. output1 is the only one with this feature).
 
 
    
    
