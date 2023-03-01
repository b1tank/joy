import week_6.ToHex;

public class App {
    public static void main(String[] args) throws Exception {
        ToHex cla = new ToHex();
        String res = cla.toHex(-1);
        System.out.println(res);
    }
}
