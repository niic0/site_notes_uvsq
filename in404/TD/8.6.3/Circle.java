public class Circle extends Shape {
    int radius;

    /*
     * place the circle in the window and adding a radius to him
     */
    Circle(String shapeName, int x, int y, int radius){
        super(shapeName, x, y);
        this.radius = radius;
    }

    /*
     * Change the radius of the circle
     */
    void changeRadius(int radiusModify){
        this.radius = radiusModify;
    }
}
