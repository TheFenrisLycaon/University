package src;

import java.util.ArrayList;
import java.util.Scanner;
import java.util.*;

public class book {
    public static void main(String args[]) {
        ArrayList<String> l = new ArrayList<String>(Arrays.asList("Angels & Demons", "Harry Potter",
                "Lord of the Rings", "Deception Point", "Inferno", "The Hobbit"));
        Scanner sc = new Scanner(System.in);
        int ch;
        do {
            System.out.print(
                    "\n\t[1] Add Books\t\t\t[2] Retrive Book\n\t[3] Display Store\t\t[4] Search\n\t[0] Exit.\n\nEnter your choice::\t");
            ch = sc.nextInt();
            switch (ch) {
            case 1:
                System.out.print("Enter number of books::\t");
                int n = sc.nextInt();
                while (n != 0) {
                    System.out.print("Enter Name::\t");
                    String a = sc.next();
                    l.add(a);
                    System.out.println("Book Added!!");
                    n--;
                }
                break;
            case 2:
                System.out.print("Enter number of books to retrive::\t");
                int n1 = sc.nextInt();
                while (n1 != 0) {
                    System.out.print("Enter the name ::\t");
                    String a = sc.next();
                    l.remove(a);
                    n1--;
                }
                break;
            case 3:
                System.out.println("Current Status::\n");
                Iterator it = l.iterator();
                while (it.hasNext()) {
                    System.out.println(it.next());
                }
                break;
            case 4:
                System.out.print("Enter bookk naem to search::\t ");
                String b = sc.next();
                if (l.contains(b)) {
                    System.out.println("AVAILBLE!!");
                } else {
                    System.out.println("NOT AVAILBLE");
                }
            }
        } while (ch != 0);
    }
}
