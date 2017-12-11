package com.servlet;

import java.util.Scanner;


public class Main {
	public static void main(String args[]){  
		String str;
		Scanner cin = new Scanner(System.in);
		int N;
		N = cin.nextInt();
		for(int i = 1; i <= N; i++) {
			str = cin.next();
			int dg = dg(str);
			System.out.println(dg);
		}
    }  
	private static int dg(String str) {
		if(str.length() == 1) return 1;
		String pre = str.substring(0, str.length()/2);
		String aft = str.substring(str.length()/2);
		aft = new StringBuffer(aft).reverse().toString();
		if(pre.equals(aft)) {
			return dg(pre);
		} else {
			return str.length();
		}
	}
}
