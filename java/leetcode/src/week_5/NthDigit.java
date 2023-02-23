package week_5;

class NthDigit {
    public int findNthDigit(int n) {
        long powerOf10 = 1;
        int lengthOfNumber = 1;
        int remained = n;
        while (remained > 9 * powerOf10 * lengthOfNumber) {
            remained -= 9 * powerOf10 * lengthOfNumber;
            powerOf10 *= 10;
            lengthOfNumber++;
        }
        
        long target = powerOf10 + remained / lengthOfNumber; // int overflow
        int digitLocation = remained % lengthOfNumber;
        if (digitLocation == 0) {
            target--;
            digitLocation = lengthOfNumber;
        }
        
        return Long.toString(target).charAt(digitLocation-1) - '0';
    }
};