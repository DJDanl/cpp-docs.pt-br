---
title: Sequências de caracteres
ms.date: 11/04/2016
ms.assetid: 1e6961a9-150e-4c13-b427-9af4b6a1fb7a
ms.openlocfilehash: dea24a2ae5887ea8c0111d8251ba4d9d03ccba0f
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50489655"
---
# <a name="character-sequences"></a>Sequências de caracteres

**ANSI 3.8.2** O mapeamento de sequências de caracteres do arquivo de origem

As instruções do pré-processador usam o mesmo conjunto de caracteres das instruções de arquivo de origem, com exceção das sequências de escape, que não têm suporte.

Assim, para especificar um caminho para um arquivo de inclusão, use somente uma barra invertida:

```
#include "path1\path2\myfile"
```

No código-fonte, duas barras invertidas são necessárias:

```
fil = fopen( "path1\\path2\\myfile", "rt" );
```

## <a name="see-also"></a>Consulte também

[Diretivas de pré-processamento](../c-language/preprocessing-directives.md)