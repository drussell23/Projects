%% Homework Assignment for ENGR 25 - MATLAB
% Professor Dr. Weathers 
%% Date: January 25th, 2019
% Script written by: [RUSSELL, DEREK J.]
%% Homework #1 - Due January 29th, 2019 
% Third edition: 1-31 odd
%% BEGIN EACH SCRIPT WITH THE FOLLOWING
% clc; clear all; close all;

%% Section 1.1 
% 1.) Make sure you know how to start and quit a MATLAB session. Use MATLAB
%     to make the following calculations, using the values x = 10, y = 3. 
%     Check the results by using a calculator. 
% 1a.) u = x + y 
x = 10
y = 3

u = x + y

% 1b.) v = xy 
v = x*y;

% 1c.) w = x/y
w = x/y

% 1d.) z = sinx
z = sin(x)

% 1e.) r = 8siny
r = 8 * sin(y)

% 1f.) s = 5sin(2y)
s = 5 * sin(2*y)

% 3.) Suppose that x = 3 and y = 4. Use MATLAB to compute the following,
%     and check the results with a calculator.
x = 3
y = 4

% 3a.) (1 - 1/x^5)^-1
a = (1 - 1/x^5)^-1

% 3b.) 3pi*x^2
b = (3*pi*x^2);

% 3c.) 3y/4x-8
c = 3*y/((4*x)-8)

% 3d.) 4(y-5)/3x-6
d = 4*(y-5)/((3*x)-6)

% 5.) Assuming that the variables a, b, c, d, and f are scalars, write
%     MATLAB statements to compute and display the following expressions. Test
%     your statements for the values a = 1.12, b = 2.34, c = 0.72, d = 0.81,
%     and f = 19.83. 
a = 1.12, b = 2.34; c = 0.72, d = 0.81, f = 19.83

% x = 1 + a/b + c/f^2
x = 1 + a/b + c/f^2

% s = b-a/d-c
s = (b-a)/(d-c)

% r = 1/(1/a + 1/b + 1/c + 1/d)
r = 1/(1/a + 1/b + 1/c + 1/d)

% y = ab(1/c)(f^2/2)
y = (a*b)*(1/c)*(f^2/2)

% 7.) The volume of a sphere is given by V = 4*pi*r^3/3, where r is the radius. Use 
%     MATLAB to compute the radius of a sphere having a volume 40 percent
%     greater than that of a sphere of radius 4 ft.
% This problem was solved through the MATLAB Command Window. 
r = 4
V = (4*pi*r^3)/(3)
V1 = 40/100*V+V
syms R
solve(4/3*pi*R^3-V1)

% 9.) Use MATLAB to compute the following. Check your answers by hand. 

% 9a.) (3+6i)(-7-9i)
a = (3+6i)*(-7-9i)

% 9b.) (5+4i)/(5-4i)
b = (5+4i)/(5-4i)

% 9c.) 3/2(i)
c = (3/2)*(i)

% 9d.) 3/(2*i)
d = 3/(2*i)

% 11.) The ideal gas law provides one way to esitmate the pressure exerted
%      by a gas in a container. The law is P = nRT/V 
%      More accurate estimates can be made with the van der Waals equation
%                     P = (nRT/V-nb)-(an^2/V^2)
%      when the term nb is a correction for the volume of the molecules and
%      the term an^2/V^2 is a correction for molecular attractions. The
%      values of a and b depend on the type of gas. The gas constant is R,
%      the absolute temperature is T, the gas volume is V, and the number
%      of gas molecules is indicated by n. If n = 1 mol of an ideal gas
%      were confined to a volume of V = 22.41 L at 0 degree celcius
%      (273.2 K), it would exert a pressure of 1 atm. In these units, 
%      R = 0.08206. 
%           For chlorine (Cl2), a = 6.49 and b = 0.0562. Compare the
%           pressure estimates given by the ideal gas law and the van der
%           Waals equation for 1 mol of Cl2 in 22.41 L at 273.2 K. What is
%           the main cause of the difference in the two pressure estimates,
%           the molecular volume or the molecular attractions?
n = 1, R = 0.08206, T = 273.2, V = 22.41, a = 6.49, b = 0.0562
Pideal = (n*R*T)/V
P1 = (n*R*T)/(V-(n*b))
P2 = (a*n^2)/V^2
Pwaals = P1+P2

%% Section 1.3
% 13.) Suppose x takes on the values x = 1, 1.2, 1.4,...,5. Use MATLAB to
% compute the array y that results from the function y = 7sin(4x). Use
% MATLAB to determine how many elements are in the array y and the value of
% the third element in the array y.

x = 1:0.2:5; % Give the value of x with increment of 0.2.
y = 7*sin(4*x); % Compute the array y by function. 
length(y)
y(3)

% 15.) Use MATLAB to calculate 

