module fifo #(
    parameter int DATA_WIDTH = 8,
    parameter int DEPTH = 4,
    parameter int ADDR_WIDTH = $clog2(DEPTH)
) (
    input  logic                  clk,
    input  logic                  rst_n,
    input  logic                  wr_en,
    input  logic                  rd_en,
    input  logic [DATA_WIDTH-1:0] din,
    output logic [DATA_WIDTH-1:0] dout,
    output logic                  full,
    output logic                  empty
);
    logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];
    logic [ADDR_WIDTH-1:0] wr_ptr;
    logic [ADDR_WIDTH-1:0] rd_ptr;
    int unsigned count;

    assign full  = (count == DEPTH);
    assign empty = (count == 0);

    always_ff @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            wr_ptr <= '0;
            rd_ptr <= '0;
            count  <= 0;
            dout   <= '0;
        end else begin
            // A write is accepted only when not full.
            if (wr_en && !full) begin
                mem[wr_ptr] <= din;
                if (wr_ptr == DEPTH-1)
                    wr_ptr <= '0;
                else
                    wr_ptr <= wr_ptr + 1'b1;
            end

            // A read is accepted only when not empty.
            if (rd_en && !empty) begin
                dout <= mem[rd_ptr];
                if (rd_ptr == DEPTH-1)
                    rd_ptr <= '0;
                else
                    rd_ptr <= rd_ptr + 1'b1;
            end

            case ({wr_en && !full, rd_en && !empty})
                2'b10: count <= count + 1;
                2'b01: count <= count - 1;
                default: count <= count;
            endcase
        end
    end
endmodule
