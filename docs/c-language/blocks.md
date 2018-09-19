---
title: Blocos | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- function definitions, blocks in code
- blocks
- compound statements
- statements, compound
ms.assetid: be231a92-c712-464e-ae25-a4becb20f7f5
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 9704b499106fc59364f5cc9ae97277939e835a77
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46025316"
---
# <a name="blocks"></a>Blocos

Uma sequência de declarações, definições e instruções entre chaves (**{ }**) é denominada "bloco". Existem dois tipos de blocos em C. A "instrução composta", uma instrução composta por uma ou mais instruções (consulte [A instrução composta](../c-language/compound-statement-c.md)), é um tipo de bloco. O outro, a "definição de função", consiste em uma instrução composta (o corpo da função) com o "cabeçalho" associado à função (o nome da função, o tipo de retorno e os parâmetros, formais). Um bloco dentro de outros blocos é chamado de "aninhado".

Observe que, ainda que todas as instruções compostas estejam entre chaves, nem tudo que está entre chaves constitui uma instrução composta. Por exemplo, embora as especificações de matriz, estrutura ou dos elementos de enumeração possam aparecer entre chaves, elas não são instruções compostas.

## <a name="see-also"></a>Consulte também

[Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)