---
title: "3.2.2 funções omp_destroy_lock e omp_destroy_nest_lock | Microsoft Docs"
ms.custom: 
ms.date: 11/04/2016
ms.reviewer: 
ms.suite: 
ms.technology: cpp-windows
ms.tgt_pltfrm: 
ms.topic: article
dev_langs: C++
ms.assetid: d334907d-94f7-4bbf-b20e-41d53484cbff
caps.latest.revision: "6"
author: mikeblome
ms.author: mblome
manager: ghogen
ms.workload: cplusplus
ms.openlocfilehash: 5d0b91fd311581235a893a0b3f4f383e724f9aa6
ms.sourcegitcommit: 8fa8fdf0fbb4f57950f1e8f4f9b81b4d39ec7d7a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 12/21/2017
---
# <a name="322-ompdestroylock-and-ompdestroynestlock-functions"></a>3.2.2 funções omp_destroy_lock e omp_destroy_nest_lock
Essas funções Certifique-se de que o indicado para a variável de bloqueio *bloqueio* não foi inicializado. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_destroy_lock(omp_lock_t *lock);  
void omp_destroy_nest_lock(omp_nest_lock_t *lock);  
```  
  
 Ele está em conformidade para chamar um essas rotinas com uma variável de bloqueio não inicializado ou desbloqueada.