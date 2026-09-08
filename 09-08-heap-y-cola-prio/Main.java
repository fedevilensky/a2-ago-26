import adts.priority_queue.*;
import java.util.Scanner;

public class Main {
   public static void main(String[] args) {
      System.err.println("Hola esto es un error");

      System.out.println("Cuantos elementos queres agregar?");

      Scanner sc = new Scanner(System.in);
      int N = sc.nextInt();

      PriorityQueue<String, Integer> pq = new MinPriorityQueue<>(N);

      for (int i = 0; i < N; i++) {
         String elem = sc.next();
         int prio = sc.nextInt();
         pq.push(elem, prio);
         System.out.println("Elemento mas chico es: " + pq.top());
         System.out.println("El heap contiene " + pq.size() + " elementos");
      }

      while (!pq.isEmpty()) {
         System.out.println("Elemento mas chico es " + pq.pop());
      }

      sc.close();
   }
}
