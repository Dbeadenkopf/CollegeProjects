module testbenchPrac;
   // in terms of memmory for the registers
   // array of addresses
   reg [2:0] switches;
   wire      y;
   //            This part of register is connected as output
   //            here-V// combing into a bus switches
   prac f1(y,switches);
   
   initial // starts intalize all varibles 
     begin
	// 3 in binary format (`) will seperate it
	switches = 3'b000;	
	$display("switches=ABC\n");
	#90 $finish;
	// wait 90 timesteps
     end
   
   always // always running(hardware running unless stopping)
     begin
	switches = switches + 1'b1;
	//                     same declaration from before
	//                     defing what we are adding here
	//                     acounting for decimal one and other formats
	#10 $display("swicthes=%b, y=%b", switches,y);
     end
endmodule // testbenchPrac

   