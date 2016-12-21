---
title: "Erro do Compilador C2467 | Microsoft Docs"
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
  - "C2467"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2467"
ms.assetid: f9ead270-5d0b-41cc-bdcd-586a647c67a7
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2467
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

declaração ilegal de “anônimo” tipo definidas pelo usuário usadas  
  
 Um tipo definido pelo usuário aninhado foi declarado.  Este é um erro durante a criação do código\-fonte de 2.0 C com a opção de compatibilidade ANSI \([\/Za](../../build/reference/za-ze-disable-language-extensions.md)\) habilitado.  
  
 O seguinte exemplo gera C2467:  
  
```  
//C2467.c  
// compile with: /Za   
int main() {  
   struct X {  
      union { int i; };   // C2467, nested declaration  
   };  
}  
```