---
title: omp_unset_nest_lock | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- omp_unset_nest_lock
dev_langs:
- C++
helpviewer_keywords:
- omp_unset_nest_lock OpenMP function
ms.assetid: 1721d061-3f9c-45d7-b479-a665cd0a121d
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 03ea941e793f8c3a9f40e0495442deb71b2ffa93
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46402714"
---
# <a name="ompunsetnestlock"></a>omp_unset_nest_lock

Libera um bloqueio empilhável.

## <a name="syntax"></a>Sintaxe

```
void omp_unset_nest_lock( 
   omp_nest_lock_t *lock 
);
```

### <a name="parameters"></a>Parâmetros

*lock*<br/>
Uma variável do tipo [omp_nest_lock_t](../../../parallel/openmp/reference/omp-nest-lock-t.md) que foi inicializado com [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md), possuídas por thread e em execução na função.

## <a name="remarks"></a>Comentários

Para obter mais informações, consulte [3.2.4 funções omp_unset_lock e omp_unset_nest_lock funções](../../../parallel/openmp/3-2-4-omp-unset-lock-and-omp-unset-nest-lock-functions.md).

## <a name="example"></a>Exemplo

Ver [omp_init_nest_lock](../../../parallel/openmp/reference/omp-init-nest-lock.md) para obter um exemplo de como usar `omp_unset_nest_lock`.

## <a name="see-also"></a>Consulte também

[Funções](../../../parallel/openmp/reference/openmp-functions.md)