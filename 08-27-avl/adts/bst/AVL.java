package adts.bst;

public class AVL<T extends Comparable<T>> implements BST<T> {
   class node {
      T data;
      node left = null;
      node right = null;
      int height = 1;

      // constructor
      node(T data) {
         this.data = data;
      }
   }

   node root = null;

   int size(node n) {
      if (n == null) {
         return 0;
      }

      return 1 + size(n.left) + size(n.right);
   }

   int max(int a, int b) {
      if (a > b)
         return a;
      return b;
   }

   int height(node n) {
      if (n == null) {
         return 0;
      }
      return n.height;
   }

   node leftRotation(node n) {
      // z
      // / \
      // z_l y
      // / \
      // y_l x

      // y
      // / \
      // z x
      // / \
      // z_l y_l

      node z = n;
      node y = z.right;
      node y_l = y.left;

      z.right = y_l;
      y.left = z;

      z.height = 1 + max(height(z.left), height(z.right));
      y.height = 1 + max(height(y.left), height(y.right));

      return y;
   }

   node rightRotation(node n) {
      throw new UnsupportedOperationException("Unimplemented method 'rightRotation'");
   }

   node rightLeftRotation(node n) {
      throw new UnsupportedOperationException("Unimplemented method 'rightLeftRotation'");
   }

   node leftRightRotation(node n) {
      throw new UnsupportedOperationException("Unimplemented method 'leftRightRotation'");
   }

   node balance(node n) {
      // bf => Balance Factor
      int bF = height(n.left) - height(n.right);

      if (bF == -2) {
         // desbalance der-?
         int bFRight = height(n.right.left) - height(n.right.right);
         if (bFRight == -1) {
            // desbalance der-der
            n = leftRotation(n);
         } else {
            // desbalance der-izq
            n = rightLeftRotation(n);
         }
      } else if (bF == 2) {
         // desbalance izq-?

         int bFLeft = height(n.left.left) - height(n.left.right);
         if (bFLeft == -1) {
            // desbalance izq-der
            n = leftRightRotation(n);
         } else {
            // desbalance izq-izq
            n = rightRotation(n);
         }
      }

      return n;
   }

   node add(node n, T data) {
      if (n == null) {
         return new node(data);
      }

      // else
      if (data.compareTo(n.data) < 0) {
         n.left = add(n.left, data);
      } else {
         n.right = add(n.right, data);
      }
      n.height = 1 + max(height(n.left), height(n.right));

      // si no esta balanceado, lo balanceamos
      n = balance(n);

      return n;
   }

   @Override
   public void add(T data) {
      this.root = add(this.root, data);
   }

   @Override
   public void remove(T data) {
      // TODO Auto-generated method stub
      throw new UnsupportedOperationException("Unimplemented method 'remove'");
   }

   @Override
   public int size() {
      return size(root);
   }

   @Override
   public T max() {
      // TODO Auto-generated method stub
      throw new UnsupportedOperationException("Unimplemented method 'max'");
   }

   @Override
   public T min() {
      // TODO Auto-generated method stub
      throw new UnsupportedOperationException("Unimplemented method 'min'");
   }

}
