---
title: "Armazenamento de uniões| Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-language
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
helpviewer_keywords:
- storage, union
- union keyword [C], storage
- union keyword [C]
ms.assetid: b33d246a-8d20-41c4-89b2-ab05f1428792
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.openlocfilehash: cb349b2c1649b6e4e46fcc92829de87043d0c50a
ms.sourcegitcommit: ebec1d449f2bd98aa851667c2bfeb7e27ce657b2
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/24/2017
---
# <a name="storage-of-unions"></a>Armazenamento de uniões
O armazenamento associado a uma variável de união é o armazenamento necessário para o maior membro da união. Quando um membro menor é armazenado, a variável de união pode conter espaço de memória não utilizado. Todos os membros são armazenados no mesmo espaço de memória e começam no mesmo endereço. O valor armazenado é substituído sempre que um valor é atribuído a um membro diferente. Por exemplo:  
  
```  
union         /* Defines a union named x */  
{  
    char *a, b;  
    float f[20];  
} x;  
```  
  
 Os membros da união `x` são, por ordem de declaração, um ponteiro para um valor `char`, um valor `char` e uma matriz de valores **float**. O armazenamento alocado para `x` é o armazenamento necessário para a matriz `f`de 20 elementos, pois `f` é o membro mais longo da união. Como nenhuma marca é associada à união, seu tipo é sem nome ou “anônimo”.  
  
## <a name="see-also"></a>Consulte também  
 [Declarações de união](../c-language/union-declarations.md)