---
title: 2.4.2 constructo sections | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: e9e6e3ea-7fc9-4925-8f68-92b8a5bb1e76
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 35ae940e37b40cbb9c883c4d7d6bca7b0fa65520
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46410533"
---
# <a name="242-sections-construct"></a>2.4.2 Constructo sections

O **seções** diretiva identifica uma construção de compartilhamento de trabalho noniterative que especifica um conjunto de construções que devem ser divididos entre os threads em uma equipe. Cada seção é executada uma vez por um thread em que a equipe. A sintaxe do **seções** diretiva é da seguinte maneira:

```
#pragma omp sections [clause[[,] clause] ...] new-line
   {
   [#pragma omp section new-line]
      structured-block
   [#pragma omp section new-linestructured-block ]
...
}
```

A cláusula é um dos seguintes:

**private(** *variable-list* **)**

**firstprivate(** *variable-list* **)**

**lastprivate(** *variable-list* **)**

**reduction(** *operator* **:**  *variable-list* **)**

**nowait**

Cada seção é precedida por um **seção** diretiva, embora o **seção** diretiva é opcional para a primeira seção. O **seção** diretivas devem ser exibido entre a extensão léxica do **seções** diretiva. Há uma barreira implícita no final de uma **seções** construir, a menos que um **nowait** for especificado.

Restrições para o **seções** diretiva são da seguinte maneira:

- Um **seção** diretiva não pode aparecer fora a extensão léxica do **seções** diretiva.

- Um único **nowait** cláusula pode aparecer em uma **seções** diretiva.

## <a name="cross-references"></a>Entre as referências:

- **privado**, **firstprivate**, **lastprivate**, e **redução** cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.