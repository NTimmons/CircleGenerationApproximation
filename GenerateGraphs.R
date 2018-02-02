#Setting working directory
library(ggplot2); library(scales); library(grid); library(RColorBrewer)
library(reshape2);

setwd("C:/Users/ngt26/source/repos/FloatErrorCompute/FloatErrorCompute")
Circle_A_Real     = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A.txt")
Circle_A_Approx1  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx1.txt")
Circle_A_Approx2  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx2.txt")
Circle_A_Approx3  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx3.txt")
Circle_A_Approx4  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx4.txt")
Circle_A_Approx5  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx5.txt")
Circle_A_Approx6  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx6.txt")
Circle_A_Approx7  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx7.txt")
Circle_A_Approx8  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx8.txt")
Circle_A_Approx9  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx9.txt")
Circle_A_Approx10 = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_A_Approx10.txt")

Circle_B_Real     = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B.txt")
Circle_B_Approx1  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx1.txt")
Circle_B_Approx2  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx2.txt")
Circle_B_Approx3  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx3.txt")
Circle_B_Approx4  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx4.txt")
Circle_B_Approx5  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx5.txt")
Circle_B_Approx6  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx6.txt")
Circle_B_Approx7  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx7.txt")
Circle_B_Approx8  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx8.txt")
Circle_B_Approx9  = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx9.txt")
Circle_B_Approx10 = read.csv("Results/FloatRoundingCumulativeError_CircleGeometry_B_Approx10.txt")

#plot(Circle_A_Real[(1:8),2], Circle_A_Real[(1:8),6], col = "red",
#     type="l", log='y', xlab=("Circle Radius"), ylab=("Mean Difference from Ground Truth"))
#lines(Circle_A_Approx[(1:8),2], Circle_A_Approx[(1:8),6], col = "blue", type="l")

for (i in 1:22) 
{
  start = i
  endIndex = i * 26
  Real_AlgorithmA   = Circle_A_Real[(i:endIndex),6]
  Approx_AlgorithmA1  = Circle_A_Approx1 [(i:endIndex),6]
  Approx_AlgorithmA2  = Circle_A_Approx2 [(i:endIndex),6]
  Approx_AlgorithmA3  = Circle_A_Approx3 [(i:endIndex),6]
  Approx_AlgorithmA4  = Circle_A_Approx4 [(i:endIndex),6]
  Approx_AlgorithmA5  = Circle_A_Approx5 [(i:endIndex),6]
  Approx_AlgorithmA6  = Circle_A_Approx6 [(i:endIndex),6]
  Approx_AlgorithmA7  = Circle_A_Approx7 [(i:endIndex),6]
  Approx_AlgorithmA8  = Circle_A_Approx8 [(i:endIndex),6]
  Approx_AlgorithmA9  = Circle_A_Approx9 [(i:endIndex),6]
  Approx_AlgorithmA10 = Circle_A_Approx10[(i:endIndex),6]
  
  title = paste("Specific Computation of Values. Offset=" , toString(Circle_A_Real[i,2]))
  p1 =  ggplot(NULL, aes(x = Circle_A_Real[i:endIndex,2]), log10="y") + 
        geom_line(aes(y = Real_AlgorithmA, colour="blue"), show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA1 , colour = "red1") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA2 , colour = "red2") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA3 , colour = "red3") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA4 , colour = "red4") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA5 , colour = "red5") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA6 , colour = "red6") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA7 , colour = "red7") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA8 , colour = "red8") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA9 , colour = "red9") , show.legend=TRUE) + 
        geom_line(aes(y = Approx_AlgorithmA10, colour = "red10") , show.legend=TRUE) + 
        xlab(label="Circle Radius") + 
        ylab("Mean Difference from Ground Truth") +
        scale_y_log10() +
        ggtitle(title) +
        #ylim(0, 1000)+
        scale_color_discrete(name = "Algorithm Type", labels = c("Standard", "Approximate Order 1", "Approximate Order 2",
                                                                 "Approximate Order 3", "Approximate Order 4", "Approximate Order 5",
                                                                 "Approximate Order 6", "Approximate Order 7", "Approximate Order 8",
                                                                 "Approximate Order 9", "Approximate Order 10"))

  #print(p1)
 
  pdpi = 300
  pwidth = 800 * (1/pdpi)
  pheight = 600 * (1/pdpi)
  ggsave(paste("Results/Direct_Radius_",toString(Circle_A_Real[i,2]), ".png"))#,width=pwidth, height=pheight, dpi=pdpi)
  
  print(paste("Finished index at:" , (i) ))
}

