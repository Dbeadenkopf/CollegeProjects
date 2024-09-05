


module testFullAdder();
   reg [2:0] I;
   
   wire      Sum, Carr;
   
   integer   file;
   
   fulladder circuit1(Sum, Carr, I[2],I[1], I[0]);
   
   initial
     begin
	file = $fopen("output.txt");
	I = 2'b00;
	
	// two bit input
	// b for bits 1 and 0
	repeat (7) #10 I = I+1'b1;
	
	// adding one bit every occuranc
     end // initial begin
   initial
     $fmonitor(file, "ABCin=%b  output = %b", I, Sum,Carr);   
endmodule // testFullAdder


   

   