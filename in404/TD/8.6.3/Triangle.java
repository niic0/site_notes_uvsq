public class Triangle extends Shape {
    int size;

    /*
     * Adding a triangle of size <size> at position x y on the window
     */
    Triangle(String shapeName, int x, int y, int size){
        super(shapeName, x, y);
        this.size = size;
    }

}
