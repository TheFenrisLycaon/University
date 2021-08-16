package com.serialization;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
  private static int menuChoice;
  private static final Scanner scanner = new Scanner(System.in);
  private static ArrayList<Employee> employeeArrayList;
  
  public static void main(String[] args) {
    employeeArrayList = EmployeeData.getInstance().loadEmployees();
    do {
      displayMenu();
    } while(menuChoice != MenuChoice.QUIT);
    
  }
  
  private static void displayMenu() {
    System.out.println("Main Menu:");
    System.out.println("\t[1]\tAdd an employee");
    System.out.println("\t[2]\tDisplay All");
    System.out.println("\t[3]\tExit");
    
    menuChoice = scanner.nextInt();
    
    switch (menuChoice) {
      case MenuChoice.ADDEMPLOYEE:
        addEmployee();
        saveData();
        break;
      
      case MenuChoice.DISPLAY:
        loadData();
        displayEmployees();
        break;
        
      case MenuChoice.QUIT:
        System.exit(0);
        break;
      
      default:
        System.out.println("Invalid Input");
    }
  }
  
  private static void loadData() {
    employeeArrayList = EmployeeData.getInstance().loadEmployees();
  }
  
  private static void saveData() {
    EmployeeData.getInstance().saveEmployees(employeeArrayList);
  }
  
  private static void displayEmployees() {
    System.out.println();
    System.out.println("Employee Data in Memory:");
    for(var e : employeeArrayList) {
      System.out.println("\t" + e);
    }
    System.out.println();
  }
  
  private static void addEmployee() {
    System.out.println("Enter the Employee id:");
    int id = scanner.nextInt();
    scanner.nextLine();
    System.out.println("Enter the name of the Employee:");
    String name = scanner.nextLine();
    System.out.println("Enter the salary of the Employee:");
    double salary = scanner.nextDouble();
    scanner.nextLine();
    System.out.println("Enter the age of the Employee:");
    int age = scanner.nextInt();
    scanner.nextLine();
    employeeArrayList.add(new Employee(id, name, salary, age));
  }
}
