---
title: "Compilador C4807 de aviso (n&#237;vel 1) | Microsoft Docs"
ms.custom: ""
ms.date: "12/03/2016"
ms.prod: "visual-studio-dev14"
ms.reviewer: ""
ms.suite: ""
ms.technology: 
  - "devlang-csharp"
ms.tgt_pltfrm: ""
ms.topic: "article"
f1_keywords: 
  - "C4807"
dev_langs: 
  - "C++"
helpviewer_keywords: 
  - "C4807"
ms.assetid: 089c9f87-fd81-402e-9826-66a8ef1ef1fe
caps.latest.revision: 7
caps.handback.revision: 7
author: "corob-msft"
ms.author: "corob"
manager: "ghogen"
---
# Compilador C4807 de aviso (n&#237;vel 1)
[!INCLUDE[vs2017banner](../../assembler/inline/includes/vs2017banner.md)]

'operation': unsafe combinação do tipo 'type' e junte assinado do tipo 'type'  
  
 Esse aviso é gerado ao comparar um campo de bits assinado de um bit para um `bool` variável. Como um campo de bits assinado, um bit só pode conter os valores de \-1 ou 0, é perigoso compará\-la para `bool`. Nenhum aviso é gerado sobre a combinação de `bool` e não assinados, um bit campos de bits desde que sejam idênticos ao `bool` e só podem ter 0 ou 1.  
  
## Exemplo  
 O exemplo a seguir gera C4807:  
  
```  
// C4807.cpp // compile with: /W1 typedef struct bitfield { signed mybit : 1; } mybitfield; int main() { mybitfield bf; bool b = true; // try.. // int b = true; bf.mybit = -1; if (b == bf.mybit) {   // C4807 b = false; } }  
```