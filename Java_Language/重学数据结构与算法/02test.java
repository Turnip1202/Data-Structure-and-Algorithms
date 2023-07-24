import java.util.HashMap;
import java.util.Map;

public class test {
  public static void main(String[] args) {
    s2_1();
  }

  public static void s2_1() {
    int count = 0;
    for (int i = 0; i < (100 / 7); i++) {
      for (int j = 0; j < (100 / 3); j++) {
        for (int k = 0; k < (100 / 2); k++) {
          if (i * 7 + j * 3 + k * 2 == 100) {
            count += 1;
          }
        }
      }
    }
    System.out.println(count);
    s2_2();
  }

  public static void s2_2() {
    int count = 0;
    for (int i = 0; i < (100 / 7); i++) {
      for (int j = 0; j < (100 / 3); j++) {
        if ((100 - i * 7 - j * 3) % 2 == 0) {
          count += 1;
        }
      }
    }
    System.out.println(count);
    s2_3();
  }

  public static void s2_3() {
    int a[] = { 1, 2, 3, 4, 5, 5, 6 };
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
    s2_4();
  }

  public static void s2_4() {
    int a[] = { 1, 2, 3, 4, 5, 5, 6 };
    Map<Integer, Integer> d = new HashMap<>();
    for (int i = 0; i < a.length; i++) {
      if (d.containsKey(a[i])) {
        d.put(a[i], d.get(a[i]) + 1);
      } else {
        d.put(a[i], 1);
      }
    }
    int val_max = -1;
    int time_max = 0;
    for (Integer key : d.keySet()) {
      if (d.get(key) > time_max) {
        time_max = d.get(key);
        val_max = key;
      }

    }
    System.out.println(val_max);

  }

}
