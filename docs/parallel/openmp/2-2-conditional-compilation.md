---
title: 2.2 compilação condicional | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 8f9c914d-736c-48cf-899d-c8029dbe1e32
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 25b52ce624777efe85e27b8ce5e7941bc2f5dcba
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46440375"
---
# <a name="22-conditional-compilation"></a>2.2 Compilação condicional

O _**OPENMP** nome da macro é definida por implementações em conformidade com o OpenMP, como a constante decimal *yyyymm*, que será o ano e mês da especificação de aprovados. Essa macro não deve ser o assunto de um **#define** ou um **#undef** diretiva de pré-processamento.

```
#ifdef _OPENMP
iam = omp_get_thread_num() + index;
#endif
```

Se fornecedores definam ampliações OpenMP, eles podem especificar outras macros predefinidas.