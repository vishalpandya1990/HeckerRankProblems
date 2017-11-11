import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

/*
 * Problem statement :- https://www.hackerrank.com/challenges/pythagorean-triple/problem
 */

public class Solution {

    static long[] pythagoreanTriple(long a){
        long[] res = {a, -1, -1};
        if(a%2 == 1) {
            long k = (a-1)/2;
            res[1] = 2*k*(k+1);
            res[2] = 2*k*(k+1) + 1;
        } else {
            long k2 = (a/2)*(a/2);
            res[1] = k2+1;
            res[2] = k2-1;
        }
        return res;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long a = in.nextLong();
        long[] triple = pythagoreanTriple(a);
        for (int i = 0; i < triple.length; i++) {
            System.out.print(triple[i] + (i != triple.length - 1L ? " " : ""));
        }
        System.out.println("");
    }
}
