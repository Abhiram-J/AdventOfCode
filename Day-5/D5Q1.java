import java.util.*;

public class D5Q1 {

    private static ArrayList<Long> findNext(ArrayList<Long> curr, ArrayList<Long> map) {
        for (int i = 0; i < curr.size(); i++) {
            Long val = curr.get(i);
            for (int j = 1; j < map.size(); j += 3) {
                if (map.get(j) <= val && val <= map.get(j) + map.get(j + 1)) {
                    curr.set(i, map.get(j - 1) + val - map.get(j));
                    break;
                }
            }
        }

        return curr;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        input = input.substring(7);
        String[] seeds = input.split(" ");
        ArrayList<Long> curr = new ArrayList<Long>();
        for (int i = 0; i < seeds.length; i++) {
            curr.add(Long.parseLong(seeds[i]));
        }

        input = sc.nextLine();
        while (sc.hasNextLine()) {
            ArrayList<Long> map = new ArrayList<Long>();
            input = sc.nextLine();
            while (sc.hasNextLine()) {
                input = sc.nextLine();
                if (input.equals("")) {
                    break;
                }
                String[] vals = input.split(" ");
                for (int i = 0; i < vals.length; i++) {
                    map.add(Long.parseLong(vals[i]));
                }
            }

            curr = findNext(curr, map);

        }
        Long ans = Long.MAX_VALUE;
        for (int i = 0; i < curr.size(); i++) {
            ans = Math.min(ans, curr.get(i));
        }
        System.out.println(ans);
        sc.close();
    }
}
