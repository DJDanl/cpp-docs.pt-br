---
title: Erros de posição do arquivo
ms.date: 11/04/2016
helpviewer_keywords:
- file pointers [C++], file position errors
ms.assetid: d5e59d8b-08c0-4927-a338-0b2d8234ce24
ms.openlocfilehash: f8c1d5dfc6a599533ce8c1dcfa624d2595779f2b
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50554603"
---
# <a name="file-position-errors"></a>Erros de posição do arquivo

**ANSI 4.9.9.1, 4.9.9.4** O valor para o qual a macro `errno` é definida pela função `fgetpos` ou `ftell` em caso de falha

Quando `fgetpos` ou `ftell` falha, `errno` é definido como a constante de manifesto `EINVAL` caso a posição seja inválida ou `EBADF`, caso o número do arquivo esteja incorreto. As constantes também são definidas em ERRNO.H.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)
