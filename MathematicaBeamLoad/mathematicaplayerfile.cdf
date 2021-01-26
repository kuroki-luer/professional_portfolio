(* Content-type: application/vnd.wolfram.cdf.text *)

(*** Wolfram CDF File ***)
(* http://www.wolfram.com/cdf *)

(* CreatedBy='Mathematica 10.0' *)

(*************************************************************************)
(*                                                                       *)
(*  The Mathematica License under which this file was created prohibits  *)
(*  restricting third parties in receipt of this file from republishing  *)
(*  or redistributing it by any means, including but not limited to      *)
(*  rights management or terms of use, without the express consent of    *)
(*  Wolfram Research, Inc. For additional information concerning CDF     *)
(*  licensing and redistribution see:                                    *)
(*                                                                       *)
(*        www.wolfram.com/cdf/adopting-cdf/licensing-options.html        *)
(*                                                                       *)
(*************************************************************************)

(*CacheID: 234*)
(* Internal cache information:
NotebookFileLineBreakTest
NotebookFileLineBreakTest
NotebookDataPosition[      1064,         20]
NotebookDataLength[     25146,        542]
NotebookOptionsPosition[     25716,        538]
NotebookOutlinePosition[     26150,        557]
CellTagsIndexPosition[     26107,        554]
WindowFrame->Normal*)

(* Beginning of Notebook Content *)
Notebook[{
Cell[BoxData[
 TagBox[
  StyleBox[
   DynamicModuleBox[{$CellContext`D1$$ = 400, $CellContext`D2$$ = 
    300, $CellContext`p1$$ = 0, $CellContext`p2$$ = 10, $CellContext`p3$$ = 
    26, $CellContext`p4$$ = 32, Typeset`show$$ = True, 
    Typeset`bookmarkList$$ = {}, Typeset`bookmarkMode$$ = "Menu", 
    Typeset`animator$$, Typeset`animvar$$ = 1, Typeset`name$$ = 
    "\"untitled\"", Typeset`specs$$ = {{{
       Hold[$CellContext`D1$$], 400, "#1 Concentrated Load"}}, {{
       Hold[$CellContext`p1$$], 0, "#1 Concentrated Load Position 1"}, 0, 
      Dynamic[$CellContext`p2$$ - 0.5]}, {{
       Hold[$CellContext`p2$$], 10, "#1 Concentrated Load Position 2"}, 
      Dynamic[$CellContext`p1$$ + 1], 20}, {{
       Hold[$CellContext`p3$$], 26, "#2 Concentrated Load Position 1"}, 20, 
      Dynamic[$CellContext`p4$$ - 0.5]}, {{
       Hold[$CellContext`p4$$], 32, "#2 Concentrated Load Position 2"}, 
      Dynamic[$CellContext`p3$$ + 1], 32}, {{
       Hold[$CellContext`D2$$], 300, "#2 Concentrated Load"}}}, 
    Typeset`size$$ = {1161., {232.5, 239.5}}, Typeset`update$$ = 0, 
    Typeset`initDone$$, Typeset`skipInitDone$$ = 
    True, $CellContext`p1$15532$$ = 0, $CellContext`p2$15533$$ = 
    0, $CellContext`p3$15534$$ = 0, $CellContext`p4$15535$$ = 0}, 
    DynamicBox[Manipulate`ManipulateBoxes[
     1, StandardForm, 
      "Variables" :> {$CellContext`D1$$ = 400, $CellContext`D2$$ = 
        300, $CellContext`p1$$ = 0, $CellContext`p2$$ = 10, $CellContext`p3$$ = 
        26, $CellContext`p4$$ = 32}, "ControllerVariables" :> {
        Hold[$CellContext`p1$$, $CellContext`p1$15532$$, 0], 
        Hold[$CellContext`p2$$, $CellContext`p2$15533$$, 0], 
        Hold[$CellContext`p3$$, $CellContext`p3$15534$$, 0], 
        Hold[$CellContext`p4$$, $CellContext`p4$15535$$, 0]}, 
      "OtherVariables" :> {
       Typeset`show$$, Typeset`bookmarkList$$, Typeset`bookmarkMode$$, 
        Typeset`animator$$, Typeset`animvar$$, Typeset`name$$, 
        Typeset`specs$$, Typeset`size$$, Typeset`update$$, Typeset`initDone$$,
         Typeset`skipInitDone$$}, 
      "Body" :> ($CellContext`Picture = 
        Import["C:\\Users\\Jose A. Millan\\Desktop\\Capture1.png"]; \
$CellContext`dist1 = $CellContext`p2$$ - $CellContext`p1$$; \
$CellContext`dist2 = $CellContext`p4$$ - $CellContext`p3$$; 
       Solve[$CellContext`A + $CellContext`B - $CellContext`D1$$ \
$CellContext`dist1 - $CellContext`D2$$ $CellContext`dis2 == 
         0, $CellContext`B]; $CellContext`b = 
        Solve[(-$CellContext`D1$$) $CellContext`dist1 ($CellContext`p1$$ + \
$CellContext`dist1/2) + $CellContext`B 
            20 - $CellContext`D2$$ $CellContext`dist2 ($CellContext`p3$$ + \
$CellContext`dist2/2) == 0, $CellContext`B]; $CellContext`b1 = 
        Values[$CellContext`b]; $CellContext`b2 = Part[
          Flatten[$CellContext`b1, 1], 1]; $CellContext`a = 
        Solve[$CellContext`A + $CellContext`b1 - $CellContext`D1$$ \
$CellContext`dist1 - $CellContext`D2$$ $CellContext`dist2 == 
          0, $CellContext`A]; $CellContext`a1 = 
        Values[$CellContext`a]; $CellContext`a2 = Part[
          Flatten[$CellContext`a1, 1], 1]; If[
         And[$CellContext`p1$$ != 0, $CellContext`p2$$ != 20], $CellContext`f1[
            Pattern[$CellContext`x, 
             Blank[]]] = $CellContext`a2; $CellContext`f2[
            Pattern[$CellContext`x$, 
             
             Blank[]]] = $CellContext`a2 - $CellContext`D1$$ ($CellContext`x$ - \
$CellContext`p1$$); $CellContext`f3[
            Pattern[$CellContext`x$, 
             
             Blank[]]] = $CellContext`f2[$CellContext`p2$$]; \
$CellContext`limit = $CellContext`f3[20]; $CellContext`ff1[
            Pattern[$CellContext`x$, 
             Blank[]]] = Which[0 < $CellContext`x$ < $CellContext`p1$$, 
            $CellContext`f1[$CellContext`x$], $CellContext`p1$$ < \
$CellContext`x$ < $CellContext`p2$$, 
            $CellContext`f2[$CellContext`x$], $CellContext`p2$$ < \
$CellContext`x$ < 20, 
            $CellContext`f3[$CellContext`x$]]; Null, If[
           
           And[$CellContext`p1$$ == 0, $CellContext`p2$$ == 
            20], $CellContext`f1[
              Pattern[$CellContext`x$, 
               
               Blank[]]] = $CellContext`a2 - $CellContext`D1$$ \
$CellContext`x$; $CellContext`limit = $CellContext`f1[20]; $CellContext`ff1[
              Pattern[$CellContext`x, 
               Blank[]]] = Which[0 < $CellContext`x < 20, 
              $CellContext`f1[$CellContext`x]]; Null, If[
             
             And[$CellContext`p1$$ != 0, $CellContext`p2$$ == 
              20], $CellContext`f1[
                Pattern[$CellContext`x, 
                 Blank[]]] = $CellContext`a2; $CellContext`f2[
                Pattern[$CellContext`x$, 
                 
                 Blank[]]] = $CellContext`a2 - $CellContext`D1$$ \
($CellContext`x$ - $CellContext`p1$$); $CellContext`limit = $CellContext`f2[
               20]; $CellContext`ff1[
                Pattern[$CellContext`x$, 
                 Blank[]]] = Which[0 < $CellContext`x$ < $CellContext`p1$$, 
                $CellContext`f1[$CellContext`x$], $CellContext`p1$$ < \
$CellContext`x$ < 20, 
                $CellContext`f2[$CellContext`x$]]; Null, If[
               
               And[$CellContext`p1$$ == 0, $CellContext`p2$$ != 
                20], $CellContext`f1[
                  Pattern[$CellContext`x$, 
                   
                   Blank[]]] = $CellContext`a2 - $CellContext`D1$$ \
$CellContext`x$; $CellContext`f2[
                  Pattern[$CellContext`x$, 
                   
                   Blank[]]] = $CellContext`f1[$CellContext`p2$$]; \
$CellContext`limit = $CellContext`f2[20]; $CellContext`ff1[
                  Pattern[$CellContext`x$, 
                   Blank[]]] = Which[0 < $CellContext`x$ < $CellContext`p2$$, 
                  $CellContext`f1[$CellContext`x$], $CellContext`p2$$ < \
$CellContext`x$ < 20, 
                  $CellContext`f2[$CellContext`x$]]; Null]; Null]; Null]; 
         Null]; If[
         And[$CellContext`p3$$ == 20, $CellContext`p4$$ == 
          32], $CellContext`f1b[
            Pattern[$CellContext`x$, 
             
             Blank[]]] = ($CellContext`limit + $CellContext`b2) - \
$CellContext`D2$$ ($CellContext`x$ - 20); $CellContext`ff2[
            Pattern[$CellContext`x, 
             Blank[]]] = Which[20 < $CellContext`x < 32, 
            $CellContext`f1b[$CellContext`x]]; Null, If[
           
           And[$CellContext`p3$$ != 20, $CellContext`p4$$ != 
            32], $CellContext`f1b[
              Pattern[$CellContext`x, 
               
               Blank[]]] = $CellContext`limit + $CellContext`b2; \
$CellContext`f2b[
              Pattern[$CellContext`x$, 
               Blank[]]] = $CellContext`f1b[
              20] - $CellContext`D2$$ ($CellContext`x$ - $CellContext`p3$$); \
$CellContext`f3b[
              Pattern[$CellContext`x$, 
               
               Blank[]]] = $CellContext`f2b[$CellContext`p4$$]; \
$CellContext`ff2[
              Pattern[$CellContext`x$, 
               Blank[]]] = Which[20 < $CellContext`x$ < $CellContext`p3$$, 
              $CellContext`f1b[$CellContext`x$], $CellContext`p3$$ < \
$CellContext`x$ < $CellContext`p4$$, 
              $CellContext`f2b[$CellContext`x$], $CellContext`p4$$ < \
$CellContext`x$ < 32, 
              $CellContext`f3b[$CellContext`x$]]; Null, If[
             
             And[$CellContext`p3$$ == 20, $CellContext`p4$$ != 
              32], $CellContext`f1b[
                Pattern[$CellContext`x$, 
                 
                 Blank[]]] = ($CellContext`limit + $CellContext`b2) - \
$CellContext`D2$$ ($CellContext`x$ - 20); $CellContext`f2b[
                Pattern[$CellContext`x$, 
                 
                 Blank[]]] = $CellContext`f1b[$CellContext`p4$$]; \
$CellContext`ff2[
                Pattern[$CellContext`x$, 
                 Blank[]]] = Which[20 < $CellContext`x$ < $CellContext`p4$$, 
                $CellContext`f1b[$CellContext`x$], $CellContext`p4$$ < \
$CellContext`x$ < 32, 
                $CellContext`f2b[$CellContext`x$]]; Null, If[
               
               And[$CellContext`p3$$ != 20, $CellContext`p4$$ == 
                32], $CellContext`f1b[
                  Pattern[$CellContext`x, 
                   
                   Blank[]]] = $CellContext`limit + $CellContext`b2; \
$CellContext`f2b[
                  Pattern[$CellContext`x$, 
                   
                   Blank[]]] = ($CellContext`limit + $CellContext`b2) - \
$CellContext`D2$$ ($CellContext`x$ - $CellContext`p3$$); $CellContext`ff2[
                  Pattern[$CellContext`x$, 
                   Blank[]]] = Which[20 < $CellContext`x$ < $CellContext`p3$$, 
                  $CellContext`f1b[$CellContext`x$], $CellContext`p3$$ < \
$CellContext`x$ < 32, 
                  $CellContext`f2b[$CellContext`x$]]; Null]; Null]; Null]; 
         Null]; If[
         And[$CellContext`p1$$ != 0, $CellContext`p2$$ != 20], $CellContext`f1[
            Pattern[$CellContext`x, 
             Blank[]]] = $CellContext`a2; $CellContext`f1I[
            Pattern[$CellContext`t, 
             Blank[]]] = Integrate[
            $CellContext`f1[$CellContext`x], {$CellContext`x, 
             0, $CellContext`t}]; $CellContext`f2[
            Pattern[$CellContext`x$, 
             
             Blank[]]] = $CellContext`a2 - $CellContext`D1$$ ($CellContext`x$ - \
$CellContext`p1$$); $CellContext`f2Ii[
            Pattern[$CellContext`t, 
             Blank[]]] = Integrate[
            $CellContext`f2[$CellContext`x], {$CellContext`x, 
             0, $CellContext`t}]; $CellContext`f2I[
            Pattern[$CellContext`t$, 
             
             Blank[]]] = $CellContext`f2Ii[$CellContext`t$] - \
