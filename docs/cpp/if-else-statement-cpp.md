---
title: "Instru&#231;&#227;o if-else (C++) | Microsoft Docs"
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
  - "else_cpp"
  - "else"
  - "if_cpp"
  - "if"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "palavra-chave else [C++]"
  - "palavra-chave if [C++]"
  - "palavra-chave if [C++], if-else"
ms.assetid: f8c45cde-6bce-42ae-81db-426b3dbd4caa
caps.latest.revision: 13
caps.handback.revision: 11
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Instru&#231;&#227;o if-else (C++)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Controla a ramificação condicional.  
  
## Sintaxe  
  
```  
  
      if ( expression )  
   statement1  
[else  
   statement2]  
```  
  
## Comentários  
 Se o valor de *expression* for diferente de zero, *statement1* é executado.  Se o **else** opcional estiver presente, *statement2* é executado se o valor de *expression* for zero.  *expression* deve ser do tipo aritmético ou ponteiro, ou deve ser de um tipo de classe que define uma conversão inequívoca para um tipo aritmético ou ponteiro. \(Para obter mais informações sobre conversões, consulte [Conversões padrão](../cpp/standard-conversions.md).\)  
  
 Em ambos os formatos da instrução **if**, *expression*, que pode ter qualquer valor exceto uma estrutura, é avaliada, inclusive todos os efeitos colaterais.  O controle passa da instrução **if** para a próxima instrução no programa a menos que uma das *instruçõe*s contenha um [break](../cpp/break-statement-cpp.md), [continue](../cpp/continue-statement-cpp.md) ou [goto](../cpp/goto-statement-cpp.md).  
  
 A cláusula **else** de uma instrução `if...else` é associada à instrução anterior mais próxima de **if** no mesmo escopo que não tem uma instrução correspondente de **else**.  
  
 Para que esse exemplo seja inequívoco sobre o pareamento de `if...else`, remova os comentários das chaves.  
  
## Exemplo  
  
```  
// if_else_statement.cpp  
#include <stdio.h>  
  
int main()   
{  
   int x = 0;  
   if (x == 0)  
   {  
      printf_s("x is 0!\n");  
   }  
   else  
   {  
      printf_s("x is not 0!\n"); // this statement will not be executed  
   }  
  
   x = 1;  
   if (x == 0)  
   {  
      printf_s("x is 0!\n"); // this statement will not be executed  
   }  
   else  
   {  
      printf_s("x is not 0!\n");  
   }  
  
   return 0;  
}  
```  
  
  **x é 0\!**  
**x não é 0\!**   
## Consulte também  
 [Instruções de seleção](../cpp/selection-statements-cpp.md)   
 [Palavras\-chave C\+\+](../cpp/keywords-cpp.md)   
 [Instrução switch \(C\+\+\)](../cpp/switch-statement-cpp.md)