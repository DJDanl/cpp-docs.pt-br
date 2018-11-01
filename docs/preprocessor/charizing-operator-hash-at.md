---
title: Operador de caracterização (#@)
ms.date: 11/04/2016
f1_keywords:
- '#@'
helpviewer_keywords:
- preprocessor, operators
- charizing operator
- '#@ preprocessor operator'
ms.assetid: dee03314-d27c-4063-965c-64756efbef22
ms.openlocfilehash: 7259487a3289173bc77517c8c616638c370041c4
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50568331"
---
# <a name="charizing-operator-"></a>Operador de caracterização (#@)
**Seção específica da Microsoft**

O operador de charizing pode usado apenas com os argumentos das macros. Se `#@` preceder um parâmetro formal na definição da macro, o argumento real é colocado entre aspas simples e tratado como um caractere quando a macro é expandida. Por exemplo:

```
#define makechar(x)  #@x
```

faz com que a instrução

```
a = makechar(b);
```

seja expandida para

```
a = 'b';
```

O caractere de aspas simples não pode ser usado com o operador de charizing.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)