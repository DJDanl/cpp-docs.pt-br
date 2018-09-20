---
title: 2.5.1 paralela para Construct | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: a233e7ed-2462-4f7a-9a5d-556ab9f363d8
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: cfff3b0c17dd098b5d802af61a7ca1f81cb02845
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46373955"
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