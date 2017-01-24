---
title: "true (C++) | Microsoft Docs"
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
  - "true_cpp"
  - "true"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave true [C++]"
ms.assetid: 96be2a70-51c3-4250-9752-874d25a5a11e
caps.latest.revision: 12
caps.handback.revision: 10
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# true (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

## Sintaxe  
  
```  
  
        bool-identifier = true ;  
bool-expression logical-operator true ;  
```  
  
## Comentários  
 Essa palavra\-chave é um dos dois valores de uma variável do tipo [booliano](../cpp/bool-cpp.md) ou uma expressão condicional \(uma expressão condicional agora é uma expressão booliana true\).  Se `i` for do tipo `bool`, a instrução `i = true;` atribuirá **true** a `i`.  
  
## Exemplo  
  
```  
// bool_true.cpp  
#include <stdio.h>  
int main()  
{  
    bool bb = true;  
    printf_s("%d\n", bb);  
    bb = false;  
    printf_s("%d\n", bb);  
}  
```  
  
  **1**  
**0**   
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)