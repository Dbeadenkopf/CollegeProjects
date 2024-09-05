// David Beadenkopf
// email: beadenk1@umbc.edu

module testDemorgan();
   
   reg [1:0] I;
   wire      W;
   integer   file;
   proveDemorgan circuit(W, I[1] ,I[0]);
   initial
     begin
	file = $fopen("output3.txt");
	

	I = 1'b0;
	
	
	// two bit input
	repeat (3) #10 I = I+1'b1;
	
	
	                         // adding one bit every occurance
	
     end // initial begin
   initial
     $fmonitor(file, "AB=%b  output = %b", I,W);
   
   
   
endmodule // testAdder

