import java.util.Iterator;

import adts.list.*;

public class Main {
    static void print(Iterable<Integer> iter) {
        /*
         * Iterator<Integer> it = iter.iterator();
         * while (it.hasNext()) {
         * int i = it.next();
         * System.out.println(i);
         * }
         */
        for (int i : iter) {
            System.out.println(i);
        }
    }

    public static void main(String[] args) {

        List<Integer> l = new ArrayList<Integer>(10);

        for (int i = 0; i < 10; i++) {
            l.add(i);
        }

        print(l);
    }
}
