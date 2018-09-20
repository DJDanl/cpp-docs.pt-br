---
title: atômica | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- atomic
dev_langs:
- C++
helpviewer_keywords:
- atomic OpenMP directive
ms.assetid: 275e0338-cf2f-4525-97b5-696250000df7
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c845f6147280e7248db7899a182eed8d71fc34f5
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46442689"
---
# <a name="atomic"></a>atomic

Especifica que um local de memória que será atualizado atomicamente.

## <a name="syntax"></a>Sintaxe

```
#pragma omp atomic
   expression
```

#### <a name="parameters"></a>Parâmetros

*Expressão*<br/>
A instrução que contém o lvalue cujo local de memória que você deseja proteger contra várias gravações. Para obter mais informações sobre os formulários de expressão legais, consulte a especificação de OpenMP.

## <a name="remarks"></a>Comentários

O `atomic` diretiva dá suporte a nenhuma cláusulas OpenMP.

Para obter mais informações, consulte [2.6.4 atômica construir](../../../parallel/openmp/2-6-4-atomic-construct.md).

## <a name="example"></a>Exemplo

```
// omp_atomic.cpp
// compile with: /openmp
#include <stdio.h>
#include <omp.h>

#define MAX 10

int main() {
   int count = 0;
   #pragma omp parallel num_threads(MAX)
   {
      #pragma omp atomic
      count++;
   }
   printf_s("Number of threads: %d\n", count);
}
```

```Output
Number of threads: 10
```

## <a name="see-also"></a>Consulte também

[OpenMP](../../../parallel/openmp/openmp-in-visual-cpp.md)