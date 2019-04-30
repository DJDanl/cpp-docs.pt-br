---
title: substituir especificador
ms.date: 11/04/2016
helpviewer_keywords:
- override Identifier
ms.assetid: b286fb46-9374-4ad8-b2e7-4607119b6133
ms.openlocfilehash: 71505f8b9b4dc2800e80a78a64f0ca6984af1349
ms.sourcegitcommit: c6f8e6c2daec40ff4effd8ca99a7014a3b41ef33
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/24/2019
ms.locfileid: "64345861"
---
# <a name="override-specifier"></a>substituir especificador

Você pode usar o **substituir** palavra-chave para designar as funções que substituem uma função virtual em uma classe base membro.

## <a name="syntax"></a>Sintaxe

```
function-declaration override;
```

## <a name="remarks"></a>Comentários

**substituir** é contextual e tem um significado somente quando especial é usada após uma declaração de função de membro; caso contrário, ele não é uma palavra-chave reservada.

## <a name="example"></a>Exemplo

Use **substituir** para ajudar a evitar o comportamento de herança inadequados em seu código. O exemplo a seguir mostra onde, sem usar **substituir**, o comportamento da função de membro da classe derivada pode não ser o esperado. O compilador não emite erros para esse código.

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

Quando você usa **substituir**, o compilador gera erros em vez de criar silenciosamente novo membro de funções.

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

Para especificar que as funções não podem ser substituídas e que as classes não podem ser herdadas, use o [final](../cpp/final-specifier.md) palavra-chave.

## <a name="see-also"></a>Consulte também

[Especificador final](../cpp/final-specifier.md)<br/>
[Palavras-chave](../cpp/keywords-cpp.md)