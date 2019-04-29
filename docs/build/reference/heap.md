---
title: /HEAP
ms.date: 11/04/2016
f1_keywords:
- /heap
helpviewer_keywords:
- heap allocation, setting heap size
- HEAP editbin option
- -HEAP editbin option
- /HEAP editbin option
ms.assetid: 6ce759b5-75b7-44ff-a5fd-3a83a0ba9a48
ms.openlocfilehash: fcf557b467ba5bd04352ba2f2702659a1eb2948d
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62291984"
---
# <a name="heap"></a>/HEAP

Define o tamanho do heap em bytes. Essa opção só se aplica a arquivos executáveis.

```

/HEAP:
reserve[,commit]
```

## <a name="remarks"></a>Comentários

O `reserve` argumento especifica a alocação inicial de heap total na memória virtual. Por padrão, o tamanho do heap é 1 MB. [Referência de EDITBIN](editbin-reference.md) Arredonda o valor especificado para o múltiplo mais próximo de 4 bytes.

Opcional `commit` argumento está sujeitas a interpretação pelo sistema operacional. Em um sistema operacional Windows, ele especifica a quantidade inicial de memória física para alocar e a quantidade de memória adicional para alocar ao heap deve ser expandido. Memória virtual confirmada faz com que o espaço a ser reservado no arquivo de paginação. Uma maior `commit` valor permite que o sistema alocar memória menor geralmente, quando o aplicativo precisa de mais espaço de heap, mas aumenta os requisitos de memória e, possivelmente, a duração de inicialização do aplicativo. O `commit` valor deve ser menor ou igual ao `reserve` valor.

Especifique o `reserve` e `commit` valores em decimal ou notação octal ou hexadecimal de linguagem C. Por exemplo, um valor de 1 MB pode ser especificado como 1048576 em decimal, ou como 0x100000 em hexadecimal ou como 04000000 em octal.

## <a name="see-also"></a>Consulte também

[Opções de EDITBIN](editbin-options.md)
