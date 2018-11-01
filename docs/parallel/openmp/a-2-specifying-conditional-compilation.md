---
title: A.2   Especificando compilação condicional
ms.date: 11/04/2016
ms.assetid: de4a21b9-f987-4738-9f13-c4795f6f2dff
ms.openlocfilehash: 92ae22ffac1b1a1c3fc45a9a7a883203ff6d251e
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50491215"
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