package com.bittech;

/**
 * package:com.bittech
 * Description:TODO
 * @date:2019/6/5
 * @Author:weiwei
 **/
public class Test0605 {
    public int add(int A,int B){
        int sum,carry;
        do{
            sum = A^B;
            carry = (A^B) <<  1;
            A = sum;
            B = carry;
        }while(B != 0);
        return A;
    }
}
