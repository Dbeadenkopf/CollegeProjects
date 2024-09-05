// David Beadenkopf
// email: beadenk1@umbc.edu
module Simplify(O,A, B, C, D);
   input A, B, C, D;
   output O;
   wire   W1,W2,W3,W4,W5, W6, W7;
   not(W1,A);
   not(W2,B);
   not(W3,D);
   not(W4,C);
   and(W1,W2,W3);
   and(C,W4);
   and(A,B,D,C);
   and(W2,W3);
   or(O,A, B,D, D);
endmodule // simplify
   
   

 