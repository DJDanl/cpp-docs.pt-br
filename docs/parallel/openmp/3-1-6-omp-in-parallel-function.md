---
title: 3.1.6 função omp_in_parallel | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: db6e3a63-2a0a-4b8e-8cc6-c6b49edca5fb
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9ba6c35d42f8497869894bd5ec95b83f0c8793f1
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46404612"
---
# <a name="316-ompinparallel-function"></a>3.1.6 função omp_in_parallel

O **omp_in_parallel** função retorna um valor diferente de zero se ele é chamado dentro de extensão dinâmica de uma região paralela em execução em paralelo; caso contrário, retornará 0. O formato é o seguinte:

```
#include <omp.h>
int omp_in_parallel(void);
```

Essa função retorna um valor diferente de zero quando chamado de dentro de uma região de execução em paralelo, incluindo as regiões aninhadas que são serializadas.