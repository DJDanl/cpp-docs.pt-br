---
title: padrão (OpenMP) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- default
dev_langs:
- C++
helpviewer_keywords:
- default OpenMP clause
- defaults, OpenMP clause
ms.assetid: 96055106-a8f0-40b3-8319-e412b6e07bf8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4ea32f473d96c8f48c6628d8f71212269bd6d345
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46392601"
---
# <a name="default-openmp"></a>default (OpenMP)

Especifica o comportamento de variáveis fora do escopo em uma região paralela.

## <a name="syntax"></a>Sintaxe

```
default(shared | none)
```

## <a name="remarks"></a>Comentários

`shared`, que está em vigor se o `default` cláusula não for especificada, significa que qualquer variável em uma região paralela será tratada como se ele tiver sido especificado com o [compartilhado](../../../parallel/openmp/reference/shared-openmp.md) cláusula. `none` significa que todas as variáveis usadas em uma região paralela que não estão no escopo com o [privados](../../../parallel/openmp/reference/private-openmp.md), [compartilhado](../../../parallel/openmp/reference/shared-openmp.md), [redução](../../../parallel/openmp/reference/reduction.md), [firstprivate](../../../parallel/openmp/reference/firstprivate.md), ou [lastprivate](../../../parallel/openmp/reference/lastprivate.md) cláusula causará um erro do compilador.

`default` aplica-se para as seguintes diretivas:

- [parallel](../../../parallel/openmp/reference/parallel.md)

- [for](../../../parallel/openmp/reference/for-openmp.md)

- [Seções](../../../parallel/openmp/reference/sections-openmp.md)

Para obter mais informações, consulte [2.7.2.5 padrão](../../../parallel/openmp/2-7-2-5-default.md).

## <a name="example"></a>Exemplo

Ver [privados](../../../parallel/openmp/reference/private-openmp.md) para obter um exemplo de como usar `default`.

## <a name="see-also"></a>Consulte também

[Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)