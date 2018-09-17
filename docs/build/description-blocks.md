---
title: Blocos de descrição | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- description blocks
- NMAKE program, description blocks
- blocks, description
ms.assetid: 1321f228-d389-40ac-b0cd-4f6e9293602b
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: d83e010f690f96afa5a57eb89ca1e8f4cf444225
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45699654"
---
# <a name="description-blocks"></a>Blocos de descrição

Um bloco de descrição é uma linha de dependência opcionalmente seguida por um bloco de comandos:

```
targets... : dependents...
    commands...
```

Uma linha de dependência Especifica um ou mais destinos e dependentes de zero ou mais. Um destino deve ser no início da linha. Destinos separados de dependentes por dois-pontos (:); tabulações ou espaços são permitidas. Para dividir a linha, use uma barra invertida (\) depois de um destino ou dependente. Se um destino não existir, tem um carimbo de hora anterior que um dependente, ou é um [pseudotarget](../build/pseudotargets.md), NMAKE executa os comandos. Se um dependente é um destino em outro lugar e não existe ou está desatualizado em relação a seus próprios dependentes, NMAKE atualiza o dependente antes de atualizar a dependência atual.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Destinos](../build/targets.md)

[Dependentes](../build/dependents.md)

## <a name="see-also"></a>Consulte também

[Referência a NMAKE](../build/nmake-reference.md)