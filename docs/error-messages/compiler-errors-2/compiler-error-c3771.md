---
title: Erro do compilador C3771
ms.date: 11/04/2016
f1_keywords:
- C3771
helpviewer_keywords:
- C3771
ms.assetid: 68c23b25-7f21-4eaa-8f7e-38fda1130a69
ms.openlocfilehash: 6c29ad6007d33c43ae1e4758ae05caa9109053e3
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80165724"
---
# <a name="compiler-error-c3771"></a>Erro do compilador C3771

"Identifier": declaração Friend não pode ser encontrada no escopo de namespace mais próximo

A declaração de modelo de classe para o *identificador* de modelo especificado não pode ser encontrada no namespace atual.

### <a name="to-correct-this-error"></a>Para corrigir esse erro

- Verifique se a declaração de modelo de classe para o identificador de modelo está definida no namespace atual ou se o identificador de modelo é um nome totalmente qualificado.

## <a name="example"></a>Exemplo

O exemplo de código a seguir declara um modelo de classe e uma função no namespace `NA`, mas tenta declarar um modelo de função Friend no namespace `NB`.

```cpp
// C3771.cpp
// compile with: /c

namespace NA {
template<class T> class A {
    void aFunction(T t) {};
    };
}
// using namespace NA;
namespace NB {
    class X {
        template<class T> friend void A<T>::aFunction(T); // C3771
// try the following line instead
//      template<class T> friend void NA::A<T>::aFunction(T);
// or try "using namespace NA;" instead.
    };
}
```

## <a name="see-also"></a>Confira também

[Modelos](../../cpp/templates-cpp.md)
