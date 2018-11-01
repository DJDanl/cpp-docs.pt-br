---
title: Aviso LNK4197 (Ferramentas de Vinculador)
ms.date: 09/05/2018
f1_keywords:
- LNK4197
helpviewer_keywords:
- LNK4197
ms.assetid: 8a976fd7-a74b-4c83-ab66-a9e7d7073c4a
ms.openlocfilehash: 0abad1b98ff4782f077312752603ec17fd611c12
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50527329"
---
# <a name="linker-tools-warning-lnk4197"></a>Aviso LNK4197 (Ferramentas de Vinculador)

> Exportar '*exportname*' especificado várias vezes; usando primeira especificação

Uma exportação é especificada em várias e diferentes maneiras. O vinculador usa a primeira especificação e ignora o resto.

Se você estiver recriando a biblioteca de tempo de execução C, você pode ignorar essa mensagem.

Se uma exportação for especificada, exatamente da mesma forma, com várias vezes, o vinculador não emitirá um aviso.

Por exemplo, o seguinte conteúdo de um arquivo. def poderia causar esse aviso:

```
EXPORTS
   functioname      NONAME
   functioname      @10
```

### <a name="to-fix-by-checking-the-following-possible-causes"></a>Para corrigir verificando as possíveis causas a seguir

1. A mesma exportação é especificada na linha de comando (por meio de exportação:) e no arquivo. def.

2. A mesma exportação é listada duas vezes no arquivo. def com atributos diferentes.