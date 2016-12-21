---
title: "bool (C++) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "language-reference"
f1_keywords: 
  - "bool_cpp"
  - "bool"
  - "__BOOL_DEFINED"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Macro __BOOL_DEFINED"
  - "palavra-chave bool [C++]"
ms.assetid: 9abed3f2-d21c-4eb4-97c5-716342e613d8
caps.latest.revision: 9
caps.handback.revision: 9
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# bool (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Essa palavra\-chave é um tipo interno.  Uma variável desse tipo pode ter valores [true](../cpp/true-cpp.md) e [false](../Topic/false%20\(C++\).md).  As expressões condicionais têm o tipo `bool` e, sendo assim, têm valores do tipo `bool`.  Por exemplo, `i!=0` agora tem **true** ou **false**, dependendo do valor de `i`.  
  
 Os valores **true** e **false** têm a seguinte relação:  
  
```  
!false == true  
!true == false  
```  
  
 Na instrução a seguir:  
  
```  
if (condexpr1) statement1;   
```  
  
 Se `condexpr1` for **true**, `statement1` sempre será executado; se `condexpr1` for **false**, `statement1` nunca será executado.  
  
 Quando um operador de sufixo ou prefixo `++` for aplicado a uma variável do tipo `bool`, a variável será definida como **true**.  O operador `--` de sufixo ou prefixo não pode ser aplicado a uma variável desse tipo.  
  
 O tipo `bool` participa de promoções de integral.  Um r\-value do tipo `bool` pode ser convertido em um r\-value do tipo `int`, com **false** se tornando zero e **true** se tornando um.  Como um tipo diferente, `bool` participa da resolução de sobrecarga.  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Tipos fundamentais](../cpp/fundamental-types-cpp.md)