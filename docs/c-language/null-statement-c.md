---
title: Instrução nula (C)
ms.date: 11/04/2016
helpviewer_keywords:
- semicolon, C null statement
- expressions [C++], null
- null statement
- null values, expressions
ms.assetid: 72576ce6-26d0-4379-be65-fee522088790
ms.openlocfilehash: 58825544121c6cb189b52469403effb93f5f5f8c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87227810"
---
# <a name="null-statement-c"></a>Instrução nula (C)

Uma "instrução nula" é uma instrução que contém apenas um ponto e vírgula; ela pode aparecer onde quer que uma instrução seja esperada. Nada acontece quando uma instrução nula é executada. A forma correta de codificar uma instrução nula é:

## <a name="syntax"></a>Sintaxe

> **;**

## <a name="remarks"></a>Comentários

Instruções como **`do`** ,, **`for`** **`if`** e **`while`** exigem que uma instrução executável apareça como o corpo da instrução. A instrução nula satisfaz o requisito de sintaxe nos casos que não precisam de um corpo de instrução substantivo.

Como acontece com qualquer outra instrução do C, você pode incluir um rótulo antes de uma instrução nula. Para rotular um item que não é uma instrução, como a chave de fechamento de uma instrução composta, você pode rotular uma instrução nula e inseri-la imediatamente antes do item para obter o mesmo efeito.

Este exemplo ilustra a instrução nula:

```C
for ( i = 0; i < 10; line[i++] = 0 )
     ;
```

Neste exemplo, a expressão de loop da **`for`** instrução `line[i++] = 0` Inicializa os primeiros 10 elementos de `line` como 0. O corpo da instrução é uma instrução nula, já que nenhuma instrução adicional é necessária.

## <a name="see-also"></a>Confira também

[Instruções](../c-language/statements-c.md)
