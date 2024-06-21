# 42_so_long
First 2D game demo by C.

Still in progress...

Some work plan:
1) read map:  
   check file name.                ✅  
   save map content to array.      ✅  
2) check map:  
   check exist.                    ✅  
   check shape.                    ✅  
   check bound.                    ✅  
   check element.                  ✅  
   check path.                     ✅  
3) display image in right position ✅   
4) player control                  ✅  


Bonus part:
1) enemy part.                     ✅
2) Moves show on the screen.       ✅  
3) Animation.

Some tips:   
If you can't run this demo, please reinstall MLX42.  
This demo doesn't work for the Windows system. Because for the read file part, Windows will use "\r\n" as the line ending. It is different from Linux and OS (by "\n"). If you want to test it by Windows, please change code "g->map->cont[i] = ft_strtrim(res, "\n")" to "g->map->cont[i] = ft_strtrim(res, "\r\n")". It is from create_map.c. Maybe I will publish the Windows version after finishing all the work.  
