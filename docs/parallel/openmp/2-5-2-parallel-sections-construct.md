---
title: 2.5.2 Constructo parallel sections
ms.date: 11/04/2016
ms.assetid: 94220e27-14f8-465c-bd8d-eb960b4b5dee
ms.openlocfilehash: 1b74dacb9730a14364d7202918ae195cbf691955
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50533660"
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