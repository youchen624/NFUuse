import java.util.Scanner;

public class CSIE_41343131_1114_2 {
    // public enum Dir {
    // RIGHT,
    // LEFT,
    // UP,
    // DOWN
    // };
    static public void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int t = input.nextInt();
        for (int i = 0; i < t; ++i) {
            int n = input.nextInt();
            int dir = input.nextInt();
            int[][] data = spinMatrix(n, dir);
            // System.out.println("#OUT BEGIN>");
            for (int j = 0; j < n; ++j) {
                for (int jj = 0; jj < n; ++jj) {
                    System.out.printf("%d ", data[j][jj]);
                }
                System.out.println();
            }
            // System.out.println("<OUT END#");
        }
        input.close();
    };

    static public int[][] spinMatrix(int n, int dir) {
        if (n == 1) {
            int[][] pq = {{1}};
            return pq;
        }
        int[][] res = new int[n][n];
        int i = 1, t = n - 1;
        int[] xy = { 0, 0 };

        while (i <= n * n) {
            for (int t4 = 0; t4 < 4; ++t4) {
                if (t <= 0) {
                    // System.out.printf("i: %d-> xy: (%d, %d);\nt: %d\n", i, xy[0], xy[1], t);
                    if (dir-1 == 1) {
                        res[xy[0]][xy[1]] = i;
                    } else {
                        res[xy[1]][xy[0]] = i;
                    }
                    return res;
                }
                for (int re = 0; re < t; ++re) {
                    if (i > n * n) return res;
                    // System.out.printf("i: %d-> xy: (%d, %d);\nt: %d\n", i, xy[0], xy[1], t);
                    if (dir-1 == 1) {
                        res[xy[0]][xy[1]] = i;
                    } else {
                        res[xy[1]][xy[0]] = i;
                    }
                    i++;
                    int[] xy_n = indexSearcher(xy, t4);
                    if (t4 == 3 && (re == t - 1)) xy = indexSideIn(xy_n);
                    else xy = xy_n;
                }
            }
            // xy = indexSearcher(xy, 0);
            t -= 2;
            // if (t < 0) t = 0;
            // if (t < 0) return res;
        }


    // boolean rotation = (dir - 1 != 0), backing = false;
    // int x = 0, y = 0,
    //     x_min =0, y_min = 1,
    //     x_max = n - 1, y_max = n - 1,
    //     i = 1;
    // while (i <= n * n) {
    //     if (rotation) res[y][x] = i;
    //     else res[x][y] = i;
    //     if (!backing) {
    //         if ((y < y_max) && (x < x_max)) {
    //             // righting
    //             ++x;
    //         } else if (y < y_max) {
    //             // downing
    //             x_max = x - 1;
    //             ++y;
    //         } else {
    //             // backing (&lefting)
    //             --x;
    //             if (x == x_min) {
    //                 y_max = y - 1;
    //                 backing = true;
    //             }
    //         }
    //     } else {
    //         --y;
    //         if (y == y_min) {
    //             ++y_min;
    //             ++x_min;
    //             backing = false;
    //         // }
    //         // if () {
    //         // upping
    //         // } else if () {
    //         // // righting
    //         } else {
    //             --y;
    //             if (y == y_min) backing = false;
    //         }
    //     }
    //     ++i;
    // };
    return res;
};

    // [0] = x; [1] = y;
    // static public boolean indexBorderOverDis(int index[], int side_l, int dis) {

    // //
    // };

    // [0] = x; [1] = y;
    static public int[] indexSideIn(int index[]) {
        int[] res = new int[2];
        res[0] = index[0] + 1;
        res[1] = index[1] + 1;
        return res;
    };

    // [0] = x; [1] = y;
    static public int[] indexSearcher(int index[], int dir) {
        int[] res = new int[2];
        switch (dir) {
            case 0: { // RIGHT
                res[0] = index[0] + 1;
                res[1] = index[1];
            }
                break;
            case 1: { // DOWN
                res[0] = index[0];
                res[1] = index[1] + 1;
            }
                break;
            case 2: { // LEFT
                res[0] = index[0] - 1;
                res[1] = index[1];
            }
                break;
            case 3: { // UP
                res[0] = index[0];
                res[1] = index[1] - 1;
            }
                break;
        }
        return res;
    };
};