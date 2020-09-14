public class Lab00
{
	public static void main(String[] args)
	{
		// Declaring and initializing some variables. 
		int x = 5;
		String y = "hello";
		double = 9.8; 
		
		// Printing the variables.
		System.out.println("x: " + x " y: " + y " z: " + z);
		
		// A list (make an array in Java).
		int [] numbers = {3, 6, -1, 2};
		
		for(int count = 0; count < numbers.length; count++)
		{
			System.out.println(numbers[count]);
		}
		
		// Call a function. 
		System.out.print("Found: ");
		Count_Character(y, 'l');
		
		// A counting for loop.
		for(int j = 1; j < 11; j++)
		{
			System.out.print(j + " ");
		}
		System.out.println();
	}
	public static void Count_Character(String str, char c_temp)
	{
		int temp = 0;
		
		// This calculates the length of a string. 
		for(int i = 0; i < str.length(); i++)
		{
			/* 
				The charAt() method returns the character at the specified index in string. 
				The index of the 1st character is 0, the 2nd character is 1, and so on. 
			*/
			if(str.charAt(i) == c_temp)
			{
				temp++;
			}
		}
		System.out.println(temp);
	}
}