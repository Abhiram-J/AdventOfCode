import java.util.Scanner;

public class D6Q2 {
    /*
     * Input :
     * Time: 71530
     * Distance: 940200
     * 
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.next();
        long curr = sc.nextLong();
        input = sc.next();
        long dis = sc.nextLong();
        long pos = 0;
        for (long j = 0; j <= curr; j++) {
            if (j * (curr - j) > dis) {
                pos++;
            }
        }

        System.out.println(pos);
        sc.close();
    }
}
