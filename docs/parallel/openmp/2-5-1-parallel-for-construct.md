---
title: 2.5.1 Construto parallel for
ms.date: 11/04/2016
ms.assetid: a233e7ed-2462-4f7a-9a5d-556ab9f363d8
ms.openlocfilehash: e74fa958a70fb10aadd39ccc6b4e56670bc072b0
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50590317"
---
# <a name="251-parallel-for-construct"></a>2.5.1 Construto parallel for

O **paralela para** diretiva é um atalho para um **paralela** região que contém um único **para** diretiva. A sintaxe do **paralela para** diretiva é da seguinte maneira:

```
#pragma omp parallel for [clause[[,] clause] ...] new-linefor-loop
```

Essa diretiva permite que todas as cláusulas do **paralelas** diretiva e a **para** diretiva, exceto o `nowait` cláusula com significados idênticos e restrições. A semântica é idêntica à explicitamente especificando um **paralelas** diretiva seguida imediatamente por um **para** diretiva.

## <a name="cross-references"></a>Entre as referências:

- **Parallel** diretiva, consulte [seção 2.3](../../parallel/openmp/2-3-parallel-construct.md) na página de 8.

- **para** diretiva, consulte [seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página de 11.

- Cláusulas de atributo de dados, consulte [2.7.2 cláusulas de atributo de compartilhamento de dados](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.