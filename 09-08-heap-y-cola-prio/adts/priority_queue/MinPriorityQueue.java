package adts.priority_queue;

import adts.heap.MinHeap;

public class MinPriorityQueue<E, P extends Comparable<P>> implements PriorityQueue<E, P> {
   private class Pair implements Comparable<Pair> {
      E elem;
      P prio;

      Pair() {
      }

      Pair(E elem, P prio) {
         this.elem = elem;
         this.prio = prio;
      }

      @Override
      public int compareTo(Pair other) {
         return this.prio.compareTo(other.prio);
      }
   }

   private MinHeap<Pair> h;

   public MinPriorityQueue(int expectedSize) {
      this.h = new MinHeap<>(expectedSize);
   }

   @Override
   public void push(E elem, P prio) {
      Pair p = new Pair(elem, prio);
      this.h.push(p);
   }

   @Override
   public E top() {
      Pair t = this.h.top();
      return t.elem;
   }

   @Override
   public E pop() {
      Pair t = this.h.pop();
      return t.elem;
   }

   @Override
   public int size() {
      return this.h.size();
   }

   @Override
   public boolean isEmpty() {
      return this.h.isEmpty();
   }

}
