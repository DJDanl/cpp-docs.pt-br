---
title: "xor_eq | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
apilocation: 
  - "msvcrt.dll"
  - "msvcr80.dll"
  - "msvcr90.dll"
  - "msvcr100.dll"
  - "msvcr100_clr0400.dll"
  - "msvcr110.dll"
  - "msvcr110_clr0400.dll"
  - "msvcr120.dll"
  - "msvcr120_clr0400.dll"
  - "ucrtbase.dll"
apitype: "DLLExport"
f1_keywords: 
  - "std.xor_eq"
  - "xor_eq"
  - "std::xor_eq"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Função xor_eq"
ms.assetid: eca4b6b4-b77a-4d44-a09a-5a7e69fdb56c
caps.latest.revision: 12
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# xor_eq
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

Uma alternativa para o operador ^\=.  
  
## Sintaxe  
  
```  
  
#define xor_eq ^=  
  
```  
  
## Comentários  
 A macro produz o operador ^\=.  
  
## Exemplo  
  
```  
// iso646_xor_eq.cpp  
// compile with: /EHsc  
#include <iostream>  
#include <iso646.h>  
  
int main( )  
{  
   using namespace std;  
   int a = 3, b = 2, result;  
  
   result= a ^= b;  
   cout << result << endl;  
  
   a = 3;  
   b = 2;  
  
   result= a xor_eq b;  
   cout << result << endl;  
}  
```  
  
  **1**  
**1**   
## Requisitos  
 **Cabeçalho:** \<iso646.h\>