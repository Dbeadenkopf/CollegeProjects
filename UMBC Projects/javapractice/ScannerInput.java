import java.util.Scanner;


class ScannerInput{


    public static void main(String[] args){
	Scanner input = new Scanner(System.in);
	System.out.print("Enter Name (First Last): ");
	String FirstName = input.next();
	String LastName = input.nextLine();
	System.out.print("Enter age (in words): ");
	String age = input.nextLine();
	System.out.println("You Entered: ");
	System.out.println(LastName + ", " + FirstName + ", " + age);
	
    }






}
