// Name: David Beadenkopf
// Email: beadenk1@umbc.edu


module testbench;
   reg [2:0] I;
   
   wire w;
   
   prac discussionGate(w, I[0],I[1],I[2]);
   initial
   begin  
      file = $fopen("lab2_out.txt");

      I = 3'b000;
      #10 I = I +1'b1;
      
   end
   initial
     $fmonitor(file, "AB = %b lab2 Output = %b", I, O);
endmodule