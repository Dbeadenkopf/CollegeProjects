// David Beadenkopf
// lab 10


// test bench 
module testDflip();
   reg clk;
   reg D; //
   wire Q; // wire connects them
   Dflip mod(clk,D, Q);
   
   //$shm_open("filename.shm")
     initial begin
	//fork
	$display;
	
	$shm_open("filename.shm");
	
	  
	clk = 0;
	// time one to time nine
	# 1 D = 1;
	# 9 D = 0;
	$shm_probe(clk, D, Q);
	
	//join
	# 9  
	  $shm_close();
	$finish;
	
	
     end // initial begin
  
   always
     // the clock input does not equal the clk input
     #5 clk = ~clk;
   
endmodule
	    