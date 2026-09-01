package adts.table;

import java.util.ArrayList;

import adts.hash_func.HashFunc;

public class ClosedHashTable<K, V> implements Table<K, V> {
   private class Bucket {
      K key;
      V value;
      boolean isDeleted = false;

      Bucket(K key, V value) {
         this.key = key;
         this.value = value;
      }
   };

   /// type Bucket[]
   private Object[] array;
   private int cantidad, capacidad, largoArray;
   private HashFunc<K> h;
   private float fc;

   private boolean esPrimo(int num) {
      if (num <= 1)
         return false;
      if (num == 2)
         return true;
      if (num % 2 == 0)
         return false;
      for (int i = 3; i <= num / 2; i += 2) {
         if (num % i == 0) {
            return false;
         }
      }
      return true;
   }

   private int primoSup(int num) {
      while (!esPrimo(++num))
         ;
      return num;
   }

   private int abs(int x) {
      if (x < 0)
         return -x;

      return x;
   }

   public ClosedHashTable(int capacidad, HashFunc<K> h) {
      this.cantidad = 0;
      this.capacidad = capacidad;
      this.fc = (float) 0.0;
      this.largoArray = primoSup(capacidad);
      this.array = new Object[largoArray];
      this.h = h;
   }

   @Override
   public void set(K key, V value) {
      remove(key);

      int collissions = 0;
      while (true) {
         int pos = abs(this.h.hash(key) + collissions % this.largoArray);
         Bucket b = (Bucket) this.array[pos];

         if (b == null || b.isDeleted) {
            if (b == null) {
               this.array[pos] = new Bucket(key, value);
            } else {
               b.isDeleted = false;
               b.key = key;
               b.value = value;
            }

            break;
         }

         collissions++;
      }

      this.cantidad++;
      // mas cosas, como checkear factor de carga y hacer rehashing
   }

   @Override
   public boolean exists(K key) {
      // TODO Auto-generated method stub
      throw new UnsupportedOperationException("Unimplemented method 'exists'");
   }

   @Override
   public V get(K key) {
      // TODO Auto-generated method stub
      throw new UnsupportedOperationException("Unimplemented method 'get'");
   }

   @Override
   public void remove(K key) {
      // TODO Auto-generated method stub
      throw new UnsupportedOperationException("Unimplemented method 'remove'");
   }

   @Override
   public int size() {
      return this.cantidad;
   }

}