% 15a.) e^(-2.1)^3 + 3.47log(14) + 287^(1/4)
A = (((exp(1))^(-2.1))^3)+(3.47*(log10(14)))+(287^(1/4));

% 15b.) (3.4)^7 * log(14) + 287^(1/4)
B = ((3.4)^7)*(log10(14))+(287^(1/4));

% 15c.) cos^2(4.12*pi/6)
C = cos((4.12*pi)/6)^2;

% 15d.) cos(4.12*pi/6)^2
D = cos((4.12*pi/6)^2);

% 17.) The Richer scale is a measure of the intensity of an earthquake. The
%      energy E (in joules) released by the quake is related to the
%      magnitude M on the Richter scale as follows. 
%           E = 10^(4.4)*10^(1.5M)
%      How much more energy is released by a magnitude 7.6 quake than a 5.6
%      quake?
M1 = 7.3; % First Quake Magnitude
M2 = 5.5; % Second Quake Magnitude 
E1 = (10^4.4)*(10^(1.5*M1)); % Energy released by First Quake Magnitude
E2 = (10^4.4)*(10^(1.5*M2)); % Energy released by Second Quake Magnitude
ER = E1-E2; % Energy Difference

% 19.) Use MATLAB to find the roots of the polynomial 70x^3+24x^2-10x+20.
p = [70, 24, -10, 20];
roots(p);

% 21.) Use MATLAB to plot the function T = 6lnt-7e^0.2t over the interval
% 1<(equal) t <(equal) 3. Put a title on the plot and properly label the
% axes. The variable T represents temperature in degrees Celsius; the
% variable t represents time in minutes.
t = 1:0.005:3;
T = 6*log(t)-7*exp(-0.2*t);
plot(t,T)
title('Temperature Versus Time');
xlabel('Time t(min)');
ylabel('Temperature T(Degree Celsius)');

% 23.) The Fourier series is a series representation of a periodic function
%      in terms of sines and cosines. The Fourier series representation of
%      the function
%           f(x) = {1  0 < x < pi} & {-1  -pi < x < 0}
%       is
%       4/pi(sinx/1 + sin3x/3 + sin5x/5 + sin7x/7 + ...)
%     
%       Plot on the same graph the function f(x) and its series
%       representation, using the four terms shown.

x = -pi:0.1:pi; % Give limits to angle. 

% Write first four odd fourier function.
f1 = (4*sin(x))/(pi);
f2 = (4/pi)*((sin(x))+((sin(3*x))/3));
f3 = (4/pi)*((sin(x))+((sin(3*x))/3)+((sin(5*x))/5));
f4 = (4/pi)*((sin(x))+((sin(3*x))/3)+((sin(5*x))/5)+((sin(7*x))/7));

% Plot all functions.
plot(x, f1, x, f2, x, f3, x, f4);
xlabel('f(x)');
legend('n = 1', 'n = 2', 'n = 3', 'n =4 ');
title('Fourier Series');

%% Section 1.4
% 25.) A fence around a field is shaped as shown in Figure P25. It consists
%      of a rectangle of length L and width W and a right triangle that is 
%      symmetric about the central horizontal axis of the rectangle.
%      Suppose the width W is known (in meters) and the enclosed area A is
%      known (in square meters). Write a MATLAB script file in terms of the
%      given variables W and A to determine the length L required so that
%      the enclosed area is A. Also determien the total length of fence
%      required. Test your script for the values W = 6m and A = 80m^2. 

%**********************************************************
% This program is used to find the length of the fence for
% the given width and enclosed area of the fence and also 
% the total length of the fence is evaluated. 
%**********************************************************/
% Get the input of the variables.
% Test value W = 6; A = 80;
W = input('Width ='); % Gets the input of Width. 
A = input('Area ='); % Gets the input of Area.
L = (A-(W^2)/4)/W; % To find the length for the given area. 
disp('The length of the fence is');
% Get input for variable L.
disp(L);
% To find the perimeter of the fence. 
P = (2*L+W+W/(sin(45*pi/180)))
% Display the text of the total length of the fence is.
disp('The total length of the fence is');
% Display the calculated periometer. 
disp(P);

%% Section 1.5
% 27.) Use the MATLAB Help facilities to find information about the
%      following topics and symbols: plot, label, cos, cosine, :, and*.

%% plot
% 2-D line plot

% Syntax
% ------
%   plot(X,Y)
%   plot(X,Y,LineSpec)
%   plot(X1,Y1,...,Xn,Yn)
%   plot(X1,Y1,LineSpec1,...,Xn,Yn, LineSpecn)

%   plot(Y)
%   plot(Y, LineSpec)

%   plot(__, Name, Value)
%   plot(ax,__)

%   h = plot(__)

