---
title: Erros de posição do arquivo
ms.date: 11/04/2016
helpviewer_keywords:
- file pointers [C++], file position errors
ms.assetid: d5e59d8b-08c0-4927-a338-0b2d8234ce24
ms.openlocfilehash: 3d581d86d6f08eee564feb6373a623512085ccca
ms.sourcegitcommit: f4be868c0d1d78e550fba105d4d3c993743a1f4b
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 02/12/2019
ms.locfileid: "56147796"
---
# <a name="file-position-errors"></a>Erros de posição do arquivo

**ANSI 4.9.9.1, 4.9.9.4** O valor para o qual a macro `errno` é definida pela função `fgetpos` ou `ftell` em caso de falha

Quando `fgetpos` ou `ftell` falha, `errno` é definido como a constante de manifesto `EINVAL` caso a posição seja inválida ou `EBADF`, caso o número do arquivo esteja incorreto. As constantes também são definidas em ERRNO.H.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)
