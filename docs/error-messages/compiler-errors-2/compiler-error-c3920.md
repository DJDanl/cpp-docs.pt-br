---
title: "Erro do Compilador C3920 | Microsoft Docs"
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
  - "C3920"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C3920"
ms.assetid: 66e91f28-ed82-4ce2-bf22-c0c74905b1ed
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C3920
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

' operador ': não é possível definir um operador CLR chamando o sufixo ou sufixo incrementar\/diminuir WinRT operador WinRT ou CLR chamará o prefixo correspondente WinRT ou CLR operador \(op\_Increment op\_Decrement\), mas semântica de sufixo  
  
 O tempo de execução do Windows e o CLR não suportam o operador de sufixo e operadores de sufixo definida pelo usuário não são permitidas.  Você pode definir um operador de prefixo e o operador de prefixo será usado para operações de pré e pós\-incrementos.  
  
 O exemplo a seguir gera C3920 e mostra como corrigi\-lo:  
  
```  
// C3920.cpp  
// compile with: /clr /LD  
public value struct V {  
   static V operator ++(V me, int)  
   // try the following line instead  
   // static V operator ++(V me)  
   {   // C3920  
      me.m_i++;  
      return me;  
   }  
  
   int m_i;  
};  
  
```