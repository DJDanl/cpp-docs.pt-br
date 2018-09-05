---
title: Tamanhos de tipo e variável em Assembly embutido | Microsoft Docs
ms.custom: ''
ms.date: 08/30/2018
ms.technology:
- cpp-masm
ms.topic: reference
f1_keywords:
- length
- Type
dev_langs:
- C++
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
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 3defb0b11a55258aa0a7d8c050d5a59bb6b8eb5a
ms.sourcegitcommit: a7046aac86f1c83faba1088c80698474e25fe7c3
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/04/2018
ms.locfileid: "43683616"
---
# <a name="type-and-variable-sizes-in-inline-assembly"></a>Tamanhos de tipo e variável em assembly embutido

**Seção específica da Microsoft**

O **comprimento**, **tamanho**, e **tipo** operadores têm um significado limitado em assembly embutido. Não pode ser usados em todos os com o `DUP` operador (porque você não pode definir os dados com diretivas MASM ou operadores). Mas você pode usá-los para localizar o tamanho de variáveis de C ou C++ ou tipos:

- O **comprimento** operador pode retornar o número de elementos em uma matriz. Ele retorna o valor 1 para não-matriz de variáveis.

- O **tamanho** operador pode retornar o tamanho de uma variável de C ou C++. Tamanho da variável é o produto de sua **comprimento** e **tipo**.

- O **tipo** operador pode retornar o tamanho de uma variável ou tipo de C ou C++. Se a variável for uma matriz **tipo** retorna o tamanho de um único elemento da matriz.

Por exemplo, se seu programa tem um elemento de 8 **int** matriz,

```cpp
int arr[8];
```

as expressões de C e o assembly a seguir produzem o tamanho de `arr` e seus elementos.

|__asm|C|Tamanho|
|-------------|-------|----------|
|**COMPRIMENTO** arr|`sizeof`(arr) /`sizeof`(arr[0])|8|
|**TAMANHO** arr|`sizeof`(arr)|32|
|**TIPO** arr|`sizeof`(arr[0])|4|

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Usando a linguagem de assembly em blocos __asm](../../assembler/inline/using-assembly-language-in-asm-blocks.md)<br/>