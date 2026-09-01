package adts.table;

public interface Table<K, V> {
   public void set(K key, V value);

   public boolean exists(K key);

   public V get(K key);

   public void remove(K key);

   public int size();
}
