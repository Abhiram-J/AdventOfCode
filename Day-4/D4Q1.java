import java.util.*;

public class D4Q1 {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    ArrayList<String> cards = new ArrayList<String>();
    while (sc.hasNextLine()) {
      cards.add(sc.nextLine());
    }
    int n = cards.size();
    int[] pointsArray = new int[n + 1];

    int ans = 0;
    for (int j = 0; j < n; j++) {
      String input = cards.get(j).split(":")[1];
      input = input.substring(1, input.length());
      String[] currCards = input.split("\\|");
      String[] Swinning = currCards[0].trim().split(" ");
      String[] Shave = currCards[1].trim().split(" ");

      TreeMap<String, Boolean> winning = new TreeMap<String, Boolean>();
      for (int i = 0; i < Swinning.length; i++) {
        if (!Swinning[i].equals("") && !Swinning[i].equals(" ")) {
          winning.put(Swinning[i], true);
        }
      }
      int points = 0;
      for (int i = 0; i < Shave.length; i++) {
        if (!Shave[i].equals("") && !Shave[i].equals(" ") && winning.containsKey(Shave[i])) {
          if (points == 0) {
            points = 1;
          } else {
            points *= 2;
          }
        }
      }
      ans += points;
    }
    while (sc.hasNextLine()) {

    }
    System.out.println(ans);
    sc.close();
  }
}
