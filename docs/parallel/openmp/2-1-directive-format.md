---
title: 2.1 Formato de diretiva
ms.date: 11/04/2016
ms.assetid: 918b6445-d35e-4176-9565-b045be941b4d
ms.openlocfilehash: 6ee977005d421a59e71f852be3d78a2caad9b45b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50629483"
---
# <a name="21-directive-format"></a>2.1 Formato de diretiva

A sintaxe de uma diretiva de OpenMP formalmente é especificada pela gramática em [Apêndice C](../../parallel/openmp/c-openmp-c-and-cpp-grammar.md)e informalmente da seguinte maneira:

```
#pragma omp directive-name  [clause[ [,] clause]...] new-line
```

Cada diretiva começa com **#pragma omp**, para reduzir o potencial de conflito com outras políticas de pragma (não-OpenMP ou fornecedor de extensões OpenMP) com os mesmos nomes. O restante da diretiva segue as convenções dos padrões de diretivas de compilador C e C++. Em particular, o espaço em branco pode ser usado antes e depois o **#**, e, às vezes, o espaço em branco devem ser usado para separar as palavras em uma diretiva. A seguir de tokens de pré-processamento a **#pragma omp** estão sujeitos a substituição de macro.

As diretivas são diferencia maiusculas de minúsculas. A ordem na qual as cláusulas aparecem nas diretivas não é significativa. Cláusulas sobre as diretivas podem ser repetidas, conforme necessário, de acordo com as restrições listadas na descrição de cada cláusula. Se *lista variável* aparece em uma cláusula, ele deve especificar somente as variáveis. Somente um *nome da diretiva* pode ser especificado por diretiva.  Por exemplo, a diretiva a seguir não é permitida:

```
/* ERROR - multiple directive names not allowed */
#pragma omp parallel barrier
```

Uma diretiva de OpenMP aplica-se a no máximo uma subsequente instrução, que deve ser um bloco estruturado.