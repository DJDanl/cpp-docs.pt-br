---
title: Bloqueios
ms.date: 11/04/2016
helpviewer_keywords:
- function definitions, blocks in code
- blocks
- compound statements
- statements, compound
ms.assetid: be231a92-c712-464e-ae25-a4becb20f7f5
ms.openlocfilehash: 4f308864e6e85f74e40d9c9df200a0254fea366a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62325904"
---
# <a name="blocks"></a>Bloqueios

Uma sequência de declarações, definições e instruções entre chaves (**{ }**) é denominada "bloco". Existem dois tipos de blocos em C. A "instrução composta", uma instrução composta por uma ou mais instruções (consulte [A instrução composta](../c-language/compound-statement-c.md)), é um tipo de bloco. O outro, a "definição de função", consiste em uma instrução composta (o corpo da função) com o "cabeçalho" associado à função (o nome da função, o tipo de retorno e os parâmetros, formais). Um bloco dentro de outros blocos é chamado de "aninhado".

Observe que, ainda que todas as instruções compostas estejam entre chaves, nem tudo que está entre chaves constitui uma instrução composta. Por exemplo, embora as especificações de matriz, estrutura ou dos elementos de enumeração possam aparecer entre chaves, elas não são instruções compostas.

## <a name="see-also"></a>Confira também

[Arquivos e programas de origem](../c-language/source-files-and-source-programs.md)
