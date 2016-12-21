---
title: "Manipuladores de Fluxo de Sa&#237;da com um Argumento (int ou long) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "fluxos de saída, manipuladores com argumento int ou long"
ms.assetid: 338f3164-b5e2-4c5a-a605-7d9dc3629ca1
caps.latest.revision: 8
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Manipuladores de Fluxo de Sa&#237;da com um Argumento (int ou long)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

A biblioteca de classes iostream fornece um conjunto de macros para criar manipuladores com parâmetros.  Os manipuladores com um único `int` argumento ou de `long` é um caso especial.  Para criar um manipulador de fluxo de saída que aceita `int` ou único argumento de `long` \(como `setw`\), você deverá usar a macro do \_Smanip, que é definido \<no iomanip\>.  Este exemplo define um manipulador de `fillblank` que insere um número especificado de espaços em branco no fluxo:  
  
## Exemplo  
  
```  
// output_stream_manip.cpp  
// compile with: /GR /EHsc  
#include <iostream>  
#include <iomanip>  
using namespace std;  
  
void fb( ios_base& os, int l )  
{  
   ostream *pos = dynamic_cast<ostream*>(&os);  
   if (pos)  
   {  
      for( int i=0; i < l; i++ )  
      (*pos) << ' ';  
   };  
}  
  
_Smanip<int>  
   __cdecl fillblank(int no)  
   {     
   return (_Smanip<int>(&fb, no));  
   }  
  
int main( )  
{  
   cout << "10 blanks follow" << fillblank( 10 ) << ".\n";  
}  
```  
  
## Consulte também  
 [Manipuladores personalizados com argumentos](../standard-library/custom-manipulators-with-arguments.md)