import java.util.Scanner;

class Factorial {
    public static long factorial(int n) {
        long f = 1;
        while (n > 0) {
            f *= n;
            n--;
        }
        return f;
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        System.out.println(factorial(n));
        input.close();
    }
}