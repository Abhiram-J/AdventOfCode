import java.util.ArrayList;
import java.util.Scanner;

public class D6Q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        String[] vals = input.split(" ");
        ArrayList<Integer> time = new ArrayList<Integer>();
        for (int i = 0; i < vals.length; i++) {
            if (vals[i] != "" && vals[i].charAt(0) <= '9' && vals[i].charAt(0) >= '0') {
                time.add(Integer.parseInt(vals[i]));
            }
        }
        input = sc.nextLine();
        vals = input.split(" ");
        ArrayList<Integer> distance = new ArrayList<Integer>();
        for (int i = 0; i < vals.length; i++) {
            if (vals[i] != "" && vals[i].charAt(0) <= '9' && vals[i].charAt(0) >= '0') {
                distance.add(Integer.parseInt(vals[i]));
            }
        }
        int ans = 1;
        for (int i = 0; i < time.size(); i++) {
            int curr = time.get(i);
            int dis = distance.get(i);
            int pos = 0;
            for (int j = 0; j <= curr; j++) {
                if (j * (curr - j) > dis) {
                    pos++;
                }
            }
            ans *= pos;

        }

        System.out.println(ans);
        sc.close();
    }
}
