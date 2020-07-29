---
title: Tamanhos de tipo e variável em assembly embutido
ms.date: 08/30/2018
ms.topic: reference
helpviewer_keywords:
- variables, length
- size, getting in inline assembly
- size
- LENGTH operator
- TYPE operator
- SIZE operator
- inline assembly, operators
- variables, type
- variables, size
ms.assetid: b62c2f2b-a7ad-4145-bae4-d890db86d348
ms.openlocfilehash: 3e244aaa8ea849b558b77c3f1569820079f6f76c
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87191606"
---
# <a name="type-and-variable-sizes-in-inline-assembly"></a>Tamanhos de tipo e variável em assembly embutido

**Específico da Microsoft**

Os operadores de **comprimento**, **tamanho**e **tipo** têm um significado limitado no assembly embutido. Eles não podem ser usados com o `DUP` operador (porque você não pode definir dados com diretivas ou operadores MASM). Mas você pode usá-los para localizar o tamanho de variáveis ou tipos C ou C++:

- O operador **Length** pode retornar o número de elementos em uma matriz. Ele retorna o valor 1 para variáveis que não são da matriz.

- O operador **size** pode retornar o tamanho de uma variável C ou C++. O tamanho de uma variável é o produto de seu **comprimento** e **tipo**.

- O operador **Type** pode retornar o tamanho de um tipo C ou C++ ou uma variável. Se a variável for uma matriz, **Type** retornará o tamanho de um único elemento da matriz.

Por exemplo, se seu programa tiver uma matriz de 8 elementos **`int`** ,

```cpp
int arr[8];
```

as expressões C e assembly a seguir produzem o tamanho `arr` e seus elementos.

|__asm|C|Tamanho|
|-------------|-------|----------|
|**Comprimento** arr|`sizeof(arr)/sizeof(arr[0])`|8|
|Arr de **tamanho**|`sizeof(arr)`|32|
|**Digite** arr|`sizeof(arr[0])`|4|

**FINAL específico da Microsoft**

## <a name="see-also"></a>Confira também

[Usando o idioma do assembly em blocos de __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
