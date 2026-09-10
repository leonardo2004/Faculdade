function [] = ftplanta()
    C = 100E-6;
    L = 100;
    s = %s;
    den =(L*C)*(s**2+s*(R/L)+1/(C*L))
    num =1
    H = syslin('c', num/den);
    plzr(H);
endfunction
