---
title: "Operadores de atribui&#231;&#227;o C | Microsoft Docs"
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
  - "Operador %="
  - "Operador &="
  - "Operador *="
  - "Operador /="
  - "Operador ^=, operadores de atribuição"
  - "Operador |="
  - "Operador +="
  - "Operador <<="
  - "Operador ="
  - "Operador -="
  - "Operador =, operadores de atribuição"
  - "Operador >>"
  - "Operador >>="
  - "conversões de atribuição"
  - "operadores de atribuição"
  - "operadores de atribuição, C"
  - "Operador de atribuição AND bit a bit"
  - "Operador de atribuição de divisão"
  - "Operador de atribuição de multiplicação (*=)"
  - "Operador >>=, operadores de atribuição C"
  - "operadores [C], atribuição"
  - "operadores [C], shift"
  - "Operador de atribuição restante (%=)"
  - "Operadores right shift"
  - "operadores shift, direita"
  - "Operador de subtração"
  - "Operador de subtração, operadores de atribuição C"
ms.assetid: 11688dcb-c941-44e7-a636-3fc98e7dac40
caps.latest.revision: 8
caps.handback.revision: 8
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Operadores de atribui&#231;&#227;o C
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

Uma operação de atribuição atribui o valor do operando à direita para o local de armazenamento nomeado pelo operando à esquerda.  Portanto, o operando à esquerda de uma operação de atribuição deve ser um valor l modificável.  Após a atribuição, uma expressão de atribuição tem o valor do operando à esquerda mas não é um valor l.  
  
 **Sintaxe**  
  
 *assignment\-expression*:  
 *conditional\-expression*  
  
 *unary\-expression assignment\-operator assignment\-expression*  
  
 *assignment\-operator*: um de  
 **\= \*\=** `/=` `%=` `+=` **–\= \<\<\= \>\>\= &\=** `^=` `|=`  
  
 Os operadores de atribuição em C podem transformar e atribuir valores em uma única operação.  O C fornece os seguintes operadores de atribuição:  
  
|Operador|Operação executada|  
|--------------|------------------------|  
|**\=**|Atribuição simples|  
|**\*\=**|Atribuição de multiplicação|  
|`/=`|Atribuição de divisão|  
|`%=`|Atribuição restante|  
|`+=`|Atribuição de adição|  
|**–\=**|Atribuição de subtração|  
|**\<\<\=**|Atribuição de shift esquerda|  
|**\>\>\=**|Atribuição de shift direita|  
|**&\=**|Atribuição AND bit a bit|  
|`^=`|Atribuição OR exclusivo bit a bit|  
|`&#124;=`|Atribuição OR inclusivo bit a bit|  
  
 Na atribuição, o tipo do valor à direita é convertido no tipo do valor à esquerda, e o valor é armazenado no operando à esquerda depois que a atribuição ocorreu.  O operando à esquerda não deve ser uma matriz, uma função ou uma constante.  O caminho específico de conversão, que depende dos dois tipos, é descrito em detalhes em [Conversões de tipos](../c-language/type-conversions-c.md).  
  
## Consulte também  
 [Operadores de atribuição](../cpp/assignment-operators.md)