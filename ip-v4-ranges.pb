Procedure ToLowerPow2(x)
   If x <> (x & (x-1))
    x = x | (x >> 1) 
    x = x | (x >> 2) 
    x = x | (x >> 4) 
    x = x | (x >> 8) 
    x = x | (x >> 16)  
    x = (x+1) >> 1
  EndIf
  ProcedureReturn x  
EndProcedure

Procedure get(start, ende)
  If start <= ende
    Debug Str(start) +  " to " + Str(ende)   
    p2=ToLowerPow2(ende - start + 1)
       
    Repeat    
      start2 = (ende) & (~ (p2 - 1))   
      ende2 = start2 + p2 - 1    
      p2 = p2 >> 1    
      If p2 < 1:p2=1:EndIf
    Until (start2 >= start) And (ende2 <= ende)  
    
    Debug p2
     
    Debug "RANGE:" +Str(start2) + " to "+Str(ende2)
    ; Debug (ende - p2) & (~ (p2 - 1)) + p2
    
    get(start, start2-1)
    get(ende2+1, ende)
  EndIf
  
EndProcedure

get(128,4096-1)





