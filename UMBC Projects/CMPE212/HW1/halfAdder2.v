// Name: David Beadenkopf
// Email: beadenk1@umbc.edu
// Class: CMPE212
// Discussion: 01
module halfAdder2(C,S,A,B);
   input A,B;
   output S,C;
   xor(S,A,B);
   and(C, A, B);
endmodule // halfAffer2


