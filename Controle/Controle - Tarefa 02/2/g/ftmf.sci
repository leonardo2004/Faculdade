function [] = ftmf()
    C = 100E-6;
    L = 100;
    H_s = 1;
    s = %s;
    den = L*C*(s**2+s*(R/L)+1/(L*C))+H_s*C_s;
    num = C_s;
    H = syslin('c', num/den);
    plzr(H);
endfunction
