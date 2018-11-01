---
title: Conversões de estilo C com - clr (C + + / CLI)
ms.date: 10/12/2018
ms.topic: reference
helpviewer_keywords:
- C-style casts and /clr
ms.assetid: d2a4401a-156a-4da9-8d12-923743e26913
ms.openlocfilehash: abbcd61f8c86709e16958e4220c0ea96e393c8bb
ms.sourcegitcommit: 6052185696adca270bc9bdbec45a626dd89cdcdd
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 10/31/2018
ms.locfileid: "50447067"
---
# <a name="c-style-casts-with-clr-ccli"></a>Conversões de Estilo C-Style com /clr (C++/CLI)

O tópico a seguir se aplica somente a Common Language Runtime.

Quando usado com tipos CLR, o compilador tenta mapear o C-style convertido em um das conversões listadas abaixo, na seguinte ordem:

1. const_cast

2. safe_cast

3. Safe_cast além de const_cast

4. static_cast

5. static_cast além de const_cast

Se nenhum das conversões listadas acima é válido e se o tipo da expressão e o tipo de destino são tipos de referência do CLR, conversão C-style é mapeado para uma verificação de tempo de execução (instrução de MSIL castclass). Caso contrário, uma conversão C-style é considerada inválida e o compilador emitirá um erro.

## <a name="remarks"></a>Comentários

Não é recomendável uma conversão C-style. Ao compilar com [/clr (compilação de tempo de execução de linguagem comum)](../build/reference/clr-common-language-runtime-compilation.md), use [safe_cast](../windows/safe-cast-cpp-component-extensions.md).

O exemplo a seguir mostra um estilo C conversão que mapeia para um **const_cast**.

```cpp
// cstyle_casts_1.cpp
// compile with: /clr
using namespace System;

ref struct R {};
int main() {
   const R^ constrefR = gcnew R();
   R^ nonconstR = (R^)(constrefR);
}
```

O exemplo a seguir mostra um estilo C conversão que mapeia para um **safe_cast**.

```cpp
// cstyle_casts_2.cpp
// compile with: /clr
using namespace System;
int main() {
   Object ^ o = "hello";
   String ^ s = (String^)o;
}
```

O exemplo a seguir mostra um estilo C conversão que mapeia para um **safe_cast** plus **const_cast**.

```cpp
// cstyle_casts_3.cpp
// compile with: /clr
using namespace System;

ref struct R {};
ref struct R2 : public R {};

int main() {
   const R^ constR2 = gcnew R2();
   try {
   R2^ b2DR = (R2^)(constR2);
   }
   catch(InvalidCastException^ e) {
      System::Console::WriteLine("Invalid Exception");
   }
}
```

O exemplo a seguir mostra um estilo C conversão que mapeia para um **static_cast**.

```cpp
// cstyle_casts_4.cpp
// compile with: /clr
using namespace System;

struct N1 {};
struct N2 {
   operator N1() {
      return N1();
   }
};

int main() {
   N2 n2;
   N1 n1 ;
   n1 = (N1)n2;
}
```

O exemplo a seguir mostra um estilo C conversão que mapeia para um **static_cast** plus **const_cast**.

```cpp
// cstyle_casts_5.cpp
// compile with: /clr
using namespace System;
struct N1 {};

struct N2 {
   operator const N1*() {
      static const N1 n1;
      return &n1;
   }
};

int main() {
   N2 n2;
   N1* n1 = (N1*)(const N1*)n2;   // const_cast + static_cast
}
```

O exemplo a seguir mostra um estilo C conversão que mapeia para uma verificação de tempo de execução.

```cpp
// cstyle_casts_6.cpp
// compile with: /clr
using namespace System;

ref class R1 {};
ref class R2 {};

int main() {
   R1^ r  = gcnew R1();
   try {
      R2^ rr = ( R2^)(r);
   }
   catch(System::InvalidCastException^ e) {
      Console::WriteLine("Caught expected exception");
   }
}
```

O exemplo a seguir mostra um inválido C-style cast, o que faz com que o compilador para emitir um erro.

```cpp
// cstyle_casts_7.cpp
// compile with: /clr
using namespace System;
int main() {
   String^s = S"hello";
   int i = (int)s;   // C2440
}
```

## <a name="requirements"></a>Requisitos

Opção do compilador: `/clr`

## <a name="see-also"></a>Consulte também

[Extensões de componentes para .NET e UWP](../windows/component-extensions-for-runtime-platforms.md)