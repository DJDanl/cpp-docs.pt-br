---
title: firstprivate | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
f1_keywords:
- firstprivate
dev_langs:
- C++
helpviewer_keywords:
- firstprivate OpenMP clause
ms.assetid: db479766-6d3b-4bbd-b28e-b192d826788c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: d070b8de3cf0382447c3b8e756140892dcd85edc
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46387114"
---
# <a name="firstprivate"></a>firstprivate

Especifica que cada thread deve ter sua própria instância de uma variável, e que a variável deverá ser inicializada com o valor da variável, porque ele existe antes da construção parallel.

## <a name="syntax"></a>Sintaxe

```
firstprivate(var)
```

#### <a name="parameters"></a>Parâmetros

|Parâmetro|Descrição|
|---------------|-----------------|
|`var`|A variável ter instâncias em cada thread e que serão ser inicializada com o valor da variável, porque ele existe antes da construção parallel. Se mais de uma variável for especificada, separe os nomes de variável com uma vírgula.|

## <a name="remarks"></a>Comentários

## <a name="remarks"></a>Comentários

`firstprivate` aplica-se para as seguintes diretivas:

- [for](../../../parallel/openmp/reference/for-openmp.md)

- [parallel](../../../parallel/openmp/reference/parallel.md)

- [Seções](../../../parallel/openmp/reference/sections-openmp.md)

- [single](../../../parallel/openmp/reference/single.md)

Para obter mais informações, consulte [2.7.2.2 firstprivate](../../../parallel/openmp/2-7-2-2-firstprivate.md).

## <a name="example"></a>Exemplo

Para obter um exemplo de uso `firstprivate`, consulte o exemplo na [privada](../../../parallel/openmp/reference/private-openmp.md).

## <a name="see-also"></a>Consulte também

[Cláusulas](../../../parallel/openmp/reference/openmp-clauses.md)