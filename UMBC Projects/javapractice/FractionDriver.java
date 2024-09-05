//package javapractice;

import java.util.Scanner;


public class FractionDriver{


    
    private int numerator;
    private int denominator;
    // just creating a constructor here now 
    public FractionDriver(int n, int d){

	// going to throw an exeption if denominator = 0
	if (d == 0){
	    throw new RuntimeException("Divide By Zero Exception");
	}
	else
	    {
		numerator = n;
		denominator = d;
		
	    }
    }

    public int getNum(){
	return numerator;
    }
    
    public int getDen(){
	return denominator;
    }

    public void setNum(int num){
	this.numerator = num;
    }
    
    public void setDen(int den){
	this.denominator = den;
    }
    

    public String toString(){

	String str = " \n";
	return denominator + str + numerator;
    }


    
    public static void main(String[] args){
	Scanner user_inp = new Scanner(System.in);
	System.out.print("What is the numerator: ");
	int num = user_inp.nextInt();
	System.out.print("What is the denominator: ");
	int den = user_inp.nextInt();
	
	FractionDriver firstFrac = new FractionDriver(num, den);
	//FractionDriver frac(num, den);
	
	

	
    }



}
