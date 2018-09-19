---
title: Erro do compilador C2248 | Microsoft Docs
ms.custom: ''
ms.date: 11/04/2016
ms.technology:
- cpp-diagnostics
ms.topic: error-reference
f1_keywords:
- C2248
dev_langs:
- C++
helpviewer_keywords:
- C2248
ms.assetid: 7a3ba0e8-d3b9-4bb9-95db-81ef17e31d23
author: corob-msft
ms.author: corob
ms.workload:
- cplusplus
ms.openlocfilehash: 47e3a2f5eb51fe2b3d773a2eeb1881c8f1adb8dc
ms.sourcegitcommit: 913c3bf23937b64b90ac05181fdff3df947d9f1c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/18/2018
ms.locfileid: "46085908"
---
# <a name="compiler-error-c2248"></a>Erro do compilador C2248

'*membro*': não é possível acessar '*access_level*'membro declarado na classe'*classe*'

Os membros de uma classe derivada não podem acessar `private` membros de uma classe base. Você não pode acessar `private` ou `protected` membros de instâncias de classes.

## <a name="example"></a>Exemplo

O exemplo a seguir gera C2248 quando particular ou protegidos membros de uma classe são acessados de fora da classe. Para corrigir esse problema, não acesse esses membros diretamente fora da classe. Use funções de membro e dados de membro público para interagir com a classe.

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

Outro problema de conformidade que expõe C2248 é o uso de amigos de modelo e especialização. Para corrigir esse problema, declare amigo funções de modelo usando um <> de lista de parâmetro de modelo vazio ou parâmetros de modelo específico.

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

Outro problema de conformidade que expõe C2248 é quando você tentar declarar um amigo de uma classe e a classe não é visível para a declaração friend no escopo da classe. Para corrigir esse problema, conceda a amizade à classe delimitadora.

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