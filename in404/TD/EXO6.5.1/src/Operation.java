enum Operations {

    ADD("+") {
        public int eval(int a, int b) { return a + b; }
    },
    SUBTRACT("-") {
        public int eval(int a, int b) { return a - b; }
    },
    MULTIPLY("*") {
        public int eval(int a, int b) { return a * b; }
    },
    DIVISE("/") {
        public int eval(int a, int b) { return a / b; }
    };

    public String symbole;

    Operations(String symbole)
    {
        this.symbole = symbole;
    }

    public abstract int eval(int a, int b);
}