---
title: omp_get_dynamic | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_get_dynamic
dev_langs:
- C++
helpviewer_keywords:
- omp_get_dynamic OpenMP function
ms.assetid: efa843c5-7266-4a75-8db3-22992663d9db
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c2b5a285ef019cd1752b60065f7040d9a937ce38
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46389883"
---
# <a name="ompgetdynamic"></a>omp_get_dynamic

Retorna um valor que indica se o número de threads disponíveis na região paralela subsequente pode ser ajustado pelo tempo de execução.

## <a name="syntax"></a>Sintaxe

```
int omp_get_dynamic();
```

## <a name="return-value"></a>Valor de retorno

Se for diferente de zero, o ajuste dinâmico de threads está habilitado.

## <a name="remarks"></a>Comentários

Ajuste dinâmico de segmentos é especificado com [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) e [OMP_DYNAMIC](../../../parallel/openmp/reference/omp-dynamic.md).

Para obter mais informações, consulte [3.1.7 função omp_set_dynamic](../../../parallel/openmp/3-1-7-omp-set-dynamic-function.md).

## <a name="example"></a>Exemplo

Ver [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) para obter um exemplo de como usar `omp_get_dynamic`.

## <a name="see-also"></a>Consulte também

[Funções](../../../parallel/openmp/reference/openmp-functions.md)