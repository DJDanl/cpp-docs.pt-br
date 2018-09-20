---
title: OMP_DYNAMIC | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- OMP_DYNAMIC
dev_langs:
- C++
helpviewer_keywords:
- OMP_DYNAMIC OpenMP environment variable
ms.assetid: e306049d-b644-4b73-8b63-46c835bff98b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b02a2a4d660057ab83da39add7fd32bcff3e6d90
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392132"
---
# <a name="ompdynamic"></a>OMP_DYNAMIC

Especifica se o OpenMP no tempo de execução pode ajustar o número de threads em uma região paralela.

## <a name="syntax"></a>Sintaxe

```
set OMP_DYNAMIC[=TRUE | =FALSE]
```

## <a name="remarks"></a>Comentários

O `OMP_DYNAMIC` variável de ambiente pode ser substituída pelo [omp_set_dynamic](../../../parallel/openmp/reference/omp-set-dynamic.md) função.

O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_DYNAMIC=FALSE`.

Para obter mais informações, consulte [OMP_DYNAMIC 4.3](../../../parallel/openmp/4-3-omp-dynamic.md).

## <a name="example"></a>Exemplo

O seguinte comando define o `OMP_DYNAMIC` variável de ambiente como TRUE:

```
set OMP_DYNAMIC=TRUE
```

O comando a seguir exibe a configuração atual de `OMP_DYNAMIC` variável de ambiente:

```
set OMP_DYNAMIC
```

## <a name="see-also"></a>Consulte também

[Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)