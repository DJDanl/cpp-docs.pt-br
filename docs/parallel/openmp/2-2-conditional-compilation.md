---
title: 2.2 Compilação condicional
ms.date: 11/04/2016
ms.assetid: 8f9c914d-736c-48cf-899d-c8029dbe1e32
ms.openlocfilehash: 9dc107ee9e5328df205d4b6f826f71c23abfb3ba
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50658543"
---
# <a name="22-conditional-compilation"></a>2.2 Compilação condicional

O _**OPENMP** nome da macro é definida por implementações em conformidade com o OpenMP, como a constante decimal *yyyymm*, que será o ano e mês da especificação de aprovados. Essa macro não deve ser o assunto de um **#define** ou um **#undef** diretiva de pré-processamento.

```
#ifdef _OPENMP
iam = omp_get_thread_num() + index;
#endif
```

Se fornecedores definam ampliações OpenMP, eles podem especificar outras macros predefinidas.