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
ms.openlocfilehash: bc98c8561a7fd06f875781802558cdd7e71a67ec
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80169234"
---
# <a name="type-and-variable-sizes-in-inline-assembly"></a>Tamanhos de tipo e variável em assembly embutido

**Seção específica da Microsoft**

Os operadores de **comprimento**, **tamanho**e **tipo** têm um significado limitado no assembly embutido. Eles não podem ser usados com o operador de `DUP` (porque você não pode definir dados com diretivas ou operadores MASM). Mas você pode usá-los para localizar o tamanho de C C++ ou de variáveis ou tipos:

- O operador **Length** pode retornar o número de elementos em uma matriz. Ele retorna o valor 1 para variáveis que não são da matriz.

- O operador **size** pode retornar o tamanho de um C ou C++ uma variável. O tamanho de uma variável é o produto de seu **comprimento** e **tipo**.

- O operador **Type** pode retornar o tamanho de um C ou C++ tipo ou variável. Se a variável for uma matriz, **Type** retornará o tamanho de um único elemento da matriz.

Por exemplo, se seu programa tiver uma matriz **int** de 8 elementos,

```cpp
int arr[8];
```

as expressões C e assembly a seguir produzem o tamanho de `arr` e seus elementos.

|__asm|C|Tamanho|
|-------------|-------|----------|
|**Comprimento** arr|`sizeof`(ARR)/`sizeof`(arr [0])|8|
|Arr de **tamanho**|`sizeof`(ARR)|32|
|**Digite** arr|`sizeof`(arr [0])|4|

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Confira também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>
