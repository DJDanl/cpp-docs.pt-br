---
title: 2.6.2 Construto critical
ms.date: 11/04/2016
ms.assetid: c46ecd00-b4a2-4a5e-ba92-288c329e773a
ms.openlocfilehash: dcc0e6144be5daee2a225cda621db818e5a38e2c
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50539068"
---
# <a name="262-critical-construct"></a>2.6.2 Construto critical

O **críticos** diretiva identifica uma construção que restringe a execução do bloco estruturado associado a um único thread por vez. A sintaxe do **críticos** diretiva é da seguinte maneira:

```
#pragma omp critical [(name)]  new-linestructured-block
```

Um recurso opcional *nome* pode ser usado para identificar a região crítica. Usado para identificar uma região crítica de identificadores têm vinculação externa e estão em um espaço para nome que é separado dos name spaces usados por rótulos, marcas, membros e identificadores comuns.

Um thread aguarda no início de uma região crítica, até que nenhum outro thread está em execução em uma região crítica (em qualquer lugar no programa) com o mesmo nome. Tudo sem nome **críticos** diretivas mapeiam para o mesmo nome não especificado.