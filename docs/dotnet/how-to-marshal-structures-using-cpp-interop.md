---
title: "Como realizar marshaling de estruturas usando interop C++ | Microsoft Docs"
ms.custom: ""
ms.date: "12/14/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "get-started-article"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Interoperabilidade C++, estruturas"
  - "realização de marshaling em dados [C++], estruturas"
  - "interoperabilidade [C++], estruturas"
  - "realização de marshaling [C++], estruturas"
  - "estruturas [C++], marshaling"
ms.assetid: c2080200-f983-4d6e-a557-cd870f060a54
caps.latest.revision: 15
caps.handback.revision: 15
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Como realizar marshaling de estruturas usando interop C++
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Este tópico demonstra uma faceta de interoperabilidade do Visual C\+\+.  Para obter mais informações, consulte [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md).  
  
 Os exemplos de código a seguir usam as políticas de \#pragma de [gerenciado, não gerenciado](../preprocessor/managed-unmanaged.md) para implementar gerenciado e funções não gerenciada no mesmo arquivo, mas essas funções interoperam da mesma forma que se definido em arquivos separados.  Os arquivos que contêm somente funções não gerenciado não precisam ser compilados com [\/clr \(compilação do Common Language Runtime\)](../build/reference/clr-common-language-runtime-compilation.md).  
  
## Exemplo  
 O exemplo a seguir demonstra transmitir uma estrutura de um gerenciado para uma função não gerenciado, o valor e por referência.  Como a estrutura neste exemplo contém apenas simples, os tipos de dados do intrínsecos \(consulte\) [Tipos blittable e não blittable](../Topic/Blittable%20and%20Non-Blittable%20Types.md)marshaling especial, não são necessários.  A estruturas non\-blittable de marshaling, como os que contêm ponteiros, consulte [Como realizar marshaling de ponteiros inseridos usando interop C\+\+](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md).  
  
```  
// PassStruct1.cpp  
// compile with: /clr  
  
#include <stdio.h>  
#include <math.h>  
  
using namespace System;  
using namespace System::Runtime::InteropServices;  
  
#pragma unmanaged  
  
struct Location {  
   int x;  
   int y;  
};  
  
double GetDistance(Location loc1, Location loc2) {  
   printf_s("[unmanaged] loc1(%d,%d)", loc1.x, loc1.y);  
   printf_s(" loc2(%d,%d)\n", loc2.x, loc2.y);  
  
   double h = loc1.x - loc2.x;  
   double v = loc1.y = loc2.y;  
   double dist = sqrt( pow(h,2) + pow(v,2) );  
  
   return dist;  
}  
  
void InitLocation(Location* lp) {  
   printf_s("[unmanaged] Initializing location...\n");  
   lp->x = 50;  
   lp->y = 50;  
}  
  
#pragma managed  
  
int main() {  
   Location loc1;  
   loc1.x = 0;  
   loc1.y = 0;  
  
   Location loc2;  
   loc2.x = 100;  
   loc2.y = 100;  
  
   double dist = GetDistance(loc1, loc2);  
   Console::WriteLine("[managed] distance = {0}", dist);  
  
   Location loc3;  
   InitLocation(&loc3);  
   Console::WriteLine("[managed] x={0} y={1}", loc3.x, loc3.y);  
}  
```  
  
## Exemplo  
 O exemplo a seguir demonstra transmitir uma estrutura de um não gerenciada em uma função gerenciada pelo valor, e por referência.  Como a estrutura neste exemplo contém apenas simples, os tipos de dados do intrínsecos \(consulte\) [Tipos blittable e não blittable](../Topic/Blittable%20and%20Non-Blittable%20Types.md)marshalling especial, não são necessários.  A estruturas non\-blittable de marshaling, como os que contêm ponteiros, consulte [Como realizar marshaling de ponteiros inseridos usando interop C\+\+](../dotnet/how-to-marshal-embedded-pointers-using-cpp-interop.md).  
  
```  
// PassStruct2.cpp  
// compile with: /clr  
#include <stdio.h>  
#include <math.h>  
using namespace System;  
  
// native structure definition  
struct Location {  
   int x;  
   int y;  
};  
  
#pragma managed  
  
double GetDistance(Location loc1, Location loc2) {  
   Console::Write("[managed] got loc1({0},{1})", loc1.x, loc1.y);  
   Console::WriteLine(" loc2({0},{1})", loc2.x, loc2.y);  
  
   double h = loc1.x - loc2.x;  
   double v = loc1.y = loc2.y;  
   double dist = sqrt( pow(h,2) + pow(v,2) );  
  
   return dist;  
}  
  
void InitLocation(Location* lp) {  
   Console::WriteLine("[managed] Initializing location...");  
   lp->x = 50;  
   lp->y = 50;  
}  
  
#pragma unmanaged  
  
int UnmanagedFunc() {  
   Location loc1;  
   loc1.x = 0;  
   loc1.y = 0;  
  
   Location loc2;  
   loc2.x = 100;  
   loc2.y = 100;  
  
   printf_s("(unmanaged) loc1=(%d,%d)", loc1.x, loc1.y);  
   printf_s(" loc2=(%d,%d)\n", loc2.x, loc2.y);  
  
   double dist = GetDistance(loc1, loc2);  
   printf_s("[unmanaged] distance = %f\n", dist);  
  
   Location loc3;  
   InitLocation(&loc3);  
   printf_s("[unmanaged] got x=%d y=%d\n", loc3.x, loc3.y);  
  
    return 0;  
}  
  
#pragma managed  
  
int main() {  
   UnmanagedFunc();  
}  
```  
  
## Consulte também  
 [Usando interop C\+\+ \(PInvoke implícito\)](../dotnet/using-cpp-interop-implicit-pinvoke.md)