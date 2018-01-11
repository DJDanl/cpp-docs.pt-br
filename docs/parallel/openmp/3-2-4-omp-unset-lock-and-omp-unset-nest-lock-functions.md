---
title: "3.2.4 funções omp_unset_lock e omp_unset_nest_lock | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: 5357e43e-a7c0-41d7-b529-3f7d15da8b11
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: dc71c6c31a1d93b6e9c9cce2cd4f7830502a1a2f
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
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