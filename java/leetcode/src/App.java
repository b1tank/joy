import random.*;

public class App {
    public static void main(String[] args) throws Exception {
        int[] nums = {7, 2, 5, 10, 8};
        SplitArray cla = new SplitArray();
        int res = cla.splitArray(nums, 3);
        System.out.println(res);
    }
}
