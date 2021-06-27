module top(
    input clk,
    input SP_in,
    input SP_out,
    input [4:0] M,
    input [31:0]SP,
    
    output reg [31:0] SP_tmp,
    output reg [31:0] PSP,
    output reg [31:0] MSP
    );
    
    
    always @(posedge clk) begin
        if (SP_out && M[4]) begin
            case(M[3:0])
                4'd0: PSP <= SP;
                4'd1: MSP <= SP;
                4'd2: MSP <= SP;
                4'd3: MSP <= SP;
                4'd6: MSP <= SP;
                4'd7: MSP <= SP;
                4'd10: MSP <= SP;
                4'd11: MSP <= SP;
                4'd15: MSP <= SP;
                default:;
            endcase
        end 
        
        if (SP_in && M[4]) begin
            case(M[3:0])
                4'd0: SP_tmp <= PSP;
                4'd1: SP_tmp <= MSP;
                4'd2: SP_tmp <= MSP;
                4'd3: SP_tmp <= MSP;
                4'd6: SP_tmp <= MSP;
                4'd7: SP_tmp <= MSP;
                4'd10: SP_tmp <= MSP;
                4'd11: SP_tmp <= MSP;
                4'd15: SP_tmp <= MSP;
            endcase
        end
    end
endmodule 