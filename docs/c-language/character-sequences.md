---
title: Sequências de caracteres
ms.date: 11/04/2016
ms.assetid: 1e6961a9-150e-4c13-b427-9af4b6a1fb7a
ms.openlocfilehash: 42fb6b61771feb3eaedfb4ce1e674003df91b263
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56149917"
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
