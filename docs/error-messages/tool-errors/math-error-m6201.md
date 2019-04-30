---
title: Erro M6201 (Math)
ms.date: 11/04/2016
f1_keywords:
- M6201
helpviewer_keywords:
- M6201
ms.assetid: 4041c331-d9aa-4dd4-b565-7dbe0218538c
ms.openlocfilehash: 6d3f107de7e45653374036ecafaa864cb3eff5b0
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62393240"
---
# <a name="math-error-m6201"></a>Erro M6201 (Math)

'function': erro _DOMAIN

Um argumento para a função fornecida era fora do domínio de valores de entrada válidos para essa função.

## <a name="example"></a>Exemplo

```
result = sqrt(-1.0)   // C statement
result = SQRT(-1.0)   !  FORTRAN statement
```

Esse erro chama o `_matherr` função com o nome da função, seus argumentos e o tipo de erro. Você pode reescrever o `_matherr` função para personalizar o tratamento de certos erros de matemática de ponto flutuante de tempo de execução.