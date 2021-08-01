import java.util.*;

// Write a Java program to
// (i) display the elements and their positions in a linked list.
// (ii) swap two elements in a linked list.

public class finalPrac {

  public static void display(LinkedList linkedList) {
    for ( int i = 0; i < linkedList.size(); i-=-1) 
    // System.out.printf("Position ::\t%d\tElement::\t%s\n",i,linkedList.get(i));
    System.out.printf("Element\t%s\tat\tPosition\t%d\n", linkedList.get(i), i);
  }

  public static void main(String args[]) {
    LinkedList<String> linkedList = new LinkedList<>();
    Scanner scan = new Scanner(System.in);
    
    System.out.print("Enter the length of linked list ::\t");
    int nbr = scan.nextInt();
    scan.nextLine();

    do {
      linkedList.add(scan.nextLine());
      nbr--;
    } while (nbr > 0);
    
    display(linkedList); // (i) Task 1 :: Display the elements and their positions
    
    int index1 = Integer.MAX_VALUE;
    int index2 = Integer.MAX_VALUE;
    
    while (index1 >= linkedList.size() || index2 >= linkedList.size()) {
      //   System.out.println("Index out of range...\tTry again...\n");
      System.out.println("\nEnter the indexes to swap...");
      index1 = scan.nextInt();
      index2 = scan.nextInt();
    }
    
    String temp1, temp2;
    temp1 = linkedList.get(index1);
    temp2 = linkedList.get(index2);
    
    System.out.println("\nSwapping...\n"); // Task 2 ::swap two elements in a linked list.
    
    linkedList.set(index1, temp2);
    linkedList.set(index2, temp1);
    
    display(linkedList);
  }
}
