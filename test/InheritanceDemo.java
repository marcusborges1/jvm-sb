class SuperClassDemo {
   int age;

   SuperClassDemo(int age) {
      this.age = age;
   }
}

public class InheritanceDemo extends SuperClassDemo {
   InheritanceDemo(int age) {
      super(age);
   }

   public static void main(String argd[]) {
      InheritanceDemo s = new InheritanceDemo(24);
   }
}
