import java.util.*;

public class D2Q1 {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    int ans = 0, game = 1;
    while (sc.hasNextLine()) {
      String input = sc.nextLine();
      input = input.split(":")[1];
      String[] st = input.split(";");
      boolean flag = true;
      Integer blue = 0, red = 0, green = 0;
      for (int i = 0; i < st.length; i++) {
        String[] st2 = st[i].split(",");
        for (int j = 0; j < st2.length; j++) {
          if (st2[j].charAt(st2[j].length() - 1) == 'e') {
            blue = Integer.parseInt(st2[j].split(" ")[1]);
          } else if (st2[j].charAt(st2[j].length() - 1) == 'd') {
            red = Integer.parseInt(st2[j].split(" ")[1]);
          } else {
            green = Integer.parseInt(st2[j].split(" ")[1]);
          }
        }
        if (blue > 14 || green > 13 || red > 12) {
          flag = false;
          break;
        }
      }
      if (flag)
        ans += game;
      game++;
    }
    System.out.println(ans);
    sc.close();
  }
}