$CellContext`f2Ii[$CellContext`p1$$] + $CellContext`f1I[$CellContext`p1$$]; \
$CellContext`f3[
            Pattern[$CellContext`x$, 
             Blank[]]] = $CellContext`f2[$CellContext`p2$$]; $CellContext`f3Ii[
            Pattern[$CellContext`t, 
             Blank[]]] = Integrate[
            $CellContext`f3[$CellContext`x], {$CellContext`x, 
             0, $CellContext`t}]; $CellContext`f3I[
            Pattern[$CellContext`t$, 
             
             Blank[]]] = -$CellContext`f3Ii[$CellContext`p2$$] + \
$CellContext`f3Ii[$CellContext`t$] + $CellContext`f2I[$CellContext`p2$$]; \
$CellContext`limitI = $CellContext`f3I[20]; $CellContext`ff1I[
            Pattern[$CellContext`t$, 
             Blank[]]] = Which[0 < $CellContext`t$ < $CellContext`p1$$, 
            $CellContext`f1I[$CellContext`t$], $CellContext`p1$$ < \
$CellContext`t$ < $CellContext`p2$$, 
            $CellContext`f2I[$CellContext`t$], $CellContext`p2$$ < \
$CellContext`t$ < 20, 
            $CellContext`f3I[$CellContext`t$]]; Null, If[
           
           And[$CellContext`p1$$ == 0, $CellContext`p2$$ == 
            20], $CellContext`f1[
              Pattern[$CellContext`x$, 
               
               Blank[]]] = $CellContext`a2 - $CellContext`D1$$ \
$CellContext`x$; $CellContext`f1I[
              Pattern[$CellContext`t, 
               Blank[]]] = Integrate[
              $CellContext`f1[$CellContext`x], {$CellContext`x, 
               0, $CellContext`t}]; $CellContext`limitI = $CellContext`f1I[
             20]; $CellContext`ff1I[
              Pattern[$CellContext`t, 
               Blank[]]] = Which[0 < $CellContext`t < 20, 
              $CellContext`f1I[$CellContext`t]]; Null, If[
             
             And[$CellContext`p1$$ != 0, $CellContext`p2$$ == 
              20], $CellContext`f1[
                Pattern[$CellContext`x, 
                 Blank[]]] = $CellContext`a2; $CellContext`f1I[
                Pattern[$CellContext`t, 
                 Blank[]]] = Integrate[
                $CellContext`f1[$CellContext`x], {$CellContext`x, 
                 0, $CellContext`t}]; $CellContext`f2[
                Pattern[$CellContext`x$, 
                 
                 Blank[]]] = $CellContext`a2 - $CellContext`D1$$ \
