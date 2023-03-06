package week_7;

class ValidWordAbbreviation {
    public boolean validWordAbbreviation(String word, String abbr) {
        // subway
        // s3a1
        // 6
        // 4
        int m = word.length();
        int n = abbr.length();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (Character.isDigit(abbr.charAt(j))) {
                if (abbr.charAt(j) == '0') return false;
                int k = j;
                StringBuilder sb = new StringBuilder();
                while (k < n && Character.isDigit(abbr.charAt(k))) {
                    sb.append(abbr.charAt(k));
                    k++;
                }
                int num = Integer.parseInt(sb.toString());
                i += num;
                j = k;
            } else {
                if (abbr.charAt(j) != word.charAt(i)) return false;
                i++;
                j++;
            }
        }
        
        return i == m && j == n;
    }
}