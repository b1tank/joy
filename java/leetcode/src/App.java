import week_6.ReconstructQueue;
import week_6.ToHex;

public class App {
    public static void main(String[] args) throws Exception {
        int[][] people = {{7, 0}, {7, 1}, {6, 1}, {5, 0}, {5, 2}, {4, 4}};
        ReconstructQueue cla = new ReconstructQueue();
        int[][] res = cla.reconstructQueue(people);
        System.out.println(res);
    }
}
