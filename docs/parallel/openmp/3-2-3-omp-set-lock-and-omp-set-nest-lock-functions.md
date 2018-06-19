---
title: 3.2.3 funções omp_set_lock e omp_set_nest_lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: b5323879-f72e-418e-953f-3979fdda17a2
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ba24e923051eb887db2a81c1d9765d31a4ef7b24
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33689708"
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