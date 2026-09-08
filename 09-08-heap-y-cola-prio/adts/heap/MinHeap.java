package adts.heap;

public class MinHeap<T extends Comparable<T>> implements Heap<T> {
   private Object[] arr;
   private int count;

   private void grow(int newlength) {
      Object[] newArr = new Object[newlength];
      for (int i = 0; i < this.arr.length; i++) {
         newArr[i] = this.arr[i];
      }

      this.arr = newArr;
   }

   private void swap(int posA, int posB) {
      Object aux = this.arr[posA];
      this.arr[posA] = this.arr[posB];
      this.arr[posB] = aux;
   }

   private void siftUp(int pos) {
      if (pos == 1) {
         return;
      }

      // comparo con el padre
      int parentPos = pos / 2;

      T elem = (T) this.arr[pos];
      T parent = (T) this.arr[parentPos];

      // parent > elem
      if (parent.compareTo(elem) > 0) {
         swap(pos, parentPos);
         siftUp(parentPos);
      }
   }

   public MinHeap(int expectedSize) {
      this.arr = new Object[expectedSize + 1];
      this.count = 0;
   }

   @Override
   public void push(T elem) {
      if (this.count == this.arr.length) {
         grow(this.arr.length * 2);
      }

      this.count++;
      this.arr[this.count] = elem;

      siftUp(this.count);
   }

   @Override
   public T top() {
      if (size() < 1)
         throw new RuntimeException("no hay elementos");

      return (T) this.arr[1];
   }

   @Override
   public T pop() {
      // TODO Auto-generated method stub
      throw new UnsupportedOperationException("Unimplemented method 'pop'");
   }

   @Override
   public int size() {
      return this.count;
   }

   @Override
   public boolean isEmpty() {
      return size() == 0;
   }

}
