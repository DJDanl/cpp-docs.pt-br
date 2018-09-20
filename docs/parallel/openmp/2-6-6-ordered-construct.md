---
title: 2.6.6 constructo ordered | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-parallel
ms.topic: conceptual
dev_langs:
- C++
ms.assetid: 5b3c1ba5-cfb8-4b05-865b-f446ae1c9f7c
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 7b83c3dfc13b231a1314343a1dff496acf7a99b6
ms.sourcegitcommit: 799f9b976623a375203ad8b2ad5147bd6a2212f0
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/19/2018
ms.locfileid: "46412191"
---
# <a name="266-ordered-construct"></a>2.6.6 Constructo ordered

O seguinte bloco estruturado uma **ordenados** diretiva é executada na ordem em que iterações seriam executadas em um loop sequencial. A sintaxe do **ordenados** diretiva é da seguinte maneira:

```
#pragma omp ordered new-linestructured-block
```

Uma **ordenados** diretiva deve estar dentro da extensão dinâmica de uma **para** ou **paralela para** construir. O **para** ou **paralela para** diretiva para o qual o **ordenados** associa constructo deve ter uma **ordenados** cláusula especificada conforme descrito em [Seção 2.4.1](../../parallel/openmp/2-4-1-for-construct.md) na página de 11. Na execução de um **para** ou **paralela para** construir com um **ordenados** cláusula, **ordenados** construções são executadas de forma estritamente no ordem em que eles fossem executados em uma execução sequencial do loop.

Restrições para o **ordenados** diretiva são da seguinte maneira:

- Uma iteração de um loop com um **para** constructo não deve executar a mesma diretiva ordenada mais de uma vez e não devem executar mais de uma **ordenados** diretiva.