import java.util.*;

public class D5Q2 {

    private static ArrayList<Long> findNext(ArrayList<Long> curr, ArrayList<Long> map) {

        ArrayList<Long> ans = new ArrayList<Long>();

        for (int i = 1; i < map.size(); i += 3) {
            Long val = map.get(i);
            Long range = map.get(i + 1);
            Long newVal = map.get(i - 1);
            for (int j = 0; j < curr.size(); j += 2) {
                Long currVal = curr.get(j);
                Long currRange = curr.get(j + 1);
                if (currRange == 0L)
                    continue;
                if (val <= currVal && currVal <= val + range) {
                    if (val + range < currVal + currRange) {
                        ans.add(newVal + currVal - val);
                        ans.add(val + range - currVal);
                        curr.set(j, val + range);
                        curr.set(j + 1, currVal + currRange - (val +range));

                    } else {
                        ans.add(newVal + currVal - val);
                        ans.add(currRange);
                        curr.set(j + 1, 0L);
                    }

                }
                if (currVal <= val && val <= currVal + currRange) {
                    if (currVal + currRange <= val + range) {
                        ans.add(newVal);
                        ans.add(currVal + currRange - val);
                        curr.set(j + 1, val - currVal);
                    } else {
                        ans.add(newVal);
                        ans.add(range);
                        curr.set(j + 1, val - currVal);
                        curr.add(val+range);
                        curr.add(currVal + currRange - (val + range));
                    }

                }
            }
        }

        for (int j = 0; j < curr.size(); j += 2) {
            if (curr.get(j + 1) > 0) {
                ans.add(curr.get(j));
                ans.add(curr.get(j + 1));
            }
        }

        return ans;
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
            // System.out.println("hi");
            curr = findNext(curr, map);

        }
        Long ans = Long.MAX_VALUE;
        for (int i = 0; i < curr.size(); i += 2) {
            ans = Math.min(ans, curr.get(i));
        }
        System.out.println(ans);
        sc.close();
    }
}
