import java.util.Stack;

public class Stacks
{
    public static void main(String[] args)
    {
        Stack<String> stack = new Stack<>();

        stack.add("a");
        stack.add("b");
        stack.pop();
        System.out.println(stack);
    }
}
