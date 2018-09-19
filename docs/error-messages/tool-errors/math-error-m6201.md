---
title: Erro M6201 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- M6201
dev_langs:
- C++
helpviewer_keywords:
- M6201
ms.assetid: 4041c331-d9aa-4dd4-b565-7dbe0218538c
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 87d2c09d6448bcf7fb0557fa3a174c60205a34ea
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46099389"
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