---
title: OMP_SCHEDULE | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- OMP_SCHEDULE
dev_langs:
- C++
helpviewer_keywords:
- OMP_SCHEDULE OpenMP environment variable
ms.assetid: 2295a801-e584-4d2f-826f-7ca4c88846a6
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 507067be30db019536ef222a62335244eabfaada
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46413855"
---
# <a name="ompschedule"></a>OMP_SCHEDULE

Modifica o comportamento do [agendamento](../../../parallel/openmp/reference/schedule.md) cláusula quando `schedule(runtime)` é especificado em uma `for` ou `parallel for` diretiva.

## <a name="syntax"></a>Sintaxe

```
set OMP_SCHEDULE[=type[,size]]
```

## <a name="arguments"></a>Arguments

*size*<br/>
(Opcional) Especifica o tamanho de iterações. `size` Deve ser um inteiro positivo. O padrão é 1, exceto quando `type` é estático. Não é válida quando `type` é `runtime`.

*type*<br/>
O tipo de agendamento:

- `dynamic`

- `guided`

- `runtime`

- `static`

## <a name="remarks"></a>Comentários

O valor padrão na implementação do Visual C++ do OpenMP padrão é `OMP_SCHEDULE=static,0`.

Para obter mais informações, consulte [OMP_SCHEDULE 4.1](../../../parallel/openmp/4-1-omp-schedule.md).

## <a name="example"></a>Exemplo

O seguinte comando define a **OMP_SCHEDULE** variável de ambiente:

```
set OMP_SCHEDULE="guided,2"
```

O comando a seguir exibe a configuração atual de **OMP_SCHEDULE** variável de ambiente:

```
set OMP_SCHEDULE
```

## <a name="see-also"></a>Consulte também

[Variáveis de ambiente](../../../parallel/openmp/reference/openmp-environment-variables.md)