import java.util.Arrays;

public class test {
  public static void main(String[] args) {
    s1_1();
  }

  public static void s1_1() {
    int a[] = { 1, 2, 3, 4, 5 };
    int b[] = new int[5];
    for (int i = 0; i < a.length; i++) {
      b[i] = a[i];
    }
    for (int i = 0; i < a.length; i++) {
      b[a.length - i - 1] = a[i];
    }
    System.out.println(Arrays.toString(b));
    s1_2();
  }

  public static void s1_2() {
    int a[] = { 1, 2, 3, 4, 5 };
    int temp = 0;
    for (int i = 0; i < (a.length / 2); i++) {
      temp = a[i];
      a[i] = a[a.length - i - 1];
      a[a.length - i - 1] = temp;
    }
    System.out.println(Arrays.toString(a));
    s1_3();
  }

  public static void s1_3() {
    int a[] = { 1, 4, 3 };
    int max_val = -1;
    int max_inx = -1;
    for (int i = 0; i < a.length; i++) {
      if (a[i] > max_val) {
        max_val = a[i];
        max_inx = i;
      }
    }
    System.out.println(max_val);
    s1_4();
  }

  public static void s1_4() {
    int a[] = { 1, 3, 4, 3, 4, 1, 3 };
    int val_max = -1;
    int time_max = 0;
    int time_temp = 0;
    for (int i = 0; i < a.length; i++) {
      time_temp = 0;
      for (int j = 0; j < a.length; j++) {
        if (a[i] == a[j]) {
          time_temp += 1;
        }
        if (time_temp > time_max) {
          time_max = time_temp;
          val_max = a[i];
        }
      }
    }
    System.out.println(val_max);
  }

}
