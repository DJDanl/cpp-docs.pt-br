---
title: Definindo uma regra | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-tools
ms.topic: conceptual
dev_langs:
- C++
helpviewer_keywords:
- NMAKE program, inference rules
- defining inference rules
ms.assetid: 071cd092-3f2e-4065-b0fb-36a9d393cfa8
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: a8a5cb7a0285f7abf8bcf476141451eae1b10f85
ms.sourcegitcommit: 92f2fff4ce77387b57a4546de1bd4bd464fb51b6
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2018
ms.locfileid: "45705569"
---
# <a name="defining-a-rule"></a>Definindo uma regra

O *fromext* representa a extensão de um arquivo dependente, e *toext* representa a extensão de um arquivo de destino.

```
.fromext.toext:
   commands
```

## <a name="remarks"></a>Comentários

As extensões não diferenciam maiusculas de minúsculas. Macros podem ser chamadas para representar *fromext* e *toext*; as macros são expandidas durante o pré-processamento. O ponto (.) anterior *fromext* deve aparecer no início da linha. Os dois-pontos (:) é precedido por zero ou mais espaços ou tabulações. Ele pode ser seguido apenas por espaços ou tabulações, ponto e vírgula (;) para especificar um comando, um sinal numérico (#) para especificar um comentário ou um caractere de nova linha. Não há outros espaços são permitidos. Os comandos são especificados como em blocos de descrição.

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Caminhos de pesquisa em regras](../build/search-paths-in-rules.md)

## <a name="see-also"></a>Consulte também

[Regras de inferência](../build/inference-rules.md)