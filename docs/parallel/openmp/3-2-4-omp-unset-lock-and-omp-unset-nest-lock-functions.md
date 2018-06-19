---
title: 3.2.4 funções omp_unset_lock e omp_unset_nest_lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 5357e43e-a7c0-41d7-b529-3f7d15da8b11
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: f480a75efff737356c1477593e182537ae73a8c8
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33690215"
---
# <a name="324-ompunsetlock-and-ompunsetnestlock-functions"></a>3.2.4 funções omp_unset_lock e omp_unset_nest_lock
Essas funções fornecem os meios de propriedade de um bloqueio de liberação. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_unset_lock(omp_lock_t *lock);  
void omp_unset_nest_lock(omp_nest_lock_t *lock);  
```  
  
 O argumento para cada uma dessas funções deve apontar para uma variável de bloqueio inicializado pelo thread de execução da função de propriedade. O comportamento será indefinido se o thread não possui o bloqueio.  
  
 Um bloqueio simples, o `omp_unset_lock` função libera o thread de execução da função de propriedade do bloqueio.  
  
 Um bloqueio empilhável, o `omp_unset_nest_lock` função diminui a contagem de aninhamento e as versões do thread executando a função de propriedade do bloqueio, se a contagem resultante é zero.