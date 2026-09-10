function [] = ftplanta()
    s = %s;
    C = 100E-6;
    den = s+(1/(R*C));
    num = 1/(R*C);
    H = syslin('c', num/den);
    plzr(H);
endfunction
