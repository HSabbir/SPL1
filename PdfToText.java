package pdfConverter;

import java.util.Scanner;
import java.awt.Color;
import java.io.*;
import java.util.regex.*; 
//import java.swing.JApplet;
//import java.awt.*;

//package com.aspose.words.examples.rendering_printing;

import com.aspose.words.*;
import com.aspose.words.Shape;
//import com.aspose.words.examples.Utils;

public class PdfToText {
	public  String Begin_Text= "BT";
    public  String End_Text= "ET";
    public  String Header= "%PDF-";
    public  String Rectangel= "re";
    public  String StartGraphics= "stream";
    public  String StopGraphics= "endstream";
    
    public   String inputFileName="gpdf.pdf";
    public  String outputFileName;
    
    Scanner s= new Scanner(System.in);
    
    
    public void inputFileName()
    {
    	//System.out.println("Enter Input file name in .pdf extension");
    	//inputFileName=s.nextLine();
    	//System.out.println("Enter Output File Nmae in .doc extension");
		//outputFileName=s.nextLine();
		
    }
    
    public  boolean tain()throws Exception{    
        FileReader fr=new FileReader(inputFileName);    
        BufferedReader br=new BufferedReader(fr);    

        String t;   
        t=br.readLine();
        
        if(t.substring(0,5).equals(Header)) return true;
        else return false;
  }
    public void drawRectangel(Object DocumentBuilderInsertParagraph)
    {
    	
    }
    public void getRectangel()throws Exception
    {
    	FileReader fr=new FileReader(inputFileName);    
        BufferedReader br=new BufferedReader(fr);    

        String t=br.readLine();  
        while(!t.equals("%%EOF")) {
        	System.out.println(t);
        
    	if(Pattern.matches("[0-9]{1,4} [0-9]{1,4} [0-9]{1,4} [0-9]{1,4} [r]{1}[e]{1}", t))
    			{
    				//String u="200 300 50 75 re";
    				String arr[]=t.split(" ");
    				int brr[] = {-1,-1,-1,-1};
    				
    				for(int i=0;i<4;i++)
    				{
    					//String number = arr[i];
    				    brr[i] = Integer.parseInt(arr[i]);
    				    System.out.println(brr[i]);
    				}
    			}
        t=br.readLine();
    }

}
}