module Dflip(Clk,D,Q);
   input Clk,D;
   output Q;
   reg 	  Q;
   
   always @ (posedge Clk)
     begin
	Q <= D;
     end
endmodule // Dflip

	  
  