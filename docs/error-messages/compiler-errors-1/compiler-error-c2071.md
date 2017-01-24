---
title: "Erro do Compilador C2071 | Microsoft Docs"
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
  - "C2071"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2071"
ms.assetid: f8c09255-a5c4-47e3-8089-3d875ae43cc5
caps.latest.revision: 10
caps.handback.revision: 10
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2071
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

"identificador": classe de armazenamento inválido  
  
 O `identifier` foi declarado com uma [classe de armazenamento](../../c-language/c-storage-classes.md) inválida.  Esse erro pode ser causado quando mais de uma classe de armazenamento for especificada para um identificador ou quando a definição for incompatível com a declaração de classe de armazenamento.  
  
 Para corrigir esse problema, entenda a classe de armazenamento pretendida do identificador — por exemplo, `static` ou `extern`— e corrija a declaração para corresponder.  
  
## Exemplo  
 O seguinte exemplo gera C2071.  
  
```  
// C2071.cpp  
// compile with: /c  
struct C {  
   extern int i;   // C2071  
};  
struct D {  
   int i;   // OK, no extern on an automatic  
};  
```  
  
## Exemplo  
 O seguinte exemplo gera C2071.  
  
```  
// C2071_b.cpp  
// compile with: /c  
typedef int x(int i) { return i; }   // C2071  
typedef int (x)(int);   // OK, no local definition in typedef  
```