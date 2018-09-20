---
title: A.2 especificando compilação condicional | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: de4a21b9-f987-4738-9f13-c4795f6f2dff
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 2d8b0f3df67313dbf03d40077a551fe64930199d
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46393692"
---
# <a name="a2---specifying-conditional-compilation"></a>A.2   Especificando compilação condicional

Os exemplos a seguir ilustram o uso de compilação condicional usando a macro OpenMP `_OPENMP` ([seção 2.2](../../parallel/openmp/2-2-conditional-compilation.md) na página de 8). Com a compilação de OpenMP, o `_OPENMP` macro torna-se definida.

```
# ifdef _OPENMP
    printf_s("Compiled by an OpenMP-compliant implementation.\n");
# endif
```

O operador de pré-processador definido permite que mais de uma macro a ser testado em uma única diretiva.

```
# if defined(_OPENMP) && defined(VERBOSE)
    printf_s("Compiled by an OpenMP-compliant implementation.\n");
# endif
```