---
title: /STACK
ms.date: 11/04/2016
f1_keywords:
- /stack
helpviewer_keywords:
- -STACK editbin option
- STACK editbin option
- stack, setting size
- /STACK editbin option
ms.assetid: a39bcff0-c945-4355-80cc-8e4f24a5f142
ms.openlocfilehash: 1d583a7259e1aecef0a638743fb0b6271ff09330
ms.sourcegitcommit: bff17488ac5538b8eaac57156a4d6f06b37d6b7f
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/05/2019
ms.locfileid: "57417743"
---
# <a name="stack"></a>/STACK

```
/STACK:reserve[,commit]
```

## <a name="remarks"></a>Comentários

Essa opção define o tamanho da pilha em bytes e usa os argumentos na notação decimal ou linguagem C. A opção /STACK se aplica somente a um arquivo executável.

O *reservar* argumento especifica a alocação da pilha total na memória virtual. EDITBIN Arredonda o valor especificado para o mais próximo de 4 bytes.

Opcional `commit` argumento está sujeitas a interpretação pelo sistema operacional. No Windows NT, Windows 95 e Windows 98, `commit` Especifica a quantidade de memória física para alocar por vez. Memória virtual confirmada faz com que o espaço a ser reservado no arquivo de paginação. Uma maior `commit` valor economiza tempo quando o aplicativo precisa de mais espaço de pilha, mas aumenta os requisitos de memória e, possivelmente, tempo de inicialização.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](../../build/reference/editbin-options.md)
