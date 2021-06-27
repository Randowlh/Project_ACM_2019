module top(
    input clk,
    input rst,
    input CPSR_6,
    input CPSR_7,
    input EX_irq,
    input EX_fiq,
    
    output INT_irq,
    output INT_fiq,
    output INTA_irq,
    output INTA_fiq,
    output [1:0]PC_s,
    output [31:0]PC
    );
    
    wire [31:0] PC_in;
    
    
    request request(
        .rst(rst),
        .CPSR_6(CPSR_6),
        .CPSR_7(CPSR_7),
        .INTA_irq(INTA_irq),
        .INTA_fiq(INTA_fiq),
        .EX_irq(EX_irq),
        .EX_fiq(EX_fiq),
        .INT_irq(INT_irq),
        .INT_fiq(INT_fiq)
    );
    
    decode decode_mod(
        .clk(clk),
        .INT_irq(INT_irq),
        .INT_fiq(INT_fiq),
        .INTA_irq(INTA_irq),
        .INTA_fiq(INTA_fiq),
        .PC_s(PC_s)
    );
    
endmodule


module request(
    input rst,
    input CPSR_6,
    input CPSR_7,
    input INTA_irq,
    input INTA_fiq,
    input EX_irq,
    input EX_fiq,
    
    output INT_irq,
    output INT_fiq,
    output Q_irq,
    output Q_fiq
    );
    wire INT_irq_tmp;
    //wire Q;
    d_flip_flop D_fiq1(
        .d(1'b1),
        .clk(~CPSR_6),
        .clr(INTA_fiq + rst),
        .q(Q_fiq)
    );
    d_flip_flop D_fiq2(
        .d(Q_fiq),
        .clk(EX_fiq),
        .clr(INTA_fiq + rst),
        .q(INT_fiq)
    );
    
    d_flip_flop D_irq1(
        .d(1'b1),
        .clk(~CPSR_7),
        .clr(INTA_irq + rst),
        .q(Q_irq)
    );
    
    d_flip_flop D_irq2(
        .d(Q_irq),
        .clk(EX_irq),
        .clr(INTA_irq + rst),
        .q(INT_irq_tmp)
    );
    
    assign INT_irq = ~INT_fiq * INT_irq_tmp;
endmodule

module decode(
    input clk,
    input INT_irq,
    input INT_fiq,
    
    output reg INTA_irq,
    output reg INTA_fiq,
    output reg [1:0]PC_s
    );
    always@(posedge clk) begin
        if(INT_irq) begin
            INTA_irq <= 1;
            PC_s <= 2'b11;
        end
        else if(INT_fiq) begin
            INTA_fiq <= 1;
            PC_s <= 2'b11;
        end
        else begin
            INTA_irq <= 0;
            INTA_fiq <= 0;
            PC_s <= 2'b00;
        end
    end
endmodule

module d_flip_flop(
    input d,
    input clk,
    input clr,
    output reg q
    );
        
    always@ (posedge clk or posedge clr) begin
        if(clr) begin
            q <= 0; 
        end
        else begin
            q <= d;
        end
    end
    
endmodule