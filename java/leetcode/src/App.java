import week_3.ValidUtf8;
import week_5.BinaryWatch;

public class App {
    public static void main(String[] args) throws Exception {
        var cla = new BinaryWatch();
        var res = cla.readBinaryWatch(8);
        System.out.println(res);
    }
}
