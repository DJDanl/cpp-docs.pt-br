---
title: Aviso LNK4197 (Ferramentas de Vinculador)
ms.date: 09/05/2018
f1_keywords:
- LNK4197
helpviewer_keywords:
- LNK4197
ms.assetid: 8a976fd7-a74b-4c83-ab66-a9e7d7073c4a
ms.openlocfilehash: 92702864a00455e4b70f00dfc9988bfb754e2e64
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80183274"
---
# <a name="linker-tools-warning-lnk4197"></a>Aviso LNK4197 (Ferramentas de Vinculador)

> Exportar '*exportname*' especificado várias vezes; usando a primeira especificação

Uma exportação é especificada de várias maneiras diferentes. O vinculador usa a primeira especificação e ignora o restante.

Se você estiver recompilando a biblioteca de tempo de execução do C, poderá ignorar esta mensagem.

Se uma exportação for especificada exatamente da mesma maneira várias vezes, o vinculador não emitirá um aviso.

Por exemplo, o conteúdo a seguir de um arquivo. def causaria esse aviso:

```
EXPORTS
   functioname      NONAME
   functioname      @10
```

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. A mesma exportação é especificada na linha de comando (por meio de Export:) e no arquivo. def.

2. A mesma exportação é listada duas vezes no arquivo. def com atributos diferentes.
