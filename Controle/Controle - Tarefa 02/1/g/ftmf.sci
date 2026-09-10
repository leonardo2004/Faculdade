function [] = ftmf()
    C = 100E-6;
    R = 10E3;
    H_s = 1;
    s = %s;
    den = R*C*s+1+H_s+C_s;
    num = C_s;
    H = syslin('c', num/den);
    plzr(H);
endfunction
