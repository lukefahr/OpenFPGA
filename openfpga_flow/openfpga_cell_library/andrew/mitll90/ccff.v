/**
 * Wrapper module for DFF w/Q and QN
 */

`include "/l/research/pdks/MITLL/MITLL90_STDLIB_8T/2019.12.20/MITLL90_STDLIB_8T.v"

module dffqn_1x (
    input D, 
    input CLK, 
    input RST, 
    output Q, 
    output QN
    );
    
    wire RN;
    
    inv_1x(RST,RN);
    inv_1x(Q,QN);

    dffrq_1x dff (
        .Q(Q), 
        .CLK(CLK), 
        .D(D), 
        RN(RN)
    );

endmodule
