---
title: 3.2.1 funções omp_init_lock e omp_init_nest_lock funções | Microsoft Docs
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
ms.openlocfilehash: 4303eb3ccfcb1c449022a4be32f94b9f91e6e80c
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46386997"
---
# <a name="321-ompinitlock-and-ompinitnestlock-functions"></a>3.2.1 funções omp_init_lock e omp_init_nest_lock

Essas funções fornecem o único meio de inicializar um bloqueio. Cada função inicializa o bloqueio associado ao parâmetro *bloqueio* para uso em chamadas subsequentes. O formato é o seguinte:

```
#include <omp.h>
void omp_init_lock(omp_lock_t *lock);
void omp_init_nest_lock(omp_nest_lock_t *lock);
```

O estado inicial é desbloqueado (ou seja, nenhum thread possui o bloqueio). Para obter um bloqueio empilhável, a contagem inicial de aninhamento é zero. Ele está em conformidade para chamar qualquer uma dessas rotinas com uma variável de bloqueio que já foi inicializado.