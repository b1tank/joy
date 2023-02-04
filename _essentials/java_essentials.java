package _essentials;

import java.util.ArrayList;

class Main {
    public static void main (String[] args) {
        // Number
        int i = 3;
        Integer ii = 5;

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

        sbd.append(str3);
        sbd.insert(1, str);
        sbd.delete(0, 2); // start, end-1 (inclusive)
        sbd.deleteCharAt(1);
        sbd.replace(2, 6, str3);
        sbd.reverse();
        sbd.toString();
        sbd.setLength(0); // clear
        sbd.ensureCapacity(i);
    }
}