import java.util.List;

import week_5.BinaryWatch;

public class App {
    public static void main(String[] args) throws Exception {
        BinaryWatch cla = new BinaryWatch();
        List<String> res = cla.readBinaryWatch(8);
        System.out.println(res);
    }
}
