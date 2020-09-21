---
title: Erro do compilador C3465
ms.date: 11/04/2016
f1_keywords:
- C3465
helpviewer_keywords:
- C3465
ms.assetid: aeb815e5-b3fc-4525-afe2-d738e9321df1
ms.openlocfilehash: 56eeac18d5b8efc32501bf54e2de3aa216e05a13
ms.sourcegitcommit: 72161bcd21d1ad9cc3f12261aa84a5b026884afa
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 09/17/2020
ms.locfileid: "90742015"
---
# <a name="compiler-error-c3465"></a>Erro do compilador C3465

para usar o tipo ' type ', você deve referenciar o assembly ' assembly '

O encaminhamento de tipo funcionará para um aplicativo cliente até que você recompile o cliente. Ao recompilar, você precisará de uma referência para cada assembly que contenha a definição de um tipo usado em seu aplicativo cliente.

Para obter mais informações, veja [tipo encaminhamento (C++/CLI)](../../extensions/type-forwarding-cpp-cli.md).

## <a name="examples"></a>Exemplos

O exemplo a seguir cria um assembly que contém o novo local de um tipo.

```cpp
// C3465.cpp
// compile with: /clr /LD
public ref class R {
public:
   ref class N {};
};
```

O exemplo a seguir cria um assembly que costumava conter a definição do tipo, mas agora contém a sintaxe de encaminhamento para o tipo.

```cpp
// C3465_b.cpp
// compile with: /clr /LD
#using "C3465.dll"
[ assembly:TypeForwardedTo(R::typeid) ];
```

O exemplo a seguir gera C3465.

```cpp
// C3465_c.cpp
// compile with: /clr
// C3465 expected
#using "C3465_b.dll"
// Uncomment the following line to resolve.
// #using "C3465.dll"

int main() {
   R^ r = gcnew R();
}
```
