---
title: Função system
ms.date: 11/04/2016
helpviewer_keywords:
- system function
ms.assetid: 0786ccdc-20cd-4d96-b3d8-3230507c3066
ms.openlocfilehash: e37de4e084de6727cf2858117945fd162f6b0d63
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56151215"
---
# <a name="system-function"></a>Função system

**ANSI 4.10.4.5** O conteúdo e o modo de execução de cadeia de caracteres pela função **system**

A função **system** executa um comando interno do sistema operacional ou um arquivo .EXE, .COM (.CMD no Windows NT) ou .BAT em um programa C em vez da linha de comando.

A função system localiza o interpretador de comandos, que normalmente é CMD.EXE no sistema operacional Windows NT ou em COMMAND.COM no Windows. A função system passará a cadeia de caracteres do argumento ao interpretador de comandos.

Para obter mais informações, consulte [system, _wsystem](../c-runtime-library/reference/system-wsystem.md).

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)
