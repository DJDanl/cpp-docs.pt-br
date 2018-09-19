---
title: Erros de posição do arquivo | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- file pointers [C++], file position errors
ms.assetid: d5e59d8b-08c0-4927-a338-0b2d8234ce24
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 8def11317548bfd6e70badab4563891c1b6f864d
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46031894"
---
# <a name="file-position-errors"></a>Erros de posição do arquivo

**ANSI 4.9.9.1, 4.9.9.4** O valor para o qual a macro `errno` é definida pela função `fgetpos` ou `ftell` em caso de falha

Quando `fgetpos` ou `ftell` falha, `errno` é definido como a constante de manifesto `EINVAL` caso a posição seja inválida ou `EBADF`, caso o número do arquivo esteja incorreto. As constantes também são definidas em ERRNO.H.

## <a name="see-also"></a>Consulte também

[Funções de biblioteca](../c-language/library-functions.md)
