---
title: 3.2.1 funções omp_init_lock e omp_init_nest_lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 098a2721-b16a-484f-bc83-4b8e281e382c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8f14e182e6c981cd5de7a4cf92d8c285a4b49c66
ms.sourcegitcommit: 7019081488f68abdd5b2935a3b36e2a5e8c571f8
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 05/07/2018
---
# <a name="321-ompinitlock-and-ompinitnestlock-functions"></a>3.2.1 funções omp_init_lock e omp_init_nest_lock
Essas funções fornecem a única forma de inicializar um bloqueio. Cada função inicializa o bloqueio associado ao parâmetro *bloqueio* para uso em chamadas subsequentes. O formato é o seguinte:  
  
```  
#include <omp.h>  
void omp_init_lock(omp_lock_t *lock);  
void omp_init_nest_lock(omp_nest_lock_t *lock);  
```  
  
 O estado inicial seja desbloqueado (ou seja, nenhum thread possui o bloqueio). Para obter um bloqueio empilhável, a contagem inicial de aninhamento é zero. Ele está em conformidade para chamar um essas rotinas com uma variável de bloqueio que já foi inicializado.