import adts.hash_func.IntIdentity;
import adts.table.*;

public class Main {
   public static void main(String[] args) {
      Table<Integer, String> t = new ClosedHashTable<Integer, String>(4, new IntIdentity());

      System.out.println("El largo de la tabla es " + t.size());

      System.out.println("Agrego el 1");
      t.set(1, "1");

      System.out.println("El largo de la tabla es " + t.size());

      System.out.println("Agrego el 2");
      t.set(2, "2");
      System.out.println("El largo de la tabla es " + t.size());

      System.out.println("Agrego el 3");
      t.set(3, "3");
      System.out.println("El largo de la tabla es " + t.size());

      System.out.println("Agrego el 4");
      t.set(4, "4");
      System.out.println("El largo de la tabla es " + t.size());
   }
}
