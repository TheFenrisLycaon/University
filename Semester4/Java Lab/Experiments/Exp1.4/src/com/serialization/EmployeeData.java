package com.serialization;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class EmployeeData {
  private static final EmployeeData instance;
  
  static {
    instance = new EmployeeData();
  }
  
  public static EmployeeData getInstance() {
    return instance;
  }
  
  private EmployeeData() {
  }
  
  public void saveEmployees(ArrayList<Employee> employeeArrayList) {
    try (ObjectOutputStream  toFile = new ObjectOutputStream(new FileOutputStream(new File("employees.dat")))) {
      for(Employee e : employeeArrayList) {
        toFile.writeObject(e);
      }
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
  
  public ArrayList<Employee> loadEmployees() {
    ArrayList<Employee> employeeArrayList = new ArrayList<>();
    try(ObjectInputStream fromFile  = new ObjectInputStream(new FileInputStream("employees.dat"))) {
      while(true) {
        employeeArrayList.add((Employee) fromFile.readObject());
      }
    } catch (IOException | ClassNotFoundException e) {
      return employeeArrayList;
    }
  }
}
