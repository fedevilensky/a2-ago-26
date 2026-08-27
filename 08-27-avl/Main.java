import adts.bst.AVL;
import adts.bst.BST;

public class Main {
   public static void main(String[] args) {
      BST<Integer> tree = new AVL<Integer>();
      System.out.println("Tamano de mi arbol " + tree.size());

      for (int i = 0; i < 10; i++) {
         System.out.println("Agrego el " + i);
         tree.add(i);
      }

      System.out.println("Tamano de mi arbol " + tree.size());
   }
}
