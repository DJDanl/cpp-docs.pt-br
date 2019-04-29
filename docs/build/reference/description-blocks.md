---
title: Blocos de descrição
ms.date: 11/04/2016
helpviewer_keywords:
- description blocks
- NMAKE program, description blocks
- blocks, description
ms.assetid: 1321f228-d389-40ac-b0cd-4f6e9293602b
ms.openlocfilehash: da9265d6b0026bb47496d3aa58847824b5d634d2
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62293804"
---
# <a name="description-blocks"></a>Blocos de descrição

Um bloco de descrição é uma linha de dependência opcionalmente seguida por um bloco de comandos:

```
targets... : dependents...
    commands...
```

Uma linha de dependência Especifica um ou mais destinos e dependentes de zero ou mais. Um destino deve ser no início da linha. Destinos separados de dependentes por dois-pontos (:); tabulações ou espaços são permitidas. Para dividir a linha, use uma barra invertida (\) depois de um destino ou dependente. Se um destino não existir, tem um carimbo de hora anterior que um dependente, ou é um [pseudotarget](pseudotargets.md), NMAKE executa os comandos. Se um dependente é um destino em outro lugar e não existe ou está desatualizado em relação a seus próprios dependentes, NMAKE atualiza o dependente antes de atualizar a dependência atual.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Destinos](targets.md)

[Dependentes](dependents.md)

## <a name="see-also"></a>Consulte também

[Referência a NMAKE](nmake-reference.md)
