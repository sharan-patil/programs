package Human;

class Person
{
	private String name;
	
	public Person(String name)
	{
		this.name = name;
	}
	
	public String getName()
	{
		return this.name;
	}
	
	public static void main(String args[])
	{
		Person sharan = new Person("Sharan");
		System.out.println(sharan.getName());
	}
}
