---
title: "Erro do Compilador C2842 | Microsoft Docs"
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
  - "C2842"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2842"
ms.assetid: 8674f08d-9f50-46ad-9229-abc6b74fa0e5
caps.latest.revision: 13
caps.handback.revision: 13
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2842
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'class': gerenciada ou tipo WinRT não pode definir seu próprios 'operator new' ou 'operador delete'  
  
 Você pode definir seus próprios [novo operador](../Topic/operator%20new%20\(%3Cnew%3E\).md) ou [operador delete](../Topic/operator%20delete%20\(%3Cnew%3E\).md) para gerenciar a alocação de memória no heap nativo.  No entanto, as classes de referência não podem definir esses operadores porque elas só são alocadas no heap gerenciado.  
  
 Para obter mais informações, consulte [Operadores definidos pelo usuário](../../dotnet/user-defined-operators-cpp-cli.md).  
  
## Exemplo  
 O exemplo a seguir gera C2842.  
  
```  
// C2842.cpp  
// compile with: /clr /c  
ref class G {  
   void* operator new( size_t nSize );   // C2842  
};  
```  
  
## Exemplo  
 O exemplo a seguir gera C2842.  
  
```  
// C2842_b.cpp  
// compile with: /clr:oldSyntax /c  
__gc class G {  
   void* operator new( size_t nSize );   // C2842  
};  
```