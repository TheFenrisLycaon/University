package com.serialization;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  private static int c;
  private static final Scanner scanner = new Scanner(System.in);
  private static ArrayList<Student> StudentArrayList;

  public static void main(String[] args) {
    StudentArrayList = StudentData.getInstance().loadStudents();
    do {
      displayMenu();
    } while (c != choice.QUIT);

  }

  private static void displayMenu() {
    System.out.println("\n\t[1]\tAdd a Student");
    System.out.println("\t[2]\tDisplay All");
    System.out.println("\t[3]\tExit");

    c = scanner.nextInt();
    scanner.nextLine();

    switch (c) {
    case choice.ADDStudent:
      addStudent();
      saveData();
      break;

    case choice.DISPLAY:
      loadData();
      displayStudents();
      break;

    case choice.QUIT:
      System.exit(0);
      break;

    default:
      System.out.println("Invalid Input");
    }
  }

  private static void loadData() {
    StudentArrayList = StudentData.getInstance().loadStudents();
  }

  private static void saveData() {
    StudentData.getInstance().saveStudents(StudentArrayList);
  }

  private static void displayStudents() {
    System.out.println();
    for (var e : StudentArrayList) {
      System.out.println("\t" + e);
    }
    System.out.println();
  }

  private static void addStudent() {
    System.out.println("Enter the StudentID::\t");
    String id = scanner.nextLine();
    System.out.println("Enter the Name::\t");
    String name = scanner.nextLine();
    System.out.println("Enter the CourseID::\t");
    String CourseID = scanner.nextLine();
    System.out.println("Enter the Name of the College::\t");
    String age = scanner.nextLine();
    StudentArrayList.add(new Student(id, name, CourseID, age));
  }
}