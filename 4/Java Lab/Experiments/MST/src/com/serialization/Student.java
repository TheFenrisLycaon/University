package com.serialization;

import java.io.Serializable;

public class Student implements Serializable {
  private static final long serialVersionUID = 10L;
  private String id;
  private String name;
  private String courseID;
  private String cllgName;

  public Student(String id, String name, String courseID, String cllgName) {
    this.id = id;
    this.name = name;
    this.courseID = courseID;
    this.cllgName = cllgName;
  }

  public String getId() {
    return id;
  }

  private void setID(String id) {
    this.id = id;
  }

  public String getName() {
    return name;
  }

  private void setName(String name) {
    this.name = name;
  }

  public String getcourseID() {
    return courseID;
  }

  private void setcourseID(String courseID) {
    this.courseID = courseID;
  }

  public String getcllgName() {
    return cllgName;
  }

  private void setcllgName(String cllgName) {
    this.cllgName = cllgName;
  }

  @Override
  public String toString() {
    return "StudentID::\t" + id + "\t|\tName::\t" + name + "\t|\tCourseID::\t" + courseID + "\t|\tCollege::\t"
        + cllgName;
  }

}
