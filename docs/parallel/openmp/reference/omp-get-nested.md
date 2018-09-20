---
title: omp_get_nested | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_get_nested
dev_langs:
- C++
helpviewer_keywords:
- omp_get_nested OpenMP function
ms.assetid: e9784847-516e-40d3-89f7-b8b6898d8667
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 20a7378ba7e7f6dcec55cfe265dd0873bdc1fd38
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46371947"
---
# <a name="ompgetnested"></a>omp_get_nested

Retorna um valor que indica se o paralelismo aninhado está habilitado.

## <a name="syntax"></a>Sintaxe

```
int omp_get_nested( );
```

## <a name="return-value"></a>Valor de retorno

Se diferente de zero, o paralelismo aninhado está habilitado.

## <a name="remarks"></a>Comentários

Paralelismo aninhado é especificado com [omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md) e [OMP_NESTED](../../../parallel/openmp/reference/omp-nested.md).

Para obter mais informações, consulte [3.1.10 função omp_get_nested](../../../parallel/openmp/3-1-10-omp-get-nested-function.md).

## <a name="example"></a>Exemplo

Ver [omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md) para obter um exemplo de como usar `omp_get_nested`.

## <a name="see-also"></a>Consulte também

[Funções](../../../parallel/openmp/reference/openmp-functions.md)