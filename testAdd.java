package com.bittech;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * package:com.bittech
 * Description:TODO
 *
 * @date:2019/7/22 0022
 * @Author:weiwei
 **/
public class testAdd {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        //首先判断,如果n>m,则n中大于m的数不可能参与组合,此时n=m
        int up = n > m ? m:n;
        printList(m,up,list);
    }

    /**
     *
     * @param m     要求满足的和sum
     * @param n      取数的范围scope
     * @param list   每一种满足条件的组合
     */
    private static void printList(int m, int n, List<Integer> list) {
        //m=0时,即背包刚好装满,打印并退出
        if(m == 0){
            System.out.println(list);
            return;
        }
        //根据题意,可知m和n必须正整数,所以mn为负数,或m=n时直接退出
        if(n <= 0 || m < 0 ){
            return;
        }
        //拿到上一次计算结果list
        List<Integer> list1 = new ArrayList<Integer>(list);

        //n没有加入
        printList(m,n-1,list);

        //n加入
        list1.add(n);
        printList(m-n,n-1,list1);
    }
}
