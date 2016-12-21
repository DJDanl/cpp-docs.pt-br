---
title: "Erro do Compilador C3254 | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "error-reference"
f1_keywords: 
  - "C3254"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3254"
ms.assetid: 93427b10-fa72-4e43-80d1-1a6e122f9f40
caps.latest.revision: 9
caps.handback.revision: 9
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3254
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

“substituição” explícita: a classe contém a substituição explícita “substituição” mas não se deriva de uma interface que contém a declaração de função  
  
 Quando você [explicitamente substituição](../../cpp/explicit-overrides-cpp.md) um método, a classe que contém a substituição deve derivar, direta ou indiretamente, do tipo que contém a função que você estiver substituindo.  
  
 O seguinte exemplo gera C3254:  
  
```  
// C3254.cpp  
__interface I  
{  
   void f();  
};  
  
__interface I1 : I  
{  
};  
  
struct A /* : I1 */  
{  
   void I1::f()  
   {   // C3254, uncomment : I1 to resolve this C3254  
   }  
};  
  
int main()  
{  
}  
```