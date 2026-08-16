import java.util.*;

class Matrix{
    protected int Arr[][];
    protected int iRow;
    protected int iCol;

    public Matrix(int iRow,int iCol){
        Arr = new int[iRow][iCol]; 

        this.iRow = iRow;
        this.iCol = iCol;

        System.out.println("Inside Matrix Constructor");
    }

    public void Accept(){
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the elements of matrix : ");        

        for(int i=0;i<iRow;i++){
            for(int j=0;j<iCol;j++){
                Arr[i][j] = sobj.nextInt();
            }
        }

        sobj.close();
    }

    public void Display(){
        System.out.println("Elements of matrix : ");        

        for(int i=0;i<iRow;i++){
            for(int j=0;j<iCol;j++){
                System.out.print( Arr[i][j] + "\t"); 
            }
            System.out.println();        
        }
    }
}

class MatrixLB extends Matrix{
    public MatrixLB(int iRow,int iCol){
        super(iRow,iCol);
    }

    public int SummationAll(){
        int iSum = 0;
        for(int i=0;i<iRow;i++){
            for(int j=0;j<iCol;j++){
                iSum += Arr[i][j];
            }  
        }
        return iSum;
    }
}

class program796{
    public static void main(String A[]){
        Scanner sobj = new Scanner(System.in);
        int iRow = 0,iCol=0;
        int i=0,j=0;
        int iRet = 0;

        System.out.println("Enter number of rows :");
        iRow = sobj.nextInt();
        
        System.out.println("Enter number of columns :");
        iCol = sobj.nextInt();

        MatrixLB mobj = new MatrixLB(iRow, iCol);

        mobj.Accept();
        mobj.Display();

        iRet = mobj.SummationAll();

        System.out.println("Summation of all elements is : " + iRet);

        System.gc();

        int Arr[][] = new int[iRow][iCol];

        

    }
}