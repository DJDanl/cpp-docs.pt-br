---
title: Comandos em um makefile
ms.date: 11/04/2016
helpviewer_keywords:
- commands, makefiles
ms.assetid: 8085517e-42f4-493b-b8f8-44311fc08c64
ms.openlocfilehash: 1fbaddef535ee1066c0723b5709ce2d55e67682e
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57419654"
---
# <a name="commands-in-a-makefile"></a>Comandos em um makefile

Uma regra de inferência de tipos ou bloco de descrição Especifica um bloco de comandos a serem executadas se a dependência está desatualizada. NMAKE exibe cada comando antes de executá-lo, a menos que /S, **. SILENCIOSA**, **! CMDSWITCHES**, ou \@ é usado. NMAKE procura por uma regra de inferência de tipos de correspondência, se um bloco de descrição não é seguido por um bloco de comandos.

Um bloco de comandos contém um ou mais comandos, cada um em sua própria linha. Nenhuma linha em branco pode aparecer entre a dependência ou regra e o bloco de comandos. No entanto, pode aparecer uma linha que contém somente espaços ou tabulações; Essa linha é interpretada como um comando nulo e não ocorre nenhum erro. Linhas em branco são permitidas entre as linhas de comando.

Uma linha de comando começa com um ou mais espaços ou tabulações. Uma barra invertida (\) seguida por um caractere de nova linha é interpretada como um espaço no comando; Use uma barra invertida no final de uma linha para continuar um comando para a próxima linha. NMAKE interpreta a barra invertida, literalmente, se qualquer outro caractere, incluindo um espaço ou tabulação, segue a barra invertida.

Um comando precedido por um ponto e vírgula (;) pode aparecer em uma regra de linha ou de inferência de tipos de dependência, se um bloco de comandos segue:

```
project.obj : project.c project.h ; cl /c project.c
```

## <a name="what-do-you-want-to-know-more-about"></a>Que mais você deseja saber?

[Modificadores de comando](../build/command-modifiers.md)

[Sintaxe de partes do nome de arquivo](../build/filename-parts-syntax.md)

[Arquivos embutidos em um makefile](../build/inline-files-in-a-makefile.md)

## <a name="see-also"></a>Consulte também

[Referência a NMAKE](../build/nmake-reference.md)
