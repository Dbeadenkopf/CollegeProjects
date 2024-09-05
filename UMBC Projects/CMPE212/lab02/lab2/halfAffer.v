// simple half adder module
// email: beadenk1@umbc.edu
module halfAffer(C,S,A,B);
   input A,B;
   output S,C;
   xor(S,A,B);
   and(C, A, B);
endmodule