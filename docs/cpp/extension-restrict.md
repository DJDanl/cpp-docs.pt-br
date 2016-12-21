---
title: "__restrict | Microsoft Docs"
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
  - "__restrict"
  - "__restrict_cpp"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "Palavra-chave __restrict [C++]"
ms.assetid: 2d151b4d-f930-49df-bd16-d8757ec7fa83
caps.latest.revision: 13
caps.handback.revision: 13
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# __restrict
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Como o **declspec \( [restrict](../cpp/restrict.md) \)** modificador, o `__restrict` palavra\-chave indica que um símbolo não é um alias no escopo atual.  A palavra\-chave `__restrict` difere do modificador `__declspec ( restrict )` das seguintes maneiras:  
  
-   A palavra\-chave `__restrict` só é válida em variáveis, e `__declspec ( restrict )` só é válido em declarações e definições de função.  
  
-   `__restrict` é semelhante a `restrict` das especificações C99, mas `__restrict` pode ser usado em programas C ou C\+\+.  
  
-   Quando `__restrict` é usado, o compilador não propaga a propriedade no\-alias de uma variável.  Ou seja, se você atribuir um `__restrict` variável para um não \-`__restrict` variável, o compilador ainda permitirá que os não\- Restrict variável para receber um alias.  Isso é diferente do comportamento da palavra\-chave `restrict` da especificação C99.  
  
 Em geral, se você afeta o comportamento de uma função inteira, é melhor usar `__declspec ( restrict )` que a palavra\-chave.  
  
 No Visual Studio de 2015 e posterior, `__restrict` pode ser usado em referências C\+\+.  
  
> [!NOTE]
>  Quando usada em uma variável que também tenha o [volatile](../cpp/volatile-cpp.md) palavra\-chave, `volatile` terá precedência.  
  
## Exemplo  
  
```  
// __restrict_keyword.c  
// compile with: /LD  
// In the following function, declare a and b as disjoint arrays  
// but do not have same assurance for c and d.  
void sum2(int n, int * __restrict a, int * __restrict b,   
          int * c, int * d) {  
   int i;  
   for (i = 0; i < n; i++) {  
      a[i] = b[i] + c[i];  
      c[i] = b[i] + d[i];  
    }  
}  
  
// By marking union members as __restrict, tell compiler that  
// only z.x or z.y will be accessed in any given scope.  
union z {  
   int * __restrict x;  
   double * __restrict y;  
};  
```  
  
## Consulte também  
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)