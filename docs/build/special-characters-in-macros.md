---
title: Caracteres especiais em Macros | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- special characters, in NMAKE macros
ms.assetid: c0a06cfc-7103-4ee2-a585-e8f6e85dccd7
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 55a94001e2f912049518120911c25ae64afa24da
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45721405"
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