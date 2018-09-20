---
title: omp_unset_lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_unset_lock
dev_langs:
- C++
helpviewer_keywords:
- omp_unset_lock OpenMP function
ms.assetid: 68fcb728-040b-4bad-979e-aaecb9097a4e
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: fe6d24c6d4fe6cd1df1eea6f0e575ff5c7947c56
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46417040"
---
# <a name="ompunsetlock"></a>omp_unset_lock

Libera um bloqueio.

## <a name="syntax"></a>Sintaxe

```
void omp_unset_lock(
   omp_lock_t *lock
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Uma variável do tipo [omp_lock_t](../../../parallel/openmp/reference/omp-lock-t.md) que foi inicializado com [funções omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md), possuídas por thread e em execução na função.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [3.2.4 funções omp_unset_lock e omp_unset_nest_lock funções](../../../parallel/openmp/3-2-4-omp-unset-lock-and-omp-unset-nest-lock-functions.md).

## <a name="example"></a>Exemplo

Ver [funções omp_init_lock](../../../parallel/openmp/reference/omp-init-lock.md) para obter um exemplo de como usar `omp_unset_lock`.

## <a name="see-also"></a>Consulte também

[Funções](../../../parallel/openmp/reference/openmp-functions.md)