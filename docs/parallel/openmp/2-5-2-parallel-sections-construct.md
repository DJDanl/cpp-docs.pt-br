---
title: 2.5.2 constructo parallel sections | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 94220e27-14f8-465c-bd8d-eb960b4b5dee
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 073d0561fe4bfbb96ed88681a077da6fc985c963
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46402324"
---
# <a name="252-parallel-sections-construct"></a>2.5.2 Constructo parallel sections

O **seções em paralelo** diretiva fornece um formulário de atalho para especificar um **paralela** região que contém um único **seções** diretiva. A semântica é idêntica à explicitamente especificando um **paralelas** diretiva seguida imediatamente por um **seções** diretiva. A sintaxe do **seções em paralelo** diretiva é da seguinte maneira:

```
#pragma omp parallel sections  [clause[[,] clause] ...] new-line
   {
   [#pragma omp section new-line]
      structured-block
   [#pragma omp section new-linestructured-block  ]
   ...
}
```

O *cláusula* pode ser uma das cláusulas aceitas pela **paralela** e **seções** diretivas, exceto o **nowait** cláusula.

## <a name="cross-references"></a>Entre as referências:

- **Parallel** diretiva, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.

- **seções** diretiva, consulte [seção 2.4.2](../../parallel/openmp/2-4-2-sections-construct.md) na página 14.