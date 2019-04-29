---
title: Erro do compilador C3465
ms.date: 11/04/2016
f1_keywords:
- C3465
helpviewer_keywords:
- C3465
ms.assetid: aeb815e5-b3fc-4525-afe2-d738e9321df1
ms.openlocfilehash: 117c9b9918950fd2e95e206c5aea457dee183b0a
ms.sourcegitcommit: 0ab61bc3d2b6cfbd52a16c6ab2b97a8ea1864f12
ms.translationtype: MT
ms.contentlocale: pt-BR
ms.lasthandoff: 04/23/2019
ms.locfileid: "62222313"
---
# <a name="compiler-error-c3465"></a>Erro do compilador C3465

Para usar o tipo 'type', você deve referenciar o assembly 'assembly'

Encaminhamento de tipo funcionará para um aplicativo cliente até que você recompilar o cliente. Quando você recompilar, você precisará de uma referência para cada assembly que contém a definição de um tipo usado em seu aplicativo cliente.

Para obter mais informações, consulte [encaminhamento de tipo (C++/CLI)](../../extensions/type-forwarding-cpp-cli.md).

## <a name="example"></a>Exemplo

O exemplo a seguir cria um assembly que contém o novo local de um tipo.

```
// C3465.cpp
// compile with: /clr /LD
public ref class R {
public:
   ref class N {};
};
```

## <a name="example"></a>Exemplo

O exemplo a seguir cria um assembly que é usado para conter a definição do tipo, mas agora contém uma sintaxe de encaminhamento para o tipo.

```
// C3465_b.cpp
// compile with: /clr /LD
#using "C3465.dll"
[ assembly:TypeForwardedTo(R::typeid) ];
```

## <a name="example"></a>Exemplo

O exemplo a seguir gera C3465.

```
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