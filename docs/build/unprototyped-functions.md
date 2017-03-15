---
title: "Fun&#231;&#245;es sem prot&#243;tipo | Microsoft Docs"
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
ms.assetid: 34200b8c-5b52-4f0d-aff8-9f70d82868ed
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Fun&#231;&#245;es sem prot&#243;tipo
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Para funções não totalmente protótipos, o chamador passar valores inteiros como números inteiros e valores de ponto flutuante com precisão dupla.  Para valores de ponto flutuante somente, ambos o registro inteiro e o registro de ponto flutuante conterão o valor de flutuante caso que o receptor espera o valor registro inteiro.  
  
```  
func1();  
func2() {   // RCX = 2, RDX = XMM1 = 1.0, and R8 = 7  
   func1(2, 1.0, 7);  
}  
```  
  
## Consulte também  
 [Convenção de chamada](../build/calling-convention.md)