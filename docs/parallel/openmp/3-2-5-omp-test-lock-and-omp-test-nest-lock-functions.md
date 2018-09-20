---
title: 3.2.5 funções omp_test_lock e omp_test_nest_lock funções | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 36818945-c22c-4c24-b754-4e73eba6f3f8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5349134bf92f407d4b65df9b92e3eebe87c097c1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426140"
---
# <a name="325-omptestlock-and-omptestnestlock-functions"></a>3.2.5 funções omp_test_lock e omp_test_nest_lock

Essas funções tentam de definir um bloqueio, mas não bloquearão a execução do thread. O formato é o seguinte:

```
#include <omp.h>
int omp_test_lock(omp_lock_t *lock);
int omp_test_nest_lock(omp_nest_lock_t *lock);
```

O argumento deve apontar para uma variável inicializada de bloqueio. Essas funções tentam definir um bloqueio da mesma maneira como `omp_set_lock` e `omp_set_nest_lock`, exceto que eles não bloqueiam a execução do thread.

Para obter um bloqueio simple, o `omp_test_lock` função retorna um valor diferente de zero se o bloqueio é definido com êxito; caso contrário, retornará zero.

Para obter um bloqueio empilhável, o `omp_test_nest_lock` função retorna a nova contagem de aninhamento se o bloqueio é definido com êxito; caso contrário, retornará zero.