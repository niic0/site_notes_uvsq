public class Rectangle extends Shape {
    int sizex;
    int sizey;

    /*
     *         <shapeName> : Name of the rectangle
     *             <x> <y> : Location on the window
     *     <sizex> <sizey> : size x and y of the rectangle
     */
    Rectangle(String shapeName, int x, int y, int sizex, int sizey){
        super(shapeName, x, y);
        this.sizex = sizex;
        this.sizey = sizey;
    }

    /*
     * Change the size x and y of the rectangle
     */
    void changeSize(int sizexModify, int sizeyModify){
        this.sizex = sizexModify;
        this.sizey = sizeyModify;
    }
}
