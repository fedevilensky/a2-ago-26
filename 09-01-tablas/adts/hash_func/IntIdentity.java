package adts.hash_func;

public class IntIdentity implements HashFunc<Integer> {

   @Override
   public int hash(Integer i) {
      return i;
   }

}
