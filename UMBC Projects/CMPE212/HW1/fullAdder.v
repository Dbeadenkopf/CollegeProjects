// Name: David Beadenkopf
// Class: CMPE212
// Discussion: 01
// email: beadenk1@umbc.edu


// 3 carries in total

module fulladder(S, Carr, a, b, Cin);

   input a, b, Cin;

   output S, Carr;

      //

   wire   Carry1, Carry2, Sum1;

      // calling our first module?
   halfAdder2 circuit1(Carry1, Sum1,a ,b);


   halfAdder2 circuit2(Carry2, S, Cin, Sum1);


      // the or gates Carr, then the outputs
      // are both carrys, carry1 and carry2
   or(Carr, Carry1, Carry2);

endmodule // fulladder
