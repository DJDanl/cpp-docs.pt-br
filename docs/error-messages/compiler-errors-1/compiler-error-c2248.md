---
title: Erro do compilador C2248
ms.date: 11/04/2016
f1_keywords:
- C2248
helpviewer_keywords:
- C2248
ms.assetid: 7a3ba0e8-d3b9-4bb9-95db-81ef17e31d23
ms.openlocfilehash: d35ded4b06423be53911f3efd0b55d75cb979773
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87212807"
---
# <a name="compiler-error-c2248"></a>Erro do compilador C2248

'*Member*': não é possível acessar o membro '*access_level*' declarado na classe '*Class*'

Os membros de uma classe derivada não podem acessar **`private`** membros de uma classe base. Você não pode acessar **`private`** ou **`protected`** membros de instâncias de classe.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2248 quando membros privados ou protegidos de uma classe são acessados de fora da classe. Para corrigir esse problema, não Acesse esses membros diretamente fora da classe. Use dados de membro público e funções de membro para interagir com a classe.

```cpp
// C2248_access.cpp
// compile with: cl /EHsc /W4 C2248_access.cpp
#include <stdio.h>

class X {
public:
    int  m_publicMember;
    void setPrivateMember( int i ) {
        m_privateMember = i;
        printf_s("\n%d", m_privateMember);
    }
protected:
    int  m_protectedMember;

private:
    int  m_privateMember;
} x;

int main() {
    x.m_publicMember = 4;
    printf_s("\n%d", x.m_publicMember);
    x.m_protectedMember = 2; // C2248 m_protectedMember is protected
    x.m_privateMember = 3;   // C2248  m_privMemb is private
    x.setPrivateMember(0);   // OK uses public access function
}
```

Outro problema de conformidade que expõe C2248 é o uso de amigos e especialização do modelo. Para corrigir esse problema, declare funções de modelo Friend usando uma lista de parâmetros de modelo vazia <> ou parâmetros de modelo específicos.

```cpp
// C2248_template.cpp
// compile with: cl /EHsc /W4 C2248_template.cpp
template<class T>
void f(T t) {
    t.i;   // C2248
}

struct S {
private:
    int i;

public:
    S() {}
    friend void f(S);   // refer to the non-template function void f(S)
    // To fix, comment out the previous line and
    // uncomment the following line.
    // friend void f<S>(S);
};

int main() {
    S s;
    f<S>(s);
}
```

Outro problema de conformidade que expõe C2248 é quando você tenta declarar um amigo de uma classe e quando a classe não está visível para a declaração Friend no escopo da classe. Para corrigir esse problema, conceda a amizade à classe delimitadora.

```cpp
// C2248_enclose.cpp
// compile with: cl /W4 /c C2248_enclose.cpp
class T {
    class S {
        class E {};
    };
    friend class S::E;   // C2248
};

class A {
    class S {
        class E {};
        friend class A;  // grant friendship to enclosing class
    };
    friend class S::E;   // OK
};
```
