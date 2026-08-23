import java.util.*;
import java.time.LocalDate;
import java.time.LocalDateTime;

/*
class Object{
    public String toString()
}
*/
// class StudyLog extends toString

class StudyLog{
    public LocalDate Date;
    public String Subject;
    public double Duration;
    public String Description;

    public StudyLog(LocalDate a,String b,double c,String d){
        this.Date = a;
        this.Subject = b;
        this.Duration = c;
        this.Description = d;
    } 

    public String toString(){           // method overiding
        return Date + " | " + Subject + " | " + Duration + " | " + Description ;
    }

}

class program843{
    public static void main(String A[]) throws Exception
    {   
        LocalDate lobj = LocalDate.now();

        StudyLog sobj1 = new StudyLog(lobj,"C Programming", 3.5,"Pointers in C");
        StudyLog sobj2 = new StudyLog(lobj,"Java Programming", 3.5,"Inheritance in Java");

        System.out.println(sobj1);
        System.out.println(sobj2);
    }  
}
