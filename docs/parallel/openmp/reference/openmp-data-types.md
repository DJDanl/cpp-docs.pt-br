---
title: Tipos de dados de OpenMP | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: reference
dev_langs:
- C++
ms.assetid: cf1e1045-4d12-4d03-80b7-d5843b80ef85
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: b41eaf7012c1d119071281f98177e4a4d841890b
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46410061"
---
# <a name="openmp-data-types"></a>OpenMP Tipos de dados

Fornece links para os tipos de dados usados na API OpenMP.

A implementação do Visual C++ do OpenMP padrão inclui os seguintes tipos de dados.

|Tipo de dados|Descrição|
|---------------|-----------------|
|[omp_lock_t](../../../parallel/openmp/reference/omp-lock-t.md)|Um tipo que contém o status de um bloqueio, se o bloqueio está disponível ou se um thread possui um bloqueio.|
|[omp_nest_lock_t](../../../parallel/openmp/reference/omp-nest-lock-t.md)|Um tipo que contém uma das seguintes partes de informações sobre um bloqueio: se o bloqueio está disponível e a identidade do thread que possui o bloqueio e uma contagem de aninhamento.|

## <a name="see-also"></a>Consulte também

[Referência da biblioteca](../../../parallel/openmp/reference/openmp-library-reference.md)