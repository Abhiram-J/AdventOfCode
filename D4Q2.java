import java.util.*;

public class D4Q2 {

  public static void main(String[] args) {

    Scanner sc = new Scanner(System.in);
    ArrayList<String> cards = new ArrayList<String>();
    while (sc.hasNextLine()) {
      cards.add(sc.nextLine());
    }
    int n = cards.size();
    int[] prefixSum = new int[n + 1];
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
          points++;
        }
      }
      if (j > 1) {
        prefixSum[j] += prefixSum[j - 1];
      }
      ans += prefixSum[j] + 1;
      if (j + points + 1 <= n) {
        prefixSum[j + points + 1] += -1 * (prefixSum[j] + 1);
      }
      prefixSum[j + 1] += 1 * (prefixSum[j] + 1);

    }

    System.out.println(ans);
    sc.close();
  }
}
