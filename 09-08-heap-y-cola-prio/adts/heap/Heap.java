package adts.heap;

public interface Heap<T> {
   public void push(T elem);

   public T top();

   public T pop();

   public int size();

   public boolean isEmpty();
}
