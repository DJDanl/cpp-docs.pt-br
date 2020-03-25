---
title: substituir especificador
ms.date: 11/04/2016
helpviewer_keywords:
- override Identifier
ms.assetid: b286fb46-9374-4ad8-b2e7-4607119b6133
ms.openlocfilehash: 82837ae34ab786e607df54038493b14350574a15
ms.sourcegitcommit: 857fa6b530224fa6c18675138043aba9aa0619fb
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/24/2020
ms.locfileid: "80188474"
---
# <a name="override-specifier"></a>substituir especificador

Você pode usar a palavra-chave **override** para designar funções de membro que substituem uma função virtual em uma classe base.

## <a name="syntax"></a>Sintaxe

```
function-declaration override;
```

## <a name="remarks"></a>Comentários

a **substituição** é contextual e tem um significado especial apenas quando é usada após uma declaração de função de membro; caso contrário, não é uma palavra-chave reservada.

## <a name="example"></a>Exemplo

Use **override** para ajudar a evitar o comportamento de herança acidental em seu código. O exemplo a seguir mostra onde, sem usar **override**, o comportamento da função membro da classe derivada pode não ter sido planejado. O compilador não emite erros para esse código.

```cpp
class BaseClass
{
    virtual void funcA();
    virtual void funcB() const;
    virtual void funcC(int = 0);
    void funcD();
};

class DerivedClass: public BaseClass
{
    virtual void funcA(); // ok, works as intended

    virtual void funcB(); // DerivedClass::funcB() is non-const, so it does not
                          // override BaseClass::funcB() const and it is a new member function

    virtual void funcC(double = 0.0); // DerivedClass::funcC(double) has a different
                                      // parameter type than BaseClass::funcC(int), so
                                      // DerivedClass::funcC(double) is a new member function
};
```

Quando você usa **override**, o compilador gera erros em vez de criar silenciosamente novas funções de membro.

```cpp
class BaseClass
{
    virtual void funcA();
    virtual void funcB() const;
    virtual void funcC(int = 0);
    void funcD();
};

class DerivedClass: public BaseClass
{
    virtual void funcA() override; // ok

    virtual void funcB() override; // compiler error: DerivedClass::funcB() does not
                                   // override BaseClass::funcB() const

    virtual void funcC( double = 0.0 ) override; // compiler error:
                                                 // DerivedClass::funcC(double) does not
                                                 // override BaseClass::funcC(int)

    void funcD() override; // compiler error: DerivedClass::funcD() does not
                           // override the non-virtual BaseClass::funcD()
};
```

Para especificar que as funções não podem ser substituídas e que as classes não podem ser herdadas, use a palavra-chave [final](../cpp/final-specifier.md) .

## <a name="see-also"></a>Confira também

[Especificador final](../cpp/final-specifier.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)
