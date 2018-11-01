---
title: Erro do compilador C3772
ms.date: 11/04/2016
f1_keywords:
- C3772
helpviewer_keywords:
- C3772
ms.assetid: 63e938d4-088d-41cc-a562-5881a05b5710
ms.openlocfilehash: 9a72cb9ee5d1d839f6ca5d113c25795f83dab811
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50595670"
---
# <a name="compiler-error-c3772"></a>Erro do compilador C3772

"name": declaração de modelo friend inválido

Não é válido para declarar um amigo de uma especialização de modelo de classe. Você não pode declarar uma especialização explícita ou parcial de um modelo de classe e na mesma instrução declare um amigo que especialização. O *nome* espaço reservado identifica declaração inválida.

### <a name="to-correct-this-error"></a>Para corrigir este erro

- Não declare um amigo de uma especialização de modelo de classe.

- Se for apropriado para seu aplicativo, declare um amigo do modelo de classe ou declare um amigo de uma especialização explícita ou parcial específico.

## <a name="example"></a>Exemplo

O exemplo de código a seguir falha porque ela declara um amigo de uma especialização parcial de um modelo de classe.

```cpp
// c3772.cpp
// compile with: /c

// A class template.
    template<class T> class A {};

// A partial specialization of the class template.
    template<class T> class A<T*> {};

// An explicit specialization.
    template<> class A<char>;

class X {
// Invalid declaration of a friend of a partial specialization.
    template<class T> friend class A<T*>; // C3772

// Instead, if it is appropriate for your application, declare a
// friend of the class template. Consequently, all specializations
// of the class template are friends:
//    template<class T> friend class A;
// Or declare a friend of a particular partial specialization:
//    friend class A<int*>;
// Or declare a friend of a particular explicit specialization:
//    friend class A<char>;
};
```

## <a name="see-also"></a>Consulte também

[Modelos](../../cpp/templates-cpp.md)<br/>
[Especialização de modelo](../../cpp/template-specialization-cpp.md)
