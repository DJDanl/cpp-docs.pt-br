---
title: Macros de variável de ambiente
ms.date: 11/04/2016
helpviewer_keywords:
- NMAKE program, environment variable macros
- environment variables, macros in NMAKE
- macros, environment-variable
ms.assetid: f8e96635-0906-47b0-9f56-12a6fdf5e347
ms.openlocfilehash: 7f7f8a05545658142001b75ac78975251185a033
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62272605"
---
# <a name="environment-variable-macros"></a>Macros de variável de ambiente

NMAKE herda as definições de macro para variáveis de ambiente que existem antes do início da sessão. Se uma variável foi definida no ambiente do sistema operacional, ele está disponível como uma macro NMAKE. Os nomes herdados são convertidos em maiusculas. Herança ocorre antes de pré-processamento. Use a opção /E para fazer com que as macros herdadas de variáveis de ambiente para substituir todas as macros com o mesmo nome no makefile.

Macros de variável de ambiente podem ser redefinidas na sessão, e isso altera a variável de ambiente correspondente. Você também pode alterar as variáveis de ambiente com o comando SET. Usando o comando SET para alterar uma variável de ambiente em uma sessão não altera a macro correspondente, no entanto.

Por exemplo:

```
PATH=$(PATH);\nonesuch

all:
    echo %PATH%
```

Neste exemplo, alterando `PATH` altera a variável de ambiente correspondente `PATH`; ele acrescenta `\nonesuch` ao seu caminho.

Se uma variável de ambiente é definida como uma cadeia de caracteres que seria sintaticamente incorreta em um makefile, nenhuma macro é criada e nenhum aviso é gerado. Se o valor da variável contém um sinal de cifrão ($), NMAKE interpretará como o início de uma invocação de macro. Usando a macro pode causar um comportamento inesperado.

## <a name="see-also"></a>Consulte também

[Macros NMAKE especiais](special-nmake-macros.md)
