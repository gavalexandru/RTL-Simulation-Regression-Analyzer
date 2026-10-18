module tb_fifo;
    localparam int DATA_WIDTH = 8;
    localparam int DEPTH = 4;

    logic clk = 0;
    logic rst_n = 0;
    logic wr_en = 0;
    logic rd_en = 0;
    logic [DATA_WIDTH-1:0] din = '0;
    logic [DATA_WIDTH-1:0] dout;
    logic full;
    logic empty;

    fifo #(.DATA_WIDTH(DATA_WIDTH), .DEPTH(DEPTH)) dut (
        .clk(clk), .rst_n(rst_n), .wr_en(wr_en), .rd_en(rd_en),
        .din(din), .dout(dout), .full(full), .empty(empty)
    );

    always #5 clk = ~clk;

    task automatic tick;
        @(posedge clk);
        #1;
    endtask

    task automatic fail(input string message);
        $display("FAIL: %s", message);
        $fatal(1);
    endtask

    initial begin
        $display("TEST_START fifo_basic");
        repeat (2) tick();
        rst_n = 1;
        tick();

        if (!empty) fail("FIFO should be empty after reset");
        if (full) fail("FIFO should not be full after reset");

        // Fill FIFO with 10, 20, 30, 40.
        for (int i = 1; i <= DEPTH; i++) begin
            @(negedge clk);
            wr_en = 1;
            din = i * 10;
            tick();
        end
        @(negedge clk);
        wr_en = 0;
        if (!full) fail("FIFO should be full after DEPTH writes");

        // Attempted write while full must not alter stored sequence.
        @(negedge clk);
        wr_en = 1;
        din = 8'hEE;
        tick();
        @(negedge clk);
        wr_en = 0;

        // Read back in FIFO order.
        for (int i = 1; i <= DEPTH; i++) begin
            rd_en = 1;
            tick();
            if (dout !== i * 10)
                fail($sformatf("Expected %0d, got %0d", i * 10, dout));
        end
        @(negedge clk);
        rd_en = 0;
        if (!empty) fail("FIFO should be empty after reading all items");

        $display("PASS: fifo_basic");
        $finish;
    end
endmodule
