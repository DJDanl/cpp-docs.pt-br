---
title: Sequências de caracteres | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
ms.assetid: 1e6961a9-150e-4c13-b427-9af4b6a1fb7a
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 5cf3b52b8a4e76062d06b0b9ca3d4535b79595c5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46061500"
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