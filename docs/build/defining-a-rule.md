---
title: Definindo uma regra
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, inference rules
- defining inference rules
ms.assetid: 071cd092-3f2e-4065-b0fb-36a9d393cfa8
ms.openlocfilehash: 7031f56d82fcaf557388c7600d493ebda48add1a
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57416924"
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
