import java.util.*;

class node{
    public int data;
    public node next;

    node(int no){
        this.data = no;
        this.next = null;
    }
}

class SinglyLL{
    public node first;
    public int iCount;

    public SinglyLL(){
        this.first = null;
        this.iCount = 0;
    }

    public int Count(){
        return iCount;
    }

    public void Display(){
        node temp = null;
        temp = first;
        while(temp!=null){
            System.out.print(temp.data+" -> ");
            temp = temp.next;
        }
        System.out.print("NULL\n");
    }

    public void InsertFirst(int iNo){
        node newn = new node(iNo);
        if(first == null){
            first = newn;
        }
        else{
            newn.next = first;
            first = newn;
        }
        iCount++;
    }

    public void InsertLast(int iNo){
        node newn = new node(iNo);
        node temp = null;
        if(first == null){
            first = newn;
        }
        else{
            temp = first;
            while(temp.next!=null){
                temp = temp.next;
            }
            temp.next = newn;
            newn.next = null;
        }
        iCount++;
    }

    public void InsertAtPos(){

    }

    public void DeleteFirst(){
        if(first == null){
            System.out.println("LL is empty");
            return;
        }
        else{
            first = first.next;
        }
        iCount--;
    }

    public void DeleteLast(){

    }

    public void DeleteAtPos(){

    }
}

class program452{
    public static void main(String A[]){
        SinglyLL sobj = new SinglyLL();
        int iRet = 0;

        sobj.InsertFirst(51);
        sobj.InsertFirst(21);
        sobj.InsertFirst(11);

        sobj.InsertLast(101);
        sobj.InsertLast(111);
        sobj.InsertLast(121);

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("No. of elements : "+iRet);

        sobj.DeleteFirst();

        sobj.Display();
        iRet = sobj.Count();
        System.out.println("No. of elements : "+iRet);
    }
} 
