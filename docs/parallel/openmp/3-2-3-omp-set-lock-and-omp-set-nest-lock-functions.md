---
title: "3.2.3 funções omp_set_lock e omp_set_nest_lock | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology:
- cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs:
- C++
ms.assetid: b5323879-f72e-418e-953f-3979fdda17a2
caps.latest.revision: 
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload:
- cplusplus
ms.openlocfilehash: e709e43a0b32b68bc34c4e76e8680ae371e30670
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="323-ompsetlock-and-ompsetnestlock-functions"></a>3.2.3 funções omp_set_lock e omp_set_nest_lock
Cada uma dessas funções bloqueia o thread de execução da função até que o bloqueio especificado está disponível e, em seguida, define o bloqueio. Um bloqueio simple estará disponível se ele está desbloqueado. Um bloqueio empilhável estará disponível se ele está desbloqueado ou se ele já pertence ao thread executando a função. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_set_lock(omp_lock_t *lock);  
void omp_set_nest_lock(omp_nest_lock_t *lock);  
```  
  
 Um bloqueio simples, o argumento para o `omp_set_lock` função deve apontar para uma variável de bloqueio foi inicializado. Propriedade do bloqueio é concedida para o thread de execução da função.  
  
 Um bloqueio empilhável, o argumento para o `omp_set_nest_lock` função deve apontar para uma variável de bloqueio foi inicializado. A contagem de aninhamento é incrementada, e o thread é concedido ou reterá, a propriedade do bloqueio.