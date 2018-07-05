class DoubleDemo {

  static double TESTEDOCARALHO(double arg) {
    return arg;
  }

  public static void main(String[] args) {
    double e1 = 3.0;
    System.out.println(e1);
    double e2 = 2.3;
    System.out.println(e2);

    double e3 = e1 + e2;
    System.out.println(e3);
    double e4 = e1 - e2;
    System.out.println(e4);
    double e5 = e1 / e2;
    System.out.println(e5);
    double e6 = e1 * e2;
    System.out.println(e6);

    int i1 = 1;
    double e7 = (double)(i1);
    System.out.println(e7);

    long i2 = 1l;
    double e8 = (double)(i2);
    System.out.println(e8);

    float i3 = 1.0f;
    double e9 = (double)(i3);
    System.out.println(e9);

    System.out.println(TESTEDOCARALHO(e1));
  }
}
