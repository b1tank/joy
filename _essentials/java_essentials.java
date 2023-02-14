package _essentials;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Random;
import java.util.Stack;

class Main {
    /**
     * @param args
     */
    public static void main (String[] args) {
        // Number
        int i = 3;
        Integer ii = 5;
        Integer ma = Integer.MAX_VALUE;
        Integer mi = Integer.MIN_VALUE;

        ii.compareTo(i);
        ii.shortValue();
        ii.floatValue();
        ii.doubleValue();
        ii.byteValue();
        ii.equals(i);

        Integer i3 = Integer.valueOf("19");
        int i4 = Integer.parseInt("19");

        Integer.toString(12);
        ii.toString();

        Integer.decode("0xff");

        short j = 3;
        long k = 3;
        float f = 2.0f;
        double d = 2.0d;
        byte mask = 0x7f;

        int binary = 0b00000111; // binary literal

        // Math
        Math.min(f, i);
        Math.max(f, i);

        Math.random();

        Math.sqrt(f);
        Math.pow(f, 2);
        Math.exp(f); // e^f

        Math.abs(f);
        Math.ceil(f);
        Math.floor(f);
        Math.rint(f);
        Math.round(f);

        Math.toDegrees(f);
        Math.toRadians(f);

        // random
        Random rand = new Random();
        int r = rand.nextInt(1000); // 0-999
        double rd = rand.nextDouble(); // 0-1
        double rd2 = Math.random(); // 0-1

        // char and Character
        char ch = 'a';
        char uniChar = '\u03A9';
        char[] charArray = {'a', 'b', 'c'};
        Character c = new Character(ch);
        Character.isLetter(ch);
        Character.isDigit(ch);
        Character.isWhitespace(ch);
        Character.isUpperCase(ch);
        Character.isLowerCase(ch);
        Character.toUpperCase(ch);
        Character.toLowerCase(ch);
        Character.toString(ch);
        System.out.println("I love \"Java\"");

        // String and CharSequence
        CharSequence cs = "hello";
        String str = new String(charArray);
        String str2 = new String("Hello");

        str.length();
        str.charAt(0);

        str.concat(str2);
        "World".concat(str2);
        String str3 = str + str2;

        System.out.printf("%f, %d, %s", f, i, str);
        String fs = String.format("%f, %d, %s", f, i, str);
        System.out.println(fs);

        String substr = str.substring(1, 2); // start, end
        String substr2 = str.substring(1); // start, end
        CharSequence charSequence = str3.subSequence(0, 2);
        str.toCharArray();

        String[] strs = str3.split("sa", 2);
        str.trim();

        str.toUpperCase();
        str.toLowerCase();

        str.indexOf('a');
        str.lastIndexOf('a');
        str.indexOf('a', 1);
        str.lastIndexOf('a', 1);
        str.indexOf("abc");
        str.lastIndexOf("abc");
        str.indexOf("abc", 1);
        str.lastIndexOf("abc", 1);

        str.contains(charSequence);

        str.replace('a', 'b');
        str.replace(charSequence, charSequence);
        str.replaceAll("xy.+", "abc");
        str.replaceFirst("xy.+", "abc");

        str.compareTo(str3);
        str.compareToIgnoreCase(str3);
        str.equals(str3);
        str.equalsIgnoreCase(str3);

        StringBuffer sbu = new StringBuffer();
        str.contentEquals(sbu);

        String str4 = String.copyValueOf(charArray);
        String str5 = String.copyValueOf(charArray, 2, 3);
        
        str.startsWith("abc");
        str.endsWith("xyz");

        str.getBytes();
        str.getChars(1, 3, charArray, 2);

        str.hashCode();

        str.matches("xy.+");

        // StringBuilder(faster) (used in single-thread env)
        // StringBuffer(slower, thread-safe and synchronized) (used in multi-threaded env)
        StringBuilder sbd = new StringBuilder();
        StringBuilder sbd2 = new StringBuilder(charSequence);
        StringBuilder sbd3 = new StringBuilder(20);
        StringBuilder sbd4 = new StringBuilder(str);

        sbd.length();
        sbd.append(str3);
        sbd.insert(1, str);
        sbd.delete(0, 2); // start, end-1 (inclusive)
        sbd.deleteCharAt(1);
        sbd.replace(2, 6, str3);
        sbd.reverse();
        sbd.toString();
        sbd.setLength(0); // clear
        sbd.ensureCapacity(i);

        for (char c1 : str.toCharArray()) {
            System.out.println(c1);
        }

        // static methods of Arrays class
        int[] data = {197, 125, 3};
        Integer[] data2 = {197, 125, 3};
        List<Integer> li = Arrays.asList(data2);
        List<Integer> li0 = Arrays.asList(1, 34, 56);
        Arrays.sort(data2, 0, 2);
        int index = Arrays.binarySearch(data2, 34);
        System.out.println("34 found the key at the index = " + index);
        int[] newl = Arrays.copyOf(data, 10);
        Arrays.fill(newl, 11);
        Arrays.toString(newl);

        // Array and ArrayList
        int l = data.length; // array length is a field
        // List<Integer> li = Arrays.asList(data); // compile error
        List<Integer> li1 = new ArrayList<Integer>();
        li.add(0, 1);
        li.add(1, 2);
        List<Integer> li2 = new ArrayList<Integer>();
        li2.add(3);
        li2.add(4);
        li.addAll(1, li2);
        li.remove(1);
        li.set(0, 5);
        li.size();
        for (int i0=0; i0<li.size(); i0++) {
            System.out.println(li.get(i0));
        }
        for (int i1 : li) {
            System.out.println(i1);
        }
        li.clear();
        li.equals(li2);
        li.isEmpty();
        li.contains(2);
        li.containsAll(li2);
        li.indexOf(3);
        li.lastIndexOf(3);
        li.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer a, Integer b) {
                return a - b;
            }
        });
        li.sort((a, b) -> a - b);

        // stack
        Stack st = new Stack<Integer>();
        st.push(1);
        Integer stp = (Integer) st.pop();
        Integer stk = (Integer) st.peek();
        st.empty();
        int pos = st.search(i);

        // dequeue and priority queue (heap)
        Queue<String> deque = new ArrayDeque<>();
        PriorityQueue<String> sbq =new PriorityQueue<String>(); // String is comparable by default
        boolean suc = sbq.add("Amit"); // if unsuccessful, throw exception
        boolean suc2 = sbq.offer("Amit"); // if unsuccessful, return false
        sbq.remove();
        sbq.poll(); // return null if empty
        sbq.element();
        sbq.peek(); // return null if empty

        PriorityQueue<int[]> heap = new PriorityQueue<int[]>(5, new CustomComparator());

        // HashSet
        HashSet hs = new HashSet<Integer>();
        hs.add(1);
        hs.contains(2);
        hs.remove(2);
        hs.clear();

        // HashMap
        HashMap hm = new HashMap<Integer, String>();
        hm.put(1, "amy");
        hm.get(1);
        hm.remove(1);
        hm.clear();
    }

    static class CustomComparator implements Comparator<int[]> {
        public int compare(int[] s1, int[] s2) {
            if (s1[0] > s2[0]) {
                return 1;
            } else if (s1[0] < s2[0]) {
                return -1;
            } else {
                if (s1[1] > s2[1]) {
                    return 1;
                } else if (s1[1] < s2[1]) {
                    return -1;
                } else {
                    return 0;
                }
            }
        }
    }
}