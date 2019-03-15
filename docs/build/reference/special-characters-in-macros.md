---
title: Caracteres especiais em macros
ms.date: 11/04/2016
helpviewer_keywords:
- special characters, in NMAKE macros
ms.assetid: c0a06cfc-7103-4ee2-a585-e8f6e85dccd7
ms.openlocfilehash: aac7b07500d2a129194e7234210a590cb5d0f19a
ms.sourcegitcommit: 8105b7003b89b73b4359644ff4281e1595352dda
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/14/2019
ms.locfileid: "57824276"
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

[Definindo uma macro NMAKE](defining-an-nmake-macro.md)
