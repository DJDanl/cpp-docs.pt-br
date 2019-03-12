---
title: 'Como: Declarar especificadores de substituição (C + + / CLI)'
ms.date: 11/04/2016
helpviewer_keywords:
- override specifiers in native compilation, overriding
ms.assetid: d0551836-9ac7-41eb-a6e9-a4b3ef60767d
ms.openlocfilehash: 2c9238eab1627b0494c4073c88032c488fdfb828
ms.sourcegitcommit: dedd4c3cb28adec3793329018b9163ffddf890a4
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 03/11/2019
ms.locfileid: "57752379"
---
# <a name="how-to-declare-override-specifiers-in-native-compilations-ccli"></a>Como: Declarar especificadores de substituição em compilações nativas (C + + / CLI)

[lacrado](../windows/sealed-cpp-component-extensions.md), [abstrata](../windows/abstract-cpp-component-extensions.md), e [substituir](../windows/override-cpp-component-extensions.md) estão disponíveis em compilações que não usam **/ZW** ou [/clr](../build/reference/clr-common-language-runtime-compilation.md).

> [!NOTE]
>  O ISO C + + 11 linguagem padrão tem o [substituir](../cpp/override-specifier.md) identificador e o [final](../cpp/final-specifier.md) identificador e ambos têm suporte no Visual Studio, Use `final` em vez de `sealed` no código que destina-se ao ser compilado como somente nativo.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir mostra que `sealed` é válido em compilações nativas.

### <a name="code"></a>Código

```cpp
// sealed_native_keyword.cpp
#include <stdio.h>
__interface I1 {
   virtual void f();
   virtual void g();
};

class X : public I1 {
public:
   virtual void g() sealed {}
};

class Y : public X {
public:

   // the following override generates a compiler error
   virtual void g() {}   // C3248 X::g is sealed!
};
```

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a seguir mostra que `override` é válido em compilações nativas.

### <a name="code"></a>Código

```cpp
// override_native_keyword.cpp
#include <stdio.h>
__interface I1 {
   virtual void f();
};

class X : public I1 {
public:
   virtual void f() override {}   // OK
   virtual void g() override {}   // C3668 I1::g does not exist
};
```

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

Este exemplo mostra que `abstract` é válido em compilações nativas.

### <a name="code"></a>Código

```cpp
// abstract_native_keyword.cpp
class X abstract {};

int main() {
   X * MyX = new X;   // C3622 cannot instantiate abstract class
}
```

## <a name="see-also"></a>Consulte também

[Especificadores de substituição](../windows/override-specifiers-cpp-component-extensions.md)
