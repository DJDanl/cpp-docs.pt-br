---
title: Sequências de caracteres
ms.date: 11/04/2016
ms.assetid: 1e6961a9-150e-4c13-b427-9af4b6a1fb7a
ms.openlocfilehash: 42fb6b61771feb3eaedfb4ce1e674003df91b263
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62312681"
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

## <a name="see-also"></a>Confira também

[Pré-processando diretivas](../c-language/preprocessing-directives.md)
