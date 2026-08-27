package adts.bst;

public interface BST<T extends Comparable<T>> {
   public void add(T data);

   public void remove(T data);

   public int size();

   public T max();

   public T min();
}
