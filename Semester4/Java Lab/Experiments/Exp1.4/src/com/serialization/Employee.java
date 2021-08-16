package com.serialization;

import java.io.Serializable;

public class Employee implements Serializable {
  private int id;
  private String name;
  private double salary;
  private int age;
  private static final long SerialVersionUID = 10L;
  
  
  public Employee(int id, String name, double salary, int age) {
    this.id = id;
    this.name = name;
    this.salary = salary;
    this.age = age;
  }
  
  public int getId() {
    return id;
  }
  
  private void setId(int id) {
    this.id = id;
  }
  
  public String getName() {
    return name;
  }
  
  private void setName(String name) {
    this.name = name;
  }
  
  public double getSalary() {
    return salary;
  }
  
  private void setSalary(double salary) {
    this.salary = salary;
  }
  
  public int getAge() {
    return age;
  }
  
  private void setAge(int age) {
    this.age = age;
  }
  
  @Override
  public String toString() {
    return "Employee [id=" + id + ", name=" + name + ", salary=" + salary + ", age=" + age + "]";
  }
  
}
