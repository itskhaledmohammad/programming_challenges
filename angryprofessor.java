/* AUTHOR: Khaled Mohammad
 * DATED: October 22, 2016.
 * git: https://github.com/itskhaledmohammad
 * twitter: https://twitter.com/itskhaledmd (@itskhaledmd)
 *
 * It is a programming contest practice problem from HackerRank.
 * Link to Problem: https://www.hackerrank.com/challenges/angry-professor
 *
 */

import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {

        // Initialization
        int n = 0, k = 0, a = 0, t = 0, totalStudent = 0;
		Scanner sn = new Scanner(System.in);

        // Getting the value of t.
		t = sn.nextInt();

        // Taking n number of cases.
		for(int i = 0; i < t; i++){

            // Taking the value of n and k.
			n = sn.nextInt();
			k = sn.nextInt();
            totalStudent = 0;

            // Checking number of students present in class on time.
			for(int j = 0; j < n; j++){
				a = sn.nextInt();
				if(a <= 0){
					totalStudent++;
				}
			}

            // Printing the result.
			if(totalStudent < k){
				System.out.println("YES");
			}
			else{
				System.out.println("NO");
			}
		}
    }
}
