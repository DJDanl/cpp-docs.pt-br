---
title: Ferramentas de vinculador LNK4197 aviso | Microsoft Docs
ms.custom: ''
ms.date: 09/05/2018
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- LNK4197
dev_langs:
- C++
helpviewer_keywords:
- LNK4197
ms.assetid: 8a976fd7-a74b-4c83-ab66-a9e7d7073c4a
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 55044ce511e2584e2859b7e8a8d723cbe0976105
ms.sourcegitcommit: d10a2382832373b900b1780e1190ab104175397f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/06/2018
ms.locfileid: "43894480"
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