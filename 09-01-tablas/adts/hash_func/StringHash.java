package adts.hash_func;

public class StringHash implements HashFunc<String> {

   @Override
   public int hash(String s) {
      // ESTO ES UNA MALA FUNCION EL QUE LA ENTREGA
      // PIERDE PUNTOS

      int n = 0;
      for (int i = 0; i < s.length(); i++) {
         n += s.charAt(i);
      }

      return n;
   }
}
