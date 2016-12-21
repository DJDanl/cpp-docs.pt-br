---
title: "Armazenamento de uni&#245;es | Microsoft Docs"
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
  - "armazenamento, união"
  - "palavra-chave union [C]"
  - "palavra-chave union [C], armazenamento"
ms.assetid: b33d246a-8d20-41c4-89b2-ab05f1428792
caps.latest.revision: 6
caps.handback.revision: 6
author: "mikeblome"
ms.author: "mblome"
manager: "ghogen"
---
# Armazenamento de uni&#245;es
[!INCLUDE[vs2017banner](../assembler/inline/includes/vs2017banner.md)]

O armazenamento associado a uma variável de união é o armazenamento necessário para o maior membro da união.  Quando um membro menor é armazenado, a variável de união pode conter espaço de memória não utilizado.  Todos os membros são armazenados no mesmo espaço de memória e começam no mesmo endereço.  O valor armazenado é substituído sempre que um valor é atribuído a um membro diferente.  Por exemplo:  
  
```  
union         /* Defines a union named x */  
{  
    char *a, b;  
    float f[20];  
} x;  
```  
  
 Os membros da união `x` são, por ordem de declaração, um ponteiro para um valor `char`, um valor `char` e uma matriz de valores **float**.  O armazenamento alocado para `x` é o armazenamento necessário para a matriz `f`de 20 elementos, pois `f` é o membro mais longo da união.  Como nenhuma marca é associada à união, seu tipo é sem nome ou “anônimo”.  
  
## Consulte também  
 [Declarações de união](../c-language/union-declarations.md)