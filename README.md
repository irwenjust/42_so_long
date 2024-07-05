# 42_so_long
First 2D game demo by C.

The grade is 125/100.  
![Mandatory](https://github.com/irwenjust/42_so_long/assets/35918898/2af7d3a8-7258-48a1-b162-b3b99f5de904)  
Some parts of work:  
Mandatory part:  
1) read map:  
   check the file name.                     ✅  
   save map content to the array.           ✅  
2) check map:  
   check exist.                             ✅  
   check shape.                             ✅  
   check bound.                             ✅  
   check element.                           ✅  
   check path.                              ✅  
3) display the image in the right position. ✅   
4) player control                           ✅  


Bonus part:
1) enemy part.                              ✅
2) Moves show on the screen.                ✅  
3) Animation.                               ✅  

Some tips:   
This project could do so many things. It just depends on how much time you want to spend on it. For me, I think the current progress should be enough for the "60 hours" project. I will try more, but not now. :)  

This demo doesn't work for the Windows system. Because for the read file part, Windows will use "\r\n" as the line ending. It is different from Linux and OS (by "\n"). If you want to test it by Windows, please change code "g->map->cont[i] = ft_strtrim(res, "\n")" to "g->map->cont[i] = ft_strtrim(res, "\r\n")". It is from create_map.c. Maybe I will publish the Windows version after finishing all the work.  

If you use Vargrind to test the memory leak, there probably will be some error messages from the "reachable" part. That could be fine if all of the error messages are from MLX42. Please check carefully for error messages. You could also add a suppressions file to ignore these messages. But, at least in my opinion, I don't want to do this.  
