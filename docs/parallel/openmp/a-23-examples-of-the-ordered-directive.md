---
title: A.23 exemplos da diretiva ordered | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: f8fa761b-7fc5-4447-95f9-8571e9ca31bf
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: ec609a77e9bdc7cbdbb0822dfde0a88110ce0244
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46405964"
---
# <a name="a23---examples-of-the-ordered-directive"></a>A.23   Exemplos da diretiva ordered

É possível ter várias seções ordenadas com uma `for` especificado com o `ordered` cláusula. O primeiro exemplo é em não conformidade porque a API Especifica o seguinte:

"Uma iteração de um loop com um `for` constructo não deve executar a mesma `ordered` diretiva mais de uma vez e ele não devem executar mais de um `ordered` diretiva." (Consulte [seção 2.6.6](../../parallel/openmp/2-6-6-ordered-construct.md) na página 22)

Neste exemplo não compatíveis, todas as iterações execute seções ordenadas 2:

```
#pragma omp for ordered
for (i=0; i<n; i++)
{
    ...
    #pragma omp ordered
    { ... }
    ...
    #pragma omp ordered
    { ... }
    ...
}
```

A conformidade de exemplo a seguir mostra um `for` com mais de uma seção ordenada:

```
#pragma omp for ordered
for (i=0; i<n; i++)
{
    ...
    if (i <= 10)
    {
        ...
        #pragma omp ordered
        { ... }
    }
    ...
    (i > 10)
    {
        ...
        #pragma omp ordered
        { ... }
    }
    ...
}
```