// David Beadenkopf
// email: beadenk1@umbc.edu
module proveDemorgan(O, A, B);
   input A,B;
   output O;
   wire  W;
   not(W,A);
   and(O,W,B,A);
endmodule