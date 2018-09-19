---
title: 4.4 OMP_NESTED | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: fd17b6f4-84e8-44c0-a96a-3a9e5ba33688
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 1083269f31ebc710da24430635ff8381e3f2147a
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46419510"
---
# <a name="44-ompnested"></a>4.4 OMP_NESTED

O `OMP_NESTED` variável de ambiente habilita ou desabilita o paralelismo aninhado, a menos que o paralelismo aninhado está habilitado ou desabilitado chamando o `o` **mp_set_nested** rotina da biblioteca. Se definido como **verdadeira**, paralelismo aninhado está habilitado; se ele for definido como **FALSE**aninhada paralelismo está desativado. O valor padrão é **falsos**.

Exemplo:

```
setenv OMP_NESTED TRUE
```

## <a name="cross-reference"></a>Referência cruzada:

- `omp_set_nested` função, consulte [seção 3.1.9](../../parallel/openmp/3-1-9-omp-set-nested-function.md) na página de 40.