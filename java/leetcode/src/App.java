import week_3.ValidUtf8;

public class App {
    public static void main(String[] args) throws Exception {
        int[] data = {197, 130, 1};
        var cla = new ValidUtf8();
        var res = cla.validUtf8(data);
        System.out.println(res);
    }
}
