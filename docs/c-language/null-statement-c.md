---
title: Instrução nula (C) | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-language
ms.topic: language-reference
dev_langs:
- C++
helpviewer_keywords:
- semicolon, C null statement
- expressions [C++], null
- null statement
- null values, expressions
ms.assetid: 72576ce6-26d0-4379-be65-fee522088790
author: mikeblome
ms.author: mblome
ms.workload:
- cplusplus
ms.openlocfilehash: 4428852dd3b949bea75961d3878fc23d27a2b4f5
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: HT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46106267"
---
# <a name="null-statement-c"></a>Instrução nula (C)

Uma "instrução nula" é uma instrução que contém apenas um ponto e vírgula; ela pode aparecer onde quer que uma instrução seja esperada. Nada acontece quando uma instrução nula é executada. A forma correta de codificar uma instrução nula é:

## <a name="syntax"></a>Sintaxe

> **;**

## <a name="remarks"></a>Comentários

Instruções como **do**, **for**, **if** e `while` requerem que uma instrução executável apareça como o corpo da instrução. A instrução nula satisfaz o requisito de sintaxe nos casos que não precisam de um corpo de instrução substantivo.

Como acontece com qualquer outra instrução do C, você pode incluir um rótulo antes de uma instrução nula. Para rotular um item que não é uma instrução, como a chave de fechamento de uma instrução composta, você pode rotular uma instrução nula e inseri-la imediatamente antes do item para obter o mesmo efeito.

Este exemplo ilustra a instrução nula:

```C
for ( i = 0; i < 10; line[i++] = 0 )
     ;
```

Nesse exemplo, a expressão de loop da instrução **for** `line[i++] = 0` inicializa os 10 primeiros elementos de `line` como 0. O corpo da instrução é uma instrução nula, já que nenhuma instrução adicional é necessária.

## <a name="see-also"></a>Consulte também

[Instruções](../c-language/statements-c.md)