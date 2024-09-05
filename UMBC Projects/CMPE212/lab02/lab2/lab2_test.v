// Name: Patrick Sykes
// Email: psykes1@umbc.edu


module lab2test; 
   reg [2:0] I;
   // an 8 bit regester vector
   // individual bits: test[2] .... test[0]
   // by////   
   wire w;
   // 16bit wire vector net1, does not take
   // input because it needs to be driven
   // also represents physical wires that connect module
   integer file;
   
	lab2 circuit1(w, I[0], I[1], I[2]);

	initial
	begin
		file = $fopen("lab2_out.txt");
	   
	   I = 3'b000;	
		repeat(7) #10 I = I + 1'b1;
	end
	initial
		$fmonitor( file, "AB = %b   lab2 Output = %b", I, O);

endmodule
