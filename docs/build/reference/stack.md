---
title: /STACK
ms.date: 11/04/2016
f1_keywords:
- /stack_editbin
helpviewer_keywords:
- -STACK editbin option
- STACK editbin option
- stack, setting size
- /STACK editbin option
ms.assetid: a39bcff0-c945-4355-80cc-8e4f24a5f142
ms.openlocfilehash: 63fcddec8ff8afd81084bb5a2786f394db594b07
ms.sourcegitcommit: 63784729604aaf526de21f6c6b62813882af930a
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/17/2020
ms.locfileid: "79438891"
---
# <a name="stack"></a>/STACK

```
/STACK:reserve[,commit]
```

## <a name="remarks"></a>Comentários

Essa opção define o tamanho da pilha em bytes e usa argumentos em notação decimal ou C-Language. A opção/STACK aplica-se somente a um arquivo executável.

O argumento *Reserve* especifica a alocação de pilha total na memória virtual. EDITBIN arredonda o valor especificado para os 4 bytes mais próximos.

O argumento opcional `commit` está sujeito à interpretação do sistema operacional. No Windows NT, Windows 95 e Windows 98, `commit` especifica a quantidade de memória física a ser alocada de cada vez. A memória virtual confirmada faz com que o espaço seja reservado no arquivo de paginação. Um valor mais alto `commit` poupa tempo quando o aplicativo precisa de mais espaço de pilha, mas aumenta os requisitos de memória e, possivelmente, o tempo de inicialização.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
