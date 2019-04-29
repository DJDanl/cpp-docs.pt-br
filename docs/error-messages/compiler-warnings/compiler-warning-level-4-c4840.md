---
title: C4840 do compilador (nível 4) de aviso
ms.date: 09/13/2018
f1_keywords:
- C4840
helpviewer_keywords:
- C4840
ms.openlocfilehash: a757004659c1a9d2ce858cfae5ddfbc6c024d782
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62360002"
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