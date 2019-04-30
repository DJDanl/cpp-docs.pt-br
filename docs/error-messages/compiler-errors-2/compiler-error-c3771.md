---
title: Erro do compilador C3771
ms.date: 11/04/2016
f1_keywords:
- C3771
helpviewer_keywords:
- C3771
ms.assetid: 68c23b25-7f21-4eaa-8f7e-38fda1130a69
ms.openlocfilehash: 6b15d867bbaf66f511cbda200d692f5db4371ab3
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62400156"
---
# <a name="compiler-error-c3771"></a>Erro do compilador C3771

"identificador": declaração friend não pode ser encontrada no escopo de namespace mais próximo

A declaração de modelo de classe para o modelo especificado *identificador* não pode ser encontrado no namespace atual.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Certifique-se de que a declaração de modelo de classe para o identificador de modelo é definida no namespace atual ou que o identificador de modelo é um nome totalmente qualificado.

## <a name="example"></a>Exemplo

O exemplo de código a seguir declara um modelo de classe e uma função no namespace `NA`, mas tentar declarar um modelo de função friend no namespace `NB`.

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

## <a name="see-also"></a>Consulte também

[Modelos](../../cpp/templates-cpp.md)