module top(
    input clk,
    input rst,
    input [31:0] IR,
    
    output reg Write_PC,
    output reg Write_IR,
    output reg Write_CPSR,
    output reg S,
    output reg SP_in,
    output reg SP_out,
    output reg [1:0] W_Rdata_s,
    output reg [2:0] W_CPSR_s,
    output reg [3:0] PC_s,
    output reg [3:0] ALU_OP
    );
    reg [4:0] ST,Next_ST;
    
    parameter 
        Idle = 6'b000000,
        S0 = 6'b000001,
        S1 = 6'b000010,
        S26 = 6'b011011,
        S27 = 6'b011100,
        S28 = 6'b011101;
    
    always @(posedge rst or posedge clk)  begin
	  if (rst) ST <= Idle;
      else  ST <= Next_ST;
    end
    
    always @(*) begin	
        Next_ST = Idle;
        case (ST)
            Idle: Next_ST = S0;
            S0: Next_ST = S1;
            S1:
                if(IR[15:12] == 4'hf && IR[3:0] == 4'he && IR[27:25] == 3'b000) begin
                    Next_ST = S28;
                end
            S27: 
                Next_ST = S0;
            S28: Next_ST = S26;
            S26: Next_ST = S27;
            default:  Next_ST = S0; 
        endcase
    end
    
    
    always @(posedge rst or posedge clk) begin
        if (rst) begin
            Write_PC <= 0;
            Write_IR <= 0;
            Write_CPSR <= 0;
            S <= 0;
            SP_in <= 0;
            SP_out <= 0;
            W_Rdata_s <= 0;
            W_CPSR_s <= 0;
            PC_s <= 0;
            ALU_OP <= 0;
        end
        else
            Write_PC <= 0;
            Write_IR <= 0;
            Write_CPSR <= 0;
            S <= 0;
            SP_in <= 0;
            SP_out <= 0;
            W_Rdata_s <= 0;
            W_CPSR_s <= 0;
            PC_s <= 0;
            ALU_OP <= 0;
            
            case(Next_ST)
                S0: begin
                    Write_PC <= 1;
                    PC_s <= 3'b000;
                    Write_IR <= 1;
                end
                S1:;
                S26: begin
                   W_Rdata_s <= 0;
                   Write_CPSR <= 1;
                   W_CPSR_s <= 0;
                   S <= 0;
                   PC_s <= 2'b01;
                   SP_out <= 1;
                   SP_in <= 0;
                end
                S27: begin
                    SP_in <= 1;
                    SP_out <= 0;
                end
                S28: begin //MOVS
                   ALU_OP <= 4'b1000; 
                   S <= 1;
                end
            endcase
    end
endmodule