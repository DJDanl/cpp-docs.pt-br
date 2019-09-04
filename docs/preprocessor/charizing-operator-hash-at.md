---
title: Operador de caracterização (#@)
ms.date: 08/29/2019
f1_keywords:
- '#@'
helpviewer_keywords:
- preprocessor, operators
- charizing operator
- '#@ preprocessor operator'
ms.assetid: dee03314-d27c-4063-965c-64756efbef22
ms.openlocfilehash: cb2a4e07287edf5ed2d0850ec7d870c8ef307879
ms.sourcegitcommit: 6e1c1822e7bcf3d2ef23eb8fac6465f88743facf
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/03/2019
ms.locfileid: "70218538"
---
# <a name="charizing-operator-"></a>Operador de caracterização (#@)

**Seção específica da Microsoft**

O operador de charizing pode usado apenas com os argumentos das macros. Se `#@` precede um parâmetro formal na definição da macro, o argumento real será colocado entre aspas simples e tratado como um caractere quando a macro for expandida. Por exemplo:

```cpp
#define makechar(x)  #@x
```

faz com que a instrução

```cpp
a = makechar(b);
```

seja expandida para

```cpp
a = 'b';
```

O caractere de aspas simples (`'`) não pode ser usado com o operador de caractere.

**Fim da seção específica da Microsoft**

## <a name="see-also"></a>Consulte também

[Operadores de pré-processador](../preprocessor/preprocessor-operators.md)
