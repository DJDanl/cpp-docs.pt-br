---
title: Nomes de ambientes
ms.date: 11/04/2016
ms.assetid: 9af409a5-e724-465a-9a21-88d3586c2e92
ms.openlocfilehash: 43e1254b4c1ee61a92fbb6499d9396e8b15a3047
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56147991"
---
# <a name="environment-names"></a>Nomes de ambientes

**ANSI 4.10.4.4** O conjunto de nomes de ambiente e o método para alterar a lista de ambientes usada pela função [getenv](../c-runtime-library/reference/getenv-wgetenv.md)

O conjunto de nomes de ambientes é ilimitado.

Para alterar as variáveis de ambiente de um programa C, chame a função [_putenv](../c-runtime-library/reference/putenv-wputenv.md). Para alterar as variáveis de ambiente de linha de comando no Windows, use o comando SET (por exemplo, SET LIB = D:\ LIBS).

As variáveis de ambiente definidas dentro de um programa C só existirão enquanto sua cópia do host de shell de comando do sistema operacional estiver em execução (CMD.EXE ou COMMAND.COM). Por exemplo, a linha

```
system( SET LIB = D:\LIBS );
```

executará uma cópia do shell de comando (CMD.EXE), definirá a variável de ambiente LIB e retornará ao programa C, saindo da cópia secundária de CMD.EXE. Sair dessa cópia de CMD.EXE remove a variável de ambiente temporária LIB.

Da mesma forma, as alterações feitas pela função `_putenv` durará apenas até o encerramento do programa.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)<br/>
[_putenv, _wputenv](../c-runtime-library/reference/putenv-wputenv.md)<br/>
[getenv, _wgetenv](../c-runtime-library/reference/getenv-wgetenv.md)
