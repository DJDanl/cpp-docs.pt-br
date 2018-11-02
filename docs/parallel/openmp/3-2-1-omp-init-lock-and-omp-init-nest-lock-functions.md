---
title: 3.2.1 funções omp_init_lock e omp_init_nest_lock
ms.date: 11/04/2016
ms.assetid: 098a2721-b16a-484f-bc83-4b8e281e382c
ms.openlocfilehash: 2d15aacb5e6743d18150fb45bea85b7ca22a401f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50472769"
---
# <a name="321-ompinitlock-and-ompinitnestlock-functions"></a>3.2.1 funções omp_init_lock e omp_init_nest_lock

Essas funções fornecem o único meio de inicializar um bloqueio. Cada função inicializa o bloqueio associado ao parâmetro *bloqueio* para uso em chamadas subsequentes. O formato é o seguinte:

```
#include <omp.h>
void omp_init_lock(omp_lock_t *lock);
void omp_init_nest_lock(omp_nest_lock_t *lock);
```

O estado inicial é desbloqueado (ou seja, nenhum thread possui o bloqueio). Para obter um bloqueio empilhável, a contagem inicial de aninhamento é zero. Ele está em conformidade para chamar qualquer uma dessas rotinas com uma variável de bloqueio que já foi inicializado.