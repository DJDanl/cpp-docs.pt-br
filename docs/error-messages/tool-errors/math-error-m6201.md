---
title: Erro M6201 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6201
helpviewer_keywords:
- M6201
ms.assetid: 4041c331-d9aa-4dd4-b565-7dbe0218538c
ms.openlocfilehash: 0b1cd0d3fcd86a2174b19da41176dd97f547a295
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80193700"
---
# <a name="math-error-m6201"></a>Erro M6201 (Math)

' function ': erro de _DOMAIN

Um argumento para a função fornecida estava fora do domínio de valores de entrada legais para essa função.

## <a name="example"></a>Exemplo

```
result = sqrt(-1.0)   // C statement
result = SQRT(-1.0)   !  FORTRAN statement
```

Esse erro chama a função `_matherr` com o nome da função, seus argumentos e o tipo de erro. Você pode reescrever a função `_matherr` para personalizar o tratamento de determinados erros de matemática de ponto flutuante de tempo de execução.
