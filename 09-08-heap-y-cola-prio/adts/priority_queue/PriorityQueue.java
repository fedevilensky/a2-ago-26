package adts.priority_queue;

public interface PriorityQueue<E, P> {
   public void push(E elem, P prio);

   public E top();

   public E pop();

   public int size();

   public boolean isEmpty();
}
