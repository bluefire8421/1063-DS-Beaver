/**
* @ProgramName: Program-1
* @Author: Sarah Beaver 
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2017
* @Date: 30 01 2017
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
    int r;
    int g;
    int b;
};
/**
* @FunctionName: flipVert
* @Description: 
*     Loops through a 2D array and switches each column across the vertical
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image,int width,int height){
    int temp;
    for(int i=0;i<height/2;i++)
    {
      for(int j=0;j<width;j++)
      {
        temp=image[i][j].r;
        image[i][j].r=image[height-1-i][j].r;
        image[height-1-i][j].r=temp;
        temp=image[i][j].g;
        image[i][j].g=image[height-1-i][j].g;
        image[height-1-i][j].g=temp;
        temp=image[i][j].b;
        image[i][j].b=image[height-1-i][j].b;
        image[height-1-i][j].b=temp;
      }
    }
}
/**
* @FunctionName: flipHorz
* @Description: 
*     Loops through a 2D array and switches each row across the horizontal
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipHorz(rgb** image,int width,int height){
    rgb temp;
    for(int i=0;i<height;i++)
    {
      for(int j=0;j<width/2;j++)
      {
        temp.r=image[i][j].r;
        temp.g=image[i][j].g;
        temp.b=image[i][j].b;
        image[i][j].r=image[i][width-j-1].r;
        image[i][j].g=image[i][width-j-1].g;
        image[i][j].b=image[i][width-j-1].b;
        image[i][width-j-1].r=temp.r;
        image[i][width-j-1].g=temp.g;
        image[i][width-j-1].b=temp.b;
;      }
    }
}
/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image,int width,int height){
    int temp;
    for(int i=0;i<height;i++)
    {
      for(int j=0;j<width;j++)
      {
        temp=(image[i][j].r+image[i][j].g+image[i][j].b)/3;
        image[i][j].r=temp;
        image[i][j].g=temp;
        image[i][j].b=temp;
      }
    }
}
/**
* @FunctionName: changeColor
* @Description: 
*     Loops through a 2D array and turns every RGB value into the new color.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
*    rgb newColor - a struct holding the new color for the image.
* @Returns:
*    void
*/
void changeColor(rgb** image,int width, int height, rgb newColor){
   for(int i=0;i<height;i++)
   {
     for(int j=0;j<width;j++)
     {
       image[i][j].r=newColor.r;
       image[i][j].g=newColor.g;
       image[i][j].b=newColor.b;
     }
   }
}
int main(){
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("test.txt");
    ofile.open("output.txt");   
    
    int width;               //width of image
    int height;              //height of image
    
    rgb **imgArray;         //Pointer var for our 2D array          
    
    ifile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right 
                            //size.
    
    imgArray = new rgb*[height];    //This array points to every row
    
    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }
    
    //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }
    grayScale(imgArray,width,height);
    //We could make any changes we want to the color image here
    
    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }
    
    flipVert(imgArray,width,height);
    //We could make any changes we want to the color image here
    
    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }
    flipHorz(imgArray,width,height);
    //We could make any changes we want to the color image here
    
    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }
    
    
  return 0;
}
