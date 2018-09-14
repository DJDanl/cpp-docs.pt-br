---
title: C4840 do compilador (nível 4) de aviso | Microsoft Docs
ms.custom: ''
ms.date: 09/13/2018
ms.topic: error-reference
f1_keywords:
- C4840
dev_langs:
- C++
helpviewer_keywords:
- C4840
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 0baf70ac7fd4d07958478d2eef455c7dc395e221
ms.sourcegitcommit: 87d317ac62620c606464d860aaa9e375a91f4c99
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/14/2018
ms.locfileid: "45601821"
---
# <a name="compiler-warning-level-4-c4840"></a>C4840 do compilador (nível 4) de aviso

> o uso não portátil da classe*tipo*' como um argumento para uma função variadic
  
## <a name="remarks"></a>Comentários

Classes ou estruturas que são passadas para uma função variadic devem ser facilmente copiadas. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor.

Esse aviso é disponível partir do Visual Studio 2017.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C4840 e mostra como corrigi-lo:

```cpp
// C4840.cpp
// compile by using: cl /EHsc /W4 C4840.cpp
#include <stdio.h>

int main()
{
    struct S {
        S(int i) : i(i) {}
        S(const S& other) : i(other.i) {}
        operator int() { return i; }
    private:
        int i;
    } s(0);

    printf("%i\n", s); // warning C4840 : non-portable use of class 'main::S'
                       // as an argument to a variadic function
    // To correct the error, you can perform a static cast
    // to convert the object before passing it:
    printf("%i\n", static_cast<int>(s));
}
```

Para cadeias de caracteres criadas e gerenciadas usando `CStringW`, fornecido `operator LPCWSTR()` deve ser usado para converter um `CStringW` objeto no ponteiro de cadeia de caracteres de estilo C esperado pela cadeia de caracteres de formato:

```cpp
    CStringW str1;
    CStringW str2;
    // ...
    str1.Format("%s", static_cast<LPCWSTR>(str2));
```