($CellContext`x$ - $CellContext`p1$$); $CellContext`f2Ii[
                Pattern[$CellContext`t, 
                 Blank[]]] = Integrate[
                $CellContext`f2[$CellContext`x], {$CellContext`x, 
                 0, $CellContext`t}]; $CellContext`f2I[
                Pattern[$CellContext`t$, 
                 
                 Blank[]]] = $CellContext`f2Ii[$CellContext`t$] - \
$CellContext`f2Ii[$CellContext`p1$$] + $CellContext`f1I[$CellContext`p1$$]; \
$CellContext`limitI = $CellContext`f2I[20]; $CellContext`ff1I[
                Pattern[$CellContext`t$, 
                 Blank[]]] = Which[0 < $CellContext`t$ < $CellContext`p1$$, 
                $CellContext`f1I[$CellContext`t$], $CellContext`p1$$ < \
$CellContext`t$ < 20, 
                $CellContext`f2I[$CellContext`t$]]; Null, If[
               
               And[$CellContext`p1$$ == 0, $CellContext`p2$$ != 
                20], $CellContext`f1[
                  Pattern[$CellContext`x$, 
                   
                   Blank[]]] = $CellContext`a2 - $CellContext`D1$$ \
$CellContext`x$; $CellContext`f1I[
                  Pattern[$CellContext`t, 
                   Blank[]]] = Integrate[
                  $CellContext`f1[$CellContext`x], {$CellContext`x, 
                   0, $CellContext`t}]; $CellContext`f2[
                  Pattern[$CellContext`x$, 
                   
                   Blank[]]] = $CellContext`f1[$CellContext`p2$$]; \
$CellContext`f2Ii[
                  Pattern[$CellContext`t, 
                   Blank[]]] = Integrate[
                  $CellContext`f2[$CellContext`x], {$CellContext`x, 
                   0, $CellContext`t}]; $CellContext`f2I[
                  Pattern[$CellContext`t$, 
                   
                   Blank[]]] = $CellContext`f2Ii[$CellContext`t$] - \
$CellContext`f2Ii[$CellContext`p2$$] + $CellContext`f1I[$CellContext`p2$$]; \
$CellContext`limitI = $CellContext`f2I[20]; $CellContext`ff1I[
                  Pattern[$CellContext`t$, 
                   Blank[]]] = Which[0 < $CellContext`t$ < $CellContext`p2$$, 
                  $CellContext`f1I[$CellContext`t$], $CellContext`p2$$ < \
$CellContext`t$ < 20, 
                  $CellContext`f2I[$CellContext`t$]]; Null]; Null]; Null]; 
         Null]; If[
         And[$CellContext`p3$$ == 20, $CellContext`p4$$ == 
          32], $CellContext`f1b[
            Pattern[$CellContext`x$, 
             
             Blank[]]] = ($CellContext`limit + $CellContext`b2) - \
$CellContext`D2$$ ($CellContext`x$ - 20); $CellContext`f1biI[
            Pattern[$CellContext`t, 
             Blank[]]] = Integrate[
            $CellContext`f1b[$CellContext`x], {$CellContext`x, 
             0, $CellContext`t}]; $CellContext`f1bI[
            Pattern[$CellContext`t, 
             
             Blank[]]] = $CellContext`f1biI[$CellContext`t] - \
$CellContext`f1biI[20] + $CellContext`limitI; $CellContext`ff2I[
            Pattern[$CellContext`t, 
             Blank[]]] = Which[20 < $CellContext`t < 32, 
            $CellContext`f1bI[$CellContext`t]]; Null, If[
           
           And[$CellContext`p3$$ != 20, $CellContext`p4$$ != 
            32], $CellContext`f1b[
              Pattern[$CellContext`x, 
               
               Blank[]]] = $CellContext`limit + $CellContext`b2; \
$CellContext`f1biI[
              Pattern[$CellContext`t, 
               Blank[]]] = Integrate[
              $CellContext`f1b[$CellContext`x], {$CellContext`x, 
               0, $CellContext`t}]; $CellContext`f1bI[
              Pattern[$CellContext`t, 
               
               Blank[]]] = $CellContext`f1biI[$CellContext`t] - \
$CellContext`f1biI[20] + $CellContext`limitI; $CellContext`f2b[
              Pattern[$CellContext`x$, 
               Blank[]]] = $CellContext`f1b[
              20] - $CellContext`D2$$ ($CellContext`x$ - $CellContext`p3$$); \
$CellContext`f2biI[
              Pattern[$CellContext`t, 
               Blank[]]] = Integrate[
              $CellContext`f2b[$CellContext`x], {$CellContext`x, 
               0, $CellContext`t}]; $CellContext`f2bI[
              Pattern[$CellContext`t$, 
               
               Blank[]]] = $CellContext`f2biI[$CellContext`t$] - \
$CellContext`f2biI[$CellContext`p3$$] + $CellContext`f1bI[$CellContext`p3$$]; \
$CellContext`f3b[
              Pattern[$CellContext`x$, 
               
               Blank[]]] = $CellContext`f2b[$CellContext`p4$$]; \
$CellContext`f3biI[
              Pattern[$CellContext`t, 
               Blank[]]] = Integrate[
              $CellContext`f3b[$CellContext`x], {$CellContext`x, 
               0, $CellContext`t}]; $CellContext`f3bI[
              Pattern[$CellContext`t$, 
               
               Blank[]]] = $CellContext`f3biI[$CellContext`t$] - \
$CellContext`f3biI[$CellContext`p4$$] + $CellContext`f2bI[$CellContext`p4$$]; \
$CellContext`ff2I[
              Pattern[$CellContext`t$, 
               Blank[]]] = Which[20 < $CellContext`t$ < $CellContext`p3$$, 
              $CellContext`f1bI[$CellContext`t$], $CellContext`p3$$ < \
$CellContext`t$ < $CellContext`p4$$, 
              $CellContext`f2bI[$CellContext`t$], $CellContext`p4$$ < \
$CellContext`t$ < 32, 
              $CellContext`f3bI[$CellContext`t$]]; Null, If[
             
             And[$CellContext`p3$$ == 20, $CellContext`p4$$ != 
              32], $CellContext`f1b[
                Pattern[$CellContext`x$, 
                 
                 Blank[]]] = ($CellContext`limit + $CellContext`b2) - \
$CellContext`D2$$ ($CellContext`x$ - 20); $CellContext`f1biI[
                Pattern[$CellContext`t, 
                 Blank[]]] = Integrate[
                $CellContext`f1b[$CellContext`x], {$CellContext`x, 
                 0, $CellContext`t}]; $CellContext`f1bI[
                Pattern[$CellContext`t, 
                 
                 Blank[]]] = $CellContext`f1biI[$CellContext`t] - \
$CellContext`f1biI[20] + $CellContext`limitI; $CellContext`f2b[
                Pattern[$CellContext`x$, 
                 
                 Blank[]]] = $CellContext`f1b[$CellContext`p4$$]; \
$CellContext`f2biI[
                Pattern[$CellContext`t, 
                 Blank[]]] = Integrate[
                $CellContext`f2b[$CellContext`x], {$CellContext`x, 
                 0, $CellContext`t}]; $CellContext`f2bI[
                Pattern[$CellContext`t$, 
                 
                 Blank[]]] = $CellContext`f2biI[$CellContext`t$] - \
$CellContext`f2biI[$CellContext`p4$$] - $CellContext`f1bI[$CellContext`p4$$]; \
$CellContext`ff2I[
                Pattern[$CellContext`t$, 
                 Blank[]]] = Which[20 < $CellContext`t$ < $CellContext`p4$$, 
                $CellContext`f1bI[$CellContext`t$], $CellContext`p4$$ < \
$CellContext`t$ < 32, 
                $CellContext`f2bI[$CellContext`t$]]; Null, If[
               
               And[$CellContext`p3$$ != 20, $CellContext`p4$$ == 
                32], $CellContext`f1b[
                  Pattern[$CellContext`x, 
                   
                   Blank[]]] = $CellContext`limit + $CellContext`b2; \
$CellContext`f1biI[
                  Pattern[$CellContext`t, 
                   Blank[]]] = Integrate[
                  $CellContext`f1b[$CellContext`x], {$CellContext`x, 
                   0, $CellContext`t}]; $CellContext`f1bI[
                  Pattern[$CellContext`t, 
                   
                   Blank[]]] = $CellContext`f1biI[$CellContext`t] - \
$CellContext`f1biI[20] + $CellContext`limitI; $CellContext`f2b[
                  Pattern[$CellContext`x$, 
                   
                   Blank[]]] = ($CellContext`limit + $CellContext`b2) - \
$CellContext`D2$$ ($CellContext`x$ - $CellContext`p3$$); $CellContext`f2biI[
                  Pattern[$CellContext`t, 
                   Blank[]]] = Integrate[
                  $CellContext`f2b[$CellContext`x], {$CellContext`x, 
                   0, $CellContext`t}]; $CellContext`f2bI[
                  Pattern[$CellContext`t$, 
                   
                   Blank[]]] = $CellContext`f2biI[$CellContext`t$] - \
$CellContext`f2biI[$CellContext`p3$$] + $CellContext`f1bI[$CellContext`p3$$]; \
$CellContext`ff2I[
                  Pattern[$CellContext`t$, 
                   Blank[]]] = Which[20 < $CellContext`t$ < $CellContext`p3$$, 
                  $CellContext`f1bI[$CellContext`t$], $CellContext`p3$$ < \
$CellContext`t$ < 32, 
                  $CellContext`f2bI[$CellContext`t$]]; Null]; Null]; Null]; 
         Null]; Grid[{{
           Plot[
            Piecewise[{{
               $CellContext`ff1[$CellContext`x], 
               Inequality[0, LessEqual, $CellContext`x, Less, 20]}, {
               $CellContext`ff2[$CellContext`x], 20 <= $CellContext`x <= 
               32}}], {$CellContext`x, 0, 32}, PlotStyle -> {Black, Thick}, 
            ImageSize -> Medium, AxesLabel -> {"m", "N"}, 
            PlotLegends -> {"Shear Force"}, Filling -> Axis, FillingStyle -> 
            LightGray], 
           Plot[
            Piecewise[{{
               $CellContext`ff1I[$CellContext`t], 
               Inequality[0, LessEqual, $CellContext`t, Less, 20]}, {
               $CellContext`ff2I[$CellContext`t], 20 <= $CellContext`t <= 
               32}}], {$CellContext`t, 0, 32}, PlotStyle -> {Blue, Thick}, 
            ImageSize -> Medium, AxesLabel -> {"m", "N\[CenterDot]m"}, 
            PlotLegends -> {"Bending Moment"}, Filling -> Axis, FillingStyle -> 
            LightBlue]}, {
           Image[$CellContext`Picture, ImageSize -> Large], 
           Graphics[{
             Rectangle[{0, 0}, {32, 1}], {Red, 
              Rectangle[{$CellContext`p1$$, 1}, {$CellContext`p2$$, 2}]}, {
             Orange, 
              Rectangle[{$CellContext`p3$$, 1}, {$CellContext`p4$$, 2}]}, {
             Black, 
              Line[{{0, -2}, {0, -0.5}}], 
              Line[{{20, -2}, {20, -0.5}}], 
              Line[{{0, -1.25}, {20, -1.25}}], 
              Line[{{32, -2}, {32, -0.5}}], 
              Line[{{20, -1.25}, {32, -1.25}}]}, 
             Text[
              
              Style[$CellContext`p1$$, 12, Bold, 
               "Tahoma"], {$CellContext`p1$$, 2.5}], 
             Text[
              
              Style[$CellContext`p2$$, 12, Bold, 
               "Tahoma"], {$CellContext`p2$$, 1.5}], 
             Text[
              
              Style[$CellContext`p3$$, 12, Bold, 
               "Tahoma"], {$CellContext`p3$$, 2.5}], 
             Text[
              
              Style[$CellContext`p4$$, 12, Bold, 
               "Tahoma"], {$CellContext`p4$$, 1.5}], 
             Text[
              Style[20, 12, Bold, "Tahoma"], {10, -2}], 
             Text[
              Style[12, 12, Bold, "Tahoma"], {26, -2}], 
             Text[
              
              Style[$CellContext`D1$$, 12, Bold, 
               "Tahoma"], {($CellContext`p1$$ + $CellContext`p2$$)/2, 3.5}], 
             Text[
              
              Style[$CellContext`D2$$, 12, Bold, 
               "Tahoma"], {($CellContext`p3$$ + $CellContext`p4$$)/2, 3.5}]}, 
            ImageSize -> Large]}}]), 
      "Specifications" :> {{{$CellContext`D1$$, 400, "#1 Concentrated Load"}, 
         ControlType -> 
         InputField[Number]}, {{$CellContext`p1$$, 0, 
          "#1 Concentrated Load Position 1"}, 0, 
         Dynamic[$CellContext`p2$$ - 0.5]}, {{$CellContext`p2$$, 10, 
          "#1 Concentrated Load Position 2"}, 
         Dynamic[$CellContext`p1$$ + 1], 
         20}, {{$CellContext`p3$$, 26, "#2 Concentrated Load Position 1"}, 20, 
         Dynamic[$CellContext`p4$$ - 0.5]}, {{$CellContext`p4$$, 32, 
          "#2 Concentrated Load Position 2"}, 
         Dynamic[$CellContext`p3$$ + 1], 
         32}, {{$CellContext`D2$$, 300, "#2 Concentrated Load"}, ControlType -> 
         InputField[Number]}}, "Options" :> {ControlPlacement -> Left}, 
      "DefaultOptions" :> {}],
     ImageSizeCache->{1604., {265., 272.}},
     SingleEvaluation->True],
    Deinitialization:>None,
    DynamicModuleValues:>{},
    SynchronousInitialization->True,
    UnsavedVariables:>{Typeset`initDone$$},
    UntrackedVariables:>{Typeset`size$$}], "Manipulate",
   Deployed->True,
   StripOnInput->False],
  Manipulate`InterpretManipulate[1]]], "Output"]
},
WindowSize->{1920, 997},
Visible->True,
ScrollingOptions->{"VerticalScrollRange"->Fit},
ShowCellBracket->Automatic,
CellContext->Notebook,
TrackCellChangeTimes->False,
FrontEndVersion->"10.0 for Microsoft Windows (64-bit) (July 1, 2014)",
StyleDefinitions->"Default.nb"
]
(* End of Notebook Content *)

(* Internal cache information *)
(*CellTagsOutline
CellTagsIndex->{}
*)
(*CellTagsIndex
CellTagsIndex->{}
*)
(*NotebookFileOutline
Notebook[{
Cell[1464, 33, 24248, 503, 554, "Output"]
}
]
*)

(* End of internal cache information *)

(* NotebookSignature 4w05lBh9lZm1oC1nS7I6cX2F *)
