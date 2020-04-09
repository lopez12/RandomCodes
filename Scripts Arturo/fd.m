function [sinderivar]=fd(xi,xi1)
    sinderivar=xi1-velocidad(xi1)*(xi1-xi)/(velocidad(xi1)-velocidad(xi));
end