---
title: "Erro do Compilador C2814 | Microsoft Docs"
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
  - "C2814"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2814"
ms.assetid: 7d165136-a08b-4497-a76d-60a21bb19404
caps.latest.revision: 16
caps.handback.revision: 16
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2814
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'member': um tipo nativo não pode ser aninhado em gerenciada ou WinRT digite 'type'  
  
## Exemplo  
 Um tipo nativo não pode ser aninhado em um tipo CLR ou WinRT.  O exemplo a seguir gera C2814 e mostra como corrigi\-lo.  
  
```  
// C2814.cpp  
// compile with: /clr /c  
ref class A {  
   class B {};   // C2814  
   ref class C {};   // OK  
};  
```  
  
## Exemplo  
 Usando extensões gerenciadas para C\+\+, você deve especificar explicitamente a "gerenciados"a qualidade de um tipo inserido usando uma das seguintes palavras\-chave: [GC](../Topic/__gc.md), [nogc](../../misc/nogc.md), ou [Value](../../misc/value.md).  
  
 O exemplo a seguir gera C2814 e mostra como corrigi\-lo.  
  
```  
// C2814_b.cpp  
// compile with: /clr:oldSyntax /c  
__gc class A {  
   class B {};   // C2814  
   __gc class C {};   // OK  
};  
```