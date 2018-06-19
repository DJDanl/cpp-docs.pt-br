---
title: 3.2.2 funções omp_destroy_lock e omp_destroy_nest_lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: d334907d-94f7-4bbf-b20e-41d53484cbff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 33c21ec9ca07651480748ac705ea6b9e4dcf8e94
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
ms.locfileid: "33686289"
---
# <a name="322-ompdestroylock-and-ompdestroynestlock-functions"></a>3.2.2 funções omp_destroy_lock e omp_destroy_nest_lock
Essas funções Certifique-se de que o indicado para a variável de bloqueio *bloqueio* não foi inicializado. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_destroy_lock(omp_lock_t *lock);  
void omp_destroy_nest_lock(omp_nest_lock_t *lock);  
```  
  
 Ele está em conformidade para chamar um essas rotinas com uma variável de bloqueio não inicializado ou desbloqueada.