for (i in 1:22) {
  endIndex = i * 26
  
  Real_AlgorithmB = Circle_B_Real[(i:endIndex),6]
  #Approx_AlgorithmB1  = Circle_B_Approx1 [(i:endIndex),6]
  #Approx_AlgorithmB2  = Circle_B_Approx2 [(i:endIndex),6]
  #Approx_AlgorithmB3  = Circle_B_Approx3 [(i:endIndex),6]
  #Approx_AlgorithmB4  = Circle_B_Approx4 [(i:endIndex),6]
  Approx_AlgorithmB5  = Circle_B_Approx5 [(i:endIndex),6]
  Approx_AlgorithmB6  = Circle_B_Approx6 [(i:endIndex),6]
  Approx_AlgorithmB7  = Circle_B_Approx7 [(i:endIndex),6]
  Approx_AlgorithmB8  = Circle_B_Approx8 [(i:endIndex),6]
  Approx_AlgorithmB9  = Circle_B_Approx9 [(i:endIndex),6]
  Approx_AlgorithmB10 = Circle_B_Approx10[(i:endIndex),6]
  
  title = paste("Cumulative Computation of Values. Offset=" , toString(Circle_A_Real[i,2]))
  p2 =  ggplot(NULL, aes(x = Circle_B_Real[i:endIndex,2]), log10="y") + 
        geom_line(aes(y = Real_AlgorithmB, colour="blue") ) + 
        #geom_line(aes(y = Approx_AlgorithmB1 , colour = "red1")) + 
        #geom_line(aes(y = Approx_AlgorithmB2 , colour = "red2")) + 
        #geom_line(aes(y = Approx_AlgorithmB3 , colour = "red3")) + 
        #geom_line(aes(y = Approx_AlgorithmB4 , colour = "red4")) + 
        geom_line(aes(y = Approx_AlgorithmB5 , colour = "red5")) + 
        geom_line(aes(y = Approx_AlgorithmB6 , colour = "red6")) + 
        geom_line(aes(y = Approx_AlgorithmB7 , colour = "red7")) + 
        geom_line(aes(y = Approx_AlgorithmB8 , colour = "red8")) + 
        geom_line(aes(y = Approx_AlgorithmB9 , colour = "red9")) + 
        geom_line(aes(y = Approx_AlgorithmB10, colour = "red10")) + 
        xlab(label="Circle Radius") + 
        ylab("Mean Difference from Ground Truth") +
        scale_y_log10() +
        ggtitle(title) +
        ylim(0, 1000) +
        scale_color_discrete(name = "Algorithm Type", labels = c("Standard", "Approximate Order 1", "Approximate Order 2",
                                                                 "Approximate Order 3", "Approximate Order 4", "Approximate Order 5",
                                                                 "Approximate Order 6", "Approximate Order 7", "Approximate Order 8",
                                                                 "Approximate Order 9", "Approximate Order 10"))
  
  #print(p2)
  
  pdpi = 300
  pwidth = 800 * (1/pdpi)
  pheight = 600 * (1/pdpi)
  ggsave(paste("Results/Cumulative_Radius_",toString(Circle_A_Real[i,2]), ".png"))#,width=pwidth, height=pheight, dpi=pdpi)
  
  
  p2 =  ggplot(NULL, aes(x = Circle_B_Real[i:endIndex,2]), log10="y") + 
        geom_line(aes(y = Circle_B_Real[(i:endIndex),6], colour="blue")) + 
        #geom_line(aes(y = Approx_AlgorithmB1 , colour = "red1")) + 
        #geom_line(aes(y = Approx_AlgorithmB2 , colour = "red2")) + 
        #geom_line(aes(y = Approx_AlgorithmB3 , colour = "red3")) + 
        #geom_line(aes(y = Approx_AlgorithmB4 , colour = "red4")) + 
        geom_line(aes(y = Approx_AlgorithmB5 , colour = "red5")) + 
        geom_line(aes(y = Approx_AlgorithmB6 , colour = "red6")) + 
        geom_line(aes(y = Approx_AlgorithmB7 , colour = "red7")) + 
        geom_line(aes(y = Approx_AlgorithmB8 , colour = "red8")) + 
        geom_line(aes(y = Approx_AlgorithmB9 , colour = "red9")) + 
        geom_line(aes(y = Approx_AlgorithmB10, colour = "red10")) + 
        xlab(label="Circle Radius") + 
        ylab("Mean Difference from Ground Truth") +
        scale_y_log10() +
        ggtitle(title) +
        scale_color_discrete(name = "Algorithm Type", labels = c("Standard", "Approximate Order 1", "Approximate Order 2",
                                                                 "Approximate Order 3", "Approximate Order 4", "Approximate Order 5",
                                                                 "Approximate Order 6", "Approximate Order 7", "Approximate Order 8",
                                                                 "Approximate Order 9", "Approximate Order 10"))
  
  #print(p2)
  ggsave(paste("Results/Log_Cumulative_Radius_",toString(Circle_A_Real[i,2]), ".png"))#,width=pwidth, height=pheight, dpi=pdpi)
  print(paste("Finished index:" , (i) ))
  
  
  
  
}
