---
title: "Atribui&#231;&#227;o simples (C) | Microsoft Docs"
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
  - "operadores de atribuição [C++], simples"
  - "conversão de tipo de dados [C++], atribuição simples"
  - "sinal de igual"
  - "operadores [C], atribuição simples"
  - "Operador de atribuição simples"
  - "conversão de tipo [C++], atribuição simples"
ms.assetid: e7140a0a-7104-4b3a-b293-7adcc1fdd52b
caps.latest.revision: 7
caps.handback.revision: 7
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Atribui&#231;&#227;o simples (C)
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O operador de atribuição simples atribui o operando à direita ao operando à esquerda.  O valor do operando à direita é convertido no tipo da expressão de atribuição e substituir o valor armazenado no objeto designado pelo operando à esquerda.  As regras de conversão para a atribuição se aplicam \(consulte [Conversões de atribuição](../c-language/assignment-conversions.md)\).  
  
```  
double x;  
int y;  
  
x = y;  
```  
  
 Neste exemplo, o valor de `y` é convertido para o tipo **double** e é atribuído a `x`.  
  
## Consulte também  
 [Operadores de atribuição C](../c-language/c-assignment-operators.md)