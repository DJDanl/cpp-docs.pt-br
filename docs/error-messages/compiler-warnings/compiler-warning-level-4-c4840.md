---
title: Aviso do compilador (nível 4) C4840
ms.date: 09/13/2018
f1_keywords:
- C4840
helpviewer_keywords:
- C4840
ms.openlocfilehash: 649083d66d0c7a0ef11c742e56cbfb70e2e9b75f
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80185198"
---
# <a name="compiler-warning-level-4-c4840"></a>Aviso do compilador (nível 4) C4840

> uso não portátil da classe '*Type*' como um argumento para uma função Variadic

## <a name="remarks"></a>Comentários

Classes ou estruturas que são passadas para uma função Variadic devem ser trivialmente copiáveis. Ao passar esses objetos, o compilador simplesmente faz uma cópia bit a bit e não chama o construtor nem o destruidor.

Esse aviso está disponível a partir do Visual Studio 2017.

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

Para cadeias de caracteres criadas e gerenciadas usando `CStringW`, o `operator LPCWSTR()` fornecido deve ser usado para converter um objeto `CStringW` para o ponteiro de cadeia de caracteres estilo C esperado pela cadeia de caracteres de formato:

```cpp
    CStringW str1;
    CStringW str2;
    // ...
    str1.Format("%s", static_cast<LPCWSTR>(str2));
```
