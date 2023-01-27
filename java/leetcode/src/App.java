import week_2.*;

public class App {
    public static void main(String[] args) throws Exception {
        int[][] a = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
        var f = new IsRectangleCover();
        boolean r = f.isRectangleCover(a);
        System.out.println(r);
    }
}
