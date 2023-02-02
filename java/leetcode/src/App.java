import week_2.*;
import week_3.DecodeString;

public class App {
    public static void main(String[] args) throws Exception {
        var s = "3[a]";
        var cla = new DecodeString();
        var res = cla.decodeString(s);
        System.out.println(res);
    }
}
