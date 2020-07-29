---
title: 'Como: declarar especificadores de substituição (C++/CLI)'
ms.date: 11/04/2016
helpviewer_keywords:
- override specifiers in native compilation, overriding
ms.assetid: d0551836-9ac7-41eb-a6e9-a4b3ef60767d
ms.openlocfilehash: c5ed413f403fb12f116633c0e39f9e7b32b2e9f8
ms.sourcegitcommit: 1f009ab0f2cc4a177f2d1353d5a38f164612bdb1
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 07/27/2020
ms.locfileid: "87221322"
---
# <a name="how-to-declare-override-specifiers-in-native-compilations-ccli"></a>Como declarar especificadores de substituição em compilações nativas (C++/CLI)

[sealed](../extensions/sealed-cpp-component-extensions.md), [abstract](../extensions/abstract-cpp-component-extensions.md)e [override](../extensions/override-cpp-component-extensions.md) estão disponíveis em compilações que não usam **/zw** ou [/CLR](../build/reference/clr-common-language-runtime-compilation.md).

> [!NOTE]
> O idioma padrão ISO C++ 11 tem o identificador de [substituição](../cpp/override-specifier.md) e o identificador [final](../cpp/final-specifier.md) , e ambos têm suporte no uso do Visual Studio `final` em vez de **`sealed`** no código que deve ser compilado como somente nativo.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

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
