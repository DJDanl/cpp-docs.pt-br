---
title: "Erro do Compilador C2594 | Microsoft Docs"
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
  - "C2594"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C2594"
ms.assetid: 68cd708f-266e-44b0-a211-3e3ab63b11bf
caps.latest.revision: 14
caps.handback.revision: 14
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Erro do Compilador C2594
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

operador “”: conversões de tipo ambíguas “\- 1 " para o tipo “\- 2 "  
  
 Nenhuma conversão de *type1* a *type2* fosse mais direto do que qualquer outro.  Nós sugerimos duas possíveis soluções para converter de *type1* a *type2*.  A primeira opção é definir uma conversão direta de *type1* a *type2*, e a segunda opção é especificar uma sequência conversões de *type1* a *type2*.  
  
 O exemplo a seguir produz C2594.  A resolução sugerida ao erro é uma sequência das conversões:  
  
```  
// C2594.cpp  
// compile with: /c  
struct A{};  
struct I1 : A {};  
struct I2 : A {};  
struct D : I1, I2 {};  
  
A *f (D *p) {  
   return (A*) (p);    // C2594  
  
// try the following line instead  
// return static_cast<A *>(static_cast<I1 *>(p));  
}  
```