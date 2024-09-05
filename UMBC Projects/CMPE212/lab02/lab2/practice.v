
module discussionGate(O,A,B,C)
  input A,B,C;
  output O;
   wire  W;
   or(W,B,C);
   and(O,A,W);
   
endmodule