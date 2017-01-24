---
title: "Operadores C | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-cpp"
ms.tgt_pltfrm: ""
ms.topic: "article"
dev_langs: 
  - "C++"
  - "C"
helpviewer_keywords: 
  - "associatividade dos operadores"
  - "dados binários, expressões binárias"
  - "operadores binários"
  - "operadores [C]"
  - "símbolos, operadores"
  - "operadores ternários"
ms.assetid: 13bc4c8e-2dc9-4b23-9f3a-25064e8777ed
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Os operadores C são um subconjunto de [operadores C\+\+](../misc/cpp-operators.md).  
  
 Há três tipos de operadores.  Uma expressão unária consiste em um operador unário pré\-anexado a um operando ou na palavra\-chave `sizeof` seguida de uma expressão.  A expressão pode ser o nome de uma variável ou uma expressão de conversão.  Se a expressão for uma expressão de conversão, ela deverá ser colocada entre parênteses.  Uma expressão binária consiste em dois operandos unidos por um operador binário.  Uma expressão ternária consiste em três operandos unidos pelo operador de expressão condicional.  
  
 O C inclui os seguintes operadores unários:  
  
|Símbolo|Nome|  
|-------------|----------|  
|**– ~ \!**|Operadores de negação e de complemento|  
|**\* &**|Operadores de indireção e address\-of|  
|`sizeof`|Operador de tamanho|  
|**\+**|Operador unário de adição|  
|**\+\+ ––**|Operadores unários de incremento e de decremento|  
  
 Operadores binários associados da esquerda para a direita.  O C fornece os seguintes operadores binários:  
  
|Símbolo|Nome|  
|-------------|----------|  
|**\* \/ %**|Operadores de multiplicação|  
|**\+ –**|Operadores aditivos|  
|**\<\<**<br /> **\>\>**|Operadores shift|  
|**\<   \>   \<\=   \>\=   \=\=   \!\=**|Operadores relacionais|  
|**&   &#124; ^**|Operadores bit a bit|  
|**&&   &#124;&#124;**|Operadores lógicos|  
|**,**|Operador de avaliação sequencial|  
  
 O operador de base \(**:\>**\), com suporte em versões anteriores do compilador de 16 bits do Microsoft C, é descrito em [Resumo da sintaxe da linguagem C](../c-language/c-language-syntax-summary.md).  
  
 O operador de expressão condicional tem uma precedência mais baixa do que as expressões binárias e difere delas por ser associado à direita.  
  
 As expressões com operadores também incluem as expressões de atribuição, que usam operadores de atribuição unários ou binários.  Os operadores de atribuição unários são operadores de incremento \(`++`\) e de decremento \(**––**\); os operadores de atribuição binários são o operador de atribuição simples \(**\=**\) e os operadores de atribuição compostos.  Cada operador de atribuição composta é uma combinação de outro operador binário com o operador de atribuição simples.  
  
## Consulte também  
 [Expressões e atribuições](../c-language/expressions-and-assignments.md)