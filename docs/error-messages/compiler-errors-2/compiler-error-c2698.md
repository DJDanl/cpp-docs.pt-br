---
title: "Erro do Compilador C2698 | Microsoft Docs"
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
  - "C2698"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2698"
ms.assetid: 3ebfe395-c20b-4c56-9980-ca9ed8653382
caps.latest.revision: 8
caps.handback.revision: 8
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2698
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

usados a declaração da declaração “1 " não pode coexistir usados com a declaração existente para a declaração “2 "  
  
 Quando você tem [usando a declaração](../../cpp/using-declaration.md) para um membro de dados, nenhuma declaração de utilização no mesmo escopo que usa o mesmo nome não é permitida, porque somente as funções podem ser sobrecarregadas.  
  
 O seguinte exemplo gera C2698:  
  
```  
// C2698.cpp  
struct A {  
   int x;  
};  
  
struct B {  
   int x;  
};  
  
struct C : A, B {  
   using A::x;  
   using B::x;   // C2698  
}  
```