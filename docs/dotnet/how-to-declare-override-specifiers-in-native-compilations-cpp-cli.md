---
title: 'Como: Declarar Especificadores de Substituição (C++/CLI)'
ms.date: 11/04/2016
helpviewer_keywords:
- override specifiers in native compilation, overriding
ms.assetid: d0551836-9ac7-41eb-a6e9-a4b3ef60767d
ms.openlocfilehash: 9f3f6855f257d0af250b9bbdd2c0360b308ce775
ms.sourcegitcommit: c123cc76bb2b6c5cde6f4c425ece420ac733bf70
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/14/2020
ms.locfileid: "81374446"
---
# <a name="how-to-declare-override-specifiers-in-native-compilations-ccli"></a>Como declarar especificadores de substituição em compilações nativas (C++/CLI)

[lacrado,](../extensions/sealed-cpp-component-extensions.md) [abstrato](../extensions/abstract-cpp-component-extensions.md)e [substituição](../extensions/override-cpp-component-extensions.md) estão disponíveis em compilações que não usam **/ZW** ou [/clr](../build/reference/clr-common-language-runtime-compilation.md).

> [!NOTE]
> A linguagem PADRÃO ISO C++11 tem o [identificador de substituição](../cpp/override-specifier.md) e o identificador `sealed` [final,](../cpp/final-specifier.md) e ambos são suportados no Visual Studio Use `final` em vez de em código que deve ser compilado apenas como nativo.

## <a name="example"></a>Exemplo

### <a name="description"></a>Descrição

O exemplo a `sealed` seguir mostra que é válido em compilações nativas.

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

O próximo exemplo `override` mostra que é válido em compilações nativas.

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

Este exemplo `abstract` mostra que é válido em compilações nativas.

### <a name="code"></a>Código

```cpp
// abstract_native_keyword.cpp
class X abstract {};

int main() {
   X * MyX = new X;   // C3622 cannot instantiate abstract class
}
```

## <a name="see-also"></a>Confira também

[Especificadores de substituição](../extensions/override-specifiers-cpp-component-extensions.md)
