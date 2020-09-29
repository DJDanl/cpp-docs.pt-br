---
title: 'Como: declarar especificadores de substituição (C++/CLI)'
ms.date: 11/04/2016
helpviewer_keywords:
- override specifiers in native compilation, overriding
ms.assetid: d0551836-9ac7-41eb-a6e9-a4b3ef60767d
ms.openlocfilehash: 92bdc41cf9ebe2389f2d22dab211029899283266
ms.sourcegitcommit: 94893973211d0b254c8bcdcf0779997dcc136b0c
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/28/2020
ms.locfileid: "91414588"
---
# <a name="how-to-declare-override-specifiers-in-native-compilations-ccli"></a>Como declarar especificadores de substituição em compilações nativas (C++/CLI)

[sealed](../extensions/sealed-cpp-component-extensions.md), [abstract](../extensions/abstract-cpp-component-extensions.md)e [override](../extensions/override-cpp-component-extensions.md) estão disponíveis em compilações que não usam **/zw** ou [/CLR](../build/reference/clr-common-language-runtime-compilation.md).

> [!NOTE]
> O idioma padrão ISO C++ 11 tem o identificador de [substituição](../cpp/override-specifier.md) e o identificador [final](../cpp/final-specifier.md) , e ambos têm suporte no uso do Visual Studio `final` em vez de **`sealed`** no código que deve ser compilado como somente nativo.

## <a name="example-sealed-is-valid"></a>Exemplo: sealed é válido

### <a name="description"></a>Description

O exemplo a seguir mostra que **`sealed`** é válido em compilações nativas.

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

## <a name="example-override-is-valid"></a>Exemplo: a substituição é válida

### <a name="description"></a>Description

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

## <a name="example-abstract-is-valid"></a>Exemplo: Abstract é válido

### <a name="description"></a>Description

Este exemplo mostra que **`abstract`** é válido em compilações nativas.

### <a name="code"></a>Código

```cpp
// abstract_native_keyword.cpp
class X abstract {};

int main() {
   X * MyX = new X;   // C3622 cannot instantiate abstract class
}
```

## <a name="see-also"></a>Confira também

[Substituir especificadores](../extensions/override-specifiers-cpp-component-extensions.md)
