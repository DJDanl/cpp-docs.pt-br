---
title: 2.4.3 constructo de único | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 15c180cd-e462-4b41-bf8c-cb8b1afb1a9b
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 81abf5324c215b9011ecbd774626a213c2eda653
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46376493"
---
# <a name="243-single-construct"></a>2.4.3 Construto single

O **único** diretiva identifica uma construção que especifica que o bloco estruturado associado é executado por apenas um thread na equipe (não necessariamente o thread mestre). A sintaxe do **único** diretiva é da seguinte maneira:

```
#pragma omp single [clause[[,] clause] ...] new-linestructured-block
```

A cláusula é um dos seguintes:

**private(** *variable-list* **)**

**firstprivate(** *variable-list* **)**

**copyprivate (** *variável-list* **)**

**nowait**

Há uma barreira implícita após o **única** construir, a menos que um **nowait** cláusula for especificada.

Restrições para o **único** diretiva são da seguinte maneira:

- Um único **nowait** cláusula pode aparecer em uma **único** diretiva.

- O **copyprivate** cláusula não deve ser usada com o **nowait** cláusula.

## <a name="cross-references"></a>Entre as referências:

- **privado**, **firstprivate**, e **copyprivate** cláusulas, consulte [seção 2.7.2](../../parallel/openmp/2-7-2-data-sharing-attribute-clauses.md) na página 25.