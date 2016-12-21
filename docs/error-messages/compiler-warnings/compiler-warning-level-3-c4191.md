---
title: "C4191 do compilador aviso (n&#237;vel 3) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4191"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4191"
ms.assetid: 576d3bc6-95b7-448a-af31-5d798452df09
caps.latest.revision: 11
caps.handback.revision: 11
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# C4191 do compilador aviso (n&#237;vel 3)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

' operator\/operation': conversão não segura de 'tipo de expressão' para 'type required'  
  
 Diversas operações que envolvem ponteiros de função são consideradas seguras:  
  
-   Tipos de função com diferentes convenções de chamada.  
  
-   Tipos de função com diferentes convenções de retornos.  
  
-   Tipos de argumento ou retorno com classificações, categorias de tipos ou tamanhos diferentes.  
  
-   Tamanhos de lista de argumento diferentes \(em `__cdecl`, somente na conversão de lista mais longa lista mais curto, mesmo se for mais curto é varargs\).  
  
-   Ponteiro para dados \(diferente de **void \***\) com alias em relação a um ponteiro para função.  
  
-   Outra diferença de tipo que gerará um erro ou aviso em um `reinterpret_cast`.  
  
 Chamar essa função através do ponteiro de resultado pode causar o programa falhe.  
  
 Esse aviso é desativada por padrão. Consulte [compilador avisos que está desativado por padrão](../Topic/Compiler%20Warnings%20That%20Are%20Off%20by%20Default.md) para obter mais informações.  
  
 O exemplo a seguir gera C4191:  
  
```  
// C4191.cpp // compile with: /W3 /clr #pragma warning(default: 4191) void __clrcall f1() { } void __cdecl   f2() { } typedef void (__clrcall * fnptr1)(); typedef void (__cdecl   * fnptr2)(); int main() { fnptr1 fp1 = static_cast<fnptr1>(&f1); fnptr2 fp2 = (fnptr2) &f2; fnptr1 fp3 = (fnptr1) &f2;   // C4191 fnptr2 fp4 = (fnptr2) &f1;   // C4191 };  
```