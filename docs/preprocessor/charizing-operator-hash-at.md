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
ms.openlocfilehash: c9acc9b9872e096cd441b950632c341e975fecb8
ms.sourcegitcommit: 72583d30170d6ef29ea5c6848dc00169f2c909aa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/18/2019
ms.locfileid: "59034329"
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