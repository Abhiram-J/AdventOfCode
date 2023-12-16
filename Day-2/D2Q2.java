import java.util.*;

public class D2Q2 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int ans = 0;
        while (sc.hasNextLine()) {
            String input = sc.nextLine();
            input = input.split(":")[1];
            String[] st = input.split(";");
            Integer blue = 0, red = 0, green = 0;
            for (int i = 0; i < st.length; i++) {
                String[] st2 = st[i].split(",");
                for (int j = 0; j < st2.length; j++) {
                    Integer b = 0, r = 0, g = 0;
                    if (st2[j].charAt(st2[j].length() - 1) == 'e') {
                        b = Integer.parseInt(st2[j].split(" ")[1]);
                        blue = Math.max(blue, b);

                    } else if (st2[j].charAt(st2[j].length() - 1) == 'd') {
                        r = Integer.parseInt(st2[j].split(" ")[1]);
                        red = Math.max(red, r);
                    } else {
                        g = Integer.parseInt(st2[j].split(" ")[1]);
                        green = Math.max(green, g);
                    }
                }
            }
            ans += red * green * blue;
        }
        System.out.println(ans);
        sc.close();
    }
}
