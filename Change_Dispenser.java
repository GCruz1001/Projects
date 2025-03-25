package assignment3;
import java.util.Scanner;
public class Change_Dispenser {

	public static void main(String[] args) {
		try (// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in)) {
			{
				// Asks user for the cost of the item in cents between 0 and 100 
				System.out.println("Enter the price of the item: ");
				int cost = input.nextInt();
				
				// Create a variable for the change for the user to receive
				int change = 100 - cost;
				
				System.out.println("Item cost is " + cost + " and the change for a dollar is: " + change);
				
				System.out.println("The exact change is: ");
				
				int quarters = change / 25;
				int dimes = (change - quarters * 25) / 10;
				int nickels = (change - (dimes * 10) - (quarters * 25)) / 5;
				int pennies = (change - (nickels * 5) - (dimes * 10) - (quarters * 25)) / 1;
				
				System.out.println("Quarters = " + quarters + "\nDimes = " + dimes + "\nNickels = " + nickels + "\nPennies = " + pennies);
			}
		}
	}

}
