

module testAdder();
   reg [1:0] I;
   wire      S,C;
   integer   file;
   halfAffer circuit(C, S , I[1], I[0]);
   initial
     begin
	file = $fopen("output.txt");
	I = 1'b0;
	// two bit input 
	repeat (3) #10 I = I+1'b1;
	// adding one bit every occurance

     end
   initial
    $fmonitor(file, "AB=%b  output = %b", I, S,C);
   
endmodule 
 