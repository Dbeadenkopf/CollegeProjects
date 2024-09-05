// David Beadenkopf
// email: beadenk1@umbc.edu
module simplifytest();

   reg [3:0] I;

   wire  W;

   integer   file;

    Simplify circuit(W, I[3] , I[2], I[1], I[0]);

      initial
	begin
	   file = $fopen("output2.txt");

	   I = 1'b0;

	           // two bit input
	   repeat (15) #10 I = I+1'b1;

	           // adding one bit every occurance

	end // initial begin
      initial
	$fmonitor(file, "AB=%b  output = %b", I,W);


endmodule // testAdder
