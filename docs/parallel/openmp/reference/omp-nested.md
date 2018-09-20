---
title: OMP_NESTED | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- OMP_NESTED
dev_langs:
- C++
helpviewer_keywords:
- OMP_NESTED OpenMP environment variable
ms.assetid: c43f5287-a548-40d0-bd54-0c6b2b9f9a53
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: c90878ce96cf1639c983be899ba13eccf1f040e8
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46376520"
---
# <a name="ompnested"></a>OMP_NESTED

Especifica se o paralelismo aninhado está habilitado, a menos que o paralelismo aninhado está habilitado ou desabilitado com `omp_set_nested`.

## <a name="syntax"></a>Sintaxe

```
set OMP_NESTED[=TRUE | =FALSE]
```

## <a name="remarks"></a>Comentários

O `OMP_NESTED` variável de ambiente pode ser substituída pelo [omp_set_nested](../../../parallel/openmp/reference/omp-set-nested.md) função.

O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_DYNAMIC=FALSE`.

Para obter mais informações, consulte [4.4 OMP_NESTED](../../../parallel/openmp/4-4-omp-nested.md).

## <a name="example"></a>Exemplo

O seguinte comando define o `OMP_NESTED` variável de ambiente como TRUE:

```
set OMP_NESTED=TRUE
```

O comando a seguir exibe a configuração atual de `OMP_NESTED` variável de ambiente:

```
set OMP_NESTED
```

## <a name="see-also"></a>Consulte também

[Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)