---
title: Caracteres especiais em macros
ms.date: 11/04/2016
helpviewer_keywords:
- special characters, in NMAKE macros
ms.assetid: c0a06cfc-7103-4ee2-a585-e8f6e85dccd7
ms.openlocfilehash: d20c88b2223732177d79e676262a3c43eb8054a9
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57418719"
---
# <a name="special-characters-in-macros"></a>Caracteres especiais em macros

Um número assinar (#), depois de uma definição especifica um comentário. Para especificar um sinal numérico literal em uma macro, use um acento circunflexo (^), como em ^ #.

Um sinal de cifrão ($) especifica uma invocação de macro. Para especificar um $ literal, use $$.

Para estender uma definição para uma nova linha, terminar a linha com uma barra invertida (\\). Quando a macro é invocada, o caractere de barra invertida e a nova linha é substituído por um espaço. Para especificar uma barra invertida literal no final da linha, preceda-o com um acento circunflexo (^) ou segui-lo com um especificador de comentário (#).

Para especificar um caractere de nova linha literal, o final da linha com um acento circunflexo (^), como em:

```
CMDS = cls^
dir
```

## <a name="see-also"></a>Consulte também

[Definindo uma macro NMAKE](../build/defining-an-nmake-macro.md)