% Description
% -----------
% plot(X,Y) creates a 2-D line plot of the data in Y versus the
% corresponding values in x. 
%
% * If X and Y are both vectors, then they must have equal length. 
%   The plot function plots Y versus X.
%
% * If X and Y are both matrices, then they must have equal size. 
%   The plot function plots columns of Y versus columns of X.
% 
% * If one of X or Y is a vector and the other is a matrix, then the matrix 
%   must have dimensions such that one of its dimensions equals the vector 
%   length. If the number of matrix rows equals the vector length, then 
%   the plot function plots each matrix column versus the vector. If the 
%   number of matrix columns equals the vector length, then the function 
%   plots each matrix row versus the vector. If the matrix is square, then 
%   the function plots each column versus the vector.
%
% * If one of X or Y is a scalar and the other is either a scalar or a 
%   vector, then the plot function plots discrete points. However, to see 
%   the points you must specify a marker symbol, for example, plot(X,Y,'o').
%
% plot(X,Y,LineSpec) sets the line style, marker symbol, and color.
% plot(___,Name,Value) specifies line properties using one or more Name,
% Value pair arguments. For a list of properties, see Line Properties. 
% Use this option with any of the input argument combinations in the 
% previous syntaxes. Name-value pair settings apply to all the lines plotted.
%
% plot(ax,___) creates the line in the axes specified by ax instead of in 
% the current axes (gca). The option ax can precede any of the input argument 
% combinations in the previous syntaxes.
%
% h = plot(___) returns a column vector of chart line objects. Use h to 
% modify properties of a specific chart line after it is created. For a 
% list of properties, see Line Properties.
%
%% label 
% title - Add title 
% xlabel - Label x-axis
% ylabel - Label y-axis
% zlabel - Label z-axis
% clabel - Label contour plot elevation
%
% legend - Add legend to axes
% colorbar - Colorbar showing color scale 
% 
% text - Add text descriptions to data points 
% texlabel - Format text with TeX characters 
% gtext - Add text to figure using mouse
%
% line - Create primitive line
% rectangle - Create rectangle with sharp or curved corners
% annotation - Create annotations
%
%% cos 
% Syntax
% ------
% Y = cos(x)
% 
% Description
% -----------
% Y = cos(x) returns the cosine for each element of x. The cos function
% operates element-wise on arrays. The function accepts both real and
% complex inputs. For purely real values or imaginary values of x, cos
% returns real values in the interval [-1,1]. For complex values of x, cos
% returns complex values. All angles are in radians. 
% 
%% cosine
% Plot the cosine function over the domain -pi <(equal) x <(equal) pi.
x = -pi:0.01:pi;
plot(x,cos(x))
grid on
%
%% colon,(:)
% Vector creation, array subscription, and for-loop iteration.
%
%% mtimes, *
% Matrix Multiplication 
% 
% Syntax
% ------
% C = A*B
% C = mtimes(A,B)
%% 
% 29.) Use the MATLAB Help facilities to determine what happens if you use
%      the exp function with an imaginary argument. 
%
% Syntax 
% ------
% Y = exp(X)
%
% Description
% -----------
% Y = exp(X) returns the exponential e^x for each element in array X. For
% complex elements z = x + iy, it returns the complex exponential 
%       e^z = e^x(cosy + isiny).
% Use expm to compute a matrix exponential. 
exp(1)
Y = exp(1i*pi)
%
%% Section 1.6
% 31.) Consider the motion of the piston discussed in Example 1.6 - 1. The
%      piston stroke is the total distance moved by the piston as the crank
%      angle varies from 0 to 180 degrees.
%           a. How does the piston stroke depend on L1 and L2?
%           b. Suppose L2 = 0.5 ft. Use MATLAB to plot the piston motion
%              versus crank angle for two cases: L1 = 0.6 ft and 
%              L1 = 1.4 ft. Compare each plot with the plot shown in Figure
%              1.6-3. Discuss how the shape of the plot depends on the
%              value of L1.
%
%*********************************************************
% A matlab code to plot the distance moved by versus the 
% crank angle for the two different length of the piston.
%*********************************************************
L11 = 0.6; % Declaration of value. 
L12 = 1.4; % Declaration of value. 
L2 = 0.5; % Declaration of value. 

R1 = L2/L11; % Computes the value.
R2 = L2/L12; % Computes the value.
A_d = 0:180; % Declaration of angle. 
B1 = asin(R1*sin(A_d*pi/180)); % Computes the value. 
B2 = asin(R2*sin(A_d*pi/180)); % Computes the value.
d1 = L11*cos(B1)+L2*cos(A_d*pi/180); % Computes the value.
d2 = L12*cos(B2)+L2*cos(A_d*pi/180); % Computes the value.
plot(A_d, d1, A_d, d2); 
grid on;
xlabel('Angle in degrees'); % Assigns text to x-axis.
ylabel('Displacement'); % Assigns text to y-axis. 

