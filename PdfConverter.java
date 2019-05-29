package pdfConverter;



public class PdfConverter {

	
	
        
      
        
        	
	public static void main(String[] args) throws Exception {
		
		PdfToText p = new PdfToText();
		//p.inputFileName();
		boolean isPdf=p.tain();
		System.out.println(isPdf);
		p.getRectangel();
		p.drawRectangel();
	}

}
