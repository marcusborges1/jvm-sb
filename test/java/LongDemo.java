class LongDemo {
    static long foo(long args) {
        return args;
    }

  public static void main(String[] args) {
    long e1 = 2L;
    System.out.println(e1);
    long e2 = 6L;

    long e3 = e1 + e2;
    System.out.println(e3);

    long e4 = e1 - e2;
    System.out.println(e4);

    long e5 = e1/e2;
    System.out.println(e5);

    long e6 = e1 * e2;
    System.out.println(e6);

    int i1 = 6;
    long e7 = (long) i1;
    System.out.println(e7);

    float i2 = 8.2f;
    long e8 = (long) i2;
    System.out.println(e8);

    double i3 = 5.5;
    long e9 = (long) i2;
    System.out.println(e9);

    System.out.println(foo(e1));

  }
}
