---
title: "Exemplo de chamada: prot&#243;tipo de fun&#231;&#227;o e chamada | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "convenções de chamada, exemplos [C++]"
  - "exemplos [C++], convenções de chamada"
ms.assetid: e4275d1f-df2e-4bfc-a162-eb43ec69554a
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Exemplo de chamada: prot&#243;tipo de fun&#231;&#227;o e chamada
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Específico da Microsoft  
 O exemplo a seguir mostra os resultados de fazer uma chamada de função usando várias convenções de chamada.  
  
 Este exemplo é baseado no seguinte esqueleto da função.  Substituir `calltype` com a convenção de chamada apropriada.  
  
```  
void    calltype MyFunc( char c, short s, int i, double f );  
.  
.  
.  
void    MyFunc( char c, short s, int i, double f )  
    {  
    .  
    .  
    .  
    }  
.  
.  
.  
MyFunc ('x', 12, 8192, 2.7183);  
```  
  
 Para obter mais informações, consulte [Resultados do exemplo de chamada](../Topic/Results%20of%20Calling%20Example.md).  
  
## FIM de Específico da Microsoft  
  
## Consulte também  
 [Convenções de chamada](../Topic/Calling%20Conventions.md)