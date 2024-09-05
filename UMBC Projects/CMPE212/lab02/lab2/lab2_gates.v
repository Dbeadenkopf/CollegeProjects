// Name: David Beadenkopf
// Email: beadenk1@umbc.edu
// The module represents a design process
module lab2(O, I0, I1, I2);
// three 1 bit wide inputs
input I1, I2, I0;
output O;
   wire w;
   or(w, I0, I1);
   and(O, I2, w);

endmodule
