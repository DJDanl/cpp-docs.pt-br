---
title: 3.1.8 função omp_get_dynamic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: c03e2daf-29c9-49e3-9b67-b980ad1ab195
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2c30f49eaf91353d6a7cd9bd26e0e10e95cb6acd
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46426777"
---
# <a name="318-ompgetdynamic-function"></a>3.1.8 função omp_get_dynamic

O **omp_get_dynamic** função retorna um valor diferente de zero se o ajuste dinâmico de threads está habilitado e, caso contrário, retornará 0. O formato é o seguinte:

```
#include <omp.h>
int omp_get_dynamic(void);
```

Se a implementação não implementar ajuste dinâmico do número de threads, essa função sempre retorna 0.

## <a name="cross-references"></a>Entre as referências:

- Para obter uma descrição de ajuste dinâmico de thread, consulte [seção 3.1.7](../../parallel/openmp/3-1-7-omp-set-dynamic-function.md) na página 39.